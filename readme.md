# Dependencias (opcional)
Dentro del contenedor, instala las dependencias necesarias (si no están instaladas):

Ya deberian de estar instaladas debido al Dockerfile
```bash
apt-get update && apt-get install -y libecpg-dev postgresql-client postgresql-contrib build-essential vim net-tools iputils-ping make
```

# Levantar los Contenedores

Para iniciar los contenedores, ejecuta:

```bash
docker-compose up --build -d
```

---

## Acceder al Contenedor

Para acceder a la terminal del contenedor de la aplicación C:

```bash
docker exec -it contenedor-postgres /bin/bash
```

O para cualquier contenedor, usa:

```bash
docker exec -it <nombre_del_contenedor> bash
```

Dentro del contenedor puedes administrar PostgreSQL o instalar dependencias adicionales según sea necesario.

---

## Obtener la IP del Contenedor

Para obtener la IP del contenedor de PostgreSQL:

```bash
docker inspect -f '{{range.NetworkSettings.Networks}}{{.IPAddress}}{{end}}' contenedor-postgres
```

Utiliza la IP obtenida para conectarte desde pgAdmin en tu navegador.

---

# Compilar y Ejecutar Código en C

Estos comandos están automatizados en el script `./compilar.sh`.
Compila el archivo fuente `.pgc` y el programa principal:
```bash
ecpg main.pgc
gcc -I/usr/include/postgresql main.c db_singleton.c -lecpg -o programa
```
# Triggers

## Validar Capacidad Parque
```sql
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
```

## Validar Capacidad Parking

```sql
CREATE OR REPLACE FUNCTION validar_capacidad_parking(
    p_id_parque INT,
    p_fecha DATE,
    p_cantidad INT
) RETURNS BOOLEAN AS $$
DECLARE
    total_actual INT;
    limite INT;
BEGIN
    -- Obtener el límite de vehículos del parking asociado al parque
    SELECT p.limite_vehiculos INTO limite
    FROM parkings p
    WHERE p.id_parque = p_id_parque;

    IF NOT FOUND THEN
        RAISE EXCEPTION 'Parking no encontrado para parque %', p_id_parque;
    END IF;

    -- Contar la cantidad de pases_parques con parking ya reservados en esa fecha
    SELECT COUNT(*) INTO total_actual
    FROM pases_parques pp
    WHERE pp.id_parque = p_id_parque
      AND pp.incluye_parking = TRUE
      AND pp.fecha_acceso = p_fecha;

    RETURN (total_actual + p_cantidad) <= limite;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION trg_validar_capacidad_parking()
RETURNS TRIGGER AS $$
BEGIN
    IF NEW.incluye_parking THEN
        IF NOT validar_capacidad_parking(NEW.id_parque, NEW.fecha_acceso, 1) THEN
            RAISE EXCEPTION 'Capacidad de parking excedida para el parque % en la fecha %', NEW.id_parque, NEW.fecha_acceso;
        END IF;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_check_capacidad_parking
BEFORE INSERT ON pases_parques
FOR EACH ROW
EXECUTE FUNCTION trg_validar_capacidad_parking();


```

VALIDAR LAS FECHAS
HACER FUNCION EN SQL QUE VALIDE LAS FECHAS AL MOMENTO DE INSERTAR ( NO PUEDO INSERTAR FECHAS DEL PASADO )


