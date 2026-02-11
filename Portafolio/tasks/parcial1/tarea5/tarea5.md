# Tarea 5 — Respaldos de Bases de Datos (MariaDB y PostgreSQL)

## 1. Objetivo
Implementar una estrategia básica de respaldos lógicos para MariaDB y PostgreSQL en Linux, documentando los comandos, correcciones de errores y la gestión de permisos y propietarios.

## 2. Estructura de carpetas
Se creó la siguiente estructura para organizar los respaldos por motor:

Backups/
├─ MariaDB/
└─ Postgress/

Comandos usados para crearla:

mkdir -p Backups/MariaDB Backups/Postgress
sudo dnf install tree -y
tree Backups/

## 3. Respaldo MariaDB
Comando correcto para generar un dump lógico de la base `Biblioteca`:

mysqldump --user=biblio_user --password Biblioteca > Backups/MariaDB/respaldoBiblioteca.sql

Nota: durante la práctica se mostró un error por typo (`mysqldum`), corregido usando `mysqldump`.

## 4. Respaldo PostgreSQL
Generar respaldo completo del clúster como el usuario `postgres`:

sudo su -
su - postgres
pg_dumpall -f /var/lib/postgresql/respladoBiblioteca.sql

Copiar al directorio de Backups y corregir propiedad:

sudo cp /var/lib/postgresql/respladoBiblioteca.sql Backups/Postgress/
sudo chown $USER:$USER Backups/Postgress/respladoBiblioteca.sql

## 5. Permisos y manejo de errores
Ejemplos de comandos para inspección y corrección:

ls -l Backups/Postgress
chmod u+r Backups/Postgress/respladoBiblioteca.sql
sudo chown eugenio_espeleta:eugenio_espeleta Backups/Postgress/*

Errores comunes resueltos en la práctica:
- Tipos en nombres de comandos (mysqldum → mysqldump).
- Rutas y nombres mal escritos (respladoBiblioteca.sql → respladoBiblioteca.sql según salida real).
- Permisos insuficientes al intentar listar o copiar archivos pertenecientes a `postgres`.

## 6. Evidencias
Incluyo archivos de ejemplo en esta carpeta:
- `evidencia_tree.txt`: salida simulada de `tree Backups/`.
- `respaldoBiblioteca.sql`: archivo ejemplo de dump MariaDB (pequeño).
- `respladoBiblioteca.sql`: archivo ejemplo de dump PostgreSQL (pequeño).

## 7. Conclusión
Se demostraron los pasos esenciales para crear respaldos lógicos en MariaDB y PostgreSQL, organizar los dumps por motor, y gestionar permisos y propietarios en Linux.

Si quieres, puedo:
- Ajustar rutas a tu servidor real.
- Añadir un script programado (cron) para automatizar respaldos.
