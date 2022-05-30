const $sendButton = document.querySelector('#enviar');
$sendButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $titleInput = document.querySelector('#titulo');
    let $ratingInput = document.querySelector('#avaliacao');
    let film = {
        "titulo": $titleInput.value,
        "avaliacao": parseFloat($ratingInput.value)
    };
    ajaxRequest("POST", "../controller/insert.php", reqInsertSuccess, reqInsertError, film);
})

//callback
function reqInsertError(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function reqInsertSuccess(response) {
    document.querySelector('#msgSucesso').textContent = response.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}