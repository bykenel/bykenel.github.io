-- [LISTA SUBQUERY]
USE basevendasv3;

-- 1) Listar o nome de todos as cidades que tiveram clientes que compraram produtos de fornecedores das UFs ‘RJ’,’SP’,’ES’ e ‘MG’ em 2006.
SELECT nome
FROM cidade
WHERE
    id IN (
        SELECT cidade_id
        FROM bairro
        WHERE
            id IN (
                SELECT bairro_id
                FROM cliente
                WHERE
                    id IN (
                        SELECT cliente_id
                        FROM venda
                        WHERE
                            YEAR(data_venda) = 2006
                            AND id IN (
                                SELECT venda_id
                                FROM produto_vendido
                                WHERE
                                    produto_id IN (
                                        SELECT id
                                        FROM produto
                                        WHERE
                                            fornecedor_id IN (
                                                SELECT id
                                                FROM fornecedor
                                                WHERE
                                                    cidade_id IN (
                                                        SELECT id
                                                        FROM cidade
                                                        WHERE
                                                            uf_id IN (
                                                                SELECT id
                                                                FROM uf
                                                                WHERE
                                                                    sigla IN ('RJ', 'SP', 'ES', 'MG')
                                                            )
                                                    )
                                            )
                                    )
                            )
                    )
            )
    );

-- 2) Listar o nome dos vendedores que tiveram valor de comissão acima de 500 em vendas realizadas no ano de 2006.
SELECT ve.nome
FROM vendedor ve
    JOIN cliente c ON (c.vendedor_id = ve.id)
    JOIN venda v ON (v.cliente_id = c.id)
WHERE
    YEAR(v.data_venda) = 2006
    AND (
        (
            v.valor_total * ve.comissao_percentual
        ) / 100
    ) > 500;

-- 3) Listar o nome dos produtos vendidos em 2006 para clientes do Rio de Janeiro.
SELECT descricao as produto
FROM produto
WHERE
    id IN (
        SELECT produto_id
        FROM produto_vendido
        WHERE
            venda_id IN (
                SELECT id
                FROM venda
                WHERE
                    YEAR(data_venda) = 2006
                    AND cliente_id IN (
                        SELECT id
                        FROM cliente
                        WHERE
                            bairro_id IN (
                                SELECT id
                                FROM bairro
                                WHERE
                                    cidade_id IN (
                                        SELECT id
                                        FROM cidade
                                        WHERE
                                            uf_id IN (
                                                SELECT id
                                                FROM uf
                                                WHERE
                                                    sigla = 'RJ'
                                            )
                                    )
                            )
                    )
            )
    );

-- 4) Listar de forma ordenada as datas e o dia da semana, por extenso, dos dias em que não houve vendas no ano de 2006.
SELECT
    DATE_FORMAT(data_venda, '%d/%m/%Y') as data,
    CASE
        WHEN WEEKDAY(data_venda) = 0 THEN 'segunda'
        WHEN WEEKDAY(data_venda) = 1 THEN 'terca'
        WHEN WEEKDAY(data_venda) = 2 THEN 'quarta'
        WHEN WEEKDAY(data_venda) = 3 THEN 'quinta'
        WHEN WEEKDAY(data_venda) = 4 THEN 'sexta'
        WHEN WEEKDAY(data_venda) = 6 THEN 'sabado'
        ELSE 'domingo'
    END as dia_da_semana
FROM venda
WHERE
    id IN (
        SELECT id
        FROM venda
    )
    AND YEAR(data_venda) = 2006;

-- 5) Listar o nome dos clientes que compraram em 2006 em ordem alfabética.
SELECT nome
FROM cliente
WHERE
    id IN (
        SELECT cliente_id
        FROM venda
        WHERE
            YEAR(data_venda) = 2006
    )
ORDER BY nome;

-- 6) Listar as ufs dos clientes que compraram em 2006.
SELECT sigla
FROM uf
WHERE
    id IN (
        SELECT uf_id
        FROM cidade
        WHERE
            id IN (
                SELECT cidade_id
                FROM bairro
                WHERE
                    id IN (
                        SELECT bairro_id
                        FROM cliente
                        WHERE
                            id IN (
                                SELECT cliente_id
                                FROM venda
                                WHERE
                                    YEAR(data_venda) = 2006
                            )
                    )
            )
    );