<?php
    require_once('../model/connection.php');
    $filmPost = file_get_contents('php://input');
    $filmContent = json_decode($filmPost, true);

    $id = (isset($filmContent["id"]) && $filmContent["id"] > 0) ? $filmContent["id"] : "";
    $title = (isset($filmContent["titulo"]) && $filmContent["titulo"] != null) ? strtoupper($filmContent["titulo"]) : "";
    $rating = (isset($filmContent["avaliacao"]) && $filmContent["avaliacao"] != null) ? $filmContent["avaliacao"] : "";

    $response["erro"] = false;
    $response["dados"] = null;
    $response["msgErro"] = "";
    $response["msgSucesso"] = "";

    if ($title != "" && $rating != "") {
        try {
            $sql = "UPDATE filmes_assistidos SET titulo=?, avaliacao=? WHERE id=?";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $title);
            $stmt -> bindParam (2, $rating);
            $stmt -> bindParam (3, $id);
            $stmt -> execute();
            $response["msgSucesso"] = "{$stmt -> rowCount()} filme alterado com sucesso! O id alterado foi {$id}";
        } catch(PDOException $e) {
            $response ["erro"] = true;
            $response ["msgErro"] = "Erro ao alterar filme: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>