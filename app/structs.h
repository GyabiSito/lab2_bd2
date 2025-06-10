#pragma once
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int conectado;
} DBSingleton;

typedef struct {
    int id_parque;
    int id_ubicacion;
    char nombre[100];
    int capacidad_maxima_diaria;
} PARQUE;

typedef struct {
    int id_precio;
    int id_parque;
    float precio;
    char fecha_inicio[11]; // YYYY-MM-DD
    char fecha_fin[11];
} PRECIO;

typedef struct {
    int id_parking;
    int id_parque;
    int limite_vehiculos;
    float costo_adicional;
} PARKING;

typedef struct {
    int id_ubicacion;
    char nombre[100];
} UBICACION;

typedef struct {
    int id_atraccion;
    int id_parque;
    char nombre[100];
    char descripcion[255];
} ATRACCIONES;

typedef struct {
    int id_uso;
    int id_pase;
    int id_atraccion;
    char fecha[11];
    char hora[6];
    char foto[255];
} USA;

typedef struct {
    int id_accede;
    int id_pase_parque;
    int id_parque;
    char fecha[11];
    char hora[6];
    char entrada_salida[10];
} ACCEDE;

typedef struct {
    int id_pase;
    int id_visitante;
    int id_compra;
    char codigo_qr[255];
    float precio_total;
} PASE;

typedef struct {
    int id_pase_parque;
    int id_parque;
    int id_pase;
    int incluye_parking; // 0 = no, 1 = sí
    char fecha_accesso[11];
} PaseParque;

typedef struct {
    int id_visitante;
    char ci[20];
    char nombre[100];
} VISITANTE;

typedef struct {
    int id_compra;
    int id_cliente;
    char fecha_compra[11];
    char hora_compra[6];
    float monto_total;
    char debito_credito[10];
    char numero_tarjeta[20];
    char fecha_vencimiento[8];
    char cvv[5];
    int cant_pases;
    int cant_vehiculos;
} COMPRA;

typedef struct {
    int id_cliente;
    char email[100];
    char ci[20];
    char nombre[100];
} CLIENTE;

#endif
