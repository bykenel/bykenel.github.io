-- [PACOTE 2]

-- 1) Listar o nome e o valor total das vendas apenas para clientes que tiverem vendas acima da média em 2006.
SELECT cl.nome AS cliente, v.valor_total AS 'valor-total'
FROM cliente cl
    JOIN venda v ON (pv.venda_id = v.id)
WHERE
    v.valor_total > (
        SELECT AVG(valor_total)
        FROM venda
    )
    AND SUSBTRING (v.datavenda, 1, 4) IN (2006);

-- 2) Listar a quantidade de clientes por fornecedor.
SELECT f.nome AS fornecedor, COUNT(*) AS quantidade
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
GROUP BY
    f.id;

-- 3) Listar os 10 princípios ativos mais vendidos em quantidade.
SELECT p.principio AS 'principio-ativo', SUM(pv.quantidade) AS quantidade
FROM produto_vendido pv
    JOIN produto p ON (pv.produto_id = p.id)
GROUP BY
    p.principio
ORDER BY quantidade DESC
LIMIT 0, 10;

-- 4) Listar a quantidade de vendas por bairro-cidade de produtos cujo princípio ativo seja composto e não tenham mais do que um espaço.
SELECT pv.quantidade AS quantidade, CONCAT(b.nome, '-', c.nome) AS 'bairro-cidade'
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    p.principio LIKE '% %'
    AND p.principio NOT LIKE '% % %'
GROUP BY
    c.id,
    b.id;

-- 5) Listar os 3 vendedores que mais lucraram em vendas para os clientes de MG, RJ, SP e ES em 2006. Proibido utilizar a cláusula IN.
SELECT ve.nome AS vendedor
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE (
        uf.sigla = 'MG'
        OR uf.sigla = 'RJ'
        OR uf.sigla = 'SP'
        OR uf.sigla = 'ES'
    )
    AND v.datavenda LIKE '2006%'
ORDER BY SUM(
        (
            v.valor_total * ve.comissao_percentual
        ) / 100
    ) DESC
LIMIT 0, 3;

-- 6) Listar o valor total de vendas por mês no ano de 2006.
SELECT v.valor_total AS 'valor-total', SUSBTRING (v.datavenda, 6, 2) AS 'mês'
FROM venda v
WHERE
    SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    'mês'
ORDER BY 'mês';

-- 7) Listar os 5 clientes que mais compraram produtos com preço de custo acima da média em quantidade no ano de 2006. Não me interessam clientes que compraram quantidade inferior a 50.
SELECT cl.nome AS cliente
FROM
    produto_vendido pv
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
WHERE
    p.pcusto > (
        SELECT AVG(pcusto)
        FROM produto
    )
    AND SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    cl.id
HAVING
    SUM(pv.quantidade) >= 50
ORDER BY SUM(pv.quantidade)
LIMIT 0, 5;

-- 8) Listar as 3 cidades para onde mais se vendeu em valores totais. Não se esqueça que pode haver 2 cidades com nome igual. Exemplo: Existe a cidade de Vitória no Espírito Santo e na Bahia.
SELECT c.nome AS cidade, uf.sigla AS uf, SUM(v.valor_total) AS 'valor total'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
GROUP BY
    c.id
ORDER BY 'valor-total' DESC
LIMIT 0, 3;

-- 9) Listar apenas o mês em que se teve mais vendas em quantidade no ano de 2006.
SELECT SUSBTRING (v.datavenda, 6, 2) AS 'mês'
FROM venda v
WHERE
    SUSBTRING (v.datavenda, 1, 4) IN (2006)
GROUP BY
    'mês'
ORDER BY COUNT(*) DESC
LIMIT 0, 1;

-- 10) Listar apenas o nome do fornecedor que teve mais vendas em valor total no ano de 2006.
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