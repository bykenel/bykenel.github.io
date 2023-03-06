//import {getPromise} from '../util-js/getPromise.js';
import {getFetch} from '../util-js/getFetch.js'
import {showErrorMsg} from '../util-js/msgUtil.js';

export function deleteFilm(id) {
    if(confirm('Confirma a exclusão do film de id '+id+'?')){ 
        let film = {"id": id};
        getFetch("DELETE", "../controller/films-php/delete.php", film)
            .then(function(response) {
                if(response.error === false)
                    reqFilmDeleteSuccess(response);
                else
                    showErrorMsg(response.errorMsg);
            })
            .catch(function(error) {
                showErrorMsg(error)
            })
    }
}

function reqFilmDeleteSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/films.html";
    }, 2500);
}