<?php
    //declare(strict_types=1);
    require_once "Produto.php";
    
    $produto1 = new Produto("Produto-1", 0.00, 1, new Fornecedor('Nome-1', 'nome1@cefet-rj.br', 'XX.XXX.XXX/0001-XX', new Endereco('Local-1', 'XX')));

    $precoDeVenda=$produto1->getPrecoDeVenda(15);

    $produto2 = new Produto("Produto-2", 0.00, 1, new Fornecedor('Nome-2', 'nome2@cefet-rj.br', 'XX.XXX.XXX/0001-XX', new Endereco('Local-2', 'XX')));

    $produto1 -> exibeDados();
    $produto2 -> exibeDados();

    echo "Temos ".Produto::getContador()." produto(s) em memória. <br/>";
    unset($produto1);
    echo "Temos ".Produto::getContador()." produto(s) em memória. <br/>";
?>