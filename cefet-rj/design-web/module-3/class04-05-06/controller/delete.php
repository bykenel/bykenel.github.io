<?php
    require_once('../model/connection.php');
    $filmPost = file_get_contents('php://input');
    $filmContent = json_decode($filmPost, true);

    $id = (isset($filmContent["id"]) && $filmContent["id"] != null) ? $filmContent["id"] : "";

    $response["erro"] = false;
    $response["dados"] = null;
    $response["msgErro"] = "";
    $response["msgSucesso"] = "";
    
    if ($id != null) {
        try {
            $sql = "DELETE FROM filmes_assistidos WHERE id = ?";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $id);
            $stmt -> execute();
            $response["msgSucesso"] = "Filmes de id $id excluído com sucesso!";
        } catch(PDOException $e) {
            $response ["erro"] = true;
            $response ["msgErro"] = "Erro ao excluir filme: ".$e -> getMessage();
        } finally {
            echo json_encode($response);
            exit();
        }
    }    
?>