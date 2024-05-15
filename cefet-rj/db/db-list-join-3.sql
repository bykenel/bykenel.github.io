-- [LISTA JOIN 3]
USE basevendasv2;

-- 1) Listar a data, o nome do cliente e o valor total de todas as vendas de 2006 e cujo nome do cliente seja composto. Ordenar pelo nome do cliente, exibindo o resultado a partir do 11º registro e limitando o resultado a 5 registros. PROIBIDO UTILIZAR SUBSTRING e comandos que tragam intervalo entre datas.
SELECT v.data_venda AS 'data-venda', cl.nome AS cliente, v.valor_total AS 'valor-total'
FROM venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
WHERE
    v.data_venda LIKE '2006%'
    AND cl.nome LIKE '% %'
ORDER BY cl.nome ASC
LIMIT 10, 5;

-- 2)  Listar a data da venda, o nome do vendedor e valor total de todas as vendas realizadas para clientes cujo nome comece com as letras A,C e D. PROIBIDO USAR LIKE. PROIBIDO USAR A CLÁUSULA IN.
SELECT v.data_venda AS 'data-venda', ve.nome AS vendedor, v.valor_total AS 'valor-total'
FROM
    venda v
    JOIN cliente cl ON (v.cliente_id = cl.id)
    JOIN vendedor ve ON (cl.vendedor_id = ve.id)
WHERE
    SUBSTRING(cl.nome, 1, 1) = 'A'
    OR SUBSTRING(cl.nome, 1, 1) = 'C'
    OR SUBSTRING(cl.nome, 1, 1) = 'D'
    
-- 3) Listar apenas o nome (Sem repetições) de todos os clientes da cidade CORDEIRO cujo nome seja OBRIGATORIAMENTE composto e que tenha no máximo 3 espaços.
SELECT DISTINCT
    cl.nome AS cliente
FROM cliente cl
    JOIN bairro b ON (cl.bairro_id = b.id)
    JOIN cidade c ON (b.cidade_id = c.id)
WHERE
    c.nome IN ('CORDEIRO')
    AND cl.nome LIKE '% %'
    AND cl.nome NOT LIKE '% % % % %';