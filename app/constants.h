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
#define MIN_TARJETA_VENCIDA 0
#define MAX_TARJETA_VENCIDA 99
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
#define IVA 1.22
#define IVA_NUM 122
#define IVA_DEN 100
//********** FIN STRUCTS *****************/

//********** LONGITUDES MAXIMAS *****************/
#define MAX_NOMBRE_LENGTH 100
#define MAX_FECHA_LENGTH 11
#define MAX_HORA_LENGTH 20
#define MAX_LENGTH 255
#define MAX_BOOL_LENGTH 1
#define MAX_CI_LENGTH 8
#define MAX_N_TARJETA_LENGTH 16
#define MAX_N_TARJETA_LENGTH_BUFFER 17
#define MAX_FECHA_VENCIMIENTO_LENGTH 10
#define MAX_FECHA_VENCIMIENTO_LENGTH_BUFFER 11
#define MAX_CVV_LENGTH 3
#define MAX_CVV_LENGTH_BUFFER 4
#define CEDULA_INVALIDA_INTENTE_NUEVAMENTE "Cédula inválida. Intente nuevamente:\n"
#define VISITANTE_NO_ENCONTRADO "Visitante no encontrado. Ingrese nombre: \n"
#define CHAR_DEBITO 1
#define CHAR_CREDITO 0
#define CHAR_DEBITO_D "D"
#define CHAR_CREDITO_C "C"
#define SEPARADOR_TARJETA '/'
#define SI_DESEA_PARKING 1
#define NO_DESEA_PARKING 0
#define NO_PASES_FECHA "No hay pases para esa fecha\n"
#define CHAR_SALIENDO "Saliendo del programa...\n"
//********** FIN LONGITUDES MAXIMAS *****************/

//*********** MENU ********************/
#define MENU_SELECCIONAR_OPCION "Seleccione una opcion:\n"
#define MENU_REALIZAR_VENTA "1. Realizar venta\n"
#define MENU_VALIDAR_ENTRADAS "2. Validar entradas\n"
#define MENU_TOTAL_RECAUDADO_MES_ANIO "3. Total recaudado por mes y año\n"
#define MENU_REGISTRAR_CLIENTE "4. Registrar cliente\n"
#define MENU_SALIR "0. Salir\n"
//*********** FIN MENU ********************/

