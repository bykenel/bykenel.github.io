<?php
    class Endereco{
        private string $logradouro="";
        private string $numero="";
        private string $bairro="";
        private string $cidade="";

        public function __construct(string $logradouro, string $numero,string $bairro,string $cidade){
            if( empty($logradouro) || empty($numero) || empty($bairro) || empty($cidade)){
                echo "Forneça todas as informações. A aplicação será encerrada.";
                exit();
            }else{
                $this->setLogradouro($logradouro);
                $this->setNumero($numero);
                $this->setBairro($bairro);
                $this->setCidade($cidade);
            }
        }

        //Métodos acessores
        public function setLogradouro(string $logradouro){
            $this->logradouro = $logradouro;
        }
        public function setNumero(string $numero):void{
            $this->numero = $numero;
        }
        public function setBairro(string $bairro){
            $this->bairro = $bairro;
        }
        public function setCidade(string $cidade):void{
            if(! strlen($cidade)>=4){
                echo "cidade precisa ter ao menos 4 caracteres.<br>";
                exit();
            }else
                $this->cidade = $cidade;
        }

        public function getLogradouro():string{
            return $this->logradouro;
        }
        public function getNumero():string{
            return $this->numero;
        }
        public function getBairro():string{
            return $this->bairro;
        }
        public function getCidade():string{
            return $this->cidade;
        }

        public function exibirEnderecoCompleto():void{
            echo "{$this->logradouro}, {$this->getNumero()}, {$this->bairro} - {$this->cidade}<br>";
        }

    }
?>