<html>
    <head>
    </head>
    <body>
            <?php
                function obtemMedia(...$numeros) {
                    $result = 0;
                    $cont = 0;
                    foreach ($numeros as $n) {
                        $result += $n;
                        $cont++;
                    }
                    return $result / $cont;
                }       

                function transformaEmMaisculaEOrdena(&$boletim) {
                    for ($i = 0; $i < count($boletim); $i++) {
                        $boletim[$i][0] = strtoupper($boletim[$i][0]); 
                    }
                    sort($boletim);
                }

                function obtemConceito ($conceito) {
                    if (9 < $conceito and $conceito < 10) {
                        return "A";
                    }  else {
                        if (7 < $conceito) {
                            return "B";
                        } else {
                            if (5 < $conceito) {
                                return "C";
                            } else {
                                if (3 < $conceito) {
                                    return "D";
                                } else {
                                    return "E";
                                }
                            }
                        }
                    }
                }
            ?>
    </body>
</html>