<?php 
    require_once "Person.php";
    class Cliente extends Pessoa{

        private string $email="";

        public function __construct(string $nome,Cpf $cpf,Endereco $endereco, string $email=""){
            parent::__construct($nome,$cpf,$endereco);
            $this->setEmail($email);
        }

        /*public function setEndereco(Endereco $endereco):void{
            $this->endereco = $endereco;
        }*/

        public function getEmail():string{
            return $this->email;
        }
    
        public function setEmail(string $email){
            //echo "A posição do @ é: ".strpos($email,'@');
            if(strpos($email,"@")<0){
                echo "E-mail precisa ter ao menos o caractere @. <br/>";
                return; //Early return
            }
            //atributo nomeDoTitular = argumento $nomeDoTitular
            $this->email = $email;
        }

        public function exibirDados():void{
            echo "Nome: {$this->getNome()}<br>";
            echo "Cpf: {$this->getCpf()->getNumero()}<br>";
            echo "Email: {$this->email}<br>";
            echo "Endereco: {$this->getEndereco()->exibirEnderecoCompleto()}<br>";
        }
    }
?>
