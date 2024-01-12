<?php
    class Endereco{
        private string $cidade = "";
        private string $uf = "";

        public function __construct(string $cidade, string $uf){
            $this->setCidade($cidade);
            $this->setUf($uf);
        }

        public function setCidade(string $cidade):void{
            $this->cidade = $cidade;
        }

        public function getCidade():string{
            return $this->cidade;
        }

        public function setUf(string $uf):void{
            $this->uf = $uf;
        }

        public function getUf():string{
            return $this->uf;
        }
        
        public function exibeDados():void{
            echo "Cidade: {$this -> getCidade()} <br>
                  UF: {$this -> getUf()} <br>
                  <hr>";
        }
    }
?>