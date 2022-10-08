<?php
    require_once ('connection.php');
    
    $sqlCommand = "SELECT * FROM musica ORDER BY idmus";
    $stmt = $connection -> query ($sqlCommand);
    $content = $stmt -> fetchAll (PDO::FETCH_ASSOC);
    echo "<h2>Exibindo DB-MUSICA</h2>";
    echo "<a href='index.html'> Início </a>";
    echo "<br><br><hr>";
   
    foreach ($content as $music) {
        $id = $music['idmus'];
        echo "<tr>
            <td><h5> Id: {$music['idmus']} </h5></td> 
            <td><h5> Título: {$music['Nome']} </h5></td> 
            <td><h5> Autor: {$music['Autor']} </h5></td> 
            <td><h5> Álbum: {$music['Album']} </h5></td> 
            <td><a href=updateButton.php?id=$id> Alterar </a></td>
            <td><a href=deleteButton.php?id=$id> Deletar </a></td>
            </tr>";
        echo "<hr>";
    }
?>