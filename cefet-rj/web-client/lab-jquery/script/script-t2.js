let produto = function(id, nome, categoria, img, valorUnitario){
    this.id = id;
    this.nome = nome;
    this.categoria = categoria;
    this.foto = img;
    this.valorUnitario = valorUnitario;
}

function pesquisaPorId(vetor, objId){
	return vetor.find(function(item){
		return item.id === objId;
	})
}

// carregamento de cardápio de exemplo
let cardapio = [new produto(1, "Capuccino", "Bebidas Quentes", "https://rafaelescalfoni.github.io/desenv_web/img/capuccino.png",7)
			, new produto(2, "Espresso", "Bebidas Quentes", "https://rafaelescalfoni.github.io/desenv_web/img/espresso.png",4)
			, new produto(3, "Frapuccino", "Bebidas Quentes", "https://rafaelescalfoni.github.io/desenv_web/img/frapuccino.png",8)
			, new produto(4, "Chococcino", "Bebidas Quentes", "https://rafaelescalfoni.github.io/desenv_web/img/chococcino.png",7)
			, new produto(5, "Chocolate Quente", "Bebidas Quentes", "https://rafaelescalfoni.github.io/desenv_web/img/chocolate_quente.png",10)
			, new produto(6, "Frapê", "Bebidas Frias", "https://rafaelescalfoni.github.io/desenv_web/img/frape.png",12)
			, new produto(7, "Suco de Laranja", "Bebidas Frias", "https://rafaelescalfoni.github.io/desenv_web/img/suco_laranja.png",10)
            , new produto(8, "Açaí", "Doces", "https://rafaelescalfoni.github.io/desenv_web/img/acai.png",12)
            , new produto(9, "Bolo de Laranja", "Doces", "https://rafaelescalfoni.github.io/desenv_web/img/bolo_laranja.png",8)];
		
$(function(){		
	let produtosEscolhidosArray = [];

	$.each(cardapio, function(ind, item){
        let itemLista = $("<li>");
        // setando o item, id e conteúdo
        itemLista.attr("id", item.id);
        itemLista.text(item.nome);
        // adicionando na lista de cardápio
		$("#cardapio").append(itemLista);
	});

	$("#cardapio").on("click", "li",function(){
		let itemEscolhido = pesquisaPorId(cardapio, parseInt($(this).attr("id")));
	    produtosEscolhidosArray.push(itemEscolhido);
        let itemLista = $("<li>");
        // setando o item, id e conteúdo
        itemLista.attr("id", itemEscolhido.id);
        itemLista.text(itemEscolhido.nome);
        // adicionando na lista de cardápio
		$("#pedidos").append(itemLista);
        console.log($("#valorTotal"))
        $("#valorTotal").text('Total - ' + produtosEscolhidosArray.length)
	});
});