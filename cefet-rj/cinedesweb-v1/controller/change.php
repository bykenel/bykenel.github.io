<?php
    require_once('../model/connection.php');
    $filmPost = file_get_contents('php://input');
    $filmContent = json_decode($filmPost, true);

    $id = (isset($filmContent["id"]) && $filmContent["id"] > 0) ? $filmContent["id"] : "";
    $title = (isset($filmContent["title"]) && $filmContent["title"] != null) ? strtoupper($filmContent["title"]) : "";
    $rating = (isset($filmContent["rating"]) && $filmContent["rating"] != null) ? $filmContent["rating"] : "";
    $genre = (isset($filmContent["genre"]) && $filmContent["genre"] > 0) ? $filmContent["genre"] : "";

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";

    if ($title != "" && $rating != "") {
        try {
            $sql = "UPDATE filmes_assistidos SET titulo=?, avaliacao=?, genero_id=? WHERE id=?";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $title);
            $stmt -> bindParam (2, $rating);
            $stmt -> bindParam (3, $genre);
            $stmt -> bindParam (4, $id);
            $stmt -> execute();
            $response["successMsg"] = "{$stmt -> rowCount()} filme alterado com sucesso! O id alterado foi {$id}";
        } catch(PDOException $e) {
            $response ["error"] = true;
            $response ["errorMsg"] = "Erro ao alterar filme: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>