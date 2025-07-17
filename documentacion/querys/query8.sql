-- Crear usuario gerente con permisos totales sobre todas las tablas y vistas del parque
CREATE USER gerente WITH PASSWORD 'gerente';


GRANT ALL PRIVILEGES ON ALL TABLES IN SCHEMA public TO gerente;

-- Crear usuario contador con acceso solo a la vista materializada
CREATE USER contador WITH PASSWORD 'contador';


GRANT SELECT ON vista_ingresos_2024 TO contador;


-- Crear usuario operador con acceso a datos de entradas vendidas y clientes
CREATE USER operador WITH PASSWORD 'operador';


-- Entradas = tabla pase, y compra
GRANT SELECT, INSERT, UPDATE ON pases TO operador;
GRANT SELECT, INSERT, UPDATE ON pases_parques TO operador;
GRANT SELECT, INSERT, UPDATE ON compras TO operador;


-- Datos de los clientes
GRANT SELECT, INSERT, UPDATE ON clientes TO operador;
