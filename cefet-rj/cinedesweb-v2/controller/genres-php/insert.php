<?php
    require_once('../../model/connection.php');
    $generoPut = file_get_contents('php://input');
    $genreContent = json_decode($generoPut, true);

    $description = (isset($genreContent["description"]) && $genreContent["description"] != null) ? strtoupper($genreContent["description"]) : "";

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";

    if($description != "") {
        try {
            $sql = "INSERT INTO generos(descricao) VALUES(?)";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $description);
            $stmt -> execute();
            $response["successMsg"] = "{$stmt -> rowCount()} Gênero inserido com sucesso! O id inserido foi {$connection -> lastInsertId()}";
        } catch(PDOException $e) {
            $response ["error"] = true;
            $response ["errorMsg"] = "Erro ao inserir gênero: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>