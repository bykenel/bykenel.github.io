//import {getPromise} from '../util-js/getPromise.js';
import {getFetch} from '../util-js/getFetch.js'
import {showErrorMsg} from '../util-js/msgUtil.js';
     
const $changeButton = document.querySelector('#change');
$changeButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $idInput = document.querySelector('#id');
    let $titleInput = document.querySelector('#title');
    let $ratingInput = document.querySelector('#rating');
    let $genreInput = document.querySelector('#genre');
    let film = {
        "id": $idInput.value,
        "title": $titleInput.value,
        "rating": parseFloat($ratingInput.value),
        "genre": parseInt($genreInput.value)
    };
    getFetch("PUT", "../controller/films-php/change.php", film)
        .then(function(response){
            if (response.error === false)
                reqFilmChangeSuccess(response);
            else
                showErrorMsg(response.errorMsg);
        })
        .catch(error => showErrorMsg(error));
})

const $cancelButton = document.querySelector('#cancel');
$cancelButton.addEventListener('click', ()=> {
    if(confirm('Deseja mesmo cancelar a alteração?')){
        window.location.href = "../view/films.html";
    }
})

function reqFilmChangeSuccess(response){
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/films.html";
    }, 2500);
}