<?php  
    class Cpf {
        //Atributos
            private string $numero = "";

        //Método construtor
            public function __construct(string $numero) {
                if ($this -> validaNumero($numero) == true) {
                    //$this -  indica o endereço de memória passado
                    $this -> numero = $numero;
                }
            }

        //Métodos acessores 
            public function recuperarNumero():string {
                //$this -  indica o endereço de memória passado
                return $this -> numero;
            }

        //Funções de validação/úteis
            private function validaNumero(string $cpf):bool {
                if (!(strlen($cpf) == 14 && strpos($cpf, '.') == 3 && strpos($cpf, '.', 4) == 7 && strpos($cpf, '-') == 11)) {
                    echo "Valor inválido";
                    exit();
                }
                return true;
            }
    }
?>