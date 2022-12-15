<?php
    require_once("Client.php");
    class Conta{
        //Atributos (características)
        private Cliente $titular;
        private float $saldo=0;
        //Atributo estático
        private static int $numDeContas=0;

        public static function getNumDeContas():int{
            return Conta::$numDeContas;
        }

        //Método construtor 
        //Uma vez criada uma conta o Cpf não pode mudar (PRINCÍPIO DA IMUTABILIDADE)
        public function __construct(Cliente $titular){
            $this->titular = $titular;
            echo "Criando uma conta....<br>";
            //Conta::$numDeContas++;
            self::$numDeContas++;
        }
        //Método destrutor
        public function __destruct(){
            self::$numDeContas--;
            echo "<br/>Destruindo uma conta....<br>";
        }

        //métodos acessores
        public function getTitular():Cliente{
            return $this->titular;
        }

        public function getSaldo():float{
            return $this->saldo;
        }

        //Comportamento (métodos)
        function saca(float $valor):void{
            if($valor>$this->saldo){
                echo "Valor R\${$valor} alto demais para saque.<br> ";
                return; //Early return
            }    
            $this->saldo -= $valor;
        }

        function deposita(float $valor){
            if(! ($valor>0) ){
                echo "Valor R\${$valor} precisa ser positivo p/ depósito.<br> ";
                return; //Early return
            }
            $this->saldo += $valor;
        }

        function transferePara(Conta $contaDestino, float $valor){
            $this->saca($valor);
            $contaDestino->deposita($valor);
        }

        function mostraDados():void{
            echo "A conta de {$this->titular->getNome()} possui o cpf 
    {$this->getTitular()->getCpf()->getNumero()} e tem o saldo de R\${$this->saldo}<br>";
        }
    }
?>