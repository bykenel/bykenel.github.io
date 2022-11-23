<?php
    require_once('Conta.php');
    $conta1 = new Conta(new Cliente("Nome_1", new Cpf("123.456.789-10"), "conta1@cefet.com")); //#1
    $conta1 -> depositar(100);
    $conta1 -> mostrarDados();

    $conta2 = new Conta(new Cliente("Nome_2",  new Cpf("123.456.789-11"), "conta2@cefet.com")); //#2
    $conta2 -> depositar(10000);
    $conta2 -> mostrarDados();

    $conta3 = new Conta(new Cliente("Nome_3",  new Cpf("123.456.789-12"), "conta3@cefet.com")); //#3
    // $conta3 = $conta2;
    $conta3 -> depositar(1);
    $conta3 -> mostrarDados();

    echo "Excluindo conta {$conta1 -> recuperarTitular() -> recuperarNome()}..."; unset($conta1);
    echo "<hr>";

    echo "Número de contas cadastradas: "; echo Conta::obterNumDeContas();
    echo "<hr>";

    echo "Conta: {$conta2 -> recuperarTitular() -> recuperarNome()} <br>
          CPF: {$conta2 -> recuperarTitular() -> recuperarCpf() -> recuperarNumero()} <br>
          Email: {$conta2 -> recuperarTitular() -> recuperarEmail()} <br>
          Saldo: R\${$conta2 -> recuperarSaldo()}
          <hr>";
?>