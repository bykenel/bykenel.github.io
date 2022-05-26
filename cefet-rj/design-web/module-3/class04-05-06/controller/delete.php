<?php
    require_once('../model/connection.php');
    $filmePost = file_get_contents('php://input');
    $filmeMatriz = json_decode($filmePost, true);

    $id = (isset($filmeMatriz["id"]) && $filmeMatriz["id"] != null) ? $filmeMatriz["id"] : "";

    $resposta["erro"] = false;
    $resposta["dados"] = null;
    $resposta["msgErro"] = "";
    $resposta["msgSucesso"] = "";
    
    if ($id != null) {
        try {
            $sql = "DELETE FROM filmes_assistidos WHERE id = ?";
            $stmt = $conexao -> prepare($sql);
            $stmt -> bindParam (1, $id);
            $stmt -> execute();
            $resposta["msgSucesso"] = "Filmes de id $id excluído com sucesso!";
        } catch(PDOException $e) {
            $resposta ["erro"] = true;
            $resposta ["msgErro"] = "Erro ao excluir filme: ".$e -> getMessage();
        } finally {
            echo json_encode($resposta);
            exit();
        }
    }    
?>