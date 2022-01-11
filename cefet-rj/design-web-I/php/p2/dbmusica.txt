CREATE DATABASE dbmusica;
USE dbmusica;

CREATE table musica (
	idmus INT AUTO_INCREMENT,
	Nome VARCHAR (45),
	Autor VARCHAR (45),
	Album VARCHAR (45),
	PRIMARY KEY (idmus)
);

INSERT INTO musica VALUES (5, 'Knights of Cydonia', 'Muse', 'Knights of Cydonia');
INSERT INTO musica VALUES (3, 'Mesmer', 'Valiant Hearts', 'Odyssey');
INSERT INTO musica VALUES (2, 'Stressed Out', 'Twenty One Pilots', 'Blurryface');
INSERT INTO musica VALUES (4, 'Icarus', 'Starset', 'Horizons');
INSERT INTO musica VALUES (1, 'Bleeding Out', 'Imagine Dragons', 'Night Visions');