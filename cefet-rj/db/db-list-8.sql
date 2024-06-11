-- [LISTA 8]

-- 1) Listar o nome do cliente e a data da venda de todas as vendas com valor acima da média
SELECT c.nome, v.data_venda
FROM cliente c
    JOIN venda v ON (v.cliente_id = c.id)
WHERE
    v.valor_total > (
        SELECT AVG(valor_total)
        FROM venda
    );

-- 2) Listar o nome(descrição) do(s) produto(s) mais caro(s)
SELECT DESCRICAO
FROM produto
WHERE
    preco_custo = (
        SELECT MAX(preco_custo)
        FROM produto
    );

-- 3) Listar apenas o nome dos fornecedores que possuem produtos com estoque acima da média vendidos no ano de 2006.
SELECT DISTINCT
    f.nome
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN produto_vendido pv ON (pv.produto_id = p.id)
    JOIN venda v ON (pv.venda_id = v.id)
WHERE
    p.estoque > (
        SELECT AVG(estoque)
        FROM produto
    )
    AND SUBSTRING(v.data_venda, 1, 4) = 2006;

-- 4) Listar apenas o nome dos vendedores que acumularam comissão acima de 200,00 nas vendas acima da média.
SELECT ve.nome
FROM vendedor ve
    JOIN cliente c ON (c.vendedor_id = ve.id)
    JOIN venda v ON (v.cliente_id = c.id)
WHERE
    v.valor_total > (
        SELECT avg(valor_total)
        FROM venda
    )
GROUP BY
    ve.id
HAVING
    SUM(
        (
            v.valor_total * ve.comissao_percentual
        ) / 100
    ) > 200;

-- 5) Desafio: Escreva o comando SQL para obter o resultado abaixo:
SELECT
    DATE_FORMAT(v.data_venda, '%d/%m/%Y') as data,
    c.nome as cliente,
    p.descricao as produto,
    f.nome as fornecedor,
    pv.valor_unitario as vunitario,
    pv.quantidade as qtde,
    pv.valor_total as vtotal,
    ve.nome as vendedor,
    ve.comissao_percentual as comissao,
    ROUND(
        (
            (
                v.valor_total * ve.comissao_percentual
            ) / 100
        ),
        2
    ) as valorComissao
FROM
    vendedor ve
    JOIN cliente c ON (c.vendedor_id = ve.id)
    JOIN venda v ON (v.cliente_id = c.id)
    JOIN produto_vendido pv ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
    JOIN fornecedor f ON (p.fornecedor_id = f.id);

-- 6) Listar o nome e o valor acumulado dos 10 produtos mais vendidos em valores. Só interessam produtos com valores acumulados acima de 500.
SELECT p.descricao as produto, ROUND(SUM(pv.valor_total), 2) as valor_acumulado
FROM
    venda v
    JOIN produto_vendido pv ON (pv.venda_id = v.id)
    JOIN produto p ON (pv.produto_id = p.id)
GROUP BY
    p.id
HAVING
    valor_acumulado > 500
ORDER BY valor_acumulado DESC
LIMIT 10;

--7) Listar o nome e o valor acumulado em compras dos 5 clientes que mais compraram no ano de 2006. Só interessam clientes que compraram um valor acumulado acima de 5000.
SELECT c.nome as cliente, ROUND(SUM(v.valor_total), 2) as valor_acumulado
FROM venda v
    JOIN cliente c ON (v.cliente_id = c.id)
WHERE
    YEAR(v.data_venda) = 2006
GROUP BY
    c.id
HAVING
    valor_acumulado > 5000
ORDER BY valor_acumulado DESC
LIMIT 5;

-- 8) Listar as 3 cidades que possuem a maior quantidade de clientes que compraram no ano de 2006.
SELECT ci.nome as cidade
FROM
    venda v
    JOIN cliente c ON (v.cliente_id = c.id)
    JOIN bairro b ON (c.bairro_id = b.id)
    JOIN cidade ci ON (b.cidade_id = ci.id)
