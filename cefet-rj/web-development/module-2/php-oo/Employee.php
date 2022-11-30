<?php
    require_once('Cpf.php');
    class Funcionario {
        //Atributos
            private string $nome = "";
            private Cpf $cpf;
            private float $salario = 0;

        //Método construtor
            public function __construct(string $nome, Cpf $cpf) {
                //$this -  indica o endereço de memória passado
                $this -> atribuirNome($nome);
                $this -> cpf = $cpf ;
            }

        //Método destrutor
            public function __destruct() {
                
            }
        
        //Métodos acessores 
            public function recuperarNome():string {
                //$this -  indica o endereço de memória passado
                return $this -> nome;
            }

            public function atribuirNome(string $nome) {
                if (strlen($nome < 6)) {
                    echo "Valor inválido: é necessário ao menos 6 caracteres.";
                    return; //early return
                }
                //$this -  indica o endereço de memória passado
                $this -> nome = $nome;
            }

            public function recuperarSalario():float {
                //$this -  indica o endereço de memória passado
                return $this -> salario;
            }

            public function atribuirSalario(float $valor):void{
                if (!($valor > 0)) {
                    echo "O valor de atribuição precisa ser positivo";
                    return; //early return
                }
                //$this -  indica o endereço de memória passado
                $this -> salario += $valor;
            }

            public function recuperarCpf():Cpf {
                //$this -  indica o endereço de memória passado
                return $this -> cpf;
            }

        //Funções de visualização
            function mostrarDados():void{
                //$this -  indica o endereço de memória passado
                echo "Funcionario: {$this -> recuperarNome()} <br>
                      CPF: {$this -> recuperarCpf() -> recuperarNumero()} <br>
                      Salario: R\${$this -> recuperarSalario()}
                      <hr>";
            }
    }
?>