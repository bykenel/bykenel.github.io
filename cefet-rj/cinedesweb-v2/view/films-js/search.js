//import {getPromise} from '../util-js/getPromise.js';
import {getFetch} from '../util-js/getFetch.js'
import {showErrorMsg} from '../util-js/msgUtil.js';

window.onload = function(){
    let qs = window.location.search.replace('?','');
    let searchParameters = qs.split('=');
    let filmId = searchParameters[1];
    searchFilm(filmId);
}

function searchFilm(id) {  
    getFetch("GET", "../controller/films-php/search.php?id="+id+"")
        .then(function(response) {
            if(response.error === false)
                reqFilmSearchSuccess(response);
            else
                showErrorMsg(response.errorMsg);
            return response.data.genero_id;
        })
        .then(function(selectedGenreId) {
            searchGenre(selectedGenreId);
        })
        .catch(error => showErrorMsg(error));
}

function reqFilmSearchSuccess(response) {
    let film = response.data;
    document.querySelector('#id').value = film.id;
    document.querySelector('#title').value = film.titulo;
    document.querySelector('#rating').value = film.avaliacao;
}

function reqGenreSearchSuccess(response, selectedGenreId) {
    console.log(response)
    let genre = response.data;
    if(genre != null)    
        genreFormer(genre, selectedGenreId);
}

function searchGenre(selectedGenreId) {
    getFetch("GET", "../controller/genres-php/list.php")
        .then(function(response) {
            if(response.error === false) {
                reqGenreSearchSuccess(response, selectedGenreId);
                document.querySelector('#successMsg').textContent = response.successMsg;
                setTimeout(function(){
                    document.querySelector('#successMsg').textContent = "";
                },2500);
            } else
                showErrorMsg(response.errorMsg);
        })
        .catch(error => showErrorMsg(error));
}

function genreFormer(genre, selectedGenreId) {
    let data = genre;
    for (const i in data) {
        let line = data[i];
        let $opt = document.createElement('option');
        $opt.value = line.id;
        if(line.id == selectedGenreId)
            $opt.setAttribute('selected', 'selected');
        $opt.textContent = line.descricao;
        document.querySelector('#genre').appendChild($opt);
    }
}