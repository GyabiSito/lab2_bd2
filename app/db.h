#pragma once
#ifndef DB_H
#define DB_H
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"


DBSingleton* getInstance();
void cerrar_conexion();
int validarCapacidadParque(int id_parque, char* fecha, int cantidad);
int validarCapacidadParking(int id_parque, char* fecha, int cantidad);
bool existeCiVisitante(const char *cedula);

#endif