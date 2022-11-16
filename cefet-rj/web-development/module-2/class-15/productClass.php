<?php
    class Produto {
        //Atributos
            private int $codigo = 0;
            private string $descricao = "";
            private float $precoDeCusto = 0;
            private int $estoque = 0;
            private string $fornecedor = "";
            private static int $numDeProdutos = 0;
        
        //Método construtor
            public function __construct(int $codigo, string $descricao, float $precoDeCusto, string $fornecedor, int $estoque = 0) {
                $this -> atribuirCodigo($codigo);
                $this -> atribuirDescricao($descricao);
                $this -> atribuirPrecoDeCusto($precoDeCusto);
                $this -> atribuirEstoque($estoque);
                $this -> atribuirFornecedor($fornecedor);
                Produto::$numDeProdutos++;
            }
        
        //Método destrutor
            public function __destruct() {
                Produto::$numDeProdutos--;
            }
            
        //Métodos acessores 
            //codigo
            public function recuperarCodigo():int {
                return $this -> codigo;
            }

            public function atribuirCodigo(int $codigo) {
                if (strlen($codigo < 4)) {
                    echo "Valor inválido: é necessário ao menos 4 caracteres.";
                    return;
                }
                $this -> codigo = $codigo;
            }

            //descricao
            public function recuperarDescricao():string {
                return $this -> descricao;
            }

            public function atribuirDescricao(string $descricao) {
                if (strlen($descricao < 6)) {
                    echo "Valor inválido: é necessário ao menos 6 caracteres.";
                    return;
                }
                $this -> descricao = $descricao;
            }

            //precoDeCusto
            public function recuperarPrecoDeCusto():float {
                return $this -> precoDeCusto;
            }

            public function atribuirPrecoDeCusto(float $precoDeCusto) {
                if (!($precoDeCusto > 0)) {
                    echo "Valor inválido: é necessário que seja maior do que 0.";
                    return;
                }
                $this -> precoDeCusto = $precoDeCusto;
            }

            //estoque
            public function recuperarEstoque():int {
                return $this -> estoque;
            }

            public function atribuirEstoque(int $estoque) {
                if (!($estoque >= 0)) {
                    echo "Valor inválido: é necessário que seja positivo.";
                    return;
                }
                $this -> estoque = $estoque;
            }

            //fornecedor
            public function recuperarFornecedor():string {
                return $this -> fornecedor;
            }

            public function atribuirFornecedor(string $fornecedor) {
                if (strlen($fornecedor < 6)) {
                    echo "Valor inválido: é necessário ao menos 6 caracteres.";
                    return;
                }
                $this -> fornecedor = $fornecedor;
            }
        
        //Funções de validação/úteis
            public static function obterNumDeProdutos():int {
                return Produto::$numDeProdutos;
            }
            
            public function obterPrecoDeVenda(float $margemDeLucro):float {
                if ($this -> validaMargemDeLucro($margemDeLucro) == true) {
                    $precoDeVenda = $this -> precoDeCusto + ($this -> precoDeCusto * $margemDeLucro);
                    return $precoDeVenda;
                }
            }

            private function validaMargemDeLucro(float $taxa):bool {
                if (!($taxa >= 0.1 && $taxa <= 0.5)) {
                    echo "A margem de lucro precisa estar entre 10% e 50%";
                    exit();
                }
                return true;
            }
        
        //Funções de visualização
            function mostrarDados():void {
                echo "Produto: {$this -> recuperarDescricao()} <br>
                      Código: {$this -> recuperarCodigo()} <br> 
                      Preço de custo: R\${$this -> recuperarPrecoDeCusto()} <br>
                      Estoque: {$this -> recuperarEstoque()} <br>
                      Fornecedor: {$this -> recuperarFornecedor()} <br>
                      <hr>";
            }
    }
?>