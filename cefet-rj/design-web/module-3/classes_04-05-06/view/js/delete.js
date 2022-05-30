function deleteFilm(id) {
    if(confirm('Confirma a exclusão do film de id '+id+'?')) {
        let film = {"id": id};
        ajaxRequest("DELETE", "../controller/delete.php", reqDeleteSuccess, reqDeleteError, film);
    }
}

//callback
function reqDeleteError(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function reqDeleteSuccess(response) {
    document.querySelector('#msgSucesso').textContent = response.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}