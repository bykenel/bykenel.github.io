<?php
    require_once('../model/conexao.php');
    $filmePost = file_get_contents('php://input');
    $filmeMatriz = json_decode($filmePost, true);

    $titulo = (isset($filmeMatriz["titulo"]) && $filmeMatriz["titulo"] != null) ? strtoupper($filmeMatriz["titulo"]) : "";
    $avaliacao = (isset($filmeMatriz["avaliacao"]) && $filmeMatriz["avaliacao"] != null) ? $filmeMatriz["avaliacao"] : "";

    $resposta["erro"] = false;
    $resposta["msgErro"] = "";
    $resposta["msgSucesso"] = "";
    $resposta["dados"] = null;

    if ($titulo != "" && $avaliacao != "") {
        try {
            $sql = "INSERT INTO filmes_assistidos(titulo, avaliacao) VALUES(?, ?)";
            $stmt = $conexao -> prepare($sql);
            $stmt -> bindParam (1, $titulo);
            $stmt -> bindParam (2, $avaliacao);
            $stmt -> execute();
            $resposta["msgSucesso"] = "{$stmt -> rowCount()} filme inserido com sucesso! O id inserido foi {$conexao -> lastInsert}";
        } catch(PDOException $e) {
            $resposta ["erro"] = true;
            $resposta ["msgErro"] = "Erro ao efetuar a inserção no BD ".$e -> getMessage(); 
        } finally {
            echo json_encode($resposta);
            exit();
        }
    }
?>