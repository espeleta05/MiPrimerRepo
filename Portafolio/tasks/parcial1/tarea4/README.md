# Tarea 4: Importación de Bases de Datos Externas

## 📋 Descripción

Esta tarea documenta el proceso completo de descargar un archivo SQL desde una fuente externa e importarlo exitosamente en una base de datos PostgreSQL. Se incluye validación de integridad, manejo de errores y verificación de datos.

## 🎯 Objetivos

- Descargar archivos SQL desde URLs externas
- Validar integridad y formato de archivos
- Importar bases de datos completas en PostgreSQL
- Verificar integridad de datos después de importación
- Manejar errores y conflictos durante la importación
- Ejecutar consultas de validación

## 📁 Contenido

### Archivos Incluidos

- `tarea4.html` - Documentación completa de la tarea
- `script_importacion.sql` - Script SQL con tabla de ejemplo (Biblioteca)
- `README.md` - Este archivo

## 🛠️ Herramientas Utilizadas

- **wget / curl** - Descarga de archivos desde URLs
- **psql** - Cliente PostgreSQL
- **Linux (CentOS)** - Sistema operativo
- **PostgreSQL** - Base de datos

## 📥 Procedimiento de Descarga e Importación

### 1. Descargar Archivo SQL

```bash
# Usando wget
wget https://ejemplo.com/base_datos.sql

# Usando curl
curl -O https://ejemplo.com/base_datos.sql

# Mostrar información del archivo
ls -lh archivo.sql
file archivo.sql
```

### 2. Validar Integridad del Archivo

```bash
# Ver primeras líneas
head -50 archivo.sql

# Ver últimas líneas
tail -20 archivo.sql

# Contar líneas
wc -l archivo.sql

# Buscar palabras clave
grep -i "CREATE TABLE" archivo.sql
grep -i "INSERT INTO" archivo.sql
```

### 3. Crear Base de Datos (Opcional)

```bash
# Conectar como usuario postgres
sudo -u postgres psql

# Crear nueva base de datos
CREATE DATABASE mi_base_datos;
\q
```

### 4. Importar Archivo SQL

```bash
# Opción 1: Importar en base de datos existente
psql -U usuario -d base_datos -f archivo.sql

# Opción 2: Importar desde stdin
cat archivo.sql | psql -U usuario -d base_datos

# Opción 3: Importar con host remoto
psql -h localhost -U usuario -d base_datos -f archivo.sql

# Opción 4: Importar con transacción (más seguro)
psql -U usuario -d base_datos << EOF
BEGIN;
\i archivo.sql
COMMIT;
EOF
```

### 5. Verificar Tablas Creadas

```bash
# Conectar a base de datos
psql -U usuario -d base_datos

# Ver todas las tablas
\dt

# Ver estructura de tabla específica
\d nombre_tabla

# Ver todas las relaciones
\d+
```

### 6. Validar Datos

```sql
-- Contar registros
SELECT COUNT(*) FROM tabla_name;

-- Ver primeros registros
SELECT * FROM tabla_name LIMIT 10;

-- Verificar integridad de llaves foráneas
SELECT a.*, b.*
FROM tabla1 a
FULL OUTER JOIN tabla2 b ON a.id = b.tabla1_id
WHERE b.id IS NULL OR a.id IS NULL;

-- Buscar duplicados
SELECT columna, COUNT(*) as cantidad
FROM tabla_name
GROUP BY columna
HAVING COUNT(*) > 1;
```

## 🚨 Manejo de Errores

### Error: Relación ya existe

```sql
-- Solución: Usar IF NOT EXISTS
CREATE TABLE IF NOT EXISTS tabla_name (
    id INTEGER PRIMARY KEY
);
```

### Error: Violación de restricción UNIQUE

```sql
-- Buscar duplicados
SELECT columna, COUNT(*) 
FROM tabla_name 
GROUP BY columna 
HAVING COUNT(*) > 1;

-- Eliminar duplicados
DELETE FROM tabla_name 
WHERE id NOT IN (
    SELECT MIN(id) FROM tabla_name 
    GROUP BY columna_unica
);
```

### Error: Violación de FOREIGN KEY

