/* Processed by ecpg (17.5 (Debian 17.5-1.pgdg120+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "main.pgc"
#include "main.h"


#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif							/* __CYGWIN__ */
#endif							/* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern "C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.             */

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 3 "main.pgc"

/* exec sql whenever sqlerror  sqlprint ; */
#line 4 "main.pgc"

/* exec sql whenever sql_warning  sqlprint ; */
#line 5 "main.pgc"


/* exec sql begin declare section */
 
 
 
 
 


#line 8 "main.pgc"
 int id_parque ;
 
#line 9 "main.pgc"
 int id_ubicacion ;
 
#line 10 "main.pgc"
 char nombre [ MAX_NOMBRE_LENGTH ] ;
 
#line 11 "main.pgc"
 int capacidad_maxima_diaria ;
 
#line 12 "main.pgc"
 int cedula_visitante ;
/* exec sql end declare section */
#line 14 "main.pgc"



int main()
{

    DBSingleton* db = getInstance();
    if (!db || !db->conectado) {
        printf(ERROR_NO_CONEXION_DB);
        return 1;
    }

    /* declare cursor_parque cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques */
#line 27 "main.pgc"


    /* declare cursor_ci_visitante cursor for select ci from visitantes */
#line 30 "main.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_parque cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques", ECPGt_EOIT, ECPGt_EORT);
#line 32 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 32 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "main.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_ci_visitante cursor for select ci from visitantes", ECPGt_EOIT, ECPGt_EORT);
#line 33 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 33 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 33 "main.pgc"

    while (1)
    {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_parque", ECPGt_EOIT, 
	ECPGt_int,&(id_parque),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_ubicacion),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)MAX_NOMBRE_LENGTH,(long)1,(MAX_NOMBRE_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(capacidad_maxima_diaria),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 36 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 36 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 36 "main.pgc"

        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_ci_visitante", ECPGt_EOIT, 
	ECPGt_int,&(cedula_visitante),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 37 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 37 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 37 "main.pgc"

        if (sqlca.sqlcode != SQL_SUCCESS)
        {
            if (sqlca.sqlcode == SQL_NO_DATA_FOUND)
            {
                printf(CHAR_NO_MAS_PARQUES_DISPONIBLES);
                break; // Fin del cursor
            }
            else
            {
                printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_parque", ECPGt_EOIT, ECPGt_EORT);
#line 48 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 48 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 48 "main.pgc"

                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_ci_visitante", ECPGt_EOIT, ECPGt_EORT);
#line 49 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 49 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 49 "main.pgc"

                cerrar_conexion(); // Cierra conexión antes de salir
                exit(1);
            }
        }
        printf("Parque ID: %d\n", id_parque);
        printf("cedula visitante: %d\n", cedula_visitante);
        
        mostrarMenu();
        char buffer[MAX_NOMBRE_LENGTH]; // Almacena la entrada del usuario
        int opcion;

        fgets(buffer, sizeof(buffer), stdin); //Lee la linea completa (incluyendo espacios) y lo guarda en el buffer de forma segura

        char *sanitizado = esNumeroValido(buffer); //Verifica solo los numeros
        if (sanitizado == NULL) {
            printf(CHAR_OPCION_INVALIDA);
            continue;
        }

        opcion = atoi(sanitizado); //Pasa a entero


        switch (opcion) {
            case 1: 
                realizarVenta();
                break;
            case 2:
                validarEntradas();
                break;
            case 3:
                totalRecaudadoFecha();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                cerrar_conexion(); // Cierra conexión antes de salir
                return 0;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }

    }
    printf(CHAR_DESCONECTANDO);
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_parque", ECPGt_EOIT, ECPGt_EORT);
#line 92 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 92 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 92 "main.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_ci_visitante", ECPGt_EOIT, ECPGt_EORT);
#line 93 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 93 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 93 "main.pgc"

    cerrar_conexion(); // Desconectar y limpiar al final
    return 0;
}

