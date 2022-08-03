//import {getPromise} from '../util-js/getPromise.js';
import {getFetch} from '../util-js/getFetch.js'
import {showErrorMsg} from '../util-js/msgUtil.js';
      
const $changeButton = document.querySelector('#change');
$changeButton.addEventListener('click', function(event) {
    event.preventDefault();

    let $idInput = document.querySelector('#id');
    let $descriptionInput = document.querySelector('#description');
    let genre = {
        "id": $idInput.value,
        "description": $descriptionInput.value
    };
    getFetch("PUT", "../controller/genres-php/change.php", genre)
        .then(function(response){
            if (response.error === false)
                reqGenreChangeSuccess(response);
            else
                showErrorMsg(response.errorMsg);
        })
        .catch(error => showErrorMsg(error));
})

const $cancelButton = document.querySelector('#cancel');
$cancelButton.addEventListener('click', ()=> {
    if(confirm('Deseja mesmo cancelar a alteração?')){
        window.location.href = "../view/genres.html";
    }
})

function reqGenreChangeSuccess(response){
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/genres.html";
    }, 2500);
}