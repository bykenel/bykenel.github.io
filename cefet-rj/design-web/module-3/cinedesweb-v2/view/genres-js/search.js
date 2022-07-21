import {getPromise} from '../util-js/getPromise.js';
import {showErrorMsg} from '../util-js/msgUtil.js';

window.onload = function(){
    let qs = window.location.search.replace('?','');
    let searchParameters = qs.split('=');
    let genreId = searchParameters[1];
    searchGenre(genreId);
}

function searchGenre(id) {  
    getPromise("GET", "../controller/genres-php/search.php?id="+id+"")
        .then(function(response) {
            if(response.error === false)
                reqGenreSearchSuccess(response);
            else
                showErrorMsg(response.errorMsg);
        })
        .catch(error => showErrorMsg(error));
}

function reqGenreSearchSuccess(response) {
    let genre = response.data;
    document.querySelector('#id').value = genre.id;
    document.querySelector('#description').value = genre.descricao;
}