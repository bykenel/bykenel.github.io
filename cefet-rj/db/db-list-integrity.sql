-- [LISTA INTEGRIDADE 1]
CREATE DATABASE biblioteca_cefet;
USE biblioteca_cefet;

-- 1) Criar o banco de dados biblioteca_cefet e implementar integridade referencial em todas as tabelas.
CREATE TABLE editora (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
) ENGINE = INNODB;

CREATE TABLE assunto (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
) ENGINE = INNODB;

CREATE TABLE livro (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    editora_id INT(11) NOT NULL,
    assunto_id INT(11) NOT NULL,
    titulo VARCHAR(30),
    ano_publicacao CHAR(4),
    CONSTRAINT fk_livro__editora_id FOREIGN KEY (editora_id) REFERENCES editora (id) ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT fk_livro__assunto_id FOREIGN KEY (assunto_id) REFERENCES assunto (id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = INNODB;

CREATE TABLE pais (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
) ENGINE = INNODB;

CREATE TABLE autor (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    pais_id INT(11) NOT NULL,
    nome VARCHAR(30),
    data_nascimento DATE,
    CONSTRAINT fk_autor__pais_id FOREIGN KEY (pais_id) REFERENCES pais (id) ON DELETE RESTRICT ON UPDATE CASCADE,
) ENGINE = INNODB;

CREATE TABLE livro_autor (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    livro_id INT(11) NOT NULL,
    autor_id INT(11) NOT NULL,
    CONSTRAINT fk_livro_autor__livro_id FOREIGN KEY (livro_id) REFERENCES livro (id) ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT fk_livro_autor__autor_id FOREIGN KEY (autor_id) REFERENCES autor (id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = INNODB;

CREATE TABLE cidade (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
) ENGINE = INNODB;

CREATE TABLE aluno (
    matricula INT(11) NOT NULL PRIMARY KEY,
    cidade_id INT(11) NOT NULL,
    nome VARCHAR(30),
    data_nascimento DATE,
    CONSTRAINT fk_autor__cidade_id FOREIGN KEY (cidade_id) REFERENCES cidade (id) ON DELETE RESTRICT ON UPDATE CASCADE,
) ENGINE = INNODB;

CREATE TABLE exemplar (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    livro_id INT(11) NOT NULL,
    status ENUM(
        'INDISPONÍVEL',
        'DISPONÍVEL',
        'EMPRESTADO'
    ) NOT NULL,
    CONSTRAINT fk_exemplar__livro_id FOREIGN KEY (livro_id) REFERENCES livro (id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = INNODB;

CREATE TABLE funcionario (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(30) NOT NULL
) ENGINE = INNODB;

CREATE TABLE emprestimo (
    id INT(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
    exemplar_id INT(11) NOT NULL,
    aluno_matricula INT(11) NOT NULL,
    funcionario_id INT(11) NOT NULL,
    data_emprestimo DATETIME,
    data_devolucao DATETIME,
    CONSTRAINT fk_emprestimo__exemplar_id FOREIGN KEY (exemplar_id) REFERENCES exemplar (id) ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT fk_emprestimo__aluno_id FOREIGN KEY (aluno_matricula) REFERENCES aluno (matricula) ON DELETE RESTRICT ON UPDATE CASCADE,
    CONSTRAINT fk_emprestimo__funcionario_id FOREIGN KEY (funcionario_id) REFERENCES funcionario (id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE = INNODB;