const $sendButton = document.querySelector('#send');
$sendButton.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $titleInput = document.querySelector('#title');
    let $ratingInput = document.querySelector('#rating');
    let film = {
        "title": $titleInput.value,
        "rating": parseFloat($ratingInput.value)
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