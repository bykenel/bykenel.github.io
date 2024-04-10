-- [LISTA 1.1]
USE basevendas;

-- 1)Listar a descricao e o endereco de todos os fornecedores do estado SP, das cidades de DIADEMA e BARUERI
SELECT 
    descricao, 
    endereco 
FROM 
    fornecedores 
WHERE 
    estado='SP' 
    AND cidade IN('DIADEMA', 'BARUERI');

-- 2)Listar todos os campos de todos os fornecedores do estado SP, exceto os das cidades de BROTAS e SAO PAULO
SELECT 
    * 
FROM 
    fornecedores 
WHERE 
    estado='SP' 
    AND NOT cidade IN('BROTAS', 'SÃO PAULO');

-- 3)Listar a descricao e o telefone de todos os fornecedores dos estados MG e SP, cujo campo cidade esteja devidamente preenchido
SELECT 
    descricao, 
    telefone 
FROM 
    fornecedores 
WHERE 
    estado IN('MG', 'SP') 
    AND NOT (cidade='' AND cidade IS NULL);

-- 4)Listar todos os campos de todos os fornecedores, ordenando pela descricao, a partir do 5° registro, limitando a 8 linhas o resultado.
SELECT 
    * 
FROM 
    fornecedores 
ORDER BY 
    descricao LIMIT 4,8;

-- 5)Listar descricao, preço de custo e preço de venda (custo acrescido de 30%) de todos os produtos com estoque maior do que 0
SELECT 
    descricao, 
    pcusto, 
    ROUND(pcusto*1.3, 2) AS pvenda 
FROM 
    produtos 
WHERE 
    estoque > 0;

-- 6)Listar descricao, preço de custo, estoque e uma coluna chamada balanco que será resultado do custo, acrescido de 25% multiplicado pelo estoque de todos os produtos
SELECT 
    descricao, 
    pcusto, 
    estoque, 
    ROUND((pcusto*1.25)*estoque, 2) AS balanco 
FROM 
    produtos;