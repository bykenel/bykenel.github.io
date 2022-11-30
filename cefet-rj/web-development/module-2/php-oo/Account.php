<?php
    require_once('Client.php');
    class Conta {
        //Atributos
            private Cliente $titular;
            private float $saldo = 0;
            private static int $numDeContas = 0;
        
        //Método construtor
            public function __construct(Cliente $titular) {
                //$this -  indica o endereço de memória passado
                $this -> titular = $titular;
                Conta::$numDeContas++;
                //self::$numDeContas++;
            }

        //Método destrutor
            public function __destruct() {
                Conta::$numDeContas--;
            }
        
        //Métodos acessores 
            public function recuperarTitular():object {
                //$this -  indica o endereço de memória passado
                return $this -> titular;
            }    

            public function recuperarSaldo():float {
                //$this -  indica o endereço de memória passado
                return $this -> saldo;
            }

        //Funções de manipulação de saldo
            function sacar(float $valor):void{
                if ($valor > $this -> saldo) {
                    echo "Valor indisponível para saque";
                    return; //early return
                }
                //this -  indica o endereço de memória passado
                $this -> saldo -= $valor;
            }

            function depositar(float $valor):void{
                if (!($valor > 0)) {
                    echo "O valor de depósito precisa ser positivo";
                    return; //early return
                }
                //$this -  indica o endereço de memória passado
                $this -> saldo += $valor;
            }

            function transferir(float $valor, Conta $contaDestino):void{
                if ($valor > $this -> saldo) {
                    echo "Valor indisponível para transferência";
                    return; //early return
                }
                //$this -  indica o endereço de memória passado
                $this -> saldo -= $valor;
                $contaDestino -> saldo += $valor;
            }

        //Funções de validação/úteis
            public static function obterNumDeContas():int {
                //$this -  indica o endereço de memória passado
                return Conta::$numDeContas;
                //self::$numDeContas++;
            }

        //Funções de visualização
            function mostrarDados():void{
                //$this -  indica o endereço de memória passado
                echo "Conta: {$this -> titular -> recuperarNome()} <br>
                      CPF: {$this -> titular -> recuperarCpf() -> recuperarNumero()} <br>
                      Email: {$this -> titular -> recuperarEmail()} <br>
                      Saldo: R\${$this -> recuperarSaldo()}
                      <hr>";
            }
    }
?>