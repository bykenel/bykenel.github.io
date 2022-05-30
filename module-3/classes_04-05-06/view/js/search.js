window.onload = function(){
    let qs = window.location.search.replace('?','');
    let searchParameters = qs.split('=');
    let filmId = searchParameters[1];
    searchFilm(filmId);
}

function searchFilm(id){
    ajaxRequest("GET", "../controller/search.php?id="+id+"", reqSearchSuccess, reqSearchError, null);
}

//callback
function reqSearchError(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function reqSearchSuccess(response) {
    let film = response.dados;
    document.querySelector('#id').value = film.id;
    document.querySelector('#titulo').value = film.titulo;
    document.querySelector('#avaliacao').value = film.avaliacao;
    document.querySelector('#msgSucesso').textContent = response.msgSucesso;
    setTimeout(function(){
        document.querySelector('#msgSucesso').textContent = "";
    }, 2500);
}