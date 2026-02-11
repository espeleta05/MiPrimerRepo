DBMS en máquina virtual de Google Cloud

Descripción
-----------
Configuración del DBMS (MariaDB) en una VM de Google Cloud. Incluye comandos SQL y pasos para crear la base de datos `Biblioteca`, crear el usuario `biblio_user`, y realizar un respaldo (dump).

Instrucciones rápidas
---------------------
1. Accede a la VM por SSH.
2. Ejecuta: `sudo mariadb-secure-installation` y sigue los pasos.
3. Cambia a tu usuario si es necesario: `su - <tu_usuario>`.
4. Entra al DBMS como root: `mysql -u root -p`.
5. Ejecuta los comandos del archivo `db_commands.sql` o copia/pega dentro del cliente MySQL.

Comandos útiles
---------------
- Crear DB: `CREATE DATABASE Biblioteca;`
- Crear usuario: `CREATE USER 'biblio_user'@'localhost' IDENTIFIED BY '666';`
- Conceder permisos: `GRANT ALL PRIVILEGES ON Biblioteca.* TO 'biblio_user'@'localhost';`
- Volcar DB: `mysqldump -u biblio_user -p Biblioteca > respaldo_biblioteca.sql`

Archivos en la carpeta
----------------------
- `tarea2.html`  -> Página web con la documentación y capturas.
- `db_commands.sql` -> Archivo con los comandos SQL usados.
- `README.md` -> Instrucciones rápidas.
- `images/` -> Pon aquí las capturas (fig1.png, fig2.png). 

Notas
-----
- Usa `localhost` en las instrucciones de GRANT para asegurar que el usuario solo pueda conectarse desde la VM.
- Reemplaza contraseñas por otras seguras antes de producción.
