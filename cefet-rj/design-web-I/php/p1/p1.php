<!DOCTYPE html>
<html lang="pt-br">
    <head>
        <meta charset="utf-8"/>
        <title>Des. Web - P1</title>
    </head>
    <body>
        <h2> CEFET - Boletim de notas </h2>
        <hr/>
        <?php
            include('functions.php');
            echo "A média do aluno fictício FULANO é: ".round(obtemMedia(7.8, 6.5), 2)."<br/>";
            $boletim = array();
            array_push($boletim, array('mariA', 8.7, 7.3, 5.6));
            array_push($boletim, array('flavia', 2.5, 4.1, 6.6));
            array_push($boletim, array('Rafael', 5, 1.4, 0.9));
            $outroAluno = "Bruna#4.4#6.6#8.4";
            array_push($boletim, explode('#', $outroAluno));
            transformaEmMaisculaEOrdena($boletim);
            foreach($boletim as $valor) {
                echo "<ul>";
                echo "<li>Aluno: <strong>$valor[0]</strong></l1>";
                echo "<li>Notas: ".$valor[1].", ".$valor[2]." e ".$valor[3]."</li>";
                $media = obtemMedia($valor[1],$valor[2],$valor[3]);
                echo "<li>Média: ".round($media, 2)." </li>";
                echo "<li>Conceito: ".obtemConceito($media)." </li>";
                echo "</ul>";
            }
        ?>      
    </body>
</html>