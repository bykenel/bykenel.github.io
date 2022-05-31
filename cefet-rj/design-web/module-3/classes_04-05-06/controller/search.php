<?php
    require_once('../model/connection.php');

    $id = (isset($_GET["id"]) && $_GET["id"] > 0) ? $_GET["id"] : "";

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";
    
    try {
        $sql = "SELECT * FROM filmes_assistidos WHERE id = ?";
        $stmt = $connection -> prepare($sql);
        $stmt -> bindParam (1, $id);
        $stmt -> execute();
        $result = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $response["data"] = $result[0];
        $response["successMsg"] = "Filmes de id $id retornado com sucesso!";
    } catch(PDOException $e) {
        $response ["error"] = true;
        $response ["errorMsg"] = "Erro ao retornar filme: ".$e -> getMessage();
    } finally {
        echo json_encode($response);
        exit();
    } 
?>