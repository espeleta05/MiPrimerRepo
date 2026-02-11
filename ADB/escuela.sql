CREATE DATABASE escuela;

GRANT ALL PRIVILEGES ON escuela.* TO 'escuela_user'@'localhost' IDENTIFIED BY '666';
FLUSH PRIVILEGES;

USE escuela;

CREATE TABLE students(
    sid INT AUTO_INCREMENT PRIMARY KEY,
    s_name VARCHAR(50) NOT NULL
);

CREATE TABLE faculties(
    fid INT AUTO_INCREMENT PRIMARY KEY,
    f_name VARCHAR(50) NOT NULL,
    f_phone VARCHAR(20)
);

CREATE TABLE courses(
    cid VARCHAR(10) PRIMARY KEY,
    c_name VARCHAR(20) NOT NULL,
    fid INT NOT NULL,
    FOREIGN KEY (fid) REFERENCES faculties(fid)
);

CREATE TABLE courses_grade(
    sid INT NOT NULL,
    cid VARCHAR(10) NOT NULL,
    grade VARCHAR(2),
    FOREIGN KEY (sid) REFERENCES students(sid),
    FOREIGN KEY (cid) REFERENCES courses(cid)
);
