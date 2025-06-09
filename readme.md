# Dependencias (opcional)
Dentro del contenedor, instala las dependencias necesarias (si no están instaladas):

Ya deberian de estar instaladas debido al Dockerfile
```bash
apt update
apt upgrade
apt-get install -y postgresql-contrib build-essential libecpg-dev
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
docker exec -it c_app /bin/bash
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
gcc -I/usr/include/postgresql -o main main.c -lecpg
```

> **Nota:** Cuando tengamos más archivos, será recomendable crear un `Makefile` para facilitar la compilación.

