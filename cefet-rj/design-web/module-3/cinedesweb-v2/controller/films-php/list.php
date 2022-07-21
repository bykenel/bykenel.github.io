<?php
    require_once('../../model/connection.php');
    
    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";
    
    try {
        $sql = "SELECT f.*, g.descricao as genero_descricao FROM filmes_assistidos f 
                JOIN generos g ON(f.genero_id=g.id) ORDER BY id";
        $stmt = $connection -> prepare($sql);
        $stmt -> execute();
        $response["data"] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $response["successMsg"] = "Filmes listados com sucesso!";
    } catch(PDOException $e) {
        $response ["error"] = true;
        $response ["errorMsg"] = "Erro ao listar filmes: ".$e -> getMessage();
    } finally {
        echo json_encode($response);
        exit();
    }
?>