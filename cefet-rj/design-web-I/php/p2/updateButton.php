<?php
    require_once ('connection.php');

    $id = $_GET['id'];
    echo "<p>Utilize os campos para alterar o cadastro $id:</p>
    <form action='updateButton.php?id=$id' method='post'>
        <input type='text' name='nome' id='nome' placeholder='Título'>
        <input type='text' name='autor' id='autor' placeholder='Autor'>
        <input type='text' name='album' id='album' placeholder='Álbum'> <br><br>
        <input type='submit' value='Atualizar'>
        <input type='reset' value='Limpar'>
    </form>";

    $sqlCommand = "UPDATE musica SET Nome = :NOME, Autor = :AUTOR, Album = :ALBUM WHERE idmus = $id";
    $stmt = $connection -> prepare ($sqlCommand);
    $stmt -> bindParam (':NOME', $_POST['nome']);
    $stmt -> bindParam (':AUTOR', $_POST['autor']);
    $stmt -> bindParam (':ALBUM', $_POST['album']);
        
    try {
        $stmt -> execute();
        if (!empty ($_POST['nome']) && !empty ($_POST['autor']) && !empty ($_POST['album'])) {
            echo "<hr>";
            echo "<h2>Cadastro $id alterado em DB-MUSICA</h2>";
            echo "<a href='consultOption.php'> Consultar </a><br>";
            echo "<a href='index.html'> Início </a>";
            echo "<br><br><hr><br>";
            $sqlCommand = "SELECT * FROM musica WHERE idmus = '$id'";
            $stmt = $connection -> query ($sqlCommand);
            $content = $stmt -> fetch (PDO::FETCH_ASSOC);   
                echo "<pre>";
                print_r($content);
                echo "</pre>";
        }
    } catch (PDOException $e) {
        echo "ERROR: {$e -> getCode()} <br>
              MESSAGE: {$e -> getMessage()}";
        echo "<hr><pre>";
        print_r ($e);
        echo "</pre>";
        exit();
    }
?>