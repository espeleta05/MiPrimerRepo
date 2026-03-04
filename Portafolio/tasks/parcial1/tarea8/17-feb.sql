-- Tarea 08: Stored Procedures avanzados + Setup de Flask en Linux
-- Fecha: 17-Feb-2026

USE Biblioteca;

-- Revisión de estructura
DESC Alumnos;

-- Consulta tradicional por matrículas
SELECT nombre, grado
FROM Alumnos
WHERE matricula = 1001
   OR matricula = 1005
   OR matricula = 1002;

-- Procedure con lista CSV
DELIMITER //
CREATE PROCEDURE buscarAlumnos(
  IN p_lista VARCHAR(300)
)
BEGIN
  SELECT nombre, matricula, grado
  FROM Alumnos
  WHERE FIND_IN_SET(matricula, p_lista) > 0;
END //
DELIMITER ;

-- Llamada incorrecta (documentación de error 1318)
CALL buscarAlumnos('1001','1005','1002');

-- Llamada correcta
CALL buscarAlumnos('1001,1005,1002');

-- Conteo total y retorno por OUT
SELECT COUNT(*) FROM Alumnos;

DELIMITER //
CREATE PROCEDURE contarAlumnos(
  OUT p_contar INT
)
BEGIN
  SELECT COUNT(*) INTO p_contar FROM Alumnos;
END //
DELIMITER ;

CALL contarAlumnos(@s);
SELECT @s;

-- Setup de entorno Python/Flask en Linux (comandos de terminal)
-- whereis python
-- python --version
-- pip --version
-- sudo dnf install python3-pip -y
-- pip --version
-- mkdir -p Proyectos/App01
-- cd Proyectos/App01
-- pip install flask
