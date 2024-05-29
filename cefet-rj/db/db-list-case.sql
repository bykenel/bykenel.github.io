-- [LISTA CASE]
USE basevendasv3;

-- 1) Considerando estoque normal a partir de 20, estoque crítico menor que 20 e estoque zerado com valor igual a zero, listar id, descrição, estoque e a situacao do estoque de todos os produtos utilizando case.
SELECT
    id,
    descricao,
    estoque,
    CASE
        WHEN estoque > 20 THEN 'Estoque normal'
        WHEN estoque = 0 THEN 'Sem estoque'
        ELSE 'Estoque crítico'
    END AS 'situacao-estoque'
FROM produto;

-- 2) Considerando estoque normal a partir de 20 e estoque crítico menor que 20 listar id, descrição, estoque e a situacao do estoque de todos os produtos utilizando IF ternário.
SELECT 
    id, 
    descricao, 
    estoque, 
    IF(
        estoque > 20, 'Estoque normal', 'Estoque crítico'
    ) AS 'situacao-estoque'
FROM produto
ORDER BY descricao;

-- 3) Considere as seguintes informações sobre as regiões do país. Liste o nome do fornecedor, o nome da cidade, a sigla da UF e a região de todos os fornecedores
-- SUL --> 'PR', 'RS', 'SC'
-- SUDESTE --> 'SP', 'RJ', 'ES', 'MG'
-- Centro-Oeste --> 'MT', 'MS', 'GO'
-- Nordeste --> 'BA', 'AL', 'SE', 'PB', 'PE', 'RN', 'CE', 'PI', 'MA'
-- Norte --> 'AM', 'RR', 'AP', 'PA', 'TO', 'RO', 'AC'
SELECT
    f.nome AS fornecedor,
    c.nome AS cidade,
    uf.sigla,
    CASE
        WHEN uf.sigla IN ('PR', 'RS', 'SC') THEN 'Sul'
        WHEN uf.sigla IN ('SP', 'RJ', 'ES', 'MG') THEN 'Sudeste'
        WHEN uf.sigla IN ('MT', 'MS', 'GO') THEN 'Centro-Oeste'
        WHEN uf.sigla IN ('BA', 'AL', 'SE', 'PB', 'PE', 'RN', 'CE','PI', 'MA') THEN 'Nordeste'
        WHEN uf.sigla IN ('AM', 'RR','AP', 'PA', 'TO', 'RO', 'AC') THEN 'Norte'
        ELSE 'Provável erro'
    END AS regiao
FROM 
    fornecedor f
    JOIN cidade c ON (f.cidade_id = c.id)
    JOIN uf ON (c.uf = uf.id)
ORDER BY fornecedor;

-- 4) Listar o nome do fornecedor, a descrição do produto, o estoque e o preço de custo dos produtos incluindo os fornecedores que não possuem produtos relacionados. Use case para ordenar. Se o nome do produto for nulo, ordene pelo fornecedor. Caso contrário, ordene pelo estoque.
SELECT 
    f.nome AS fornecedor, 
    p.descricao AS produto, 
    p.estoque, 
    p.preco_custo
FROM 
    fornecedor f
    LEFT JOIN produto p ON (p.fornecedor_id = f.id)
ORDER BY (
        CASE
            WHEN produto IS NULL THEN fornecedor
            ELSE estoque
        END
    );

-- 5) Utilizando a função date_format, listar as datas completas (no formato dia/mes/ano) e a descrição do dia da semana dos dias em que houve vendas para clientes com o nome iniciado por A,C e H em 2006. Ordenar pela data da venda. Dica: use funções de data, case e subconsulta.
SELECT DISTINCT
    DATA_FORMAT (data_venda, '%d/%m/%y') AS data_venda,
    CASE
        WHEN WEEKDAY(data_venda) = 0 THEN 'segunda'
        WHEN WEEKDAY(data_venda) = 1 THEN 'terca'
        WHEN WEEKDAY(data_venda) = 2 THEN 'quarta'
        WHEN WEEKDAY(data_venda) = 3 THEN 'quinta'
        WHEN WEEKDAY(data_venda) = 4 THEN 'sexta'
        WHEN WEEKDAY(data_venda) = 6 THEN 'sabado'
        ELSE 'domingo'
    END AS dia
FROM venda
WHERE
    id IN (
        SELECT id
        FROM venda
        WHERE
            data_venda LIKE '2006%'
            AND cliente_id IN (
                SELECT id
                FROM cliente
                WHERE
                    SUBSTRING(nome, 1, 1) IN ('A', 'C', 'H')
            )
    );