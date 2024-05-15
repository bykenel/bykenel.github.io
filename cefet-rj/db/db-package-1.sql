-- [PACOTE 1]

-- 1. Listar a data e a quantidade de vendas das 3 datas em que se teve mais vendas de produtos iniciados com as letras A, C e D para clientes de NOVA FRIBURGO, CORDEIRO e CANTAGALO. Só me interessam as datas com mais de 5 vendas vinculadas a ela.
SELECT CONCAT(
        SUBSTRING(v.datavenda, 9, 2), '/', SUBSTRING(v.datavenda, 6, 2), '/', SUBSTRING(v.datavenda, 1, 4)
    ) AS 'data-venda', COUNT(*) AS 'quantidade-vendas'
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    SUBSTRING(p.descricao, 1, 1) IN ('A', 'C', 'D')
    AND c.nome IN (
        'NOVA FRIBURGO',
        'CORDEIRO',
        'CANTAGALO'
    )
GROUP BY
    v.datavenda
HAVING
    COUNT(*) > 5
ORDER BY 'quantidade-vendas' DESC
LIMIT 0, 3;

-- 2. Listar apenas o nome dos 3 fornecedores que tiveram mais produtos do tipo MEDICAMENTOS vendidos em quantidade no ano de 2006 para clientes com nome composto. Não interessam fornecedores com quantidades abaixo de 500. Proibido usar funções de data.
SELECT f.nome AS fornecedor
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN tipo_produto tp ON (p.tipo_produto_id = tp.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
WHERE
    tp.descricao = 'MEDICAMENTOS'
    AND SUBSTRING(v.datavenda, 1, 4) IN (2006)
    AND cl.nome LIKE '% %'
GROUP BY
    f.id
HAVING
    SUM(pv.quantidade) >= 500
ORDER BY SUM(pv.quantidade) DESC
LIMIT 0, 3;

-- 3. Listar o valor total de vendas por mês/ano em forma de ranking.
SELECT SUM(v.valor_total) AS 'valor-total', CONCAT(
        SUBSTRING(v.datavenda, 6, 2), '/', SUBSTRING(v.datavenda, 1, 4)
    ) AS 'mês/ano'
FROM venda v
GROUP BY
    'mês/ano'
ORDER BY 'valor-total' DESC;

-- 4. Listar nome do vendedor e valor acumulado da comissão recebida para todas as vendas realizadas para clientes que NÃO sejam das cidades de ‘CARMO’ e ‘CORDEIRO’. Só interessam os vendedores que tenham recebido mais de 3000 de comissão. Proibido usar a cláusula IN.
SELECT ve.nome AS vendedor, SUM(
        (
            v.valor_total * ve.comissao_percentual
        ) / 100
    ) AS 'comissão-acumulada'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    c.nome <> 'CARMO'
    AND c.nome <> 'CORDEIRO'
GROUP BY
    ve.id
HAVING
    'comissão-acumulada' > 3000
ORDER BY 'comissão-acumulada' DESC;

-- 5. Listar o nome e o somatório das vendas dos 10 produtos mais vendidos para clientes vinculados ao vendedor PAULO ROBERTO, Só interessam produtos que acumularam vendas acima de 500.
SELECT p.descricao AS produto, SUM(v.valor_total) AS 'valor-total'
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    ve.nome = 'PAULO ROBERTO'
GROUP BY
    p.id
HAVING
    'valor-total' > 500
ORDER BY 'valor-total' DESC
LIMIT 0, 10;

-- 6. Listar apenas o nome dos 5 produtos que mais apareceram em vendas para as UFs SP, MG e RJ no ano de 2006. Não interessam produtos que apareceram menos de 10 vezes.
SELECT p.descricao AS produto
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    uf.sigla IN ('SP', 'MG', 'RJ')
    AND SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    p.id
HAVING
    COUNT(*) >= 10
ORDER BY COUNT(*) DESC
LIMIT 0, 5;

-- 7. Listar o nome do cliente e o somatório do valor total das vendas dos 5 clientes que mais compraram produtos de fornecedores da UF SP. Não interessam clientes que tenham comprado um somatório inferior a 2000.
SELECT cl.nome, SUM(v.valor_total) AS 'valor-total'
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    uf.sigla = 'SP'
GROUP BY
    cl.id
HAVING
    'valor-total' >= 2000
ORDER BY 'valor-total' DESC
LIMIT 0, 5;

-- 8. Listar o valor total de vendas por uf para clientes de cidades cujo nome seja composto e termine com A ou O. Proibido usar a cláusula IN.
SELECT uf.sigla AS uf, SUM(v.valor_total) AS 'valor-total'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    c.nome LIKE '% %A'
    OR c.nome LIKE '% %O'
GROUP BY
    uf.id
ORDER BY 'valor-total' DESC;

-- 9. Listar apenas o nome do fornecedor que teve mais produtos vendidos em valor no ano de 2006.
SELECT f.nome AS fornecedor
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
WHERE
    SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    f.id
ORDER BY SUM(v.valor_total) DESC
LIMIT 0, 1;

-- 10. Listar apenas o nome do vendedor que mais vendeu produtos com estoque acima da média em 2006.
SELECT ve.nome AS vendedor
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    p.estoque > (
        SELECT AVG(estoque)
        FROM produto
    )
    AND SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    ve.id
ORDER BY SUM(pv.quantidade) DESC
LIMIT 0, 1;