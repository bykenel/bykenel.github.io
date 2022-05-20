<?php
	$dsn = "mysql:host=localhost; dbname=cinedesweb";
	$user = "root";
	$pass = "";
	try {
		$conexao = new PDO($dsn, $user, $pass);
		$conexao -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch(PDOException $e) {
		$resposta["erro"] = true;
		$resposta["msgErro"] = "Erro ao conectar com o BD. " .$e -> getMessage();
		echo json_encode($resposta);
		exit();
	}
?>