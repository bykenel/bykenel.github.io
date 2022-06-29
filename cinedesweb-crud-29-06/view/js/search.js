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
    document.querySelector('#genreId').value = film.genero_id;
    document.querySelector('#id').value = film.id;
    document.querySelector('#title').value = film.titulo;
    document.querySelector('#rating').value = film.avaliacao;
    ajaxRequest("GET", "../controller/listGenre.php", reqSearchGenreSuccess, reqSearchGenreError);    
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        document.querySelector('#successMsg').textContent = "";
    }, 2500);
}

//genre callback
function reqSearchGenreError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqSearchGenreSuccess(response) {
    console.log(response)
    let genre = response.data;
    if(genre!=null)    
        genreFormer(genre);
}

function genreFormer(genre) {
    let data = genre;
    let genreId = parseInt(document.querySelector('#genreId').value);
    for (const i in data) {
        let line = data[i];
        let $opt = document.createElement('option');
        $opt.value = line.id;
        if(line.id == genreId)
            $opt.setAttribute('selected', 'selected');
        $opt.textContent = line.descricao;
        document.querySelector('#genre').appendChild($opt);
    }
}