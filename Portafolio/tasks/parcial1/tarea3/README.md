# Tarea 3: PostgreSQL en Google Cloud

## 📋 Descripción

Esta tarea documenta la instalación, configuración y uso de PostgreSQL en una máquina virtual de Google Cloud Platform. Se incluye la creación de usuarios, diseño de esquemas relacionales, y ejecución de comandos DDL y DML.

## 🎯 Objetivos

- Instalar PostgreSQL en un servidor Linux (CentOS)
- Configurar usuarios y permisos en PostgreSQL
- Crear esquemas de bases de datos relacionales
- Ejecutar comandos DDL (CREATE TABLE, ALTER TABLE, DROP TABLE)
- Ejecutar comandos DML (INSERT, UPDATE, DELETE, SELECT)
- Implementar integridad referencial y restricciones

## 📁 Contenido

### Archivos Incluidos

- `tarea3.html` - Documento principal con documentación completa
- `postgres_commands.sql` - Comandos SQL para PostgreSQL
- `README.md` - Este archivo

## 🛠️ Tecnologías Utilizadas

- **PostgreSQL 12+** - Sistema gestor de bases de datos
- **Linux (CentOS)** - Sistema operativo
- **Google Cloud Platform (GCP)** - Infraestructura en la nube
- **psql** - Cliente de línea de comandos para PostgreSQL

## 📝 Pasos de Instalación

### 1. Actualizar el Sistema
```bash
sudo yum update -y
```

### 2. Instalar Repositorio PostgreSQL
```bash
sudo yum install -y https://download.postgresql.org/pub/repos/yum/reporpms/EL-7-x86_64/pgdg-redhat-repo-latest.noarch.rpm
```

### 3. Instalar PostgreSQL
```bash
sudo yum install -y postgresql12-server postgresql12-contrib
```

### 4. Inicializar la Base de Datos
```bash
sudo /usr/pgsql-12/bin/postgresql-12-setup initdb
```

### 5. Iniciar el Servicio
```bash
sudo systemctl start postgresql-12
sudo systemctl enable postgresql-12
```

### 6. Verificar la Instalación
```bash
sudo -u postgres psql --version
```

## 👤 Crear Usuario PostgreSQL

```bash
# Cambiar a usuario postgres
sudo -u postgres psql

# En psql:
CREATE USER tuusuario WITH PASSWORD 'tucontraseña';
ALTER ROLE tuusuario WITH CREATEDB;
GRANT ALL PRIVILEGES ON DATABASE tubasedatos TO tuusuario;
\q
```

## 📊 Crear Tablas

```sql
-- Ver archivo postgres_commands.sql para todos los comandos
CREATE TABLE usuarios (
    id SERIAL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    fecha_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

## 🔄 Diferencias entre PostgreSQL y MariaDB

| Característica | PostgreSQL | MariaDB |
|---|---|---|
| Auto-increment | SERIAL | AUTO_INCREMENT |
| Booleano | BOOLEAN | TINYINT(1) |
| Identificador | SERIAL PRIMARY KEY | INT AUTO_INCREMENT PRIMARY KEY |
| Usuarios | CREATE ROLE / CREATE USER | CREATE USER |
| Vistas | CREATE VIEW | CREATE VIEW |
| Window Functions | Soportadas | Soporte limitado |

## 📚 Conceptos Clave Aprendidos

### DDL (Data Definition Language)
- CREATE TABLE: Crear tablas
- ALTER TABLE: Modificar estructura de tablas
- DROP TABLE: Eliminar tablas
- CREATE INDEX: Crear índices para optimización

### DML (Data Manipulation Language)
- INSERT: Insertar datos
- UPDATE: Actualizar datos
- DELETE: Eliminar datos
- SELECT: Consultar datos

### Integridad Referencial
- PRIMARY KEY: Clave primaria única
- FOREIGN KEY: Referencias entre tablas
- ON DELETE CASCADE: Eliminar datos relacionados automáticamente
- CHECK: Restricciones de validación

## 💾 Backup y Restore

```bash
# Realizar backup
sudo -u postgres pg_dump -U postgres mibasedatos > backup.sql

# Restaurar backup
sudo -u postgres psql -U postgres mibasedatos < backup.sql
```

## 🔍 Consultas Útiles

```sql
-- Ver todas las tablas
\dt

-- Ver estructura de tabla
\d nombre_tabla

-- Ver usuarios
\du

-- Ver bases de datos
\l

-- Conectar a otra base de datos
\c nombre_basedatos
```

## 📈 Resultados Obtenidos

- ✅ PostgreSQL instalado y ejecutándose
- ✅ Usuarios creados con permisos específicos
- ✅ 4 tablas creadas (usuarios, productos, ordenes, detalle_ordenes)
- ✅ Integridad referencial implementada
- ✅ Índices creados para optimización
- ✅ 2 vistas creadas para consultas complejas
- ✅ Datos de prueba insertados

## 🎓 Aprendizajes Principales

1. **Instalación en Linux**: Usar gestores de paquetes para instalar software
2. **Configuración de Servicios**: Habilitación automática con systemctl
3. **Gestión de Usuarios**: Control de acceso y permisos en bases de datos
4. **Diseño Relacional**: Creación de esquemas con integridad referencial
5. **SQL Avanzado**: Consultas con JOINs, GROUP BY y subconsultas

## ⚠️ Desafíos Encontrados

- La configuración inicial de PostgreSQL requería permisos de root
- Las diferencias sintácticas entre PostgreSQL y MariaDB requirieron adaptación
- La configuración de conexiones remotas requería modificar pg_hba.conf

## 🚀 Mejoras Futuras

- Implementar replicación PostgreSQL para alta disponibilidad
- Configurar backups automáticos con pg_dump y cron
- Explorar características avanzadas (Window Functions, CTEs, JSON)
- Implementar particionamiento de tablas para mejor rendimiento
- Usar ORM (Object Relational Mapping) como SQLAlchemy

## 📞 Contacto

Para más información sobre PostgreSQL:
- [Documentación Oficial](https://www.postgresql.org/docs/)
- [Tutorial PostgreSQL](https://www.postgresql.org/docs/current/tutorial.html)

---

**Fecha**: 30 de Enero, 2026  
**Estado**: ✅ Completado
