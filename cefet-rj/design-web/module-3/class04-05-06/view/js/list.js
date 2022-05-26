fazRequisicaoAjax("GET", "../controller/list.php", cbSucessoReqListar, cbErroReqListar);

function montarTabela(dados) {
    for (const i in dados) {
        let linha = dados[i];
        const $tr = document.createElement('tr');

        criarTDePendurar($tr, linha.id, false); //id
        criarTDePendurar($tr, linha.titulo, false); //título
        criarTDePendurar($tr, linha.avaliacao, false); //avaliação
        criarTDePendurar($tr, linha.id, true); //links

        document.querySelector('tbody').appendChild($tr);
    }
}

function criarTDePendurar(noPai, info, ehHTML) {
    let $td = document.createElement('td');
    if (!ehHTML) {
        $td.textContent = info;
    } else {
        $td.innerHTML = "<a href = ../view/searchForm.html?id="+info+">[Alterar]</a>";
        $td.innerHTML += "<a href =# onclick='excluirFilme("+info+");'>[Excluir]</a>";
    } 
    noPai.appendChild($td);
}

//callback
function cbErroReqListar(msg) {
    document.querySelector('#msgErro').textContent = msg;
    return;
}

function cbSucessoReqListar(resposta) {
    let dados = resposta.dados;
    montarTabela(dados);
}