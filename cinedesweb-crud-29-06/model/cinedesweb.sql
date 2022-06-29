DROP DATABASE IF EXISTS cinedesweb;
CREATE DATABASE cinedesweb CHARSET=utf8 COLLATE=utf8_unicode_ci;
USE cinedesweb;

CREATE TABLE filmes_assistidos(id INT AUTO_INCREMENT PRIMARY KEY,
                                titulo VARCHAR(80) NOT NULL,
                                avaliacao DECIMAL(9,1) NOT NULL DEFAULT 0.0,
                                UNIQUE INDEX idx_filme_titulo(titulo)
                              ) ENGINE = INNODB;

INSERT INTO filmes_assistidos VALUES(1, 'INTERESTELAR', 9.8), (2, 'AMOR A TODA PROVA', 9.7), 
(3, 'SIMPLESMENTE AMOR', 9.5), (4, 'GLADIADOR', 8.9), (5, 'DJANGO LIVRE', 9.3), 
(6, 'ENTRE FACAS E SEGREDOS', 9.5), (7, 'MATRIX', 5.5), (8, 'GRAVIDADE', 6.9), 
(9, 'PULP FICTION', 9.4), (10, 'AS BRANQUELAS', 5.4), (11, 'EFEITO BORBOLETA', 9.5);

CREATE TABLE generos(id int AUTO_INCREMENT PRIMARY KEY,
                        descricao VARCHAR(30) NOT NULL,
                        UNIQUE INDEX idx_generos_descricao(descricao)
                    ) ENGINE = INNODB;

INSERT INTO generos(descricao) VALUES('INDEFINIDO'), ('FICÇÃO CIENTIÍFICA'), ('COMÉDIA'), 
('DRAMA'), ('COMÉDIA ROMÂNTICA'), ('SUSPENSE'), ('AÇÃO');

ALTER TABLE filmes_assistidos ADD COLUMN genero_id int;

ALTER TABLE filmes_assistidos ADD CONSTRAINT fk_filmes_assistidos__genero_id FOREIGN KEY(genero_id)
REFERENCES generos(id)
ON DELETE RESTRICT ON UPDATE CASCADE;

UPDATE filmes_assistidos SET genero_id = 1;