void mostrarMenu()
{
    printf(MENU_SELECCIONAR_OPCION);
    printf(MENU_REALIZAR_VENTA);
    printf(MENU_VALIDAR_ENTRADAS);
    printf(MENU_TOTAL_RECAUDADO_MES_ANIO);
    printf(MENU_SALIR);
}
/*

INICIAR VENTA

REPETIR
    MOSTRAR PARQUES DISPONIBLES
    INGRESAR ID_PARQUE
    INGRESAR FECHA

    INGRESAR CANTIDAD_ENTRADAS
    VALIDAR CAPACIDAD PARQUE

    SI CAPACIDAD_OK
        PREGUNTAR: ¿DESEA PARKING? (S/N)
        SI SÍ:
            INGRESAR CANTIDAD_VEHICULOS
            VALIDAR CAPACIDAD ESTACIONAMIENTO
        SINO:
            CANTIDAD_VEHICULOS = 0

        INGRESAR DATOS VISITANTES (NOMBRE, CÉDULA) x CANTIDAD_ENTRADAS

        CALCULAR PRECIO TOTAL (entradas + parking)
        MOSTRAR RESUMEN
        PREGUNTAR CONFIRMACIÓN

        SI CONFIRMADO
            INGRESAR DATOS TARJETA
            INSERTAR EN BASE DE DATOS
            MOSTRAR CÓDIGOS QR
        FIN SI
    SINO
        MOSTRAR "SIN CUPOS"
    FIN SI

    PREGUNTAR: ¿DESEA INGRESAR OTRA VENTA?
HASTA QUE RESPUESTA SEA "NO"

VOLVER A MENÚ


*/
void realizarVenta() {
    int id_parque;
    int cantidad_entradas;
    int cantidad_vehiculos;
    char deseaParking;
    
    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf(CHAR_PARQUES_DISPONIBLES);
    printf(CHAR_IMPRIMIR_ASTERISCO);
    
    PARQUE* parques;
    // Obtener los parques disponibles
    parques = getParquesDisponibles();
    if(!parques) return;

    //Imprimir los parques
    for (int i = 0; i < MAX_PARQUES && parques[i].id_parque != ERROR_SIGNAL; i++) {
        printf(IMPRIMIR_PARQUE, parques[i].id_parque, parques[i].nombre, parques[i].capacidad_maxima_diaria);
    }
    
    printf(CHAR_INGRESE_ID_PARQUE);
    scanf("%d", &id_parque);

    PARQUE parqueSeleccionado;
    // Buscar el parque seleccionado
    for (int i = 0; i < MAX_PARQUES && parques[i].id_parque != ERROR_SIGNAL; i++) {
        if (parques[i].id_parque == id_parque) {
            parqueSeleccionado = parques[i];
            break;
        }
    }
    free(parques);

    int mes;
    printf(CHAR_INGRESE_MES);
    imprimirMeses();
    scanf("%d", &mes);
    if (!esMesValido(mes)) return;
    
    //En la funcion obtenerDiasDelMes, se ponen los dias que tienen los meses
    int totalDiasMes = obtenerDiasDelMes(mes, ANIO_2025);
    printf(CHAR_INGRESE_DIA, totalDiasMes);
    int dia;
    scanf("%d", &dia);
    if(!esDiaValido(dia, mes, ANIO_2025)) return;

    int entradasReservadas = getTotalReservasParque(parqueSeleccionado.id_parque, mes, dia);
    printf(TOTAL_ENTRADAS_RESERVADAS, parqueSeleccionado.id_parque, mes, dia, entradasReservadas);
    printf(CAPACIDAD_MAXIMA_PARQUE, parqueSeleccionado.id_parque, parqueSeleccionado.capacidad_maxima_diaria);
    printf(CANTIDAD_DISPONIBLE, parqueSeleccionado.capacidad_maxima_diaria - entradasReservadas);

    printf(CHAR_INGRESE_CANTIDAD_ENTRADAS);
    scanf("%d", &cantidad_entradas);
    if (!validarCapacidadParque(parqueSeleccionado, mes,dia, cantidad_entradas)) {
        printf(CHAR_NO_ESPACIOS_PARQUE, parqueSeleccionado.id_parque, mes, dia);
        return;
    }

    printf(CHAR_DESEA_PARKING);
    scanf(" %c", &deseaParking);
    // Validar la entrada de parking
    while (tolower(deseaParking) != CHAR_SI_DESEA_PARKING && tolower(deseaParking) != CHAR_NO_DESEA_PARKING) {
        printf(CHAR_ENTRADA_INVALIDA, CHAR_SI_DESEA_PARKING, CHAR_NO_DESEA_PARKING);
        scanf(" %c", &deseaParking);
    }
    

    if (tolower(deseaParking) == CHAR_SI_DESEA_PARKING) {
        int totalReservasParking = getTotalReservasParking(parqueSeleccionado.id_parque, parqueSeleccionado.id_ubicacion, mes, dia);

        PARKING parkingSeleccionado = getParking(parqueSeleccionado.id_parque);

        printf(TOTAL_PARKING_RESERVADOS, parqueSeleccionado.id_parque, mes, dia, totalReservasParking);
        printf(CAPACIDAD_MAXIMA_PARKING, parkingSeleccionado.id_parking, parkingSeleccionado.limite_vehiculos);
        printf(CANTIDAD_DISPONIBLE, parkingSeleccionado.limite_vehiculos - totalReservasParking);
        printf(CHAR_COSTO_ADICIONAL_PARKING, parkingSeleccionado.costo_adicional);
        printf(CHAR_INGRESE_CANTIDAD_VEHICULOS);

        scanf("%d", &cantidad_vehiculos);

        if (!validarCapacidadParking(parqueSeleccionado, mes, dia, cantidad_vehiculos)) {
            printf(CHAR_NO_ESPACIOS_PARKING, id_parque, mes, dia);
            return;
        }
    } else {
        cantidad_vehiculos = 0;
    }

    //***************************INGRESAR VISITANTES********************************

    // INGRESAR DATOS VISITANTES (NOMBRE, CÉDULA) x CANTIDAD_ENTRADAS
    //Todos estos visitantes van al dia que ya se pregunto
    VISITANTE visitantes[cantidad_entradas];
    //Si el visitante exiuste (por la ci) se agrega a la lista, sino se da de alta
    for (int i = 0; i < cantidad_entradas; i++) {
        char cedula[MAX_CI_LENGTH];
        printf(CHAR_INGRESE_CEDULA);
        scanf("%s", cedula);

        if (!esCedulaValida(cedula)) {
            printf(CEDULA_INVALIDA_INTENTE_NUEVAMENTE);
            i--; // Repetir la iteración actual
            continue;
        }

        VISITANTE visitante = getVisitante(cedula);
        if(visitante.id_visitante != ERROR_SIGNAL){
            printf(CHAR_VISITANTE_ENCONTRADO, visitante.nombre, visitante.id_visitante);
        }else{
            printf(VISITANTE_NO_ENCONTRADO);
            char nombre[MAX_NOMBRE_LENGTH];
            do{
                printf("Ingrese el nombre del visitante: ");
                scanf(" %[^\n]", nombre); // Leer hasta el salto de línea
                if (strlen(nombre) == 0 || strlen(nombre) > MAX_NOMBRE_LENGTH) {
                    printf(ERROR_NOMBRE_INVALIDO);
                    continue; // Repetir la iteración actual
    
                }
            }while(!esNombreValido(nombre));
            visitante = crearVisitante(cedula, nombre);
        }        
        //Si este visitante ya esta en el arreglo, no se agrega
        bool existe = false;
        for (int j = 0; j < i; j++) {
            if (visitantes[j].id_visitante == visitante.id_visitante) {
                existe = true;
                break;
            }
        }
        if (existe) {
            printf(ERROR_VISITANTE_INGRESADO, cedula);
            i--; // Repetir la iteración actual
            continue;
        }

        visitantes[i] = visitante;
    }




    //***************************PAGAR*************************************************
    // CALCULAR PRECIO TOTAL (entradas + parking)
    long precio_total = 0;
    long precio_entrada=getPrecio(parqueSeleccionado.id_parque,mes,dia);
    precio_total += precio_entrada * cantidad_entradas;
    if (cantidad_vehiculos > 0) {
        PARKING parkingSeleccionado = getParking(parqueSeleccionado.id_parque);
        precio_total += parkingSeleccionado.costo_adicional * cantidad_vehiculos;
    }
    // MOSTRAR RESUMEN
    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf("Resumen de la venta:\n");
    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf("Parque: %s (ID: %d)\n", parqueSeleccionado.nombre, parqueSeleccionado.id_parque);
    printf("Fecha: %d/%d/2025\n", dia, mes);
    printf("Cantidad de entradas: %d\n", cantidad_entradas);
    if (cantidad_vehiculos > 0) {
        printf("Cantidad de vehículos: %d\n", cantidad_vehiculos);
    } else {
        printf("No se ha reservado parking.\n");
    }
    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf("Visitantes:\n");
    for (int i = 0; i < cantidad_entradas; i++) {
        printf(" - Nombre: %s, Cédula: %s (ID: %d)\n", 
               visitantes[i].nombre, visitantes[i].ci, visitantes[i].id_visitante);
    }
    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf("Precio total: %ld\n", precio_total);
    printf(CHAR_IMPRIMIR_ASTERISCO);
    // PREGUNTAR CONFIRMACIÓN
    int confirmar;
    do {
        printf("¿Desea confirmar la venta? (1: Sí, 0: No): ");
        scanf("%d", &confirmar);
        if(confirmar < 0 || confirmar > 1) {
            printf("Opción inválida. Intente nuevamente.\n");
        }
    } while(confirmar < 0 || confirmar > 1);
    if (confirmar == 0) {
        printf("Venta cancelada.\n");
        return;
    }
    // INGRESAR DATOS TARJETA
    char numero_tarjeta[MAX_N_TARJETA_LENGTH];
    char fecha_vencimiento[MAX_FECHA_VENCIMIENTO_LENGTH];
    char cvv[MAX_CVV_LENGTH];
    char debito_credito[MAX_BOOL_LENGTH];
    // Solicitar número de tarjeta hasta que sea válido
    do {
        printf("Ingrese los datos de la tarjeta:\n");
        printf("Número de tarjeta (16 dígitos): ");
        scanf("%s", numero_tarjeta);
        if (strlen(numero_tarjeta) != MAX_N_TARJETA_LENGTH || !esNumeroValido(numero_tarjeta)) {
            printf("Número de tarjeta inválido. Debe tener 16 dígitos.\n");
        }
    } while (strlen(numero_tarjeta) != MAX_N_TARJETA_LENGTH || !esNumeroValido(numero_tarjeta));
    // Solicitar fecha de vencimiento hasta que sea válida
    do {
        printf("Fecha de vencimiento (MM/AA): ");
        scanf("%s", fecha_vencimiento);
        if (strlen(fecha_vencimiento) != MAX_FECHA_VENCIMIENTO_LENGTH || fecha_vencimiento[2] != SEPARADOR_TARJETA) {
            printf("Fecha de vencimiento inválida. Debe tener el formato MM/AA.\n");
        }
    } while (strlen(fecha_vencimiento) != MAX_FECHA_VENCIMIENTO_LENGTH || fecha_vencimiento[2] != SEPARADOR_TARJETA);

    // Solicitar CVV hasta que sea válido
    do {
        printf("CVV (3 dígitos): ");
        scanf("%s", cvv);
        if (strlen(cvv) != MAX_CVV_LENGTH || !esNumeroValido(cvv)) {
            printf("CVV inválido. Debe tener 3 dígitos.\n");
        }
    } while (strlen(cvv) != MAX_CVV_LENGTH || !esNumeroValido(cvv));

    // Solicitar tipo de tarjeta hasta que sea válido
    do {
        printf("Tipo de tarjeta (D: Débito, C: Crédito): ");
        scanf("%s", debito_credito);
        if (tolower(debito_credito[0]) != CHAR_DEBITO && tolower(debito_credito[0]) != CHAR_CREDITO) {
            printf("Tipo de tarjeta inválido. Debe ser 'D' para Débito o 'C' para Crédito.\n");
        }
    } while (tolower(debito_credito[0]) != CHAR_DEBITO && tolower(debito_credito[0]) != CHAR_CREDITO);
    // Insertar en base de datos
    printf("Registrando venta...\n");


    printf("Venta registrada (simulada).\n");
}

