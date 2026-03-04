-- Tarea 07: Índices, EXPLAIN y Stored Procedures en MariaDB
-- Fecha: 13-Feb-2026

USE Biblioteca;

-- Exploración inicial
SHOW TABLES;
DESC Libros;

-- Consulta base por autor
SELECT *
FROM Libros
WHERE autor = 'Gabriel García Márquez';

-- Índice para optimización de búsquedas por autor
CREATE INDEX indx_libros_autor ON Libros(autor);

-- Consulta filtrada posterior al índice
SELECT id_libro, titulo, autor
FROM Libros
WHERE autor = 'Gabriel García Márquez';

-- Consulta y análisis con EXPLAIN
SELECT *
FROM Prestamos
WHERE matricula = 1006
  AND fecha_prestamo >= '2024-08-01'
ORDER BY fecha_prestamo;

EXPLAIN SELECT * FROM Prestamos WHERE matricula = 1005;

-- Intento de recrear índice (genera error 1061 si ya existe)
CREATE INDEX indx_libros_autor ON Libros(autor);

-- Procedure 1: búsqueda por autor
DELIMITER //
CREATE PROCEDURE buscarLibros(
  IN p_autor VARCHAR(100)
)
BEGIN
  DECLARE n_autor VARCHAR(100);
  SET n_autor = TRIM(p_autor);

  SELECT id_libro, titulo, anio_publicacion
  FROM Libros
  WHERE autor = n_autor;
END //
DELIMITER ;

CALL buscarLibros('Gabriel García Márquez');

-- Procedure 2: alumnos por grado con validación
DELIMITER //
CREATE PROCEDURE alumnosxGrado(
  IN p_grado VARCHAR(20)
)
BEGIN
  IF p_grado IS NULL OR TRIM(p_grado) = '' THEN
    SELECT 'ERROR: no hay parametro' AS Mensaje;
  ELSE
    SELECT matricula, nombre
    FROM Alumnos
    WHERE grado = p_grado;
  END IF;
END //
DELIMITER ;

CALL alumnosxGrado('2° Secundaria');
CALL alumnosxGrado();
