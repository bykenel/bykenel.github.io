const $btnAlterar = document.querySelector('#alterar');
$btnAlterar.addEventListener('click', function(event) {
    event.preventDefault();
    
    let $inputId = document.querySelector('#id');
    let $inputTitulo = document.querySelector('#titulo');
    let $inputAvaliacao = document.querySelector('#avaliacao');
    let filme = {
        "id": $inputId.value,
        "titulo": $inputTitulo.value,
        "avaliacao": parseFloat($inputAvaliacao.value)
    };
    fazRequisicaoAjax("PUT", "../controller/change.php", cbSucessoReqAlterar, cbErroReqAlterar, filme);
})

const $btnCancelar = document.querySelector('#cancelar');
$btnCancelar.addEventListener('click', ()=> {
    if (confirm('Deseja mesmo cancelar a alteração?')){
        window.location.href = "../view/index.html";
    }
})

//callback
function cbErroReqAlterar(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReqAlterar(resposta) {
    document.querySelector('#msgSucesso').textContent = resposta.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}