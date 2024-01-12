<?php
    require_once('../../model/connection.php');
    $generoPut = file_get_contents('php://input');
    $genreContent = json_decode($generoPut, true);

    $id = (isset($genreContent["id"]) && $genreContent["id"] >0) ? strtoupper($genreContent["id"]) : ""; 

    $response["error"] = false;
    $response["data"] = null;
    $response["errorMsg"] = "";
    $response["successMsg"] = "";
    
    if ($id != null) {
        try {
            $sql = "DELETE FROM generos WHERE id=?";
            $stmt = $connection -> prepare($sql);
            $stmt -> bindParam (1, $id);
            $stmt -> execute();
            $response["successMsg"] = "Gênero de id $id excluído com sucesso!";
        } catch(PDOException $e) {
            $response ["error"] = true;
            $response ["errorMsg"] = "Erro ao excluir gênero: ".$e -> getMessage();
        } finally {
            echo json_encode($response);
            exit();
        }
    }    
?>