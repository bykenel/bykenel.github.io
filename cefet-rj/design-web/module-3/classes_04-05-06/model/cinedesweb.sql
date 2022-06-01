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