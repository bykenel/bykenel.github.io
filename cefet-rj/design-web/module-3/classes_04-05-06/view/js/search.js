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
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqSearchSuccess(response) {
    let film = response.data;
    document.querySelector('#id').value = film.id;
    document.querySelector('#title').value = film.title;
    document.querySelector('#rating').value = film.rating;
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        document.querySelector('#successMsg').textContent = "";
    }, 2500);
}