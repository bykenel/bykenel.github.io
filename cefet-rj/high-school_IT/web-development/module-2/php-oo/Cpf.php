<?php
    class Cpf{
        private string $numero="";

        public function __construct(string $numero){
            if($this->validaNumeroCpf($numero)===true)
                $this->numero = $numero;
        }

        public function getNumero():string{
            return $this->numero;
        }

        //método encapsulado (privado)
        private function validaNumeroCpf(string $numero):bool{
            if(! (strlen($numero)==14 && strpos($numero,'.')==3 && strpos($numero,'.',4)==7 && strpos($numero,'-')==11) ){
                echo "Número de cpf inválido. A aplicação será encerrada.<br>";
                exit();
            }
            return true;
        }
    }
?>