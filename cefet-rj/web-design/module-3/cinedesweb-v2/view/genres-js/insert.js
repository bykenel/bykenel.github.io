import {getPromise} from '../util-js/getPromise.js';
import {showErrorMsg} from '../util-js/msgUtil.js';

window.onload = function() {
    getPromise("GET", "../controller/genres-php/list.php")
       .then(function(response){
            showErrorMsg(response.errorMsg);
       })
       .catch(error => showErrorMsg(error));
}

const $sendButton = document.querySelector('#send');
$sendButton.addEventListener('click', function(event) {
   event.preventDefault();
   
   let $descriptionInput = document.querySelector('#description');
   let genre = {
       "description" : $descriptionInput.value
   };
   getPromise("POST", "../controller/genres-php/insert.php", genre)
       .then(function(response) {
           if(response.error === false)
               reqGenreInsertSuccess(response);
           else
               showErrorMsg(response.errorMsg);
       });
})

function reqGenreInsertSuccess(response) {
   document.querySelector('#successMsg').textContent = response.successMsg;
   setTimeout(function(){
       window.location.href = "../view/genres.html";
   }, 2500);
}