<?php
    require_once ('connection.php');

    $id = $_GET['id'];
    $sqlCommand = "DELETE FROM musica WHERE idmus= $id";
    $rtrn = $connection -> exec($sqlCommand);

    if ($rtrn !== false) {
        echo "<h2>Cadastro $id deletado de DB-MUSICA</h2>";
        echo "<a href='consultOption.php'> Consultar </a><br>";
        echo "<a href='index.html'> Início </a>";
        echo "<br><br><hr><br>";

        
    } else {
        echo "<h2>Erro na execução, tente novamente</h2>";
        echo "<hr>";
        exit();
    }
?>