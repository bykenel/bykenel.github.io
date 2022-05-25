function excluirFilme(id) {
    if(confirm('Confirma a exclusão do filme de id '+id+'?')) {
        let filme = {"id": id};
        fazRequisicaoAjax("DELETE", "../controller/filmeExcluir.php", cbSucessoReqExcluir, cbErroReqExcluir, filme);
    }
}

//callback
function cbErroReqExcluir(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReqExcluir(resposta) {
    document.querySelector('#msgSucesso').textContent = resposta.msgSucesso;
    setTimeout(function(){
        window.location.href = "../view/index.html";
    }, 2500);
}