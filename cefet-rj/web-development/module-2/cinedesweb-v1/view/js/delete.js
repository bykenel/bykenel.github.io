function deleteFilm(id) {
    if(confirm('Confirma a exclusão do film de id '+id+'?')) {
        let film = {"id": id};
        ajaxRequest("DELETE", "../controller/delete.php", reqDeleteSuccess, reqDeleteError, film);
    }
}

//callback
function reqDeleteError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqDeleteSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}