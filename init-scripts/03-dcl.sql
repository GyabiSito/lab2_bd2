-- Roles
CREATE ROLE administrador WITH LOGIN PASSWORD 'admin';
CREATE ROLE vendedor WITH LOGIN PASSWORD 'vendedor';
CREATE ROLE cliente WITH LOGIN PASSWORD 'cliente';
CREATE ROLE visitante WITH LOGIN PASSWORD 'visitante';

-- Limpieza general
REVOKE ALL ON ALL TABLES IN SCHEMA public FROM PUBLIC;

-- PARQUES
GRANT ALL ON parques TO administrador;
GRANT SELECT ON parques TO vendedor, visitante;

-- UBICACIONES
GRANT ALL ON ubicaciones TO administrador;
GRANT SELECT ON ubicaciones TO vendedor, visitante;

-- PARKINGS
GRANT ALL ON parkings TO administrador;
GRANT SELECT ON parkings TO vendedor;

-- ATRACCIONES
GRANT ALL ON atracciones TO administrador;
GRANT SELECT ON atracciones TO vendedor, visitante;

-- PASES
GRANT ALL ON pases TO administrador, vendedor;
GRANT SELECT ON pases TO visitante;

-- PASES_PARQUES
GRANT ALL ON pases_parques TO administrador, vendedor;
GRANT SELECT ON pases_parques TO visitante;

-- PRECIOS
GRANT ALL ON precios TO administrador;
GRANT SELECT ON precios TO vendedor;

-- CLIENTES
GRANT ALL ON clientes TO administrador;
GRANT SELECT ON clientes TO vendedor;
GRANT INSERT, UPDATE ON clientes TO cliente; -- Asegurar que sea solo con su mismo id_cliente, no con otros

-- VISITANTES
GRANT ALL ON visitantes TO administrador;
GRANT SELECT ON visitantes TO vendedor;
GRANT INSERT, UPDATE ON visitantes TO visitante; -- Asegurar que sea solo con su mismo id_visitante, no con otroas

-- COMPRA
GRANT SELECT,INSERT ON compras TO administrador;
GRANT INSERT ON compras TO cliente;
GRANT SELECT ON compras TO vendedor;

-- ACCEDEN
GRANT ALL ON acceden TO administrador;
GRANT SELECT ON acceden TO visitante;

-- USAN
GRANT ALL ON usan TO administrador;
GRANT SELECT ON usan TO visitante;



--EJERCICIO QUERY 8
-- -- Crear usuario gerente con permisos totales sobre todas las tablas y vistas del parque
-- CREATE USER gerente WITH PASSWORD 'gerente';


-- GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO gerente;


-- -- Crear usuario contador con acceso solo a la vista materializada
-- CREATE USER contador WITH PASSWORD 'contador';


-- GRANT SELECT ON vista_entradas_2024 TO contador;


-- -- Crear usuario operador con acceso a datos de entradas vendidas y clientes
-- CREATE USER operador WITH PASSWORD 'operador';


-- -- Entradas = tabla pase, y compra
-- GRANT SELECT, INSERT, UPDATE ON pase TO operador;
-- GRANT SELECT, INSERT, UPDATE ON compra TO operador;


-- -- Datos de los clientes
-- GRANT SELECT, INSERT, UPDATE ON cliente TO operador;

-- --FIN EJERCICIO QUERY 8