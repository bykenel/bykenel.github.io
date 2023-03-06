<?php
    require_once('../../model/connection.php');
    $generoPut = file_get_contents('php://input');
    $genreContent = json_decode($generoPut, true);

    $id = (isset($genreContent["id"]) && $genreContent["id"] >0) ? strtoupper($genreContent["id"]) : ""; 
    $description = (isset($genreContent["description"]) && $genreContent["description"] != null) ? strtoupper($genreContent["description"]) : "";

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";

    if($description != "") {
        try {
            $sql = "UPDATE generos SET descricao=? WHERE id=?";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $description);
            $stmt -> bindParam (2, $id);
            $stmt -> execute();
            $response["successMsg"] = "{$stmt -> rowCount()} Gênero alterado com sucesso! O id do gênero alterado foi {$id}"; 
        } catch(PDOException $e) {
            $response ["error"] = true;
            $response ["errorMsg"] = "Erro ao alterar gênero: ".$e -> getMessage(); 
        } finally {
            echo json_encode($response);
            exit();
        }
    }
?>