<?php
    require_once ('connection.php');

    if (!empty ($_POST['nome']) && !empty ($_POST['autor']) && !empty ($_POST['album'])){
        $sqlCommand = "INSERT INTO musica (Nome, Autor, Album) VALUES (:NOME, :AUTOR, :ALBUM)";
        $stmt = $connection -> prepare ($sqlCommand);
        $stmt -> bindParam (':NOME', $_POST['nome']);
        $stmt -> bindParam (':AUTOR', $_POST['autor']);
        $stmt -> bindParam (':ALBUM', $_POST['album']);
        
        try {
            $stmt -> execute();
            echo "<h2>Cadastro inserido em DB-MUSICA</h2>";
            echo "<a href='consultOption.php'> Consultar </a><br>";
            echo "<a href='index.html'> Início </a>";
            echo "<br><br><hr><br>";
            $sqlCommand = "SELECT * FROM musica WHERE Nome = '$_POST[nome]' AND Autor = '$_POST[autor]' AND Album = '$_POST[album]'";
            $stmt = $connection -> query ($sqlCommand);
            $content = $stmt -> fetch (PDO::FETCH_OBJ);
                echo "<pre>";
                print_r($content);
                echo "</pre>";

        } catch (PDOException $e) {
            echo "ERROR: {$e -> getCode()} <br>
                  MESSAGE: {$e -> getMessage()}";
            echo "<hr><pre>";
            print_r ($e);
            echo "</pre>";
            exit();
        }
        
    } else {
        echo "As informações não chegaram ao servidor";
        exit();
    }
?>