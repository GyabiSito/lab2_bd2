-- Claves Primarias
ALTER TABLE parques
ADD CONSTRAINT pk_id_parque PRIMARY KEY (id_parque);

ALTER TABLE parkings
ADD CONSTRAINT pk_id_parking PRIMARY KEY (id_parking),
ADD CONSTRAINT unq_id_parque UNIQUE (id_parque); 

ALTER TABLE ubicaciones
ADD CONSTRAINT pk_id_ubicacion PRIMARY KEY (id_ubicacion);
ALTER TABLE atracciones
ADD CONSTRAINT pk_id_atraccion PRIMARY KEY (id_atraccion);

ALTER TABLE usan
ADD CONSTRAINT pk_id_uso PRIMARY KEY (id_uso);

ALTER TABLE acceden
ADD CONSTRAINT pk_id_accede PRIMARY KEY (id_accede);

ALTER TABLE pases
ADD CONSTRAINT pk_id_pase PRIMARY KEY (id_pase);

ALTER TABLE pases_parques
ADD CONSTRAINT pk_id_pase_parque PRIMARY KEY (id_pase_parque);

-- -- ALTER TABLE pase_fecha_acceso
-- -- ADD CONSTRAINT pk_id_pase_fecha_acceso PRIMARY KEY (id);

ALTER TABLE precios
ADD CONSTRAINT pk_id_precio PRIMARY KEY (id_precio);

ALTER TABLE visitantes
ADD CONSTRAINT pk_id_visitante PRIMARY KEY (id_visitante);

ALTER TABLE compras
ADD CONSTRAINT pk_id_compra PRIMARY KEY (id_compra);

ALTER TABLE clientes
ADD CONSTRAINT pk_id_cliente PRIMARY KEY (id_cliente);

ALTER TABLE cotizaciones
ADD CONSTRAINT pk_id_cotizacion PRIMARY KEY (id_cotizacion);



-- Claves foraneas

ALTER TABLE parkings
ADD CONSTRAINT fk_parking_parque FOREIGN KEY (id_parque) REFERENCES parques(id_parque);

ALTER TABLE atracciones
ADD CONSTRAINT fk_atracciones_parque FOREIGN KEY (id_parque) REFERENCES parques(id_parque);

ALTER TABLE usan
ADD CONSTRAINT fk_usa_pase FOREIGN KEY (id_pase) REFERENCES pases(id_pase),
ADD CONSTRAINT fk_usa_atraccion FOREIGN KEY (id_atraccion) REFERENCES atracciones(id_atraccion);

ALTER TABLE acceden
ADD CONSTRAINT fk_accede_pases_parques FOREIGN KEY (id_pase_parque) REFERENCES pases_parques(id_pase_parque),
ADD CONSTRAINT fk_accede_parque FOREIGN KEY (id_parque) REFERENCES parques(id_parque);

ALTER TABLE pases
ADD CONSTRAINT fk_pase_visitante FOREIGN KEY (id_visitante) REFERENCES visitantes(id_visitante),
ADD CONSTRAINT fk_pase_compra FOREIGN KEY (id_compra) REFERENCES compras(id_compra);
-- ADD CONSTRAINT fk_pase_precio FOREIGN KEY (id_precio) REFERENCES precio(id_precio),
-- ADD CONSTRAINT fk_pase_parque FOREIGN KEY (id_parque) REFERENCES parque(id_parque),
-- -- -- -- ADD CONSTRAINT fk_pase_pase_fecha_acceso FOREIGN KEY (id_pase_fecha_acceso) REFERENCES pase_fecha_acceso(id),
-- ADD CONSTRAINT fk_pase_pase_parque FOREIGN KEY (id_pase_parque) REFERENCES pase_parque(id);

ALTER TABLE pases_parques
ADD CONSTRAINT fk_pase_parque_pase FOREIGN KEY (id_pase) REFERENCES pases(id_pase),
ADD CONSTRAINT fk_pase_parque_parque FOREIGN KEY (id_parque) REFERENCES parques(id_parque),
ADD CONSTRAINT fk_pase_parque_precio FOREIGN KEY (id_precio) REFERENCES precios(id_precio);


