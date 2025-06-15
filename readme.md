# Dependencias (opcional)
Dentro del contenedor, instala las dependencias necesarias (si no están instaladas):

Ya deberian de estar instaladas debido al Dockerfile
```bash
apt-get update && apt-get install -y libecpg-dev postgresql-client postgresql-contrib build-essential vim net-tools iputils-ping
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

## Compilar y Ejecutar Código en C

Estos comandos están automatizados en el script `./compilar.sh`.
Compila el archivo fuente `.pgc` y el programa principal:
```bash
ecpg main.pgc
gcc -I/usr/include/postgresql main.c db_singleton.c -lecpg -o programa
```

> **Nota:** Cuando tengamos más archivos, será recomendable crear un `Makefile` para facilitar la compilación.


Visitantes 100 pases 55448877
/*

INICIAR VENTA

REPETIR
    MOSTRAR PARQUES DISPONIBLES
    INGRESAR ID_PARQUE
    INGRESAR FECHA

    INGRESAR CANTIDAD_ENTRADAS
    VALIDAR CAPACIDAD PARQUE

    SI CAPACIDAD_OK
        PREGUNTAR: ¿DESEA PARKING? (S/N)
        SI SÍ:
            INGRESAR CANTIDAD_VEHICULOS
            VALIDAR CAPACIDAD ESTACIONAMIENTO
        SINO:
            CANTIDAD_VEHICULOS = 0

        INGRESAR DATOS VISITANTES (NOMBRE, CÉDULA) x CANTIDAD_ENTRADAS

        CALCULAR PRECIO TOTAL (entradas + parking)
        MOSTRAR RESUMEN
        PREGUNTAR CONFIRMACIÓN

        SI CONFIRMADO
            INGRESAR DATOS TARJETA
            INSERTAR EN BASE DE DATOS
            MOSTRAR CÓDIGOS QR
        FIN SI
    SINO
        MOSTRAR "SIN CUPOS"
    FIN SI

    PREGUNTAR: ¿DESEA INGRESAR OTRA VENTA?
HASTA QUE RESPUESTA SEA "NO"

VOLVER A MENÚ


*/