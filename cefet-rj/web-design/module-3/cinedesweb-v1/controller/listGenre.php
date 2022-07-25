<?php
    require_once('../model/connection.php');
    
    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";
    
    try {
        $sql = "SELECT * FROM generos ORDER BY descricao";
        $stmt = $connection -> prepare($sql);
        $stmt -> execute();
        $response["data"] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $response["successMsg"] = "Gêneros listados com sucesso!";
    } catch(PDOException $e) {
        $response ["error"] = true;
        $response ["errorMsg"] = "Erro ao listar gêneros: ".$e -> getMessage();
    } finally {
        echo json_encode($response);
        exit();
    }
?>