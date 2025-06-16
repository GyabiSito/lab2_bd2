#pragma once
#ifndef DB_H
#define DB_H
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "constants.h"

DBSingleton *getInstance();
void cerrar_conexion();
bool validarCapacidadParque(int id_parque, int mes, int dia, int cantidad);
bool validarCapacidadParking(int id_parque, int mes, int dia, int cantidad);
bool existeCiVisitante(const char *cedula);

// int getTotalPasesVisitante(int id_visitante, int mes, int dia);
// void imprimirPasesVisitante(int id_visitante);

void imprimirPasesVisitantePorFecha(int id_visitante, int mes, int dia);
long getMontoTotal(int anio, int mes);
int getTotalReservasParque(int id_parque, int mes, int dia);
VISITANTE getVisitante(const char *cedula);
PARQUE getParque(int id_parque);
PARKING getParking(int id_parque);

#endif