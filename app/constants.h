#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

//********** BASE DE DATOS *****************/
#define DB_NAME "lab02"
#define DB_IP "127.0.0.1"
#define DB_PORT "5432"
#define DB_USER "usuario"
#define DB_PASSWORD NULL  // Aquí tu contraseña sin "WITH PASSWORD" ni apóstrofes problemáticos
#define DB_CONECTADO 1
#define DB_DESCONECTADO 0
//********** FIN BASE DE DATOS *****************/

//********** CODIGOS SQL *****************/
#define SQL_SUCCESS 0
#define SQL_NO_DATA_FOUND 100
//********** FIN CODIGOS SQL *****************/

//********** MIS CONSTANTES *****************/
#define ANIO_2025 2025
#define MIN_ANIO 1900
#define MAX_ANIO 9999
#define MIN_MES 1
#define MAX_MES 12
#define MIN_DIA 1
//********** FIN MIS CONSTANTES *****************/

//********** ERRORES *****************/
// (Puedes agregar aquí tus códigos de error personalizados)
//********** FIN ERRORES *****************/

//********** STRUCTS *****************/
#define ERROR_SIGNAL -1
//********** FIN STRUCTS *****************/

//********** LONGITUDES MAXIMAS *****************/
#define MAX_NOMBRE_LENGTH 100
#define MAX_FECHA_LENGTH 11
#define MAX_HORA_LENGTH 6
#define MAX_LENGTH 255
#define MAX_BOOL_LENGTH 1
#define MAX_CI_LENGTH 8
#define MAX_N_TARJETA_LENGTH 20
#define MAX_FECHA_VENCIMIENTO_LENGTH 8
#define MAX_CVV_LENGTH 5
//********** FIN LONGITUDES MAXIMAS *****************/

//*********** MENU ********************/
#define MENU_SELECCIONAR_OPCION "Seleccione una opcion:\n"
#define MENU_REALIZAR_VENTA "1. Realizar venta\n"
#define MENU_VALIDAR_ENTRADAS "2. Validar entradas\n"
#define MENU_TOTAL_RECAUDADO_MES_ANIO "3. Total recaudado por mes y año\n"
#define MENU_SALIR "0. Salir\n"
//*********** FIN MENU ********************/

//********** CHARS *****************/
#define CHAR_DB_CONECTANDO "Conectando a la base de datos con la cadena: %s\n"
#define CHAR_DB_ERROR "Error conectando a la base de datos: %ld\n"
#define CHAR_DB_EXITOSO "Conexión exitosa a la base de datos.\n"
#define CHAR_DB_DESCONECTANDO "Desconectando de la base de datos...\n"
#define CHAR_OPCION_INVALIDA "Opción inválida. Por favor, ingrese un número válido.\n"
#define CHAR_INGRESE_DIA "Ingrese un dia entre 1 y %d: \n"
#define CHAR_INGRESE_MES "Ingrese el mes (1-12):\n"
#define CHAR_INGRESE_ANIO "Ingrese año \n"
#define CHAR_INGRESE_CEDULA "Ingrese la cédula del visitante (8 dígitos):\n"
#define CHAR_INGRESE_ID_PARQUE "Ingrese el ID del parque (1-4):\n"
#define CHAR_INGRESE_FECHA "Ingrese la fecha (YYYY-MM-DD):\n"
#define CHAR_VISITANTE_ENCONTRADO "Visitante encontrado: %s (ID: %d)\n"
#define CHAR_INGRESE_CANTIDAD_ENTRADAS "Ingrese la cantidad de entradas:\n"
#define CHAR_INGRESE_CANTIDAD_VEHICULOS "Ingrese la cantidad de vehículos:\n"
#define CHAR_CEDULA_VALIDA "Cédula válida. Procediendo con la validación...\n"
#define CHAR_DESEA_PARKING "¿Desea parking? (S/N):\n"
#define CHAR_NO_ESPACIOS_PARQUE "No hay espacio disponible para el parque %d en el mes %d, el dia %d.\n"
#define CHAR_NO_ESPACIOS_PARKING "No hay espacio de parking disponible para el parque %d en la fecha %s.\n"
#define CHAR_DESCONECTANDO "Cerrando cursores y desconectando...\n"
#define CHAR_NO_MAS_PARQUES_DISPONIBLES "No hay más parques disponibles.\n"
#define CHAR_MONTO_TOTAL "El total es %ld\n"
#define CHAR_IMPRIMIR_ASTERISCO "***************\n"
//********** FIN CHARS *****************/

//********** ERRORES DE ENTRADA *****************/
#define ERROR_CEDULA_INVALIDA "Error: La cédula debe tener exactamente 8 dígitos y solo contener números.\n"
#define ERROR_MES_INVALIDO "Error: El mes debe estar entre %d y %d.\n"
#define ERROR_DIA_INVALIDO "Error: El día debe estar entre 1 y %d para el mes %d.\n"
#define ERROR_LETRAS "Error: El input contiene letras. Solo se permiten caracteres numéricos.\n"
#define ERROR_INEXISTENTE_CI "Error: La cédula ingresada no existe en la base de datos.\n"
#define ERROR_OBTENER_DATOS "Error al obtener datos: %ld\n"
#define ERROR_NO_CONEXION_DB "Error: No se pudo establecer conexión con la base de datos.\n"
#define ERROR_ANIO_INVALIDO "Error: El año %ld es invalido\n"
//********** FIN ERRORES DE ENTRADA *****************/

#endif
