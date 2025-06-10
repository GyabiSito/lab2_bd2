#pragma once
#ifndef DB_H
#define DB_H
#include <stdlib.h>
#include <stdio.h>
#include "structs.h"


DBSingleton* getInstance();
void cerrar_conexion();


#endif