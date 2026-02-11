-- ============================================
-- TAREA 3: PostgreSQL en Google Cloud
-- Comandos DDL y DML para PostgreSQL
-- ============================================

-- Crear tabla de usuarios
CREATE TABLE usuarios (
    id SERIAL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    fecha_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    activo BOOLEAN DEFAULT TRUE
);

-- Crear tabla de productos
CREATE TABLE productos (
    id SERIAL PRIMARY KEY,
    nombre VARCHAR(150) NOT NULL,
    descripcion TEXT,
    precio DECIMAL(10, 2) NOT NULL,
    usuario_id INTEGER NOT NULL,
    fecha_creacion TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (usuario_id) REFERENCES usuarios(id) ON DELETE CASCADE
);

-- Crear tabla de órdenes
CREATE TABLE ordenes (
    id SERIAL PRIMARY KEY,
    usuario_id INTEGER NOT NULL,
    fecha_orden TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    total DECIMAL(10, 2) NOT NULL,
    estado VARCHAR(50) DEFAULT 'pendiente',
    FOREIGN KEY (usuario_id) REFERENCES usuarios(id) ON DELETE CASCADE
);

-- Crear tabla de detalles de órdenes
CREATE TABLE detalle_ordenes (
    id SERIAL PRIMARY KEY,
    orden_id INTEGER NOT NULL,
    producto_id INTEGER NOT NULL,
    cantidad INTEGER NOT NULL CHECK (cantidad > 0),
    precio_unitario DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (orden_id) REFERENCES ordenes(id) ON DELETE CASCADE,
    FOREIGN KEY (producto_id) REFERENCES productos(id) ON DELETE CASCADE
);

-- Crear índices para optimización
CREATE INDEX idx_usuarios_email ON usuarios(email);
CREATE INDEX idx_usuarios_activo ON usuarios(activo);
CREATE INDEX idx_productos_usuario ON productos(usuario_id);
CREATE INDEX idx_ordenes_usuario ON ordenes(usuario_id);
CREATE INDEX idx_detalle_ordenes_orden ON detalle_ordenes(orden_id);
CREATE INDEX idx_detalle_ordenes_producto ON detalle_ordenes(producto_id);

-- ============================================
-- INSERTAR DATOS DE PRUEBA
-- ============================================

INSERT INTO usuarios (nombre, email, activo) VALUES 
('Juan Pérez', 'juan.perez@example.com', TRUE),
('María García López', 'maria.garcia@example.com', TRUE),
('Carlos Rodríguez', 'carlos.rodriguez@example.com', TRUE),
('Ana Martínez', 'ana.martinez@example.com', FALSE);

INSERT INTO productos (nombre, descripcion, precio, usuario_id) VALUES 
('Laptop Dell XPS', 'Laptop de alta performance para desarrollo', 1200.00, 1),
('Mouse Logitech', 'Mouse inalámbrico ergonómico', 35.99, 1),
('Teclado Mecánico', 'Teclado mecánico RGB con switches Cherry', 150.00, 2),
('Monitor 4K', 'Monitor 4K 27 pulgadas', 450.00, 2),
('Webcam HD', 'Webcam 1080p con micrófono integrado', 89.99, 3);

INSERT INTO ordenes (usuario_id, total, estado) VALUES 
(1, 1235.99, 'completada'),
(2, 600.00, 'completada'),
(3, 89.99, 'pendiente'),
(1, 450.00, 'en progreso');

INSERT INTO detalle_ordenes (orden_id, producto_id, cantidad, precio_unitario) VALUES 
(1, 1, 1, 1200.00),
(1, 2, 1, 35.99),
(2, 3, 1, 150.00),
(2, 4, 1, 450.00),
(3, 5, 1, 89.99),
(4, 4, 1, 450.00);

-- ============================================
-- CONSULTAS COMPLEJAS
-- ============================================

-- Contar productos por usuario
SELECT u.nombre, COUNT(p.id) as cantidad_productos
FROM usuarios u
LEFT JOIN productos p ON u.id = p.usuario_id
GROUP BY u.id, u.nombre
ORDER BY cantidad_productos DESC;

-- Obtener órdenes con detalle
SELECT 
    o.id as orden_id,
    u.nombre as cliente,
    o.fecha_orden,
    COUNT(d.id) as cantidad_items,
    o.total,
    o.estado
FROM ordenes o
JOIN usuarios u ON o.usuario_id = u.id
LEFT JOIN detalle_ordenes d ON o.id = d.orden_id
GROUP BY o.id, u.nombre, o.fecha_orden, o.total, o.estado
ORDER BY o.fecha_orden DESC;

-- Productos con mayor valor
SELECT 
    p.nombre,
    u.nombre as vendedor,
    p.precio,
    COUNT(d.id) as veces_vendido
FROM productos p
LEFT JOIN usuarios u ON p.usuario_id = u.id
LEFT JOIN detalle_ordenes d ON p.id = d.producto_id
GROUP BY p.id, p.nombre, u.nombre, p.precio
ORDER BY p.precio DESC;

-- ============================================
-- VISTAS ÚTILES
-- ============================================

-- Vista de resumen de usuarios activos
CREATE VIEW usuarios_activos_resumen AS
SELECT 
    u.id,
    u.nombre,
    u.email,
    COUNT(DISTINCT p.id) as productos_creados,
    COUNT(DISTINCT o.id) as ordenes_realizadas,
    COALESCE(SUM(o.total), 0) as total_gastado
FROM usuarios u
LEFT JOIN productos p ON u.id = p.usuario_id
LEFT JOIN ordenes o ON u.id = o.usuario_id
WHERE u.activo = TRUE
GROUP BY u.id, u.nombre, u.email;

-- Vista de estado de órdenes
CREATE VIEW estado_ordenes AS
SELECT 
    estado,
    COUNT(*) as total_ordenes,
    SUM(total) as monto_total,
    AVG(total) as promedio_orden
FROM ordenes
GROUP BY estado;
