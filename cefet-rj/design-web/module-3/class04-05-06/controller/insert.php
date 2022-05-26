<?php
    require_once('../model/connection.php');
    $filmPost = file_get_contents('php://input');
    $filmContent = json_decode($filmPost, true);

    $title = (isset($filmContent["titulo"]) && $filmContent["titulo"] != null) ? strtoupper($filmContent["titulo"]) : "";
    $rating = (isset($filmContent["avaliacao"]) && $filmContent["avaliacao"] != null) ? $filmContent["avaliacao"] : "";

    $response["erro"] = false;
    $response["dados"] = null;
    $response["msgErro"] = "";
    $response["msgSucesso"] = "";

    if ($title != "" && $rating != "") {
        try {
            $sql = "INSERT INTO filmes_assistidos(titulo, avaliacao) VALUES(?, ?)";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $title);
            $stmt -> bindParam (2, $rating);
            $stmt -> execute();
            $response["msgSucesso"] = "{$stmt -> rowCount()} filme inserido com sucesso! O id inserido foi {$connection -> lastInsertId()}";
        } catch(PDOException $e) {
            $response ["erro"] = true;
            $response ["msgErro"] = "Erro ao inserir filme: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>