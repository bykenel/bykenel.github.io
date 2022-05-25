window.onload = function(){
    let qs = window.location.search.replace('?','');
    let parametrosBuscar = qs.split('=');
    let idFilme = parametrosBuscar[1];
    buscarFilme(idFilme);
}

function buscarFilme(id){
    fazRequisicaoAjax("GET", "../controller/filmeBuscar.php?id="+id+"", cbSucessoReqBuscar, cbErroReqBuscar, null);
}

//callback
function cbErroReqBuscar(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReqBuscar(resposta) {
    let filme = resposta.dados;
    document.querySelector('#id').value = filme.id;
    document.querySelector('#titulo').value = filme.titulo;
    document.querySelector('#avaliacao').value = filme.avaliacao;
    document.querySelector('#msgSucesso').textContent = resposta.msgSucesso;
    setTimeout(function(){
        document.querySelector('#msgSucesso').textContent = "";
    }, 2500);
}