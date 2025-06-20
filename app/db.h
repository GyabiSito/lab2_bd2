#pragma once
#ifndef DB_H
#define DB_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"
#include "constants.h"
#include "utils.h"

DBSingleton *getInstance();
void cerrar_conexion();

void imprimirPasesVisitantePorFecha(int id_visitante, int mes, int dia);
bool validarCapacidadParque(PARQUE parque, int mes, int dia, int cantidad);
bool validarCapacidadParking(PARQUE parque, int mes, int dia, int cantidad);

// int getTotalPasesVisitante(int id_visitante, int mes, int dia);
// void imprimirPasesVisitante(int id_visitante);

long getMontoTotal(int anio, int mes);
int getTotalReservasParque(int id_parque, int mes, int dia);
int getTotalReservasParking(int id_parque, int id_parking, int mes, int dia);
int getMaxIdVisitante();
int getMaxIdCompra();
int getMaxIdCliente();
int getMaxIdPase();
int getMaxIdPaseParque();



VISITANTE getVisitante(const char *cedula);
VISITANTE crearVisitante(const char *cedula, const char *nombre);
PARQUE getParque(int id_parque);
PARQUE *getParquesDisponibles();
PARKING getParking(int id_parque);
CLIENTE getCliente(const char *ci_cliente);
PRECIO getPrecio(int id_parque, const char* fecha_acceso);


bool existeCliente(const char *ci_cliente);
bool existePaseVisitante(int id_visitante, int mes, int dia);
bool existeCiVisitante(const char *cedula);


COMPRA insertarCompra(COMPRA compra);
PASE insertarPase(PASE pase);
PASE_PARQUE insertarPaseParque(PASE_PARQUE pase_parque);
CLIENTE insertarCliente(CLIENTE cliente);
#endif