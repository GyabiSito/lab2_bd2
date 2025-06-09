
# Levantar los Contenedores

Para iniciar los contenedores, ejecuta:

```bash
docker-compose up --build -d
```

---

## Acceder al Contenedor

Para acceder a la terminal del contenedor, usa:

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

Dentro del contenedor, compila y ejecuta tu programa C con:

```bash
gcc -o menu main.c
./menu
```

> **Nota:** Cuando tengamos más archivos, será recomendable crear un `Makefile` para facilitar la compilación.

