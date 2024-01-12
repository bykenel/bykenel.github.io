<?php
    require_once "Cpf.php";
    require_once "Address.php";
    class Pessoa{
        protected string $nome="";
        protected Cpf $cpf;
        protected Endereco $endereco;

        public function __construct(string $nome, Cpf $cpf, Endereco $endereco){
            $this->setNome($nome);
            $this->cpf = $cpf;// pode dar merda (mudar o modificador para protected)
            $this->endereco = $endereco;
        }
        //Métodos acessores
        public function getEndereco():Endereco{
            return $this->endereco;
        }

        public function getNome():string{
            return $this->nome;
        }

        public function setNome(string $nome){
            if(strlen($nome<6)){
                echo "Nome do titular precisa ter ao menos 6 caracteres. <br/>";
                return; //Early return
            }
            //atributo nomeDoTitular = argumento $nomeDoTitular
            $this->nome = $nome;
        }

        public function getCpf():Cpf{
            return $this->cpf;
        }
    }

    
?>