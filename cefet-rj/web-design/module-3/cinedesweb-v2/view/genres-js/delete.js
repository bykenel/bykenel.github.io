import {getPromise} from '../util-js/getPromise.js';
import {showErrorMsg} from '../util-js/msgUtil.js';

export function deleteGenre(id) {
    if(confirm('Confirma a exclusão do gênero de id '+id+'?')){ 
        let genre = {"id": id};
        getPromise("DELETE", "../controller/genres-php/delete.php", genre)
            .then(function(response) {
                if(response.error === false)
                    reqGenreDeleteSuccess(response);
                else
                    showErrorMsg(response.errorMsg);
            })
            .catch(function(error) {
                showErrorMsg(error)
            })
    }
}

function reqGenreDeleteSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/genres.html";
    }, 2500);
}