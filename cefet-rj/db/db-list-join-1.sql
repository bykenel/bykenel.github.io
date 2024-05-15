-- [LISTA JOIN 1]
USE basevendasv2;

-- 1) Listar todos os clientes da cidade NOVA FRIBURGO cujo nome seja composto, comece com A e termine com A e que tenha no máximo 3 espaços.
SELECT cl.*
FROM cliente cl
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    c.nome IN ('NOVA FRIBURGO')
    AND cl.nome NOT LIKE '% % % % %'
    AND cl.nome LIKE 'A% %A';

-- 2) Considerando uma margem de lucro de 30%, listar, sem repetições, apenas o nome de todos os produtos com preço de venda acima de 50 e que sejam de fornecedores das ufs SP, MG e RS.
SELECT DISTINCT
    p.descricao AS produto
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN cidade c ON (f.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE (p.preco_custo * 1.3) > 50
    AND uf.sigla IN ('SP', 'MG', 'RS');

-- 3) Listar todas as vendas de 2006 e cujo nome do cliente comece com 4 caracteres e seja composto. Ordenar pelo nome, exibindo o resultado a partir do 16º registro e limitando o resultado a 5 registros.
SELECT v.*
FROM venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
WHERE
    v.data_venda LIKE '2006%'
    AND cl.nome LIKE '____ %'
ORDER BY cl.nome
LIMIT 15, 5;

-- 4) Listar nome do cliente, nome do vendedor, valor da venda para todas as vendas realizadas para clientes que NÃO sejam das ufs ‘RJ’ e ‘SP’ e cujo nome do vendedor seja composto. PROIBIDO USAR A CLÁUSULA IN.
SELECT cl.nome AS cliente, ve.nome AS vendedor, v.valor_total AS 'valor-venda'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    uf.sigla != 'RJ'
    AND uf.sigla != 'SP'
    AND ve.nome LIKE '% %';

-- 5) Listar todas as unidades federativas para onde se teve vendas no ano de 2006 de produtos com estoque acima de 20
SELECT DISTINCT
    uf.sigla
FROM
    cliente cl
    JOIN venda v ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
    JOIN produto_vendido pv ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
WHERE
    v.data_venda LIKE '2006%'
    AND p.estoque > 20;

-- 6) Listar todos os vendedores com vendas acima de 2000 para clientes cujo nome contenha a palavra HOSPITAL e que sejam das cidades de CARMO, SUMIDOURO e NOVA FRIBURGO
SELECT DISTINCT
    ve.nome as vendedor
FROM
    cliente cl
    JOIN venda v ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    v.valor_total > 20
    AND cl.nome LIKE '%SAUDE%'
    AND c.nome IN (
        'CARMO',
        'SUMIDOURO',
        'NOVA FRIBURGO'
    );