void validarEntradas() { 
    char cedula[MAX_CI_LENGTH];
    printf(CHAR_INGRESE_CEDULA);
    scanf("%s", cedula);

    if(!esCedulaValida(cedula)) return;

    printf(CHAR_CEDULA_VALIDA);
    
    int mes;
    printf(CHAR_INGRESE_MES);
    imprimirMeses();
    scanf("%d", &mes);
    if (!esMesValido(mes)) return;
    
    //En la funcion obtenerDiasDelMes, se ponen los dias que tienen los meses
    int totalDiasMes = obtenerDiasDelMes(mes, ANIO_2025);
    printf(CHAR_INGRESE_DIA, totalDiasMes);
    int dia;
    scanf("%d", &dia);
    if(!esDiaValido(dia, mes, ANIO_2025)) return;

    //Buscar el visitante en la base de datos
    VISITANTE visitante= getVisitante(cedula);
    if(visitante.id_visitante== ERROR_SIGNAL ) {
        printf(ERROR_VISITANTE_NO_ENCONTRADO,cedula);
        return;
    };

    printf(CHAR_VISITANTE_ENCONTRADO, visitante.nombre, visitante.id_visitante);
    //Agarrar el total de pases que tiene ese visitante
    imprimirPasesVisitantePorFecha(visitante.id_visitante, mes, dia);

    return;
}

void totalRecaudadoFecha(){
    //Preguntar el año
    int anio;
    printf(CHAR_INGRESE_ANIO);
    scanf("%d",&anio);
    if(!esAnioValido(anio)) return;

    //Preguntar el mes
    int mes;
    printf(CHAR_INGRESE_MES);
    imprimirMeses();
    scanf("%d", &mes);
    if (!esMesValido(mes)) return;

    //Agarrar el monto total de compras segun ese año y mes
    long monto_total=getMontoTotal(anio,mes);

    printf(CHAR_IMPRIMIR_ASTERISCO);
    printf(CHAR_MONTO_TOTAL,monto_total);
    printf(CHAR_IMPRIMIR_ASTERISCO);
    return;
}
