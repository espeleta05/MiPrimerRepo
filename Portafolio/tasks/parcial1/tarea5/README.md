# Tarea 5: Respaldos de Bases de Datos - MariaDB y PostgreSQL

## 📋 Descripción

Esta tarea implementa una estrategia integral de respaldos lógicos para MariaDB y PostgreSQL en un entorno Linux (CentOS), utilizando herramientas de línea de comandos como `mysqldump` y `pg_dumpall`. Se incluye la gestión correcta de permisos (chmod) y propietarios (chown) de archivos, identificación y corrección de errores reales.

## 🎯 Objetivos

- Crear una estructura organizada de directorios para respaldos (/Backups/MariaDB y /Backups/PostgreSQL)
- Generar respaldos lógicos de MariaDB usando `mysqldump`
- Exportar el clúster completo de PostgreSQL usando `pg_dumpall`
- Gestionar permisos de archivos con `chmod` y `chown`
- Identificar y corregir errores comunes (typos en comandos, permisos insuficientes, rutas incorrectas)
- Validar la estructura final con la herramienta `tree`

## 📁 Contenido

### Archivos Incluidos

- **tarea5.html** - Página web con documentación completa de la tarea
- **README.md** - Este archivo (documentación)
- **backups.sh** - Script shell ejecutable para automatizar respaldos
- **tarea5.md** - Informe detallado con comandos y procedimientos
- **evidencia_tree.txt** - Estructura completa de directorios después de respaldos
- **respaldoBiblioteca.sql** - Respaldo de ejemplo de MariaDB
- **images/** - 3 capturas de pantalla mostrando el proceso

### Imágenes Incluidas

1. **estructura-directorios.png** - Creación de carpetas para organizar respaldos
2. **respaldos-mariadb-postgresql.png** - Proceso de generación de respaldos en ambos DBMS
3. **permisos-propietarios.png** - Corrección de permisos y propietarios

## 🛠️ Herramientas Utilizadas

| Herramienta | Función |
|-----------|---------|
| `mkdir -p` | Crear estructura de directorios |
| `mysqldump` | Generar respaldos de MariaDB/MySQL |
| `pg_dumpall` | Exportar clúster completo de PostgreSQL |
| `pg_dump` | Exportar una base de datos específica de PostgreSQL |
| `chmod` | Modificar permisos de archivos (rwx) |
| `chown` | Cambiar propietario y grupo de archivos |
| `tree` | Visualizar estructura de directorios |
| `ls -l` | Listar archivos con permisos detallados |

## 📖 Procedimiento Paso a Paso

### Paso 1: Crear Estructura de Directorios

```bash
# Crear directorio principal y subdirectorios
mkdir -p Backups/MariaDB
mkdir -p Backups/PostgreSQL

# Instalar herramienta tree (si no está instalada)
sudo dnf install tree -y

# Visualizar la estructura
tree Backups/
```

**Resultado esperado:**
```
Backups/
├── MariaDB/
└── PostgreSQL/
```

### Paso 2: Respaldo de MariaDB

#### Opción A: Respaldo de una base de datos específica

```bash
# Comando correcto (nota: mysqldump, no "mysqldum")
mysqldump --user=biblio_user --password Biblioteca > Backups/MariaDB/respaldoBiblioteca.sql

# Cuando pida contraseña, ingresa la contraseña del usuario biblio_user
```

#### Opción B: Respaldo de todas las bases de datos

```bash
mysqldump --user=root --password --all-databases > Backups/MariaDB/respaldo_completo.sql
```

#### Opción C: Respaldo con compresión (recomendado para archivos grandes)

```bash
mysqldump --user=biblio_user --password Biblioteca | gzip > Backups/MariaDB/respaldoBiblioteca.sql.gz
```

### Paso 3: Respaldo de PostgreSQL

#### Paso 3a: Cambiar a usuario postgres

```bash
# Opción 1: Con sudo
sudo -u postgres pg_dumpall -f Backups/PostgreSQL/respaldoBiblioteca.sql

# Opción 2: Cambiar a usuario postgres directamente
sudo su - postgres
pg_dumpall -f Backups/PostgreSQL/respaldoBiblioteca.sql
exit
exit  # Para volver al usuario original
```

#### Paso 3b: Respaldo de base de datos específica

```bash
sudo -u postgres pg_dump nombre_base_datos > Backups/PostgreSQL/respaldo_especifico.sql
```

### Paso 4: Gestión de Permisos

#### Ver permisos actuales

```bash
ls -l Backups/MariaDB/
ls -l Backups/PostgreSQL/
```

#### Cambiar permisos

```bash
# Dar permisos de lectura al propietario
chmod u+r Backups/PostgreSQL/respaldoBiblioteca.sql

# Permisos estándar para respaldos (solo propietario lee/escribe)
chmod 600 Backups/MariaDB/respaldoBiblioteca.sql
chmod 600 Backups/PostgreSQL/respaldoBiblioteca.sql

# Permitir lectura pero no escritura para otros usuarios del grupo
chmod 640 Backups/MariaDB/respaldoBiblioteca.sql
```

#### Cambiar propietario

```bash
# Cambiar propietario y grupo
sudo chown eugenio_espeleta:eugenio_espeleta Backups/MariaDB/*
sudo chown eugenio_espeleta:eugenio_espeleta Backups/PostgreSQL/*

# Cambiar recursivamente todo el directorio
sudo chown -R eugenio_espeleta:eugenio_espeleta Backups/
```

### Paso 5: Validación Final

```bash
# Ver estructura completa
tree Backups/

# Ver tamaño de archivos
du -sh Backups/*/

