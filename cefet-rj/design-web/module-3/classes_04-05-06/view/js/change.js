const $changeButton = document.querySelector('#change');
$changeButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $idInput = document.querySelector('#id');
    let $titleInput = document.querySelector('#title');
    let $ratingInput = document.querySelector('#rating');
    let film = {
        "id": $idInput.value,
        "title": $titleInput.value,
        "rating": parseFloat($ratingInput.value)
    };
    ajaxRequest("PUT", "../controller/change.php", reqChangeSuccess, reqChangeError, film);
})

const $cancelButton = document.querySelector('#cancel');
$cancelButton.addEventListener('click', ()=> {
    if (confirm('Deseja mesmo cancelar a alteração?')){
        window.location.href = "../view/index.html";
    }
})

//callback
function reqChangeError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqChangeSuccess(response) {
    document.querySelector('#successMsg').textContent = response.successMsg;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}