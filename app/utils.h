#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "db.h"

int obtenerDiasDelMes(int mes, int anio);
void imprimirMeses();
bool esCedulaValida(const char *cedula);
bool esMesValido(int mes);
bool esDiaValido(int dia, int mes, int anio);
bool esAnioValido(int anio);
char* esNumeroValido(char *input);
bool esNombreValido(const char *nombre);
char* esNumeroValidoTarjeta(char *input);
void clearConsole();
void obtener_fecha_hora_actual(char *fecha, char *fecha_hora);
#endif
