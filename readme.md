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



CREATE OR REPLACE TRIGGER trg_validar_capacidad_parque
BEFORE INSERT ON pases_parques
FOR EACH ROW
EXECUTE FUNCTION trigger_validar_capacidad();
```

## Validar Capacidad Parking

```sql
CREATE OR REPLACE FUNCTION validar_limite_vehiculos()
RETURNS TRIGGER AS $$
DECLARE
    limite INTEGER;
    total_vehiculos_reservados INTEGER;
    vehiculos_a_insertar INTEGER;
    compra_ya_contada BOOLEAN;
BEGIN
    IF NEW.incluye_parking THEN
        SELECT limite_vehiculos INTO limite
        FROM parkings
        WHERE id_parque = NEW.id_parque;

        IF limite IS NULL THEN
            RAISE EXCEPTION 'No se encontró límite de vehículos para el parque %', NEW.id_parque;
        END IF;

        -- Verifico si la compra de este pase ya está contada en reservas previas
        SELECT EXISTS (
            SELECT 1
            FROM pases_parques pp
            JOIN pases p ON pp.id_pase = p.id_pase
            WHERE p.id_compra = (SELECT id_compra FROM pases WHERE id_pase = NEW.id_pase)
              AND pp.id_parque = NEW.id_parque
              AND pp.fecha_acceso = NEW.fecha_acceso
              AND pp.incluye_parking = TRUE
              AND NOT (pp.id_pase = NEW.id_pase) -- Excluyo el pase actual que estoy insertando
        ) INTO compra_ya_contada;

        -- Sumo vehículos de compras distintas ya contadas para la fecha y parque
        SELECT COALESCE(SUM(compras_unicas.cant_vehiculos), 0)
        INTO total_vehiculos_reservados
        FROM (
            SELECT DISTINCT c.id_compra, c.cant_vehiculos
            FROM compras c
            JOIN pases p ON c.id_compra = p.id_compra
            JOIN pases_parques pp ON p.id_pase = pp.id_pase
            WHERE pp.id_parque = NEW.id_parque
              AND pp.fecha_acceso = NEW.fecha_acceso
              AND pp.incluye_parking = TRUE
        ) AS compras_unicas;

        -- Obtengo cantidad de vehículos de la compra del pase actual
        SELECT c.cant_vehiculos INTO vehiculos_a_insertar
        FROM compras c
        JOIN pases p ON c.id_compra = p.id_compra
        WHERE p.id_pase = NEW.id_pase;

        -- Si la compra ya fue contada, no sumo vehículos a insertar
        IF compra_ya_contada THEN
            vehiculos_a_insertar := 0;
        END IF;

        IF total_vehiculos_reservados + vehiculos_a_insertar > limite THEN
            RAISE EXCEPTION 'Capacidad de vehículos alcanzada para el parque % en la fecha % (reservados: %, intenta añadir: %, límite: %)',
                NEW.id_parque, NEW.fecha_acceso, total_vehiculos_reservados, vehiculos_a_insertar, limite;
        END IF;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;




CREATE OR REPLACE TRIGGER trigger_validar_limite_vehiculos
BEFORE INSERT ON pases_parques
FOR EACH ROW
EXECUTE FUNCTION validar_limite_vehiculos();



```


