<?php
    require_once('../model/connection.php');
    
    $response["erro"] = false;
    $response["dados"] = null;
    $response["msgErro"] = "";
    $response["msgSucesso"] = "";
    
    try {
        $sql = "SELECT * FROM filmes_assistidos ORDER BY id";
        $stmt = $connection -> prepare($sql);
        $stmt -> execute();
        $response["dados"] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $response["msgSucesso"] = "Filmes listados com sucesso!";
    } catch(PDOException $e) {
        $response ["erro"] = true;
        $response ["msgErro"] = "Erro ao listar filmes: ".$e -> getMessage();
    } finally {
        echo json_encode($response);
        exit();
    }
?>