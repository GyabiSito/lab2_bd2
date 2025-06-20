#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include "db.h"

int obtenerDiasDelMes(int mes, int anio);
void imprimirMeses();

bool esCedulaValida(const char *cedula);
bool esMesValido(int mes);
bool esDiaValido(int dia, int mes, int anio);
bool esAnioValido(int anio);
bool esNumeroValido(const char *input);
bool esNombreValido(const char *nombre);
bool esNumeroValidoTarjeta(const char *input);
bool esCorreoValido(const char *correo);
bool esTarjetaVencida(const char *fecha_vencimiento);

int getMesActual();
int getDiaActual();

void obtener_fecha_hora_actual(char *fecha, char *fecha_hora);
void clearConsole();

#endif
