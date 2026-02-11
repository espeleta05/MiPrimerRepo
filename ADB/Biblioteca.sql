--Alumnos 
CREATE TABLE Alumnos (
    matricula int PRIMARY KEY AUTO_INCREMENT,
    nombre varchar(100) not null,
    grado varchar(20) not null
);

--Libros
CREATE TABLE Libros(
    id_libro int PRIMARY KEY AUTO_INCREMENT,
    titulo varchar(100) not null,
    autor varchar(100) not null,
    anio_publicacion int not null
);

--Prestamos
CREATE TABLE Prestamos(
    id_prestamo int PRIMARY KEY AUTO_INCREMENT not null,
    matricula int not null,
    id_libro int not null,
    fecha_prestamo date not null, 
    fecha_devolucion date,

    FOREIGN KEY (matricula) REFERENCES Alumnos (matricula),
    FOREIGN KEY (id_libro) REFERENCES Libros (id_libro)
);