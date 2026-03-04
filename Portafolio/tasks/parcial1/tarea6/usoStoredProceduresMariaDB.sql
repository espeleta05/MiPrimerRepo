-- Actividad: Consultas y Stored Procedures en MariaDB (Biblioteca)
-- Fecha: Febrero 2026

USE Biblioteca;

-- 1) Verificación de tablas
SHOW TABLES;

-- 2) Inspección de estructura
DESC Alumnos;

-- 3) Consulta formateada con y sin alias
SELECT CONCAT('Alumnos: ', nombre)
FROM Alumnos;

SELECT CONCAT('Alumnos: ', nombre) AS Alumnos
FROM Alumnos;

-- 4) Verificación de procedures (asegurar delimitador)
DELIMITER //
SHOW PROCEDURE STATUS //

-- 5) Eliminación del procedure (si existe)
DROP PROCEDURE IF EXISTS etiquetaAlumno//

-- 6) Verificación final
SHOW PROCEDURE STATUS //
DELIMITER ;
