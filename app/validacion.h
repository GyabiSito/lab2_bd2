#pragma once
#ifndef VALIDACION_H
#define VALIDACION_H
#include <stdio.h>  


#include "db.h"
int validarCapacidadParque(int id_parque, char* fecha, int cantidad);
int validarCapacidadParking(int id_parque, char* fecha, int cantidad);

#endif
