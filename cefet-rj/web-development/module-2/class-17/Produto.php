<?php
    require_once('Fornecedor.php');
    class Produto{
        private string $descricao = "";
        private float $precoDeCusto;
        private int $estoque;
        private Fornecedor $fornecedor;
        private static int $contador = 0;

        public function __construct(string $descricao, float $precoDeCusto, int $estoque = 0, Fornecedor $fornecedor){
            $this->setDescricao($descricao);
            $this->setPrecoDeCusto($precoDeCusto);
            $this->setEstoque($estoque);
            $this-> fornecedor = $fornecedor;
            Produto::$contador++;
        }

        public function __destruct() {
            self::$contador--;
        }

        public static function getContador():int{
            return self::$contador;
        }

        public function getPrecoDeVenda(float $margemDeLucro):float{
            if($this->verificarMargem($margemDeLucro)===true)
                return $this->precoDeCusto + (($this->precoDeCusto * $margemDeLucro)/100);
        }

        private function verificarMargem(float $margem):bool{
            if($margem<10 || $margem>50){
                echo "Margem de lucro precisa estar entre 10 e 50 <br>";
                exit();
            }
            return true;
        }

        public function setDescricao(string $descricao):void{
            $this->descricao = $descricao;
        }

        public function getDescricao():string{
            return $this->descricao;
        }

        public function setPrecoDeCusto(float $precoDeCusto):void{
            $this->precoDeCusto = $precoDeCusto;
        }

        public function getPrecoDeCusto():float{
            return $this->precoDeCusto;
        }

        public function setEstoque(int $estoque):void{
            $this->estoque = $estoque;
        }

        public function getEstoque():int{
            return $this->estoque;
        }

        public function getFornecedor():Fornecedor{
            return $this->fornecedor;
        }
        
        public function exibeDados():void{
            echo "Nome: {$this -> getDescricao()} <br>
                  Preço de Custo: {$this -> getPrecoDeCusto()} <br>
                  Estoque: {$this -> getEstoque()} <br>
                  Fornecedor: {$this -> getFornecedor() -> getNome()}
                  <hr>";
        }
    }
?>