-- [LISTA 2]
USE basevendasv2;
 
-- 1) Considerando que os telefones estão no formato (xx)xxxx-xxxx, listar todos os fornecedores com ddd 11 e 21
SELECT 
    * 
FROM 
    fornecedor 
WHERE 
    SUBSTRING(telefone, 2, 4) IN(11, 21);
 
-- 2) Listar nome, cidade/uf dos fornecedores de SP,RJ e MG
SELECT 
    f.nome AS fornecedor, 
    CONCAT(c.nome, '/', uf.sigla) AS 'cidade/uf' 
FROM 
    fornecedor f 
    JOIN cidade c ON(f.cidade_id=c.id) 
    JOIN uf ON(c.uf_id=uf.id) 
WHERE 
    uf.sigla IN('SP', 'RJ', 'MG');
 
-- 3) Listar todos os produtos cujo principio tem 6 caracteres e nenhum espaço
SELECT 
    * 
FROM 
    produto 
WHERE 
    principio_ativo LIKE '______' 
    AND principio_ativo NOT LIKE '% %';
 
-- 4) Listar todos os produtos cujo principio começe com A e que tenha no máximo 2 espaços.
SELECT 
    * 
FROM 
    produto 
WHERE 
    principio_ativo LIKE 'A%' 
    AND principio_ativo NOT LIKE '% % % %';
 
-- 5) Listar todos os clientes cadastrados em novembro e cuja cidade comece com M
SELECT 
    * 
FROM 
    cliente cl
    JOIN bairro b ON(cl.bairro_id=b.id) 
    JOIN cidade c ON(b.cidade_id=c.id) 
WHERE 
    MONTH(cl.data_cadastro) = 11 
    AND c.nome LIKE 'M%';
 
-- 6) Listar nome, mes/ano dos clientes que não sejam de FRIBURGO nem de CORDEIRO
SELECT 
    cl.nome AS cliente, 
    -- CONCAT(MONTH(cl.data_cadastro), '/', YEAR(cl.data_cadastro)) AS 'mês/ano',
    CONCAT(SUBSTRING(v.data_venda, 6, 2), '/', SUBSTRING(v.data_venda, 1, 4)) AS 'mês/ano',
    c.nome AS cidade
FROM 
    cliente cl
    JOIN bairro b ON(cl.bairro_id=b.id) 
    JOIN cidade c ON(b.cidade_id=c.id) 
WHERE 
    c.nome NOT IN('NOVA FRIBURGO', 'CORDEIRO');
 
-- 7) Listar, sem duplicidades, as combinações de cidade-bairro onde se tem clientes cadastrados. Não interessam cidade ou bairro sem preenchimento.
SELECT DISTINCT 
    CONCAT(c.nome, '/', b.nome) AS 'cidade/bairro' 
FROM
    cliente cl
    JOIN bairro b ON(cl.bairro_id=b.id) 
    JOIN cidade c ON(b.cidade_id=c.id) 
WHERE 
    cl.nome NOT IN('', 'null') 
    AND c.nome NOT IN('', 'null') 
    AND b.nome NOT IN('', 'null');
 
-- 8) Considerando que a margem de lucro é de 5%, listar todos os produtos cujo lucro supere os 30,00.
SELECT 
    p.descricao AS produto, 
    p.preco_custo AS 'preço-custo', 
    ROUND((p.preco_custo*1.05) - p.preco_custo) AS lucro 
FROM 
    produto p 
WHERE 
    ((p.preco_custo*1.05) - p.preco_custo) > 30;
 
-- 9) Listar todos os produtos com estoque e com o campo apresentacao preenchido
SELECT 
    * 
FROM 
    produto
WHERE 
    estoque NOT IN('', 'null') 
    AND apresentacao NOT IN('', 'null');