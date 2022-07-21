import {getPromise} from '../util-js/getPromise.js';
import {showErrorMsg} from '../util-js/msgUtil.js';

window.onload = function() {
     getPromise("GET", "../controller/genres-php/list.php")
        .then(function(response){
            if(response.error === false)
                reqGenreListSuccess(response);
            else
                showErrorMsg(response.errorMsg);
        })
        .catch(error => showErrorMsg(error));
}

const $sendButton = document.querySelector('#send');
$sendButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $titleInput = document.querySelector('#title');
    let $ratingInput = document.querySelector('#rating');
    let $genreInput = document.querySelector('#genre');
    let film = {
        "title": $titleInput.value,
        "rating": parseFloat($ratingInput.value),
        "genre": parseInt($genreInput.value)
    };
    getPromise("POST", "../controller/films-php/insert.php", film)
        .then(function(response) {
            if(response.error === false)
                reqFilmInsertSuccess(response);
            else
                showErrorMsg(response.errorMsg);
        });
})

function reqFilmInsertSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/films.html";
    }, 2500);
}

function reqGenreListSuccess(response) {
    console.log(response);
    let data = response.data;
    genreFormer(data);
}

function genreFormer(data) {
    for (const i in data) {
        let line = data[i];
        let $opt = document.createElement('option');
        $opt.value = line.id;
        $opt.textContent = line.descricao;
        document.querySelector('#genre').appendChild($opt);
    }
}