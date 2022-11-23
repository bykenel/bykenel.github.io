<?php
    require_once('Funcionario.php');
    $funcionario1 = new Funcionario("Nome_1",  new Cpf("123.456.789-10")); //#1
    $funcionario1 -> atribuirSalario(10000);
    $funcionario1 -> mostrarDados();

    $funcionario2 = new Funcionario("Nome_2",  new Cpf("123.456.789-11")); //#2
    $funcionario2 -> atribuirSalario(1000);
    $funcionario2 -> mostrarDados();

    $funcionario3 = new Funcionario("Nome_3",  new Cpf("123.456.789-12")); //#3
    // $funcionario3 = $funcionario2;
    $funcionario3 -> atribuirSalario(1);
    $funcionario3 -> mostrarDados();
?>