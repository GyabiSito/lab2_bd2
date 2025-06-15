#pragma once
#ifndef DB_H
#define DB_H
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "constants.h"

DBSingleton *getInstance();
void cerrar_conexion();
int validarCapacidadParque(int id_parque, char *fecha, int cantidad);
int validarCapacidadParking(int id_parque, char *fecha, int cantidad);
bool existeCiVisitante(const char *cedula);

// int getTotalPasesVisitante(int id_visitante, int mes, int dia);
// void imprimirPasesVisitante(int id_visitante);

void imprimirPasesVisitantePorFecha(int id_visitante, int mes, int dia);
VISITANTE getVisitante(const char *cedula);

#endif