-- -- ALTER TABLE pase_fecha_acceso
-- -- ADD CONSTRAINT fk_pase_fecha_acceso_pase FOREIGN KEY (id_pase) REFERENCES pase(id_pase);


ALTER TABLE parques
ADD CONSTRAINT fk_parque_ubicacion FOREIGN KEY (id_ubicacion) REFERENCES ubicaciones(id_ubicacion);

ALTER TABLE compras
-- ADD CONSTRAINT fk_compra_pase FOREIGN KEY (id_pase) REFERENCES pase(id_pase),
ADD CONSTRAINT fk_compra_cliente FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente);


ALTER TABLE precios
ADD CONSTRAINT fk_precio_parque FOREIGN KEY (id_parque) REFERENCES parques(id_parque);
-- Luego las restricciones check

ALTER TABLE parkings
ADD CONSTRAINT chk_limite_vehiculos CHECK (limite_vehiculos > 0);

ALTER TABLE acceden
ADD CONSTRAINT chk_entrada_salida CHECK (entrada_salida IN ('E', 'S'));
-- -- -- -- ADD CONSTRAINT chk_fecha CHECK (fecha_accede <= CURRENT_DATE), -- La fecha de acceso no puede ser mayor a la fecha actual
-- ADD CONSTRAINT chk_hora CHECK (hora_accede <= CURRENT_TIMESTAMP); -- La hora de acceso no puede ser mayor a la hora actual

ALTER TABLE precios
ADD CONSTRAINT chk_precio CHECK (precio > 0);
-- -- -- -- ADD CONSTRAINT chk_fecha_inicio_menor_fin CHECK (fecha_inicio <= fecha_fin), -- No puede haber una fecha de inicio mayor a la de fin 
-- -- -- ADD CONSTRAINT chk_fecha_inicio_mayor_hoy CHECK (fecha_inicio >= CURRENT_DATE), -- La fecha de inicio puede ser hoy o mañana, pero no ayer
-- -- -- ADD CONSTRAINT chk_fecha_fin CHECK (fecha_fin >= CURRENT_DATE); -- La fecha de fin puede ser hoy o mañana, pero no ayer

ALTER TABLE visitantes
ADD CONSTRAINT fk_visitante_ci UNIQUE (ci);

ALTER TABLE compras
ADD CONSTRAINT chk_debito_credito CHECK (debito_credito IN ('D', 'C')),
ADD CONSTRAINT chk_monto_total CHECK (monto_total > 0),
ADD CONSTRAINT chk_cant_pases CHECK (cant_pases > 0),
-- -- -- -- -- ADD CONSTRAINT chk_fecha_compra CHECK (fecha_compra <= CURRENT_DATE), -- La fecha de compra no puede ser mayor a la fecha actual
-- -- -- -- -- ADD CONSTRAINT chk_hora_compra CHECK (hora_compra <= CURRENT_TIMESTAMP), -- La hora de compra no puede ser mayor a la hora actual
ADD CONSTRAINT chk_cvv_length CHECK (LENGTH(cvv) = 3),
ADD CONSTRAINT chk_numero_tarjeta_length CHECK (LENGTH(numero_tarjeta) = 16),
-- -- -- -- ADD CONSTRAINT chk_fecha_vencimiento CHECK (fecha_vencimiento > CURRENT_DATE), -- La fecha de vencimiento debe ser mayor ESTRICTO a la fecha actual
ADD CONSTRAINT chk_cant_vehiculos CHECK (cant_vehiculos >= 0); -- La cantidad de vehiculos puede ser cero, pero no negativa


ALTER TABLE parques
ADD CONSTRAINT chk_capacidad CHECK (capacidad_maxima_diaria > 0);

ALTER TABLE clientes
ADD CONSTRAINT unique_cliente UNIQUE (ci);


ALTER TABLE pases
ADD CONSTRAINT chk_precio_total CHECK (precio_total > 0);

-- ALTER TABLE pases_parques
-- ADD CONSTRAINT unq_id_pase_parque UNIQUE (id_pase, id_parque, fecha_acceso);

ALTER TABLE cotizaciones
ADD CONSTRAINT chk_precio_cotizacion CHECK (precio > 0);