# Ver información detallada
ls -lh Backups/*/
```

## ⚠️ Errores Comunes y Soluciones

### Error 1: "command not found: mysqldum"

```
❌ Error original:
mysqldum --user=biblio_user --password Biblioteca > respaldo.sql

✅ Solución:
mysqldump --user=biblio_user --password Biblioteca > respaldo.sql
(Nota: faltaba la "p" al final)
```

### Error 2: "Permission denied" al acceder a archivos PostgreSQL

```
❌ Error:
ls -l respaldoBiblioteca.sql
-rw------- 1 postgres postgres 2048 Feb 10 10:25 respaldoBiblioteca.sql

✅ Solución:
chmod u+r respaldoBiblioteca.sql
sudo chown eugenio_espeleta:eugenio_espeleta respaldoBiblioteca.sql
```

### Error 3: "Could not find directory" 

```
❌ Error:
cp respaldoBiblioteca.sql Backups/Postgress/
cp: cannot create regular file: No such file or directory

✅ Solución:
# Crear el directorio primero
mkdir -p Backups/PostgreSQL
# Luego copiar
cp respaldoBiblioteca.sql Backups/PostgreSQL/
```

## 🔧 Referencia de Comandos

### Respaldos MariaDB/MySQL

```bash
# Respaldo simple
mysqldump -u usuario -p base_datos > respaldo.sql

# Respaldo de todas las bases de datos
mysqldump -u usuario -p --all-databases > respaldo_completo.sql

# Respaldo con opciones de compresión
mysqldump -u usuario -p base_datos | gzip > respaldo.sql.gz

# Respaldo con información de estructura y datos
mysqldump -u usuario -p --create-options base_datos > respaldo.sql

# Respaldo sin datos (solo estructura)
mysqldump -u usuario -p --no-data base_datos > respaldo_estructura.sql
```

### Respaldos PostgreSQL

```bash
# Respaldo de clúster completo
pg_dumpall > respaldo_completo.sql

# Respaldo de base de datos específica
pg_dump nombre_base_datos > respaldo.sql

# Respaldo comprimido (más eficiente)
pg_dump nombre_base_datos | gzip > respaldo.sql.gz

# Respaldo con formato personalizado
pg_dump -Fc nombre_base_datos > respaldo.dump
```

### Restauración

#### MariaDB/MySQL

```bash
# Restaurar desde respaldo
mysql -u usuario -p nombre_base_datos < respaldo.sql

# Restaurar múltiples bases de datos (si el respaldo contiene --all-databases)
mysql -u usuario -p < respaldo_completo.sql
```

#### PostgreSQL

```bash
# Restaurar base de datos
psql -U usuario nombre_base_datos < respaldo.sql

# Restaurar respaldo completo
psql -U postgres < respaldo_completo.sql

# Restaurar desde formato comprimido
gunzip -c respaldo.sql.gz | psql -U usuario nombre_base_datos
```

## 💾 Mejores Prácticas para Respaldos

✅ **HACER:**

- Crear respaldos regularmente (diarios, semanales, mensuales)
- Almacenar respaldos en ubicaciones separadas del servidor principal
- Verificar regularmente que los respaldos se pueden restaurar
- Usar compresión para ahorrar espacio (gzip, bzip2)
- Documentar el proceso y mantener logs
- Usar transacciones para garantizar consistencia
- Establecer permisos restrictivos (600 o 640)
- Encriptar respaldos sensibles
- Usar scripts automatizados con cron

❌ **NO HACER:**

- Ignorar errores durante la creación de respaldos
- Almacenar todos los respaldos en el mismo disco
- Usar permisos abiertos (777) en archivos de respaldo
- Restaurar en producción sin validación previa
- Dejar respaldos sin cifrar en servidores compartidos
- Olvidar probar el proceso de restauración
- Mantener respaldos indefinidamente sin rotación

## 📊 Estructura Final de Archivos

```
Backups/
├── MariaDB/
│   └── respaldoBiblioteca.sql
└── PostgreSQL/
    └── respaldoBiblioteca.sql
```

## 🎓 Conceptos Clave Aprendidos

| Concepto | Definición |
|----------|-----------|
| **Respaldo Lógico** | Exportación de estructura y datos en formato SQL |
| **mysqldump** | Herramienta para generar respaldos en MariaDB/MySQL |
| **pg_dumpall** | Exporta clúster completo de PostgreSQL |
| **chmod** | Modifica permisos (r=lectura, w=escritura, x=ejecución) |
| **chown** | Cambia propietario y grupo de archivos |
| **Integridad** | Validación que los datos se respaldaron correctamente |
| **Automatización** | Scripts cron para respaldos programados |

## 📝 Ficheros Adicionales

- **backups.sh** - Script que automatiza el proceso completo de respaldos
- **tarea5.md** - Informe detallado con ejercicios adicionales
- **evidencia_tree.txt** - Salida de comando `tree` mostrando la estructura final

## 🔗 Referencias Útiles

- [MariaDB Official Dump Documentation](https://mariadb.com/kb/en/mysqldump/)
- [PostgreSQL Backup and Restore](https://www.postgresql.org/docs/current/backup.html)
- [Linux Permissions: chmod and chown](https://www.linux.com/training-tutorials/file-and-directory-permissions-chmod/)
- [Creating Automated Backups with Cron](https://www.cyberciti.biz/faq/how-do-i-set-up-a-cron-job/)

---

**Fecha de Creación:** 10 de Febrero, 2026  
**Estado:** ✅ Completado  
**Versión:** 1.0
