//import {getPromise} from '../util-js/getPromise.js';
import {getFetch} from '../util-js/getFetch.js'
import {showErrorMsg} from '../util-js/msgUtil.js';
import {deleteGenre} from './delete.js'

getFetch("GET", "../controller/genres-php/list.php")
    .then(function(response){
        if(response.error === false)
            reqGenreListSuccess(response);
        else
            showErrorMsg(response.errorMsg);
    })
    .then(msg => console.log(msg))
    .catch(function(error){
        showErrorMsg(error);
    })

function tableSetup(data) {
    for (const i in data) {
        let line = data[i];
        const $tr = document.createElement('tr');
    
        tdFormer($tr, line.id, false); //id
        tdFormer($tr, line.descricao, false); //description
        tdFormer($tr, line.id, true); //links
    
        document.querySelector('tbody').appendChild($tr);
    }
}
    
const $table = document.querySelector('tbody');
$table.addEventListener('click', function(event){
    let link = event.target;
    if(link.textContent === "[Excluir]"){
        let column = link.parentNode;
        let line = column.parentNode;
        let genreToDelete = parseInt(line.firstChild.textContent);
        deleteGenre(genreToDelete);
    } 
})

function tdFormer(parentNode, info, html) {
    let $td = document.createElement('td');
    if (!html) {
        $td.textContent = info;
    } else {
        $td.innerHTML = "<a href = ../view/genreSearchForm.html?id="+info+">[Alterar]</a>";
        $td.innerHTML += "<a href =# onclick='deleteGenre("+info+");'>[Excluir]</a>";
    } 
    parentNode.appendChild($td);
}

function reqGenreListSuccess(response) {
    let dataContent = response.data;
    tableSetup(dataContent);
}