#!/bin/bash
set -e

ecpg main.pgc;
#Esperar a que se genere el archivo main.c
while [ ! -f main.c ]; do
  sleep 1
  echo "Esperando a que se genere main.c..."
done
gcc -I/usr/include/postgresql -o main main.c -lecpg;
echo "Compilado"