WHERE
    YEAR(v.data_venda) = 2006
GROUP BY
    ci.id
ORDER BY COUNT(*) DESC
LIMIT 3;

-- 9) Crie a base de dados cineclube e crie as tabelas e regras de integridade das tabelas abaixo. IMPORTANTE: Não deve ser possível excluir um gênero já referenciado na tabela filmes_assistidos. Não deve ser possível cadastrar um filme de um gênero inexistente. Ao atualizar o id de um gênero, essa atualização deve repercutir em cascata na tabela filmes_assistidos.
DROP DATABASE IF EXISTS cineclube;

CREATE DATABASE cineclube CHARSET = utf8 COLLATE = utf8_unicode_ci;

USE cineclube;

CREATE TABLE genero (
    id INT(11) PRIMARY KEY,
    descricao VARCHAR(30)
) ENGINE = INNODB;

CREATE TABLE filmes_assistidos (
    id INT(11),
    genero_id INT(11),
    titulo VARCHAR(80),
    avaliacao DECIMAL(9, 1),
    PRIMARY KEY (id),
    CONSTRAINT fk_filmes_assistidos__genero_id FOREIGN KEY (genero_id) REFERENCES genero (id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = INNODB;

-- 10) Criar uma view que o nome do produto, o nome do fornecedor e o valor total dos 10 produtos mais vendidos em quantidade. Não interessam produtos que tenham vendido menos de 20 unidades no total.
CREATE OR REPLACE VIEW VW_produtos_mais_vendidos_quantidade (
    produto,
    fornecedor,
    valor_total
) AS
SELECT p.descricao, f.nome, pv.valor_total
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN produto_vendido pv ON (pv.produto_id = p.id)
GROUP BY
    p.id
HAVING
    COUNT(*) >= 20
ORDER BY COUNT(*) DESC
LIMIT 10;

-- 11) Criar uma view que o nome do produto, o nome do fornecedor e o valor total dos 10 produtos mais vendidos em valor.
CREATE OR REPLACE VIEW VW_produtos_mais_vendidos_quantidade (
    produto,
    fornecedor,
    valor_total
) AS
SELECT p.descricao, f.nome, pv.valor_total
FROM
    produto p
    JOIN fornecedor f ON (p.fornecedor_id = f.id)
    JOIN produto_vendido pv ON (pv.produto_id = p.id)
GROUP BY
    p.id
ORDER BY SUM(pv.valor_total) DESC
LIMIT 10;

-- 12) Usando a base de dados cinebd2023 (fornecida pelo professor), crie uma view que contenha todos os campos das duas tabelas. Em seguida, utilize essa view para executar cada uma das 4 operações(SELECT, INSERT, UPDATE e DELETE)
CREATE OR REPLACE VIEW vw_filmes_assistidos_completo (
    id,
    titulo,
    avaliacao,
    genero_id,
    id_genero,
    descricao_genero
) AS
SELECT fa.id, fa.titulo, fa.avaliacao, fa.genero_id, g.id, g.descricao
FROM filmes_assistidos fa
    JOIN generos g ON (fa.genero_id = g.id);

SELECT * FROM vw_filmes_assistidos_completo;

INSERT INTO
    vw_filmes_assistidos_completo (
        id,
        titulo,
        avaliacao,
        genero_id
    )
VALUES (
        11,
        'E SE FOSSE VERDADE',
        9.1,
        5
    );

UPDATE vw_filmes_assistidos_completo
SET
    avaliacao = 8.7,
    genero_id = 3
WHERE
    id = 11;

SELECT * FROM vw_filmes_assistidos_completo;

DELETE FROM vw_filmes_assistidos_completo WHERE id = 11;
-- (Não funciona)
SELECT * FROM vw_filmes_assistidos_completo;