//********** CHARS *****************/
#define CHAR_DB_CONECTANDO "Conectando a la base de datos con la cadena: %s\n"
#define CHAR_DB_ERROR "Error conectando a la base de datos: %ld\n"
#define CHAR_DB_EXITOSO "Conexión exitosa a la base de datos.\n"
#define CHAR_DB_DESCONECTANDO "Desconectando de la base de datos...\n"
#define CHAR_INGRESE_DIA "Ingrese un dia entre 1 y %d: \n"
#define CHAR_INGRESE_MES "Ingrese el mes (1-12):\n"
#define CHAR_INGRESE_ANIO "Ingrese año \n"
#define CHAR_INGRESE_CEDULA "Ingrese su cédula (8 dígitos):\n"
#define CHAR_INGRESE_CEDULA_VISITANTE "Ingrese cedula del visitante (8 dígitos):\n"
#define CHAR_INGRESE_ID_PARQUE "Ingrese el ID del parque (1-4):\n"
#define CHAR_INGRESE_FECHA "Ingrese la fecha (YYYY-MM-DD):\n"
#define CHAR_VISITANTE_ENCONTRADO "Visitante encontrado: %s (CI: %s)\n"
#define CHAR_INGRESE_CANTIDAD_ENTRADAS "Ingrese la cantidad de entradas:\n"
#define CHAR_INGRESE_CANTIDAD_VEHICULOS "Ingrese la cantidad de vehículos:\n"
#define CHAR_CEDULA_VALIDA "Cédula válida. Procediendo con la validación...\n"
#define CHAR_DESEA_PARKING "¿Desea parking? (1: Si/0. No):\n"
#define CHAR_NO_ESPACIOS_PARQUE "No hay espacio disponible para el parque %d en el mes %d, el dia %d.\n"
#define CHAR_NO_ESPACIOS_PARKING "No hay espacio de parking disponible para el parque %d en la fecha %s.\n"
#define CHAR_DESCONECTANDO "Cerrando cursores y desconectando...\n"
#define CHAR_NO_MAS_PARQUES_DISPONIBLES "No hay más parques disponibles.\n"
#define CHAR_IMPRIMIR_ASTERISCO "*************************************************\n"
#define CHAR_IMPRIMIR_LINEA "-------------------------------------------------------------\n"
#define CHAR_NO_PARQUES_DISPONIBLES "No hay parques disponibles.\n"
#define CHAR_CAPACIDAD_PARKING_EXCEDIDA "Capacidad del parking %d excedida: %d reservas actuales, límite %d\n"
#define CHAR_PARQUES_DISPONIBLES "Parques disponibles:\n"
#define CHAR_MONTO_TOTAL "Monto total: %ld\n"
#define CHAR_VISITANTE_EXISTE "El visitante con cédula %s y con nombre %s ya existe en la base de datos.\n"
#define CHAR_ENTRADA_INVALIDA "Entrada inválida. Por favor, ingrese %s para sí o %s para no: \n"
#define CHAR_COSTO_ADICIONAL_PARKING "El costo adicional por vehiculo en el parking es: %d\n"
#define CHAR_RESUMEN_VENTA "Resumen de la venta:\n"
#define CHAR_MOSTRAR_PARQUE "Parque: %s (ID: %d)\n"
#define CHAR_MOSTRAR_FECHA "Fecha: %d/%d/2025\n"
#define CHAR_MOSTRAR_CANT_ENTRADAS "Cantidad de entradas: %d\n"
#define CHAR_CANTIDAD_VEHICULOS "Cantidad de vehículos: %d\n"
#define CHAR_NO_RESERVADO_PARKING "No se ha reservado parking.\n"
#define CHAR_VISITANTES "Visitantes:\n"
#define CHAR_IMPRIMIR_VISITANTE " - Nombre: %s, Cédula: %s (ID: %d)\n"
#define CHAR_DESEA_CONFIRMAR_VENTA "¿Desea confirmar la venta? (1: Sí, 0: No): "
#define CHAR_OPCION_INVALIDA "Opción inválida. Intente nuevamente.\n"
#define CHAR_VENTA_CANCELADA "Venta cancelada.\n"
#define CHAR_INGRESE_DATOS_TARJETA "Ingrese los datos de la tarjeta:\n"
#define CHAR_INGRESE_NUMERO_TARJETA "Número de tarjeta (16 dígitos): \n"
#define CHAR_INGRESE_F_VENC_TARJETA "Fecha de vencimiento (MM/AA): "
#define CHAR_INGRESE_CVV "CVV (3 dígitos): "
#define CHAR_INGRESE_TIPO_TARJETA "Tipo de tarjeta (1: Débito, 0: Crédito): "
#define CHAR_ID_PARQUE_INVALIDO "ID de parque inválido. Intente de nuevo.\n"
#define CHAR_INGRESE_NOMBRE_VISITANTE "Ingrese el nombre del visitante: \n"
#define CHAR_CLIENTE_INEXISTENTE "Cliente no existe, registrese\n"
#define CHAR_INGRESE_NOMBRE_CLIENTE "Ingrese su nombre (máximo %d caracteres): "
#define CHAR_INGRESE_CORREO_CLIENTE "Ingrese su correo electrónico: "
#define CHAR_NOMBRE_INVALIDO "Nombre inválido. Intente nuevamente.\n"
#define CHAR_CORREO_INVALIDO "Correo inválido. Intente nuevamente.\n"
#define CHAR_CLIENTE_REGISTRADO "Cliente registrado:\nID: %d\nCI: %s\nNombre: %s\nCorreo: %s\n"
#define CHAR_CEDULA_INVALIDA "Cédula inválida. Debe tener exactamente %d dígitos y solo contener números.\n"
#define CHAR_CEDULA_EXISTE "El cliente con cédula %s ya existe en la base de datos.\n"
#define CHAR_INGRESE_CI_CLIENTE "Ingrese su cédula (máximo %d dígitos): \n"
#define CHAR_CLIENTE_EXISTE "El cliente con cédula %s ya existe en la base de datos.\n"
#define CHAR_CLIENTE_ENCONTRADO "Cliente encontrado: %s (Cédula: %s)\n"
#define CHAR_MOSTRAR_COMPRA "Compra realizada con éxito:\n ID Compra: %ld\nID Cliente: %d\nFecha: %s\nHora: %s\nMonto Total (precio pases %ld + IVA %ld): %ld\nTipo de Pago: %s\nNúmero de Tarjeta: %s\nFecha de Vencimiento: %s\nCVV: %s\nCantidad de Entradas: %d\nCantidad de Vehículos: %d\n"
#define CHAR_PASES_EXISTENTES "El visitante ya tiene pases para la fecha ingresada.\n"
#define CHAR_INGRESAR_VISITANTE "Ingrese los datos del visitante %d de %d:\n"
#define CHAR_BUSCANDO_PASES "Buscando pases del visitante (ID: %d) para el día %d/%d...\n"
#define CHAR_PASES_VISITANTE "\nPases del visitante (ID: %d) para el día %d/%d:\n"
#define CHAR_IMPRIMIR_PASE "Pase ID: %d | Fecha: %s | Parque: %s\n"
#define CHAR_PRECIO_TOTAL "Precio total de todos los pases: %ld\n"
#define CHAR_NO_RESERVADO_PARKING "No se ha reservado parking.\n"
#define CHAR_MOSTRAR_COSTO_PARQUE "Costo del parque: %ld\n"
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
#define ERROR_TARJETA_INVALIDA "Número de tarjeta inválido. Debe tener 16 dígitos.\n"
#define ERROR_F_VENC_INVALIDA "Fecha de vencimiento inválida. Debe tener el formato MM/AA.\n"
#define ERROR_CVV_INVALIDO "CVV inválido. Debe tener 3 dígitos.\n"
#define ERROR_TIPO_TARJETA_INVALIDO "Tipo de tarjeta inválido. Debe ser 'D' para Débito o 'C' para Crédito.\n"
#define ERROR_CANTIDAD_INVALIDA "Cantidad inválida. Debe ser un número mayor a 0.\n"
#define ERROR_DESEA_PARKING "Entrada inválida. Ingrese 1 para Sí o 0 para No.\n"    
#define ERROR_CANT_VEHICULOS "Entrada inválida. Ingrese un número entre 0 y %d.\n"
#define ERROR_INSERTAR_CLIENTE "Error al insertar cliente: %ld\n"
#define ERROR_SOLO_DIGITOS "ERROR: Solo se permiten dígitos.\n"
#define ERROR_CLIENTE_NO_ENCONTRADO "Error: Cliente no encontrado. Regístrese primero.\n"
#define ERROR_F_VENC_VENCIDA "Error: La fecha de vencimiento de la tarjeta ya ha vencido.\n"
#define ERROR_INSERTAR_COMPRA "Error al insertar compra: %ld\n"
#define ERROR_INSERTAR_PASE "Error al insertar pase: %ld\n"
#define ERROR_INSERTAR_PASE_PARQUE "Error al insertar pase parque: %ld\n"
#define ERROR_MES_ACTUAL "Error: El mes actual es %d, no se puede realizar la venta para el mes %d.\n"
#define ERROR_DIA_ACTUAL "Error: El día actual es %d, no se puede realizar la venta para el día %d.\n"
#define ERROR_CANT_VEHICULOS_MAYOR_ENTRADAS "Error: La cantidad de vehículos no puede ser mayor a la cantidad de entradas: %ld\n"
#define ERROR_OBTENER_TOTAL_RESERVAS_PARKING "Error al obtener total de reservas de parking: %ld"
#define ERROR_PRECIO_NO_ENCONTRADO "Error: No se encontró el precio para el parque con ID %d, mes %d y día %d.\n"

//********** FIN ERRORES DE ENTRADA *****************/


//********** IMPRIMIR PASE *****************/
#define CHAR_IMPRIMIR_PASES "Pase %d:\nID Pase: %d\nID Pase Parque: %d\nID Visitante: %d\nID Compra: %d\nID Parque: %d\nID Precio: %d\nCódigo QR: %s\nFecha de Acceso: %s\nIncluye Parking: %s\nPrecio Total Del Pase: %ld\n"
//********** FIN IMPRIMIR PASE *****************/
#endif
