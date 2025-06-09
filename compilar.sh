#!/bin/bash
set -e;
ecpg main.pgc;
while [ ! -f main.c ]; do
	sleep 1;
	echo "Esperando a que se genere main.c...";
done;
gcc -I/usr/include/postgresql -o main main.c -lecpg;
echo "Compilado";
