ses-- DBMS en máquina virtual (23 de Enero, 2026)
-- SQL commands used during the lab

-- 1) Connect as root in the DBMS: mysql -u root -p

CREATE DATABASE Biblioteca;

CREATE USER 'biblio_user'@'localhost' IDENTIFIED BY '666';
GRANT ALL PRIVILEGES ON Biblioteca.* TO 'biblio_user'@'localhost';
FLUSH PRIVILEGES;

-- Use the database
USE Biblioteca;

-- Example DDL: create a simple table
CREATE TABLE Libros (
  id INT AUTO_INCREMENT PRIMARY KEY,
  Titulo VARCHAR(255) NOT NULL,
  Autor VARCHAR(100),
  Fecha DATE DEFAULT NULL
);

-- Insert example
INSERT INTO Libros (Titulo, Autor) VALUES ('Bases de datos avanzadas', 'Raul Morales');

-- Check records
SELECT * FROM Libros;

-- Backup (from the shell):
-- mysqldump -u biblio_user -p Biblioteca > respaldo_biblioteca.sql
