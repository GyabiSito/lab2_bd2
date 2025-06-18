#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

//********** BASE DE DATOS *****************/
#define DB_NAME "lab02"
#define DB_IP "127.0.0.1"
#define DB_PORT "5432"
#define DB_USER "usuario"
// #define DB_PASSWORD NULL 
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
#define MAX_PARQUES 4
#define IMPRIMIR_PARQUE "Parque ID: %d, Nombre: %s, Capacidad: %d\n"
#define TOTAL_ENTRADAS_RESERVADAS "Total de entradas reservadas para el parque %d en el mes %d, dia %d: %d\n"
#define CAPACIDAD_MAXIMA_PARQUE "Capacidad máxima del parque %d: %d\n"
#define TOTAL_PARKING_RESERVADOS "Total de parking reservados para el parque %d en el mes %d, dia %d: %d\n"
#define CAPACIDAD_MAXIMA_PARKING "Capacidad máxima del parking %d: %d\n"
#define MAX_PARQUES 4
#define CANTIDAD_DISPONIBLE "Cantidad disponible: %d\n"
#define CHAR_SI_DESEA_PARKING 's'
#define CHAR_NO_DESEA_PARKING 'n'

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
#define MAX_FECHA_VENCIMIENTO_LENGTH 5
#define MAX_CVV_LENGTH 5
#define CEDULA_INVALIDA_INTENTE_NUEVAMENTE "Cédula inválida. Intente nuevamente:\n"
#define VISITANTE_NO_ENCONTRADO "Visitante no encontrado. Ingrese nombre: \n"
#define CHAR_DEBITO 'd'
#define CHAR_CREDITO 'c'
#define SEPARADOR_TARJETA '/'
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
#define CHAR_IMPRIMIR_ASTERISCO "***********************************\n"
#define CHAR_NO_PARQUES_DISPONIBLES "No hay parques disponibles.\n"
#define CHAR_CAPACIDAD_PARKING_EXCEDIDA "Capacidad del parking %d excedida: %d reservas actuales, límite %d\n"
#define CHAR_PARQUES_DISPONIBLES "Parques disponibles:\n"
#define CHAR_MONTO_TOTAL "Monto total: %ld\n"
#define CHAR_VISITANTE_EXISTE "El visitante con cédula %s y con nombre %s ya existe en la base de datos.\n"
#define CHAR_ENTRADA_INVALIDA "Entrada inválida. Por favor, ingrese %s para sí o %s para no: \n"
#define CHAR_COSTO_ADICIONAL_PARKING "El costo adicional por vehiculo en el parking es: %d\n"

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
#define ERROR_MAXIMOS_PARQUES "Error: El número máximo de parques es %d.\n"
#define ERROR_ASIGNAR_MEMORIA "Error: No se pudo asignar memoria.\n"
#define ERROR_RESERVAS_PARQUE "Error al obtener reservas del parque: %ld\n"
#define ERROR_NO_SE_ENCONTRO_PARKING "Error: No se encontró el parking para el parque con ID %d.\n"
#define ERROR_VISITANTE_NO_ENCONTRADO "Error: No se encontró el visitante con cédula: %s\n"
#define ERROR_PARQUE_NO_ENCONTRADO "Error: No se encontró el parque con ID: %d\n"
#define ERROR_NOMBRE_INVALIDO "Error: El nombre ingresado es inválido. Debe contener solo letras y espacios.\n"
#define ERROR_OBTENER_MAX_ID "Error: No se pudo obtener el ID máximo.\n"
#define ERROR_CONTAR_RESERVAS_PARKING "Error al contar reservas de parking para el parque %d en el mes %d, dia %d: %ld\n"
#define ERROR_VISITANTE_INGRESADO "El visitante con cédula %s ya fue ingresado. Intente nuevamente.\n"
//********** FIN ERRORES DE ENTRADA *****************/

#endif
