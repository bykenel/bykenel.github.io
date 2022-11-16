<?php
    require_once('productClass.php');
    $produto = new Produto(10001, "Nome-1", 15.5, "Nome-1 Ltda.", 3);
    /* $produto -> atribuirCodigo(10001);
       $produto -> atribuirDescricao("Nome-1");
       $produto -> atribuirPrecoDeCusto(15.5);
       $produto -> atribuirEstoque(3);
       $produto -> atribuirFornecedor("Nome-1 Ltda."); */

    $produto2 = new Produto(10000, "Nome-2", 10, "Nome-2 Ltda.", 2);
    $produto2 -> atribuirCodigo(10002);
    /* $produto2 -> atribuirDescricao("Nome-2");
       $produto2 -> atribuirPrecoDeCusto(10);
       $produto2 -> atribuirEstoque(2);
       $produto2 -> atribuirFornecedor("Nome-2 Ltda."); */

    $produto -> mostrarDados();
    $produto2 -> mostrarDados();

    $precoVenda = $produto -> obterPrecoDeVenda(0.15);;
    $precoVenda2 = $produto2 -> obterPrecoDeVenda(0.5);
    echo "Preço de venda do {$produto -> recuperarDescricao()}: {$precoVenda} <br>"; 
    echo "Preço de venda do {$produto2 -> recuperarDescricao()}: {$precoVenda2} <hr>"; 
    
    echo Produto::obterNumDeProdutos(); echo " produto(s) cadastrado(s) <br>";
    echo"Apagando produto... <br>"; unset($produto);
    echo Produto::obterNumDeProdutos(); echo " produto(s) cadastrado(s) <br>";
?>