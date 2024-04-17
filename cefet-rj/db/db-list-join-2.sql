-- [LISTA JOIN 2]

-- 1) Listar apenas o nome dos alunos (apenas um de cada) que NÃO sejam das cidades ‘CARMO’ e ‘MACUCO’, nascidos no ano 2002 e que tenham feito empréstimo de livros de HISTÓRIA e GEOGRAFIA. Proibido usar funções de data, o operador LIKE e a cláusula IN.
SELECT DISTINCT
	al.nome AS aluno
FROM
	aluno al
    JOIN cidade c ON(al.cidade_id=c.id)
    JOIN emprestimo em ON(em.aluno_matricula=al.matricula)
    JOIN exemplar ex ON(em.exemplar_id=ex.id)
    JOIN livro l ON(ex.livro_id=l.id)
    JOIN assunto a ON(l.assunto_id=a.id)
WHERE
	c.nome != 'CARMO' AND c.nome != 'MACUCO'
    AND SUBSTRING(al.data_nascimento, 1, 4) = 2002
    AND a.nome != 'HISTÓRIA' AND a.nome != 'GEOGRAFIA';

-- 2) Listar o título do livro e o nome da editora para todos os livros de autores cujo nome NÃO comece com as letras A, F ou G e que tenham sido emprestados para alunos de cidades cujo nome NÃO seja composto. Proibido usar a cláusula IN e o operador SUBSTRING.
SELECT DISTINCT
	l.titulo AS livro, 
    ed.nome AS editora
FROM
	livro l
    JOIN editora ed ON(l.editora_id=ed.id)
    JOIN livro_autor la ON(la.livro_id=l.id)
    JOIN autor a (a.id=la.autor_id)
	JOIN exemplar ex ON(ex.livro_id=l.id)
    JOIN emprestimo em ON(em.exemplar_id=ex.id)
    JOIN aluno al ON(al.matricula=em.aluno_matricula)
    JOIN cidade c ON(al.cidade_id=c.id)
WHERE
	NOT(a.nome LIKE 'A%' OR
		a.nome LIKE 'F%' OR
        a.nome LIKE 'G%')
    AND c.nome NOT LIKE '% %';
 
-- 3) Listar, sem repetições, o nome dos funcionários que emprestaram livros em setembro de 2002. Proibido usar funções de data e substring.
SELECT DISTINCT
	f.nome
FROM
	funcionario f
    JOIN emprestimo em ON(em.funcionario_id=f.id)
WHERE
	em.data_emprestimo LIKE '2002-09%';
 
-- 4) Listar o nome dos livros de REDES e PROGRAMAÇÃO publicados no ano 2010 e que se encontram emprestados para alunos cujo nome comece com as letras M, P e R. Os registros devem ser exibidos em ordem alfabética de assunto, descartando os 10 primeiros registros e exibindo 10 registros. Proibido usar like e funções de data. Uso obrigatória da cláusula IN p/ os casos em que for pertinente.
SELECT DISTINCT
	l.titulo AS livro
FROM
	livro l
    JOIN assunto a ON(l.assunto_id=a.id)
	JOIN exemplar ex ON(ex.livro_id=l.id)
    JOIN emprestimo em ON(em.exemplar_id=ex.id)
    JOIN aluno al ON(al.matricula=em.aluno_matricula)
WHERE
	a.nome IN('REDES', 'PROGRAMAÇÃO')
    AND ex.status IN('EMPRESTADO')
    AND l.ano_publicacao IN(2010)
    AND SUBSTRING(al.nome, 1, 1) IN('M', 'P', 'R')
ORDER BY
	a.nome ASC
LIMIT 
	10, 10;