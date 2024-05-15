-- [LISTA 6]
USE basevendasv2;

-- 1) Listar os 10 clientes que mais compraram em valor no ano de 2006. Exibir o nome do cliente e o valor comprado.
SELECT cl.nome AS cliente, SUM(v.valor_total) AS 'valor-comprado'
FROM venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
WHERE
    SUBSTRING(v.data_venda, 1, 4) IN (2006)
GROUP BY
    cl.id
ORDER BY 'valor-comprado' DESC
LIMIT 0, 10;

-- 2) Listar os 5 produtos mais vendidos em quantidade no ano de 2006. Só interessam os produtos que venderam acima de 10 unidades. Exibir o nome dos produtos e a quantidade vendida.
SELECT p.descricao AS produto, SUM(pv.quantidade) AS 'quantidade-vendida'
FROM
    produto_vendido pv
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN venda v ON (pv.venda_id = v.id)
WHERE
    SUBSTRING(v.data_venda, 1, 4) IN (2006)
GROUP BY
    p.id
HAVING
    SUM(pv.quantidade) > 10
ORDER BY 'quantidade-vendida' DESC
LIMIT 0, 5;

-- 3) Listar os 10 fornecedores da UF ‘SP’ com mais produtos cadastrados. Só me interessam os forneedores que possuem mais de 5 produtos cadastrados. Exibir o nome dos fornecedores e a quantidade de produtos p/ cada fornecedor
SELECT f.nome AS fornecedor, COUNT(p.id) AS 'quantidade-produto'
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN cidade c ON (f.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    uf.sigla IN ('SP')
GROUP BY
    f.id
HAVING
    COUNT(p.id) > 5
ORDER BY 'quantidade-produto' DESC
LIMIT 0, 10;

-- 4) Listar apenas o nome dos vendedores que acumularam comissão acima de 200,00 em todas as vendas.
SELECT ve.nome AS vendedor
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
GROUP BY
    ve.id
HAVING
    SUM(
        (
            v.valor_total * ve.comissao_percentual
        ) / 100
    ) > 200;

-- 5) Monte uma consulta que  mostre quantos fornecedores existem por cidade e uf (que deve ser exibido no formato : cidade – uf). Ordenando do maior para o menor. Obs: Só quero as combinações com mais de um fornecedor.
SELECT CONCAT(c.nome, '-', uf.sigla), COUNT(f.id) AS 'quantidade-fornecedor'
FROM fornecedor f
    JOIN cidade c ON (f.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
GROUP BY
    f.id
HAVING
    COUNT(f.id) > 1
ORDER BY 'quantidade-fornecedor' DESC;