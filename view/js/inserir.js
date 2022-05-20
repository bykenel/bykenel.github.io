const $btnEnviar = document.querySelector('#enviar');
$btnEnviar.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $inputTitulo = document.querySelector('#titulo');
    let $inputAvaliacao = document.querySelector('#avaliacao');
    let filme = {
        "titulo": $inputTitulo.value,
        "avaliacao": parseFloat($inputAvaliacao.value)
    };
    fazRequisicaoAjax("POST", "../controller/filmeInserir.php", cbSucessoReq, cbErroReq, filme);
})

//callback
function cbErroReq(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReq(resposta) {
    document.querySelector('#msgSucesso').textContent = resposta.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 3500);
}