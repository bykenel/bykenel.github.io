<?php
    require_once('Endereco.php');
    class Fornecedor{
        private string $nome = "";
        private string $email = "";
        private string $cnpj = "";//imutavel
        private Endereco $endereco;
        private static int $contador = 0;

        public function __construct(string $nome, string $email, string $cnpj, Endereco $endereco){
            $this->setNome($nome);
            $this->setEmail($email);
            if ($this -> validaCnpj($cnpj) == true) {
                $this->cnpj = $cnpj;
            }
            $this-> endereco = $endereco;
            Fornecedor::$contador++;
        }

        public function __destruct() {
            self::$contador--;
        }

        public static function getContador():int{
            return self::$contador;
        }

        public function setNome(string $nome):void{
            $this->nome = $nome;
        }

        public function getNome():string{
            return $this->nome;
        }

        public function setEmail(string $email):void{
            $this->email = $email;
        }

        public function getEmail():string{
            return $this->email;
        }

        public function getCnpj():string{
            return $this->cnpj;
        }

        public function getEndereco():Endereco{
            return $this->cidade;
        }

        private function validaCnpj(string $cnpj):bool{
            if (!(strlen($cnpj) == 18)) {
                echo "Valor de CNPJ inválido";
                exit();
            }
            return true;
        }
        
        public function exibeDados():void{
            echo "Nome: {$this -> getNome()} <br>
                  Email: {$this -> getEmail()} <br>
                  CNPJ: {$this -> getCnpj()} <br>
                  Endereço: {$this -> getEndereco()}
                  <hr>";
        }
    }
?>