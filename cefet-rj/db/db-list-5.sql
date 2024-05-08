-- [LISTA 5]
USE basevendasv2;
 
-- 1)Listar o nome do cliente e a data da venda de todas as vendas com valor acima da média
SELECT
	cl.nome AS cliente,
    CONCAT(SUBSTRING(v.data_venda, 9, 2), '/', SUBSTRING(v.data_venda, 6, 2), '/', SUBSTRING(v.data_venda, 1, 4)) AS 'data-venda'
FROM
	venda v
    JOIN cliente cl ON(v.cliente_id=cl.id)
WHERE
	v.valor_total > (
        SELECT 
            AVG(valor_total)
        FROM 
            venda);
 
-- 2) Listar o nome do(s) produto(s) mais caro(s)
SELECT
	p.descricao AS produto
FROM
	produto p
WHERE
	p.preco_custo = (
        SELECT 
        	MAX(preco_custo) 
        FROM 
        	produto);
 
-- 3) Listar o nome dos fornecedores ( apenas 1 de cada ) que tiverem produtos com estoque acima da média vendidos no ano de 2006
SELECT DISTINCT
	f.nome AS fornecedor
FROM
	produto p
    JOIN produto_vendido pv ON(pv.produto_id=p.id)
    JOIN venda v ON(pv.venda_id=v.id) 
    JOIN fornecedor f ON(p.fornecedor_id=f.id)
WHERE
	SUBSTRING(v.data_venda, 1, 4) IN (2006)
    AND p.estoque > (
    	SELECT
        	AVG(estoque) 
        FROM 
        	produto);

-- 4) Construa uma consulta que retorne os anos(somente um de cada) em que houve cadastro de clientes.
SELECT DISTINCT
	SUBSTRING(cl.data_cadastro, 1, 4) AS ano
FROM
	cliente cl;
 
-- 5) Escreva os comandos para:
	-- a. Mostrar a estrutura da tabela produto:
	DESCRIBE produto;
 
	-- b. Excluir a tabela produto:
	-- DROP TABLE produto;
 
-- 6) Construa uma consulta que:
	-- a. Retorne todos os clientes cujo nome termine com 'SILVA':
	SELECT
		cl.nome AS cliente
	FROM
		cliente cl
	WHERE
		cl.nome LIKE '%SILVA';
 
	-- b. Todos os clientes cujo nome começa com 'MARIA'
	SELECT
		cl.nome AS cliente
	FROM
		cliente cl
	WHERE
		cl.nome LIKE 'MARIA%';