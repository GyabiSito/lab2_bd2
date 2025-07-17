CREATE TABLE parques (
    id_parque SERIAL NOT NULL, -- PK
    id_ubicacion INT NOT NULL, -- FK a ubicacion
    nombre VARCHAR(50) NOT NULL,
    capacidad_maxima_diaria INT NOT NULL
    -- ciudad VARCHAR(50) NOT NULL,
    -- ocupantes INT NOT NULL,
    -- vehiculos_estacionados INT NOT NULL
);


CREATE TABLE parkings(
    id_parking SERIAL NOT NULL, -- PK
    id_parque INT NOT NULL, -- FK a parque
    limite_vehiculos INT NOT NULL,
    costo_adicional INT NOT NULL
);
CREATE TABLE ubicaciones(
    id_ubicacion SERIAL NOT NULL, -- PK
    nombre VARCHAR(50) NOT NULL
);
CREATE TABLE atracciones(
    id_atraccion SERIAL, -- PK
    id_parque INT NOT NULL, -- FK a parque
    nombre VARCHAR(50) NOT NULL,
    descripcion VARCHAR(255) NOT NULL
);
CREATE TABLE usan(
    id_uso SERIAL NOT NULL, -- PK
    id_pase INT NOT NULL, -- FK a pase
    id_atraccion INT NOT NULL, -- FK a atracciones
    fecha_usa DATE NOT NULL,
    hora_usa TIMESTAMP NOT NULL,
    foto VARCHAR(255) NOT NULL
);

CREATE TABLE acceden(
    id_accede SERIAL NOT NULL, -- PK
    id_pase_parque INT NOT NULL, -- FK a pase_parque
    id_parque INT NOT NULL, -- FK a parque
    fecha_accede DATE NOT NULL,
    hora_accede TIMESTAMP NOT NULL,
    entrada_salida CHAR(1) NOT NULL
);
CREATE TABLE pases(
    id_pase SERIAL NOT NULL, -- PK
    -- id_precio INT NOT NULL, -- FK a precio
    -- id_parque INT NOT NULL, -- FK a parque
    id_visitante INT NOT NULL, -- FK a visitante
    id_compra INT NOT NULL, -- FK a compra
    precio_total INT NOT NULL,
    -- id_pase_fecha_acceso INT NOT NULL, -- FK a pase_fecha_acceso
    -- id_pase_parque INT NOT NULL, -- FK a pase_parque
    -- incluye_parking BOOLEAN NOT NULL,
    codigo_qr VARCHAR(255) NOT NULL
);
CREATE TABLE pases_parques (
    id_pase_parque SERIAL,
    id_pase INT NOT NULL, -- FK a pase
    id_parque INT NOT NULL, -- FK a parque
    id_precio INT NOT NULL, -- FK a precio
    incluye_parking BOOLEAN NOT NULL DEFAULT FALSE,
    fecha_acceso DATE NOT NULL
);

-- CREATE TABLE pase_fecha_acceso (
--     id SERIAL,
--     id_pase INT NOT NULL, -- FK a pase
-- );

CREATE TABLE precios(
    id_precio SERIAL NOT NULL, -- PK
    id_parque INT NOT NULL, -- FK a parque
    precio INT NOT NULL,
    fecha_inicio DATE NOT NULL,
    fecha_fin DATE NOT NULL
);
CREATE TABLE visitantes(
    id_visitante SERIAL NOT NULL, -- PK
--    id_pase INT, -- FK a pase -- Al estar en la tabla pase no es necesario en visitante
    ci CHAR(8) NOT NULL, -- UNIQUE
    nombre VARCHAR(50) NOT NULL
);
CREATE TABLE compras (
    id_compra INT NOT NULL, -- PK
    -- id_pase INT NOT NULL, -- FK a pase
    id_cliente INT NOT NULL, -- FK a cliente
    fecha_compra DATE NOT NULL,
    hora_compra TIMESTAMP NOT NULL,
    monto_total INT NOT NULL,
    cant_pases INT NOT NULL,
    cant_vehiculos INT NOT NULL,
    debito_credito CHAR(1) NOT NULL, -- Debito o Credito | "D" o "C". Podemos cambiarlo a BOOL
    numero_tarjeta CHAR(16) NOT NULL,
    fecha_vencimiento DATE NOT NULL,
    cvv CHAR(3) NOT NULL
);
CREATE TABLE clientes(
    id_cliente SERIAL NOT NULL,
    email VARCHAR(50) NOT NULL, -- Aca no seria unique porque se puede repetir el cliente
    nombre VARCHAR(50) NOT NULL,
    ci CHAR(8) NOT NULL
);