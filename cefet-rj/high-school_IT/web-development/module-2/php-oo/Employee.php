<?php
    require_once "Person.php";
    class Funcionario extends Pessoa{
        private float $salario = 0;

        public function __construct(string $nome,Cpf $cpf,Endereco $endereco,float $salario){
            parent::__construct($nome,$cpf,$endereco);
            //salário
            $this->setSalario($salario);
        }

        public function getSalario():float{
            return $this->salario;
        }

        public function setSalario(float $salario){
            $this->salario = $salario;
        }

        public function mostraDados():void{
            echo "Nome: {$this->getNome()}<br/>";
            echo "Cpf: {$this->getCpf()->getNumero()}<br/>";
            echo "Salário: {$this->salario}<br/>";
        }
    }
?>