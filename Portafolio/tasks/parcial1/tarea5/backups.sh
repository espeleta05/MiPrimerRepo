#!/bin/bash
# Script de ejemplo para generar respaldos lógicos (MariaDB y PostgreSQL)

set -euo pipefail

# Crear estructura de carpetas
mkdir -p Backups/MariaDB Backups/Postgress

# --- MariaDB ---
# Exportar la base `Biblioteca` (reemplazar credenciales según entorno)
# mysqldump --user=USUARIO --password=CONTRASEÑA Biblioteca > Backups/MariaDB/respaldoBiblioteca.sql

# Ejemplo (sin credenciales en texto plano; usar .my.cnf o variable de entorno en producción):
if command -v mysqldump >/dev/null 2>&1; then
  echo "Generando respaldo MariaDB (si existe mysqldump)..."
  # Descomentar y ajustar la siguiente línea en entorno real
  # mysqldump --user=biblio_user --password='tu_password' Biblioteca > Backups/MariaDB/respaldoBiblioteca.sql
else
  echo "Aviso: mysqldump no está instalado o no está en PATH. Omitiendo MariaDB."
fi

# --- PostgreSQL ---
# Generar un dump de todo el clúster como usuario postgres
if command -v pg_dumpall >/dev/null 2>&1; then
  echo "Preparando respaldo PostgreSQL (pg_dumpall)..."
  # En un sistema real ejecutar como usuario postgres: sudo -u postgres pg_dumpall -f /tmp/respladoBiblioteca.sql
  # Luego copiar al backup y ajustar propiedad:
  # sudo cp /tmp/respladoBiblioteca.sql Backups/Postgress/
  # sudo chown $(whoami):$(whoami) Backups/Postgress/respladoBiblioteca.sql
else
  echo "Aviso: pg_dumpall no está instalado o no está en PATH. Omitiendo PostgreSQL."
fi

echo "Listado final de Backups:"
if command -v tree >/dev/null 2>&1; then
  tree Backups/
else
  ls -R Backups/
fi
