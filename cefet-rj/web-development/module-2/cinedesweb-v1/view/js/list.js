ajaxRequest("GET", "../controller/list.php", reqListSuccess, reqListError);

function tableSetup(data) {
    for (const i in data) {
        let line = data[i];
        const $tr = document.createElement('tr');

        tdFormer($tr, line.id, false); //id
        tdFormer($tr, line.titulo, false); //title
        tdFormer($tr, line.avaliacao, false); //rating
        tdFormer($tr, line.genero_descricao, false); //genre
        tdFormer($tr, line.id, true); //links

        document.querySelector('tbody').appendChild($tr);
    }
}

function tdFormer(parentNode, info, html) {
    let $td = document.createElement('td');
    if (!html) {
        $td.textContent = info;
    } else {
        $td.innerHTML = "<a href = ../view/searchForm.html?id="+info+">[Alterar]</a>";
        $td.innerHTML += "<a href =# onclick='deleteFilm("+info+");'>[Excluir]</a>";
    } 
    parentNode.appendChild($td);
}

//callback
function reqListError(msg) {
    document.querySelector('#errorMsg').textContent = msg;
    return;
}

function reqListSuccess(response) {
    let dataContent = response.data;
    tableSetup(dataContent);
}