```sql
-- Verificar datos huérfanos
SELECT * FROM tabla_hija 
WHERE tabla_padre_id NOT IN (
    SELECT id FROM tabla_padre
);

-- Opción 1: Eliminar datos huérfanos
DELETE FROM tabla_hija 
WHERE tabla_padre_id NOT IN (
    SELECT id FROM tabla_padre
);

-- Opción 2: Desactivar verificación temporalmente
ALTER TABLE tabla_hija 
DISABLE TRIGGER ALL;
-- Luego reactivar después de arreglar datos
ALTER TABLE tabla_hija 
ENABLE TRIGGER ALL;
```

## 📊 Importación en MariaDB

```bash
# Sintaxis
mysql -u usuario -p nombre_base < archivo.sql

# Ejemplo
mysql -u root -p biblioteca < biblioteca.sql

# Importar desde URL
wget https://ejemplo.com/archivo.sql -O - | mysql -u usuario -p nombre_base

# Con contraseña en línea (menos seguro)
mysql -u usuario -pcontraseña nombre_base < archivo.sql
```

## 📋 Ejemplo de Tabla: Biblioteca

La tarea incluye un ejemplo completo con las siguientes tablas:

- **alumnos** - Estudiantes que solicitan préstamos
- **libros** - Catálogo de libros disponibles
- **categorias** - Clasificación de libros
- **libro_categoria** - Relación muchos-a-muchos
- **prestamos** - Registro de préstamos

## 💾 Backup Antes de Importar

**IMPORTANTE**: Siempre hacer backup antes de importar datos

```bash
# Hacer backup de base de datos
pg_dump -U usuario base_datos > backup_2026-02-03.sql

# Hacer backup de tabla específica
pg_dump -U usuario -t tabla_name base_datos > tabla_backup.sql

# Hacer backup en MariaDB
mysqldump -u usuario -p base_datos > backup.sql
```

## 🔄 Restaurar Desde Backup

```bash
# PostgreSQL
psql -U usuario -d base_datos < backup_2026-02-03.sql

# MariaDB
mysql -u usuario -p base_datos < backup.sql
```

## 📈 Consultas Útiles Post-Importación

```sql
-- Estadísticas de tablas
SELECT schemaname, tablename, pg_size_pretty(pg_total_relation_size(schemaname||'.'||tablename)) AS size
FROM pg_tables 
WHERE schemaname NOT IN ('pg_catalog', 'information_schema')
ORDER BY pg_total_relation_size(schemaname||'.'||tablename) DESC;

-- Ver información de índices
SELECT indexname, indexdef 
FROM pg_indexes 
WHERE schemaname = 'public';

-- Verificar integridad de secuencias
SELECT sequence_name FROM information_schema.sequences 
WHERE sequence_schema = 'public';
```

## 🎓 Aprendizajes Principales

1. **Descarga segura**: Validar archivos antes de importar
2. **Importación transaccional**: Usar BEGIN/COMMIT para seguridad
3. **Validación de integridad**: Verificar relaciones después de importar
4. **Manejo de errores**: Identificar y resolver conflictos
5. **Backup preventivo**: Siempre tener un plan de respuesta ante errores

## ⚠️ Mejores Prácticas

✅ Hacer backup antes de importar
✅ Validar integridad del archivo antes
✅ Usar transacciones para importaciones grandes
✅ Verificar restricciones después de importar
✅ Documentar el proceso de importación
✅ Mantener logs de importaciones exitosas/fallidas

❌ No importar archivos de fuentes desconocidas
❌ No ignorar advertencias o errores
❌ No importar en base de datos de producción sin backup
❌ No borrar el archivo SQL original

## 📞 Referencias Útiles

- [Documentación PostgreSQL - COPY](https://www.postgresql.org/docs/current/sql-copy.html)
- [Documentación PostgreSQL - psql](https://www.postgresql.org/docs/current/app-psql.html)
- [pg_dump Documentation](https://www.postgresql.org/docs/current/app-pgdump.html)
- [MySQL Dump Documentation](https://dev.mysql.com/doc/refman/8.0/en/mysqldump.html)

---

**Fecha**: 3 de Febrero, 2026  
**Estado**: ✅ Completado
