<?php
    require_once('../model/connection.php');
    $filmPost = file_get_contents('php://input');
    $filmContent = json_decode($filmPost, true);

    $title = (isset($filmContent["title"]) && $filmContent["title"] != null) ? strtoupper($filmContent["title"]) : "";
    $rating = (isset($filmContent["rating"]) && $filmContent["rating"] != null) ? $filmContent["rating"] : "";
    $genre = (isset($filmContent["genre"]) && $filmContent["genre"] > 0) ? $filmContent["genre"] : "";

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";

    if ($title != "" && $rating != "") {
        try {
            $sql = "INSERT INTO filmes_assistidos(titulo, avaliacao, genero_id) VALUES(?, ?, ?)";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $title);
            $stmt -> bindParam (2, $rating);
            $stmt -> bindParam (3, $genre);
            $stmt -> execute();
            $response["successMsg"] = "{$stmt -> rowCount()} filme inserido com sucesso! O id inserido foi {$connection -> lastInsertId()}";
        } catch(PDOException $e) {
            $response ["error"] = true;
            $response ["errorMsg"] = "Erro ao inserir filme: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>