const $changeButton = document.querySelector('#alterar');
$changeButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $idInput = document.querySelector('#id');
    let $titleInput = document.querySelector('#titulo');
    let $ratingInput = document.querySelector('#avaliacao');
    let film = {
        "id": $idInput.value,
        "titulo": $titleInput.value,
        "avaliacao": parseFloat($ratingInput.value)
    };
    ajaxRequest("PUT", "../controller/change.php", reqChangeSuccess, reqChangeError, film);
})

const $cancelButton = document.querySelector('#cancelar');
$cancelButton.addEventListener('click', ()=> {
    if (confirm('Deseja mesmo cancelar a alteração?')){
        window.location.href = "../view/index.html";
    }
})

//callback
function reqChangeError(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function reqChangeSuccess(response) {
    document.querySelector('#msgSucesso').textContent = response.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}