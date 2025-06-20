CREATE OR REPLACE FUNCTION validar_capacidad_parque(
    id_parque_param INT,
    fecha_acceso_param DATE,
    cantidad_entradas_param INT
) RETURNS BOOLEAN AS $$
DECLARE
    capacidad_maxima INT;
    total_reservado INT;
BEGIN
    SELECT p.capacidad_maxima_diaria
    INTO capacidad_maxima
    FROM parques p
    WHERE p.id_parque = id_parque_param;

    IF NOT FOUND THEN
        RAISE EXCEPTION 'Parque % no encontrado.', id_parque_param;
    END IF;

    SELECT COUNT(*)
    INTO total_reservado
    FROM pases_parques
    WHERE id_parque = id_parque_param AND fecha_acceso = fecha_acceso_param;

    IF total_reservado + cantidad_entradas_param > capacidad_maxima THEN
        RETURN FALSE;
    END IF;

    RETURN TRUE;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION trigger_validar_capacidad()
RETURNS TRIGGER AS $$
BEGIN
    IF NOT validar_capacidad_parque(NEW.id_parque, NEW.fecha_acceso, 1) THEN
        RAISE EXCEPTION 'No hay capacidad disponible para el parque % en la fecha %.',
            NEW.id_parque, NEW.fecha_acceso;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

DROP TRIGGER IF EXISTS trg_validar_capacidad_parque ON pases_parques;

CREATE TRIGGER trg_validar_capacidad_parque
BEFORE INSERT ON pases_parques
FOR EACH ROW
EXECUTE FUNCTION trigger_validar_capacidad();


--*****************************************************************************VALIDAR CAPACIDAD PARKING *****************************************************************************
-- CREATE OR REPLACE FUNCTION validar_capacidad_parking(
--     p_id_parque INT,
--     p_fecha DATE,
--     p_cantidad INT
-- ) RETURNS BOOLEAN AS $$
-- DECLARE
--     total_actual INT;
--     limite INT;
-- BEGIN
--     -- Obtener el límite de vehículos del parking asociado al parque
--     SELECT p.limite_vehiculos INTO limite
--     FROM parkings p
--     WHERE p.id_parque = p_id_parque;

--     IF NOT FOUND THEN
--         RAISE EXCEPTION 'Parking no encontrado para parque %', p_id_parque;
--     END IF;

--     -- Contar la cantidad de pases_parques con parking ya reservados en esa fecha
--     SELECT COUNT(*) INTO total_actual
--     FROM pases_parques pp
--     WHERE pp.id_parque = p_id_parque
--       AND pp.incluye_parking = TRUE
--       AND pp.fecha_acceso = p_fecha;

--     RETURN (total_actual + p_cantidad) <= limite;
-- END;
-- $$ LANGUAGE plpgsql;


-- CREATE OR REPLACE FUNCTION trg_validar_capacidad_parking()
-- RETURNS TRIGGER AS $$
-- BEGIN
--     IF NEW.incluye_parking THEN
--         IF NOT validar_capacidad_parking(NEW.id_parque, NEW.fecha_acceso, 1) THEN
--             RAISE EXCEPTION 'Capacidad de parking excedida para el parque % en la fecha %', NEW.id_parque, NEW.fecha_acceso;
--         END IF;
--     END IF;
--     RETURN NEW;
-- END;
-- $$ LANGUAGE plpgsql;

-- CREATE TRIGGER trigger_check_capacidad_parking
-- BEFORE INSERT ON pases_parques
-- FOR EACH ROW
-- EXECUTE FUNCTION trg_validar_capacidad_parking();

CREATE OR REPLACE FUNCTION validar_limite_vehiculos()
RETURNS TRIGGER AS $$
DECLARE
    limite INTEGER;
    total_vehiculos_reservados INTEGER;
BEGIN
    -- Solo validar si el pase incluye parking
    IF NEW.incluye_parking THEN
        -- Obtener el límite de vehículos del parque
        SELECT limite_vehiculos INTO limite
        FROM parkings
        WHERE id_parque = NEW.id_parque;

        IF limite IS NULL THEN
            RAISE EXCEPTION 'No se encontró límite de vehículos para el parque %', NEW.id_parque;
        END IF;

        -- Sumar los vehículos ya reservados en otras compras para esa fecha y parque
        SELECT COALESCE(SUM(c.cant_vehiculos), 0) INTO total_vehiculos_reservados
        FROM compras c
        JOIN pases p ON c.id_compra = p.id_compra
        JOIN pases_parques pp ON p.id_pase = pp.id_pase
        WHERE pp.id_parque = NEW.id_parque
          AND pp.fecha_acceso = NEW.fecha_acceso
          AND pp.incluye_parking = TRUE;

        -- IMPORTANTE: La compra actual aún no está registrada en la tabla, por eso se suma aparte desde el backend (o puede traerse también si es UPDATE)

        IF total_vehiculos_reservados >= limite THEN
            RAISE EXCEPTION 'Capacidad de vehículos alcanzada para el parque % en la fecha % (reservados: %, límite: %)',
                NEW.id_parque, NEW.fecha_acceso, total_vehiculos_reservados, limite;
        END IF;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_validar_limite_vehiculos
BEFORE INSERT ON pases_parques
FOR EACH ROW
EXECUTE FUNCTION validar_limite_vehiculos();
