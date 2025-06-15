#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H
#include "constants.h"
typedef struct {
    int conectado;
} DBSingleton;

typedef struct {
    int id_parque;
    int id_ubicacion;
    char nombre[MAX_NOMBRE_LENGTH];
    int capacidad_maxima_diaria;
} PARQUE;

typedef struct {
    int id_precio;
    int id_parque;
    float precio;
    char fecha_inicio[MAX_FECHA_LENGTH]; // YYYY-MM-DD
    char fecha_fin[MAX_FECHA_LENGTH];
} PRECIO;

typedef struct {
    int id_parking;
    int id_parque;
    int limite_vehiculos;
    float costo_adicional;
} PARKING;

typedef struct {
    int id_ubicacion;
    char nombre[MAX_NOMBRE_LENGTH];
} UBICACION;

typedef struct {
    int id_atraccion;
    int id_parque;
    char nombre[MAX_NOMBRE_LENGTH];
    char descripcion[MAX_LENGTH];
} ATRACCIONES;

typedef struct {
    int id_uso;
    int id_pase;
    int id_atraccion;
    char fecha[MAX_FECHA_LENGTH];
    char hora[MAX_HORA_LENGTH];
    char foto[MAX_LENGTH];
} USA;

typedef struct {
    int id_accede;
    int id_pase_parque;
    int id_parque;
    char fecha[MAX_FECHA_LENGTH];
    char hora[MAX_HORA_LENGTH];
    char entrada_salida[MAX_BOOL_LENGTH]; // 'E' para entrada, 'S' para salida
} ACCEDE;

typedef struct {
    int id_pase;
    int id_visitante;
    int id_compra;
    char codigo_qr[MAX_LENGTH];
    float precio_total;
} PASE;

typedef struct {
    int id_pase_parque;
    int id_parque;
    int id_pase;
    bool incluye_parking; // 0 = no, 1 = sí
    char fecha_accesso[MAX_FECHA_LENGTH];
} PaseParque;

typedef struct {
    int id_visitante;
    char ci[MAX_CI_LENGTH];
    char nombre[MAX_NOMBRE_LENGTH];
} VISITANTE;

typedef struct {
    int id_compra;
    int id_cliente;
    char fecha_compra[MAX_FECHA_LENGTH];
    char hora_compra[MAX_HORA_LENGTH];
    float monto_total;
    char debito_credito[MAX_BOOL_LENGTH]; //D para débito, C para crédito
    char numero_tarjeta[MAX_N_TARJETA_LENGTH];
    char fecha_vencimiento[MAX_FECHA_VENCIMIENTO_LENGTH];
    char cvv[MAX_CVV_LENGTH];
    int cant_pases;
    int cant_vehiculos;
} COMPRA;

typedef struct {
    int id_cliente;
    char email[MAX_LENGTH];
    char ci[MAX_CI_LENGTH];
    char nombre[MAX_NOMBRE_LENGTH];
} CLIENTE;

#endif
