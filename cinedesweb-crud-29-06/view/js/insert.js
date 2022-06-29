window.onload = function() {
    ajaxRequest("GET", "../controller/listGenre.php", reqListGenreSuccess, reqListGenreError);
};

const $sendButton = document.querySelector('#send');
$sendButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $titleInput = document.querySelector('#title');
    let $ratingInput = document.querySelector('#rating');
    let $genreInput = document.querySelector('#genre');
    let film = {
        "title": $titleInput.value,
        "rating": parseFloat($ratingInput.value),
        "genre": parseInt($genreInput.value)
    };
    ajaxRequest("POST", "../controller/insert.php", reqInsertSuccess, reqInsertError, film);
})

//callback
function reqInsertError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqInsertSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}

//genre callback
function reqListGenreError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqListGenreSuccess(response) {
    console.log(response);
    let data = response.data;
    genreFormer(data);
}

function genreFormer(data) {
    for (const i in data) {
        let line = data[i];
        let $opt = document.createElement('option');
        $opt.value = line.id;
        $opt.textContent = line.descricao;
        document.querySelector('#genre').appendChild($opt);
    }
}