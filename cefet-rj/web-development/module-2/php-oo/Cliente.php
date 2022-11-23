<?php
    require_once('Cpf.php');
    class Cliente {
        //Atributos
            private string $nome = "";
            private Cpf $cpf;
            private string $email = "";

        //Método construtor
            public function __construct(string $nome, Cpf $cpf, string $email) {
                //$this -  indica o endereço de memória passado
                $this -> atribuirNome($nome);
                $this -> cpf = $cpf ;
                $this -> atribuirEmail($email);
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

            public function recuperarEmail():string {
                //$this -  indica o endereço de memória passado
                return $this -> email;
            }
            
            public function atribuirEmail(string $email) {
                if (strpos($email, '@') < 0) {
                    echo "Valor inválido: é necessário ao menos o @.";
                    return; //early return
                }
                //$this -  indica o endereço de memória passado
                $this -> email = $email;
            }

            public function recuperarCpf():Cpf {
                //$this -  indica o endereço de memória passado
                return $this -> cpf;
            }
    }
?>