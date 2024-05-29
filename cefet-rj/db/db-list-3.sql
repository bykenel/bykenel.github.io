-- [LISTA 3]
USE basevendasv2;

-- 1) Usando a cláusula in( ), monte uma consulta que retorne todos os clientes cadastrados entre ‘10/01/2004’ e 20/12/2005’ que sejam do bairro “CENTRO” e das cidades de NOVA FRIBURGO, CORDEIRO, CANTAGALO e BOM JARDIM, cujo endereço esteja preenchido.
SELECT cl.*
FROM cliente cl
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    cl.data_cadastro BETWEEN '2004-01-10' AND '2005-12-20'
    AND cl.endereco NOT IN('', 'null')
    AND b.nome IN ('CENTRO')
    AND c.nome IN (
        'NOVA FRIBURGO',
        'CORDEIRO',
        'CANTAGALO',
        'BOM JARDIM'
    );

-- 2) Usando a cláusula in( ), mostre todos os clientes das cidades de CORDEIRO, ITAOCARA e CANTAGALO, cujo endereco não esteja preenchido.
SELECT cl.*
FROM cliente cl
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    cl.endereco IN ('', 'null')
    AND c.nome IN (
        'CORDEIRO',
        'ITAOCARA',
        'CANTAGALO'
    );

-- 3) Usando os JOINS, de acordo com a estrutura das tabelas FORNECEDORES e PRODUTOS, construa as seguintes consultas:
-- a. Que retorne o nome do fornecedor, a descrição e o estoque do produto:
SELECT
    f.nome AS fornecedor,
    p.descricao AS produto,
    p.estoque AS estoque
FROM produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id);

-- b. Que retorne o nome do fornecedor, a descrição e o estoque do produto, INCLUSIVE dos produtos que não têm fornecedor cadastrado:
SELECT
    f.nome AS fornecedor,
    p.descricao AS produto,
    p.estoque AS estoque
FROM produto p
    LEFT OUTER JOIN fornecedor f ON (p.fornecedor_id = f.id);

-- c. Que retorne o nome do fornecedor, a descrição e o estoque do produto, INCLUSIVE dos fornecedores que não têm produtos cadastrados:
SELECT
    f.nome AS fornecedor,
    p.descricao AS produto,
    p.estoque AS estoque
FROM produto p
    RIGHT OUTER JOIN fornecedor f ON (p.fornecedor_id = f.id);

-- 4) Levando em conta que cada cliente tem um vendedor específico, listar Data da Venda(no formato brasileiro), Nome do Cliente, Nome do Vendedor, valor da comissão do vendedor para todas as vendas realizadas no ano de 2006
SELECT
    -- CONCAT(DAY(v.data_venda), '/', MONTH(v.data_venda), '/', YEAR(v.data_venda)) AS 'data-venda',
    CONCAT(
        SUBSTRING(v.data_venda, 9, 2), '/', SUBSTRING(v.data_venda, 6, 2), '/', SUBSTRING(v.data_venda, 1, 4)
    ) AS 'data-venda', cl.nome AS cliente, ve.nome AS vendedor, ve.comissao_percentual AS 'comissão'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    -- YEAR(v.data_venda) = 2006;
    v.data_venda LIKE '2006%';

-- 5) Listar Nome do Produto, Nome do Fornecedor, preco de custo, preço de venda (custo+25%) e lucro(venda-custo) para todos os produtos cujo fornecedor é do estado de SP e cujo tipo de produto seja MEDICAMENTOS
SELECT
    p.descricao AS produto,
    tp.descricao AS tipo,
    f.nome AS fornecedor,
    uf.sigla AS UF,
    p.preco_custo AS 'preço-custo',
    (p.preco_custo * 1.25) AS 'preço-venda',
    (p.preco_custo * 0.25) AS lucro
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN tipo_produto tp ON (p.tipo_produto_id = tp.id)
    JOIN cidade c ON (f.cidade_id = c.id)
    JOIN uf ON (c.uf_id = uf.id)
WHERE
    uf.sigla IN ('SP')
    AND tp.descricao IN ('MEDICAMENTOS');

-- 6) Listar o nome de todos os produtos vendidos para os clientes de NOVA FRIBURGO
SELECT p.descricao AS produto
FROM
    produto_vendido pv
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    c.nome IN ('NOVA FRIBURGO');

-- 7) Listar todas as vendas efetuadas que foram creditadas para vendedores cujo nome começa com a letra P
SELECT v.*
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    ve.nome LIKE 'P%';
	
-- 8) Listar nome do produto, nome do fornecedor, data da venda, nome do cliente, nome do vendedor para todos os produtos vendidos nos meses 06,08,10
SELECT
    p.descricao AS produto,
    f.nome AS fornecedor,
    -- CONCAT(DAY(v.data_venda), '/', MONTH(v.data_venda), '/', YEAR(v.data_venda)) AS 'data-venda', 
    CONCAT(
        SUBSTRING(v.data_venda, 9, 2), '/', SUBSTRING(v.data_venda, 6, 2), '/', SUBSTRING(v.data_venda, 1, 4)
    ) AS 'data-venda',
    cl.nome AS cliente,
    ve.nome AS vendedor
FROM
    produto_vendido pv
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN venda v ON (pv.venda_id = v.id)
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
WHERE
    -- MONTH(v.data_venda) IN(6, 8, 10);
    SUBSTRING(v.data_venda, 6, 2) IN ('06', '08', '10');