<?php   
    $dsn = "mysql:host=localhost;dbname=dbmusica";
    $user = "root";
    $pass = "";
    
    try {
        $connection = new PDO ($dsn, $user, $pass);

    } catch (PDOException $e) {
        echo "ERROR: {$e -> getCode()} <br>
              MESSAGE: {$e -> getMessage()}";
        echo "<hr><pre>";
        print_r ($e);
        echo "</pre>";
        exit();
      }
?>