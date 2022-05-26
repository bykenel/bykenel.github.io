<?php
    require_once('../model/connection.php');
    
    $resposta["erro"] = false;
    $resposta["dados"] = null;
    $resposta["msgErro"] = "";
    $resposta["msgSucesso"] = "";
    
    try {
        $sql = "SELECT * FROM filmes_assistidos ORDER BY id";
        $stmt = $conexao -> prepare($sql);
        $stmt -> execute();
        $resposta["dados"] = $stmt -> fetchAll(PDO::FETCH_ASSOC);
        $resposta["msgSucesso"] = "Filmes listados com sucesso!";
    } catch(PDOException $e) {
        $resposta ["erro"] = true;
        $resposta ["msgErro"] = "Erro ao listar filmes: ".$e -> getMessage();
    } finally {
        echo json_encode($resposta);
        exit();
    }
?>