<?php
    require_once('../model/conexao.php');
    $filmePost = file_get_contents('php://input');
    $filmeMatriz = json_decode($filmePost, true);

    $id = (isset($filmeMatriz["id"]) && $filmeMatriz["id"] > 0) ? $filmeMatriz["id"] : "";
    $titulo = (isset($filmeMatriz["titulo"]) && $filmeMatriz["titulo"] != null) ? strtoupper($filmeMatriz["titulo"]) : "";
    $avaliacao = (isset($filmeMatriz["avaliacao"]) && $filmeMatriz["avaliacao"] != null) ? $filmeMatriz["avaliacao"] : "";

    $resposta["erro"] = false;
    $resposta["dados"] = null;
    $resposta["msgErro"] = "";
    $resposta["msgSucesso"] = "";

    if ($titulo != "" && $avaliacao != "") {
        try {
            $sql = "UPDATE filmes_assistidos SET titulo=?, avaliacao=? WHERE id=?";
            $stmt = $conexao -> prepare($sql);
            $stmt -> bindParam (1, $titulo);
            $stmt -> bindParam (2, $avaliacao);
            $stmt -> bindParam (3, $id);
            $stmt -> execute();
            $resposta["msgSucesso"] = "{$stmt -> rowCount()} filme alterado com sucesso! O id alterado foi {$id}";
        } catch(PDOException $e) {
            $resposta ["erro"] = true;
            $resposta ["msgErro"] = "Erro ao alterar filme: ".$e -> getMessage(); 
        } finally {
            echo json_encode($resposta);
            exit();
        }
    }
?>