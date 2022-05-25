const $btnEnviar = document.querySelector('#enviar');
$btnEnviar.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $inputTitulo = document.querySelector('#titulo');
    let $inputAvaliacao = document.querySelector('#avaliacao');
    let filme = {
        "titulo": $inputTitulo.value,
        "avaliacao": parseFloat($inputAvaliacao.value)
    };
    fazRequisicaoAjax("POST", "../controller/filmeInserir.php", cbSucessoReqInserir, cbErroReqInserir, filme);
})

//callback
function cbErroReqInserir(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReqInserir(resposta) {
    document.querySelector('#msgSucesso').textContent = resposta.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}