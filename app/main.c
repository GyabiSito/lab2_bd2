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
    // Llama al singleton para obtener la conexión activa
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

        char *sanitizado = sanitizarInput(buffer); //Verifica solo los numeros
        if (sanitizado == NULL) {
            printf(CHAR_OPCION_INVALIDA);
            continue;
        }

        opcion = atoi(sanitizado); //Pasa a entero


        switch (opcion) {
            case 1: 
                realizarVenta();
                // Aquí iría la lógica para la venta de entradas
                break;
            case 2:
                validarEntradas();
                break;
            case 3:
                printf("Total Recaudado Mes o Año para el parque %s (ID: %d)\n", nombre, id_parque);
                // Aquí iría la lógica para calcular el total recaudado
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
#line 94 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 94 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 94 "main.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_ci_visitante", ECPGt_EOIT, ECPGt_EORT);
#line 95 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 95 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 95 "main.pgc"

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

void realizarVenta() {
    int id_parque;
    int cantidad_entradas;
    int cantidad_vehiculos;
    char deseaParking;
    char fecha[MAX_FECHA_LENGTH]; // formato YYYY-MM-DD

    printf(CHAR_INGRESE_ID_PARQUE);
    scanf("%d", &id_parque);

    printf(CHAR_INGRESE_FECHA);
    scanf("%10s", fecha);  // ✅ sin asterisco

    printf(CHAR_INGRESE_CANTIDAD_ENTRADAS);
    scanf("%d", &cantidad_entradas);

    if (!validarCapacidadParque(id_parque, fecha, cantidad_entradas)) {
        printf(CHAR_NO_ESPACIOS_PARQUE, id_parque, fecha);
        return;
    }

    printf(CHAR_DESEA_PARKING);
    scanf("%c", &deseaParking);  // espacio para consumir enter anterior

    if (tolower(deseaParking) == "s") {
        printf(CHAR_INGRESE_CANTIDAD_VEHICULOS);
        scanf("%d", &cantidad_vehiculos);

        if (!validarCapacidadParking(id_parque, fecha, cantidad_vehiculos)) {
            printf(CHAR_NO_ESPACIOS_PARKING, id_parque, fecha);
            return;
        }
    } else {
        cantidad_vehiculos = 0;
    }

    // Aquí continuarías con lógica de ingreso de visitante, pago, etc.
    printf("Venta registrada (simulada).\n");
}

void validarEntradas() { 
    char cedula[MAX_CI_LENGTH];
    printf(CHAR_INGRESE_CEDULA);
    scanf("%s", cedula);

    if(!esCedulaValida(cedula)) return;

    printf(CHAR_CEDULA_VALIDA, cedula);
    
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
    if(visitante.id_visitante== ERROR_SIGNAL ) return;

    printf(CHAR_VISITANTE_ENCONTRADO, visitante.nombre, visitante.id_visitante);
    //Agarrar el total de pases que tiene ese visitante
    imprimirPasesVisitantePorFecha(visitante.id_visitante, mes, dia);

    return;
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
