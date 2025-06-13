#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "db.h"

int obtenerDiasDelMes(int mes, int anio);
void imprimirMeses();
bool esCedulaValida(const char *cedula);
bool esMesValido(int mes);
#endif
