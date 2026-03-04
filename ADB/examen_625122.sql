CREATE DATABASE Examen_625122;
USE Examen_625122;

CREATE USER '625122_user'@'localhost' IDENTIFIED BY 'examen.udem1p';
GRANT ALL PRIVILEGES ON Examen_625122.* TO '625122_user'@'localhost';
FLUSH PRIVILEGES;



CREATE TABLE hospital (
  hospital_id VARCHAR(20) PRIMARY KEY,
  hospital_nombre VARCHAR(150) UNIQUE NOT NULL
);

CREATE TABLE consultorio (
  consultorio_numero INT PRIMARY KEY,
  consultorio_piso INT NOT NULL,
  hospital_id VARCHAR(20) NOT NULL,
  FOREIGN KEY (hospital_id) REFERENCES hospital(hospital_id)
);

CREATE TABLE medico (
  medico_id VARCHAR(20) PRIMARY KEY,
  medico_nombre VARCHAR(80) NOT NULL,
  medico_apellido VARCHAR(120) NOT NULL,
  medico_cedula VARCHAR(30) UNIQUE NOT NULL,
  medico_especialidad VARCHAR(80) NOT NULL,
  medico_telefono VARCHAR(30),
  medico_email VARCHAR(120),
  consultorio_numero INT NOT NULL,
  FOREIGN KEY (consultorio_numero) REFERENCES consultorio(consultorio_numero)
);

CREATE TABLE paciente (
  paciente_id VARCHAR(20) PRIMARY KEY,
  paciente_nombre VARCHAR(80) NOT NULL,
  paciente_apellido VARCHAR(120) NOT NULL,
  paciente_email VARCHAR(120) UNIQUE NOT NULL,
  paciente_telefono VARCHAR(30),
  paciente_fecha_nacimiento DATE,
  paciente_genero VARCHAR(20)
);

CREATE TABLE consulta (
  id_consulta VARCHAR(20) PRIMARY KEY,
  fecha_consulta DATE NOT NULL,
  hora_consulta TIME NOT NULL,
  paciente_id VARCHAR(20) NOT NULL,
  medico_id VARCHAR(20) NOT NULL,
  tipo_consulta VARCHAR(30) NOT NULL,
  diagnostico TEXT NOT NULL,
  tratamiento TEXT,
  costo_consulta DECIMAL(10,2) NOT NULL,
  forma_pago VARCHAR(20) NOT NULL,
  FOREIGN KEY (paciente_id) REFERENCES paciente(paciente_id),
  FOREIGN KEY (medico_id) REFERENCES medico(medico_id)
);

CREATE TABLE medicamento (
  medicamento_id VARCHAR(20) PRIMARY KEY,
  medicamento_nombre VARCHAR(120) NOT NULL,
  medicamento_laboratorio VARCHAR(120),
  medicamento_presentacion VARCHAR(60),
  medicamento_precio DECIMAL(10,2) NOT NULL,
  medicamento_stock INT NOT NULL
);

CREATE TABLE consulta_medicamento (
  id_consulta VARCHAR(20) NOT NULL,
  medicamento_id VARCHAR(20) NOT NULL,
  PRIMARY KEY (id_consulta, medicamento_id),
  FOREIGN KEY (id_consulta) REFERENCES consulta(id_consulta),
  FOREIGN KEY (medicamento_id) REFERENCES medicamento(medicamento_id)
);




DELIMITER //

CREATE PROCEDURE sp_consultas_por_paciente_email(IN p_email VARCHAR(120))
BEGIN
  SELECT
    c.fecha_consulta,
    c.hora_consulta,
    CONCAT(m.medico_nombre, ' ', m.medico_apellido) AS medico_tratante,
    m.medico_especialidad AS especialidad,
    c.diagnostico,
    c.tratamiento
  FROM paciente p
  JOIN consulta c ON c.paciente_id = p.paciente_id
  JOIN medico m ON m.medico_id = c.medico_id
  WHERE p.paciente_email = p_email
  ORDER BY c.fecha_consulta DESC, c.hora_consulta DESC;
END //

DELIMITER ;





DELIMITER //

CREATE PROCEDURE sp_resumen_por_medico()
BEGIN
  SELECT
    CONCAT(m.medico_nombre, ' ', m.medico_apellido) AS nombre_completo,
    m.medico_especialidad AS especialidad,
    COUNT(c.id_consulta) AS total_consultas,
    CoUNT(DISTINCT c.paciente_id) AS pacientes_unicos,
    AVG(c.costo_consulta) AS promedio_costo
  FROM medico m
  LEFT JOIN consulta c ON c.medico_id = m.medico_id
  GROUP BY m.medico_id, nombre_comleto, especialidad
  ORDER BY total_consultas DESC;
END //

DELIMITER ;