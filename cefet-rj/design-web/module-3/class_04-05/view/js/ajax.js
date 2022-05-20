function fazRequisicaoAjax (metodo, url, cbSucesso, cbErro, dados = null) {
    let xhr = new XMLHttpRequest();
    xhr.open(metodo, url); xhr.setRequestHeader('Content-type', 'application/json');
    xhr.send(JSON.stringify(dados));

    xhr.onreadystatechange = function() {
        if(xhr.readyState === 4) {
            if(!(xhr.status === 200 || xhr.status === 304)) {
                cbErroReq('Erro do cliente '+xhr.statusText);
            }

            if(xhr.status === 200 || xhr.status === 304) {
                let resposta = JSON.parse(xhr.responseText);
                console.log(resposta);
                if (resposta.erro === false) {
                    cbSucessoReq(resposta);
                } else {
                    cbErroReq(resposta.msgErro);
                }
            }
        }
    }
}