<?php
	$dsn = "mysql:host=localhost; dbname=cinedesweb";
	$user = "root";
	$pass = "";
	
	try {
		$connection = new PDO($dsn, $user, $pass);
		$connection -> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch(PDOException $e) {
		$response["error"] = true;
		$response["errorMsg"] = "Erro ao conectar com o BD: " .$e -> getMessage();
		echo json_encode($response);
		exit();
	}
?>