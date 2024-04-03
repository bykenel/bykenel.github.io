-- [LISTA 1.2]
USE basevendas;

-- 1)Listar todos os campos de todos os produtos cujo custo acrescido de 30% seja maior do que 8 e menor que 10
SELECT * FROM produtos 
WHERE (pcusto*1.3) BETWEEN 8 AND 10;
 
-- 2)Listar todos os produtos ordenados pelo preço de custo (do mais caro para o mais barato)
SELECT * FROM produtos 
ORDER BY pcusto DESC;
 
-- 3)Listar todos os clientes com data de cadastro maior que 1° de outubro de 2002
SELECT * FROM clientes 
WHERE datacadastro > '2002-10-01';
 
-- 4)Listar todos os clientes com data de cadastro entre 1 e 16 de outubro de 2002
SELECT * FROM clientes 
WHERE datacadastro BETWEEN '2002-10-01' AND '2002-10-16';
 
-- 5)Considerando que o lucro em cada venda é de 30%, listar todas as vendas cujo lucro tenha sido superior a 100,00
SELECT * FROM vendas 
WHERE (valorTotal*0.3) > 100;
 
-- 6)Considerando que a comissão do vendedor é de 3% em cada venda , listar todas as vendas e a comissão a ser paga para cada venda.
SELECT *, (valorTotal*0.03) AS comissao FROM vendas 
WHERE valorTotal IS NOT NULL;