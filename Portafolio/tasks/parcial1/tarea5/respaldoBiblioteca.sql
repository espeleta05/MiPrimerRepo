-- Ejemplo de inicio de dump de MariaDB para `Biblioteca`
-- (contenido reducido para evidencia)
-- ----------------------------
-- Host: localhost    Database: Biblioteca
-- ------------------------------------------------------
CREATE TABLE `libros` (
  `id` int(11) NOT NULL,
  `titulo` varchar(255) DEFAULT NULL
);
INSERT INTO `libros` VALUES (1,'Don Quijote');
