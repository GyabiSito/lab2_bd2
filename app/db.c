/* Processed by ecpg (17.5 (Debian 17.5-1.pgdg120+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "db.pgc"

#include "db.h"


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

#line 4 "db.pgc"


static DBSingleton *instancia = NULL;

DBSingleton *getInstance(void)
{
    if (instancia == NULL)
    {
        instancia = malloc(sizeof(DBSingleton));
        if (instancia != NULL)
        {
            /* exec sql begin declare section */
              //Esto es para guardar la cadena de conexión lab02@127.0.0.1:5432
             
            
#line 16 "db.pgc"
 char conn_str [ MAX_LENGTH ] ;
 
#line 17 "db.pgc"
 char usuario [ MAX_NOMBRE_LENGTH ] ;
/* exec sql end declare section */
#line 18 "db.pgc"


            //En los %s le pasamos los valores de las constantes definidas en constants.h y guardamos la cadena de conexión en conn_str
            snprintf(conn_str, sizeof(conn_str), "%s@%s:%s", DB_NAME, DB_IP, DB_PORT);
            strncpy(usuario, DB_USER, sizeof(usuario)); // Copiamos el nombre de usuario a la variable usuario
            printf(CHAR_DB_CONECTANDO, conn_str);


            { ECPGconnect(__LINE__, 0, conn_str , usuario , NULL , NULL, 0); }
#line 26 "db.pgc"


            if (sqlca.sqlcode != SQL_SUCCESS)
            {
                printf(CHAR_DB_ERROR, sqlca.sqlcode);
                free(instancia);
                instancia = NULL;
            }
            else
            {
                instancia->conectado = DB_CONECTADO;
                printf(CHAR_DB_EXITOSO);
            }
        }
    }
    return instancia;
}

void cerrar_conexion(void)
{
    if (instancia != NULL)
    {
        { ECPGdisconnect(__LINE__, "CURRENT");}
#line 48 "db.pgc"

        free(instancia);
        instancia->conectado = DB_DESCONECTADO;
        instancia = NULL;
        
        printf(CHAR_DB_DESCONECTANDO);

    }
}

bool validarCapacidadParque(PARQUE parque, int mes,int dia, int cantidad)
{
    int totalReservas=getTotalReservasParque(parque.id_parque,mes,dia);
    if(totalReservas == ERROR_SIGNAL) {
        printf(ERROR_RESERVAS_PARQUE, sqlca.sqlcode);
        return false; // Error al obtener reservas
    }
    if(totalReservas + cantidad > parque.capacidad_maxima_diaria){
        return false;
    }
    return true;
}
bool validarCapacidadParking(PARQUE parque, int mes, int dia, int cantidad_vehiculos)
{
    PARKING parking=getParking(parque.id_parque);
    int totalReservasParking=getTotalReservasParking(parque.id_parque,parking.id_parking,mes,dia);
    if(parking.id_parking==ERROR_SIGNAL) return 0;
    if (totalReservasParking + cantidad_vehiculos > parking.limite_vehiculos)
    {
        printf(CHAR_CAPACIDAD_PARKING_EXCEDIDA, parking.id_parking, totalReservasParking, parking.limite_vehiculos);
        return false;
    }
    
    return true;
}
int getTotalReservasParking(int id_parque, int id_parking, int mes, int dia)
{
    /* exec sql begin declare section */
       
       
       
       
       
    
#line 86 "db.pgc"
 int total_reservas = 0 ;
 
#line 87 "db.pgc"
 int id_parking_local = id_parking ;
 
#line 88 "db.pgc"
 int mes_local = mes ;
 
#line 89 "db.pgc"
 int dia_local = dia ;
 
#line 90 "db.pgc"
 int id_parque_local = id_parque ;
/* exec sql end declare section */
#line 91 "db.pgc"

    
    // Contar la cantidad total de vehículos reservados para ese parking y fecha
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from compras c join pases p on c . id_compra = p . id_compra join pases_parques pp on p . id_pase = pp . id_pase where pp . id_parque = $1  and extract ( month from pp . fecha_acceso ) = $2  and extract ( day from pp . fecha_acceso ) = $3  and pp . incluye_parking = true", 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mes_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(dia_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(total_reservas),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 101 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS && sqlca.sqlcode != SQL_NO_DATA_FOUND) {
        printf(ERROR_OBTENER_TOTAL_RESERVAS_PARKING, sqlca.sqlcode);
        return ERROR_SIGNAL;
    }
    if (sqlca.sqlcode == SQL_NO_DATA_FOUND) {
        printf(ERROR_CONTAR_RESERVAS_PARKING, id_parque_local, mes_local, dia_local);
        total_reservas = 0; // No hay reservas
    }
    else if (total_reservas < 0) {
        printf(ERROR_CONTAR_RESERVAS_PARKING, id_parque_local, mes_local, dia_local);
        return ERROR_SIGNAL; // señal de error
    }

    return total_reservas;
}
bool existeCiVisitante(const char *num)
{
    /* exec sql begin declare section */
     
     
    
#line 121 "db.pgc"
 char cedula [ MAX_CI_LENGTH ] ;
 
#line 122 "db.pgc"
 bool existe ;
/* exec sql end declare section */
#line 123 "db.pgc"


    strncpy(cedula, num, sizeof(cedula));


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select exists ( select 1 from visitantes where ci = $1  )", 
	ECPGt_char,(cedula),(long)MAX_CI_LENGTH,(long)1,(MAX_CI_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_bool,&(existe),(long)1,(long)1,sizeof(bool), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 128 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS && sqlca.sqlcode != SQL_NO_DATA_FOUND)
    {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        return false; // señal de error
    }

    if (sqlca.sqlcode == SQL_NO_DATA_FOUND)
    {
        printf(ERROR_INEXISTENTE_CI);
        existe = false; // No se encontró el visitante
    }
    else if (existe == 0)
    {
        printf(ERROR_INEXISTENTE_CI);
    }

    return existe;
}

VISITANTE getVisitante(const char *cedula)
{
    /* exec sql begin declare section */
     
       
       
       
    
#line 152 "db.pgc"
 int id_visitante ;
 
#line 153 "db.pgc"
 char ci [ MAX_CI_LENGTH + 1 ] ;
 
#line 154 "db.pgc"
 char nombre [ MAX_NOMBRE_LENGTH + 1 ] ;
 
#line 155 "db.pgc"
 char cedula_local [ MAX_CI_LENGTH + 1 ] ;
/* exec sql end declare section */
#line 156 "db.pgc"


    VISITANTE visitante;

    strncpy(cedula_local, cedula, sizeof(cedula_local));
    cedula_local[sizeof(cedula_local) - 1] = '\0'; // Asegurar terminación nula

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id_visitante , ci , nombre from visitantes where ci = $1 ", 
	ECPGt_char,(cedula_local),(long)MAX_CI_LENGTH + 1,(long)1,(MAX_CI_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(id_visitante),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ci),(long)MAX_CI_LENGTH + 1,(long)1,(MAX_CI_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)MAX_NOMBRE_LENGTH + 1,(long)1,(MAX_NOMBRE_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 163 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS && sqlca.sqlcode != SQL_NO_DATA_FOUND)
    {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        visitante.id_visitante = ERROR_SIGNAL; // señal de error
    }
    else if (sqlca.sqlcode == SQL_NO_DATA_FOUND)
    {
        visitante.id_visitante = ERROR_SIGNAL;
    }
    else
    {
        visitante.id_visitante = id_visitante;
        strncpy(visitante.ci, ci, sizeof(visitante.ci));
        visitante.ci[sizeof(visitante.ci) - 1] = '\0'; // Asegurar terminación nula
        strncpy(visitante.nombre, nombre, sizeof(visitante.nombre));
        visitante.nombre[sizeof(visitante.nombre) - 1] = '\0'; // Asegurar terminación nula
    }

    return visitante;
}

PARQUE getParque(int id){
    /* exec sql begin declare section */
     
     
     
     
     
    
#line 188 "db.pgc"
 int id_parque_local = id ;
 
#line 189 "db.pgc"
 int id_parque ;
 
#line 190 "db.pgc"
 int id_ubicacion ;
 
#line 191 "db.pgc"
 char nombre [ MAX_NOMBRE_LENGTH ] ;
 
#line 192 "db.pgc"
 int capacidad_maxima_diaria ;
/* exec sql end declare section */
#line 193 "db.pgc"


    PARQUE parque;

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques p where p . id_parque = $1 ", 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(id_parque),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_ubicacion),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)MAX_NOMBRE_LENGTH,(long)1,(MAX_NOMBRE_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(capacidad_maxima_diaria),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 200 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS && sqlca.sqlcode != SQL_NO_DATA_FOUND)
    {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        parque.id_parque = ERROR_SIGNAL; // señal de error
    }
    else if (sqlca.sqlcode == SQL_NO_DATA_FOUND)
    {
        printf(ERROR_PARQUE_NO_ENCONTRADO, id_parque);
        parque.id_parque = ERROR_SIGNAL;
    }
    else
    {
        parque.id_parque = id_parque;
        parque.id_ubicacion=id_ubicacion;
        parque.capacidad_maxima_diaria=capacidad_maxima_diaria;
        strncpy(parque.nombre, nombre, sizeof(parque.nombre));
    }
    return parque;
}

PARKING getParking(int id_parque){
    /* exec sql begin declare section */
         
         
         
         
    
#line 224 "db.pgc"
 int id_parking ;
 
#line 225 "db.pgc"
 int id_parque_local = id_parque ;
 
#line 226 "db.pgc"
 int limite_vehiculos ;
 
#line 227 "db.pgc"
 int costo_adicional ;
/* exec sql end declare section */
#line 228 "db.pgc"

    PARKING parking;
    

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id_parking , limite_vehiculos , costo_adicional from parkings p where p . id_parque = $1 ", 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(id_parking),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(limite_vehiculos),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(costo_adicional),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 235 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS && sqlca.sqlcode != SQL_NO_DATA_FOUND)
    {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        parking.id_parking = ERROR_SIGNAL; // señal de error
    }
    else if (sqlca.sqlcode == SQL_NO_DATA_FOUND)
    {
        printf(ERROR_NO_SE_ENCONTRO_PARKING, id_parque);
        parking.id_parking = ERROR_SIGNAL;
    }
    else
    {
        parking.id_parking = id_parking;
        parking.id_parque=id_parque;
        parking.limite_vehiculos=limite_vehiculos;
        parking.costo_adicional=costo_adicional;
    }
    return parking;
}
// int getTotalPasesVisitante(int id_visitante, int mes, int dia)
// {
//     EXEC SQL BEGIN DECLARE SECTION;
//     int total_pases = 0;
//     int id_visitante_local = id_visitante;
//     int mes_local = mes;
//     int dia_local = dia;
//     EXEC SQL END DECLARE SECTION;

//     printf("Obteniendo total de pases para visitante con ID: %d en fecha %d/%d...\n", id_visitante, mes, dia);
    
//     EXEC SQL SELECT COUNT(*) INTO :total_pases FROM pases WHERE id_visitante = :id_visitante_local;
//     if (sqlca.sqlcode != SQL_SUCCESS)
//     {
//         printf("Error al obtener total de pases: %d\n", sqlca.sqlcode);
//         return ERROR_SIGNAL; // señal de error
//     }

//     printf("Total de pases encontrados: %d\n", total_pases);
//     return total_pases;
// }
bool existePaseVisitante(int id_visitante, int mes, int dia) {
    /* exec sql begin declare section */
       
       
       
       
    
#line 279 "db.pgc"
 int id_visitante_local = id_visitante ;
 
#line 280 "db.pgc"
 int mes_local = mes ;
 
#line 281 "db.pgc"
 int dia_local = dia ;
 
#line 282 "db.pgc"
 bool existe = false ;
/* exec sql end declare section */
#line 283 "db.pgc"

    

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select exists ( select 1 from pases_parques pp join pases p on pp . id_pase = p . id_pase where p . id_visitante = $1  and extract ( month from pp . fecha_acceso ) = $2  and extract ( day from pp . fecha_acceso ) = $3  )", 
	ECPGt_int,&(id_visitante_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mes_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(dia_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_bool,&(existe),(long)1,(long)1,sizeof(bool), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 295 "db.pgc"

    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        return false; // señal de error
    }

    return existe;
}
void imprimirPasesVisitantePorFecha(int id_visitante, int mes, int dia) {
    /* exec sql begin declare section */
       
     
       
       
     // "YYYY-MM-DD"
     
    
#line 305 "db.pgc"
 int id_visitante_local = id_visitante ;
 
#line 306 "db.pgc"
 int id_pase ;
 
#line 307 "db.pgc"
 int mes_local = mes ;
 
#line 308 "db.pgc"
 int dia_local = dia ;
 
#line 309 "db.pgc"
 char fecha_acceso [ MAX_FECHA_LENGTH ] ;
 
#line 310 "db.pgc"
 char nombre_parque [ MAX_NOMBRE_LENGTH ] ;
/* exec sql end declare section */
#line 311 "db.pgc"


    ECPGset_var( 0, &( dia_local ), __LINE__);\
 ECPGset_var( 1, &( mes_local ), __LINE__);\
 ECPGset_var( 2, &( id_visitante_local ), __LINE__);\
 /* declare cur_pase_fecha cursor for select pp . id_pase , pp . fecha_acceso , pa . nombre from pases_parques pp join pases p on pp . id_pase = p . id_pase join parques pa on pp . id_parque = pa . id_parque where p . id_visitante = $1  and extract ( month from pp . fecha_acceso ) = $2  and extract ( day from pp . fecha_acceso ) = $3  order by pp . fecha_acceso */
#line 321 "db.pgc"

#line 321 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur_pase_fecha cursor for select pp . id_pase , pp . fecha_acceso , pa . nombre from pases_parques pp join pases p on pp . id_pase = p . id_pase join parques pa on pp . id_parque = pa . id_parque where p . id_visitante = $1  and extract ( month from pp . fecha_acceso ) = $2  and extract ( day from pp . fecha_acceso ) = $3  order by pp . fecha_acceso", 
	ECPGt_int,&(id_visitante_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mes_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(dia_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 323 "db.pgc"


    printf(CHAR_BUSCANDO_PASES, id_visitante, dia, mes);
    printf(CHAR_PASES_VISITANTE, id_visitante, dia, mes);
    printf(CHAR_IMPRIMIR_LINEA);
    
    int encontrados = 0;
    
    while (1) {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cur_pase_fecha", ECPGt_EOIT, 
	ECPGt_int,&(id_pase),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_acceso),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre_parque),(long)MAX_NOMBRE_LENGTH,(long)1,(MAX_NOMBRE_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 332 "db.pgc"

        if (sqlca.sqlcode != SQL_SUCCESS) break;
        
        printf(CHAR_IMPRIMIR_PASE,id_pase,fecha_acceso,nombre_parque);
        encontrados++;
    }
    
    if (encontrados == 0) {
        printf(NO_PASES_FECHA);
    }
    
    printf(CHAR_IMPRIMIR_LINEA);
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur_pase_fecha", ECPGt_EOIT, ECPGt_EORT);}
#line 344 "db.pgc"

    return;
}

long getMontoTotal(int anio, int mes){
    /* exec sql begin declare section */
     
     
     
     
    
#line 350 "db.pgc"
 long total = 0 ;
 
#line 351 "db.pgc"
 int anio_local = anio ;
 
#line 352 "db.pgc"
 int mes_local = mes ;
 
#line 353 "db.pgc"
 char fecha_compra [ MAX_FECHA_LENGTH ] ;
/* exec sql end declare section */
#line 354 "db.pgc"

    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select SUM ( monto_total ) from compras c where extract ( year from c . fecha_compra ) = $1  and extract ( month from c . fecha_compra ) = $2 ", 
	ECPGt_int,&(anio_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mes_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_long,&(total),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 358 "db.pgc"



    return total;
 
}

int getTotalReservasParque(int id_parque, int mes, int dia){
    //Agarrar el TOTAL de reservas|pases_parques para ESE parque
    /* exec sql begin declare section */
     
     
     
     
    
#line 368 "db.pgc"
 int total_pases ;
 
#line 369 "db.pgc"
 int id_parque_local = id_parque ;
 
#line 370 "db.pgc"
 int mes_local = mes ;
 
#line 371 "db.pgc"
 int dia_local = dia ;
/* exec sql end declare section */
#line 372 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from pases_parques pp where pp . id_parque = $1  and extract ( month from pp . fecha_acceso ) = $2  and extract ( day from pp . fecha_acceso ) = $3 ", 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(mes_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(dia_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(total_pases),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 377 "db.pgc"

    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_RESERVAS_PARQUE, sqlca.sqlcode);
        return ERROR_SIGNAL; // señal de error
    }
    return total_pases;
}

PARQUE * getParquesDisponibles()
{
    /* exec sql begin declare section */
     
     
     
     
    
#line 388 "db.pgc"
 int id_parque ;
 
#line 389 "db.pgc"
 int id_ubicacion ;
 
#line 390 "db.pgc"
 char nombre [ MAX_NOMBRE_LENGTH ] ;
 
#line 391 "db.pgc"
 int capacidad_maxima_diaria ;
/* exec sql end declare section */
#line 392 "db.pgc"


    /* declare cursor_get_parques cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques */
#line 395 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_get_parques cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques", ECPGt_EOIT, ECPGt_EORT);}
#line 397 "db.pgc"


    PARQUE *parques = malloc(sizeof(PARQUE) * MAX_PARQUES);
    if (!parques) {
        printf(ERROR_ASIGNAR_MEMORIA);
        return NULL;
    }

    int index = 0;

    while (1) {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_get_parques", ECPGt_EOIT, 
	ECPGt_int,&(id_parque),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_ubicacion),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)MAX_NOMBRE_LENGTH,(long)1,(MAX_NOMBRE_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(capacidad_maxima_diaria),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 408 "db.pgc"


        if(sqlca.sqlcode != SQL_SUCCESS) {
            if (sqlca.sqlcode == SQL_NO_DATA_FOUND) {
                break; // Fin del cursor
            } else {
                printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
                free(parques);
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_get_parques", ECPGt_EOIT, ECPGt_EORT);}
#line 416 "db.pgc"

                return NULL; // señal de error
            }
        }
        if (index >= MAX_PARQUES) {
            printf(ERROR_MAXIMOS_PARQUES, MAX_PARQUES);
            break; // Evita desbordamiento de memoria
        }
        parques[index].id_parque = id_parque;
        parques[index].id_ubicacion = id_ubicacion;
        strncpy(parques[index].nombre, nombre, sizeof(parques[index].nombre));
        parques[index].capacidad_maxima_diaria = capacidad_maxima_diaria;
        index++;

    }
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_get_parques", ECPGt_EOIT, ECPGt_EORT);}
#line 431 "db.pgc"

    return parques;
}

int getMaxIdVisitante() {
    /* exec sql begin declare section */
       
    
#line 437 "db.pgc"
 int max_id = 0 ;
/* exec sql end declare section */
#line 438 "db.pgc"

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( id_visitante ) from visitantes", ECPGt_EOIT, 
	ECPGt_int,&(max_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 439 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_MAX_ID, sqlca.sqlcode);
        return ERROR_SIGNAL; // señal de error
    }

    return max_id;
}
VISITANTE crearVisitante(const char *cedula, const char *nombre) {
    /* exec sql begin declare section */
         
      
      
    
#line 450 "db.pgc"
 int id_visitante = getMaxIdVisitante () + 1 ;
 
#line 451 "db.pgc"
 char ci [ MAX_CI_LENGTH + 1 ] ;
 
#line 452 "db.pgc"
 char nombre_local [ MAX_NOMBRE_LENGTH + 1 ] ;
/* exec sql end declare section */
#line 453 "db.pgc"


    VISITANTE visitante;

    strncpy(ci, cedula, sizeof(ci) - 1);
    ci[sizeof(ci) - 1] = '\0';

    strncpy(nombre_local, nombre, sizeof(nombre_local) - 1);
    nombre_local[sizeof(nombre_local) - 1] = '\0';

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into visitantes ( id_visitante , ci , nombre ) values ( $1  , $2  , $3  )", 
	ECPGt_int,&(id_visitante),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ci),(long)MAX_CI_LENGTH + 1,(long)1,(MAX_CI_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre_local),(long)MAX_NOMBRE_LENGTH + 1,(long)1,(MAX_NOMBRE_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 464 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 468 "db.pgc"

        visitante.id_visitante = ERROR_SIGNAL;
        return visitante;
    }

    visitante.id_visitante = id_visitante;


    strncpy(visitante.ci, cedula, sizeof(visitante.ci) - 1);
    visitante.ci[sizeof(visitante.ci) - 1] = '\0';

    strncpy(visitante.nombre, nombre, sizeof(visitante.nombre) - 1);
    visitante.nombre[sizeof(visitante.nombre) - 1] = '\0';

    { ECPGtrans(__LINE__, NULL, "commit");}
#line 482 "db.pgc"

    return visitante;
}


PRECIO getPrecio(int id_parque, const char* fecha_acceso) {
    /* exec sql begin declare section */
       
     
       
       
     
     
    
#line 489 "db.pgc"
 int id_parque_local = id_parque ;
 
#line 490 "db.pgc"
 char fecha_acceso_local [ MAX_FECHA_LENGTH ] ;
 
#line 491 "db.pgc"
 long precio = 0 ;
 
#line 492 "db.pgc"
 int id_precio = 0 ;
 
#line 493 "db.pgc"
 char fecha_inicio [ MAX_FECHA_LENGTH ] ;
 
#line 494 "db.pgc"
 char fecha_fin [ MAX_FECHA_LENGTH ] ;
/* exec sql end declare section */
#line 495 "db.pgc"


    PRECIO precio_local;

    // Copiar la fecha al buffer local
    strncpy(fecha_acceso_local, fecha_acceso, sizeof(fecha_acceso_local) - 1);
    fecha_acceso_local[sizeof(fecha_acceso_local) - 1] = '\0';

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id_precio , precio , fecha_inicio , fecha_fin from precios p where p . id_parque = $1  and $2  between p . fecha_inicio and p . fecha_fin order by fecha_inicio desc limit 1", 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_acceso_local),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(id_precio),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(precio),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_inicio),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_fin),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 509 "db.pgc"



    if (sqlca.sqlcode == SQL_NO_DATA_FOUND) {
        printf(ERROR_PRECIO_NO_ENCONTRADO, id_parque_local, fecha_acceso_local);
        precio_local.id_precio = ERROR_SIGNAL;
        return precio_local;
    } else if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        precio_local.id_precio = ERROR_SIGNAL;
        return precio_local;
    }

    // Asignar los datos recuperados a la estructura
    precio_local.id_precio = id_precio;
    precio_local.id_parque = id_parque_local;
    precio_local.precio = precio;
    strncpy(precio_local.fecha_inicio, fecha_inicio, sizeof(precio_local.fecha_inicio) - 1);
    precio_local.fecha_inicio[sizeof(precio_local.fecha_inicio) - 1] = '\0';
    strncpy(precio_local.fecha_fin, fecha_fin, sizeof(precio_local.fecha_fin) - 1);
    precio_local.fecha_fin[sizeof(precio_local.fecha_fin) - 1] = '\0';

    return precio_local;
}

bool existeCliente(const char* ci_cliente){
    /* exec sql begin declare section */
     
     
    
#line 536 "db.pgc"
 char ci_cliente_local [ MAX_CI_LENGTH ] ;
 
#line 537 "db.pgc"
 bool ok = false ;
/* exec sql end declare section */
#line 538 "db.pgc"

    strncpy(ci_cliente_local, ci_cliente, sizeof(ci_cliente_local));
    
    // Buscar el precio válido para la fecha dada (fecha_acceso debe estar entre fecha_inicio y fecha_fin)
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select exists ( select 1 from clientes c where c . ci = $1  )", 
	ECPGt_char,(ci_cliente_local),(long)MAX_CI_LENGTH,(long)1,(MAX_CI_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_bool,&(ok),(long)1,(long)1,sizeof(bool), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 542 "db.pgc"
 
    
    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        ok=false;
        return ok;
    }
    return ok;

}
CLIENTE getCliente(const char *ci_cliente) {
    CLIENTE cliente;
    memset(&cliente, 0, sizeof(cliente));

    /* exec sql begin declare section */
     
       
       
       
    
#line 557 "db.pgc"
 int id_cliente ;
 
#line 558 "db.pgc"
 char email [ MAX_LENGTH + 1 ] ;
 
#line 559 "db.pgc"
 char nombre [ MAX_NOMBRE_LENGTH + 1 ] ;
 
#line 560 "db.pgc"
 char ci [ MAX_CI_LENGTH + 1 ] ;
/* exec sql end declare section */
#line 561 "db.pgc"



    strncpy(ci, ci_cliente, MAX_CI_LENGTH);
    ci[MAX_CI_LENGTH] = '\0';

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select id_cliente , email , nombre from clientes where ci = $1 ", 
	ECPGt_char,(ci),(long)MAX_CI_LENGTH + 1,(long)1,(MAX_CI_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(id_cliente),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(email),(long)MAX_LENGTH + 1,(long)1,(MAX_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)MAX_NOMBRE_LENGTH + 1,(long)1,(MAX_NOMBRE_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 568 "db.pgc"


    if (sqlca.sqlcode == SQL_NO_DATA_FOUND) {
        cliente.id_cliente = ERROR_SIGNAL;
        return cliente;
    } else if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_DATOS, sqlca.sqlcode);
        cliente.id_cliente = ERROR_SIGNAL;
        return cliente;
    }

    strncpy(cliente.email, email, MAX_LENGTH);
    cliente.email[MAX_LENGTH] = '\0';

    strncpy(cliente.nombre, nombre, MAX_NOMBRE_LENGTH);
    cliente.nombre[MAX_NOMBRE_LENGTH] = '\0';

    strncpy(cliente.ci, ci, MAX_CI_LENGTH);
    cliente.ci[MAX_CI_LENGTH] = '\0';
    
    cliente.id_cliente = id_cliente;

    return cliente;
}


int getMaxIdCompra() {
    /* exec sql begin declare section */
       
    
#line 596 "db.pgc"
 int max_id = 0 ;
/* exec sql end declare section */
#line 597 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( id_compra ) from compras", ECPGt_EOIT, 
	ECPGt_int,&(max_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 599 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_MAX_ID, sqlca.sqlcode);
        return ERROR_SIGNAL; // señal de error
    }

    return max_id;
}



COMPRA insertarCompra(COMPRA compra){
    int id_compra = getMaxIdCompra() + 1; // Incrementar el ID máximo
    /* exec sql begin declare section */
       
       
     
     
       
       
     
     
     
       
       
    
#line 614 "db.pgc"
 int id_compra_local = id_compra ;
 
#line 615 "db.pgc"
 int id_cliente_local = compra . id_cliente ;
 
#line 616 "db.pgc"
 char fecha_compra [ MAX_FECHA_LENGTH ] ;
 
#line 617 "db.pgc"
 char hora_compra [ MAX_HORA_LENGTH ] ;
 
#line 618 "db.pgc"
 long monto_total_local = compra . monto_total ;
 
#line 619 "db.pgc"
 char debito_credito [ MAX_BOOL_LENGTH + 1 ] ;
 
#line 620 "db.pgc"
 char numero_tarjeta [ MAX_N_TARJETA_LENGTH_BUFFER ] ;
 
#line 621 "db.pgc"
 char fecha_vencimiento [ MAX_FECHA_VENCIMIENTO_LENGTH_BUFFER ] ;
 
#line 622 "db.pgc"
 char cvv [ MAX_CVV_LENGTH ] ;
 
#line 623 "db.pgc"
 int cant_pases = compra . cant_pases ;
 
#line 624 "db.pgc"
 int cant_vehiculos = compra . cant_vehiculos ;
/* exec sql end declare section */
#line 625 "db.pgc"


    strncpy(fecha_compra, compra.fecha_compra, sizeof(fecha_compra));
    strncpy(hora_compra, compra.hora_compra, sizeof(hora_compra));
    strncpy(debito_credito, compra.debito_credito, sizeof(debito_credito));
    strncpy(numero_tarjeta, compra.numero_tarjeta, sizeof(numero_tarjeta));
    snprintf(fecha_vencimiento, sizeof(fecha_vencimiento), "%s", compra.fecha_vencimiento);
    strncpy(cvv, compra.cvv, sizeof(cvv));


    
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into compras ( id_compra , id_cliente , fecha_compra , hora_compra , monto_total , debito_credito , numero_tarjeta , fecha_vencimiento , cvv , cant_pases , cant_vehiculos ) values ( $1  , $2  , $3  , $4  , $5  , $6  , $7  , $8  , $9  , $10  , $11  )", 
	ECPGt_int,&(id_compra_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_cliente_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_compra),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(hora_compra),(long)MAX_HORA_LENGTH,(long)1,(MAX_HORA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(monto_total_local),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(debito_credito),(long)MAX_BOOL_LENGTH + 1,(long)1,(MAX_BOOL_LENGTH + 1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(numero_tarjeta),(long)MAX_N_TARJETA_LENGTH_BUFFER,(long)1,(MAX_N_TARJETA_LENGTH_BUFFER)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_vencimiento),(long)MAX_FECHA_VENCIMIENTO_LENGTH_BUFFER,(long)1,(MAX_FECHA_VENCIMIENTO_LENGTH_BUFFER)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(cvv),(long)MAX_CVV_LENGTH,(long)1,(MAX_CVV_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(cant_pases),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(cant_vehiculos),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 641 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_INSERTAR_COMPRA, sqlca.sqlcode);
        printf("sqlca.sqlcode: %d\n", sqlca.sqlcode);
        printf("sqlca.sqlerrm: %.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 648 "db.pgc"
 // Deshacer la transacción en caso de error
        printf("DEBUG -> id_compra: %d, id_cliente: %d, fecha_compra: %s, hora_compra: %s, monto_total: %ld, debito_credito: %s, numero_tarjeta: %s, fecha_vencimiento: %s, cvv: %s, cant_pases: %d, cant_vehiculos: %d\n",
            id_compra_local, id_cliente_local, fecha_compra, hora_compra, monto_total_local,
            debito_credito, numero_tarjeta, fecha_vencimiento, cvv, cant_pases, cant_vehiculos);
        compra.id_compra = ERROR_SIGNAL; // señal de error
        return compra; // señal de error
    }

    { ECPGtrans(__LINE__, NULL, "commit");}
#line 656 "db.pgc"

    compra.id_compra = id_compra; // Asignar el ID de compra generado
    return compra; // Retornar la compra con el ID asignado
}

CLIENTE insertarCliente(CLIENTE cliente) {
    CLIENTE nuevo_cliente;
    int id_cliente = getMaxIdCliente() + 1; // Incrementar el ID máximo
    /* exec sql begin declare section */
       
     
     
     
    
#line 665 "db.pgc"
 int id_cliente_local = id_cliente ;
 
#line 666 "db.pgc"
 char ci [ MAX_CI_LENGTH ] ;
 
#line 667 "db.pgc"
 char nombre_local [ MAX_NOMBRE_LENGTH ] ;
 
#line 668 "db.pgc"
 char correo_local [ MAX_LENGTH ] ;
/* exec sql end declare section */
#line 669 "db.pgc"



    strncpy(ci, cliente.ci, sizeof(ci));
    strncpy(nombre_local, cliente.nombre, sizeof(nombre_local));
    strncpy(correo_local, cliente.email, sizeof(correo_local));



    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into clientes ( id_cliente , email , nombre , ci ) values ( $1  , $2  , $3  , $4  )", 
	ECPGt_int,&(id_cliente_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(correo_local),(long)MAX_LENGTH,(long)1,(MAX_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre_local),(long)MAX_NOMBRE_LENGTH,(long)1,(MAX_NOMBRE_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(ci),(long)MAX_CI_LENGTH,(long)1,(MAX_CI_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 678 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_INSERTAR_CLIENTE, sqlca.sqlcode);
        printf("sqlca.sqlcode: %d, sqlca.sqlerrm: %.*s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        nuevo_cliente.id_cliente = ERROR_SIGNAL; // señal de error
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 684 "db.pgc"

        return nuevo_cliente; // señal de error
    }

    { ECPGtrans(__LINE__, NULL, "commit");}
#line 688 "db.pgc"

    nuevo_cliente.id_cliente = id_cliente; // Asignar el ID de cliente generado
    strncpy(nuevo_cliente.ci, ci, sizeof(nuevo_cliente.ci) - 1);
    nuevo_cliente.ci[sizeof(nuevo_cliente.ci) - 1] = '\0';

    strncpy(nuevo_cliente.nombre, nombre_local, sizeof(nuevo_cliente.nombre) - 1);
    nuevo_cliente.nombre[sizeof(nuevo_cliente.nombre) - 1] = '\0';

    strncpy(nuevo_cliente.email, correo_local, sizeof(nuevo_cliente.email) - 1);
    nuevo_cliente.email[sizeof(nuevo_cliente.email) - 1] = '\0';

    return nuevo_cliente; // Retornar el cliente con el ID asignado
}

int getMaxIdCliente() {
    /* exec sql begin declare section */
       
    
#line 704 "db.pgc"
 int max_id = 0 ;
/* exec sql end declare section */
#line 705 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( id_cliente ) from clientes", ECPGt_EOIT, 
	ECPGt_int,&(max_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 707 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_MAX_ID, sqlca.sqlcode);
        return ERROR_SIGNAL; // señal de error
    }

    return max_id;  
}

int getMaxIdPase(){
    /* exec sql begin declare section */
       
    
#line 719 "db.pgc"
 int max_id = 0 ;
/* exec sql end declare section */
#line 720 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( id_pase ) from pases", ECPGt_EOIT, 
	ECPGt_int,&(max_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 722 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_MAX_ID, sqlca.sqlcode);
        return ERROR_SIGNAL; // señal de error
    }

    return max_id;
}


//Ya se supone que le estoy pasando un PASE con el ID de pase generado
PASE insertarPase(PASE pase){
    /* exec sql begin declare section */
       
       
       
      
       
    
#line 736 "db.pgc"
 int id_pase_local = pase . id_pase ;
 
#line 737 "db.pgc"
 int id_visitante_local = pase . id_visitante ;
 
#line 738 "db.pgc"
 int id_compra_local = pase . id_compra ;
 
#line 739 "db.pgc"
 char codigo_qr_local [ MAX_LENGTH ] ;
 
#line 740 "db.pgc"
 long precio_total_actual = pase . precio_total ;
/* exec sql end declare section */
#line 741 "db.pgc"


    strncpy(codigo_qr_local, pase.codigo_qr, sizeof(codigo_qr_local));


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into pases ( id_pase , id_visitante , id_compra , codigo_qr , precio_total ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_int,&(id_pase_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_visitante_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_compra_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(codigo_qr_local),(long)MAX_LENGTH,(long)1,(MAX_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_long,&(precio_total_actual),(long)1,(long)1,sizeof(long), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 747 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 750 "db.pgc"

        printf(ERROR_INSERTAR_PASE, sqlca.sqlcode);
        pase.id_pase = ERROR_SIGNAL; // señal de error
        printf("sqlca.sqlcode: %d, sqlca.sqlerrm: %.*s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        printf("sqlca.sqlerrm.sqlerrmc: %.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        printf("DEBUG -> id_pase: %d, id_visitante: %d, id_compra: %d, QR: %s, precio: %ld\n",
            id_pase_local, id_visitante_local, id_compra_local, codigo_qr_local, precio_total_actual);
            printf("SQL : INSERT INTO pases (id_pase, id_visitante, id_compra, codigo_qr, precio_total) VALUES (%d, %d, %d, '%s', %ld)\n",
            id_pase_local, id_visitante_local, id_compra_local, codigo_qr_local, precio_total_actual);
        printf("sqlca.sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
        printf("sqlca.sqlerrm.sqlerrmc: %.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        printf("sqlca.sqlerrm.sqlerrmc: %.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        return pase; // señal de error
    }

    { ECPGtrans(__LINE__, NULL, "commit");}
#line 765 "db.pgc"
 // Confirmar la transacción
    return pase; // Retornar el pase con el ID asignado
}

 
int getMaxIdPaseParque() {
    /* exec sql begin declare section */
       
    
#line 772 "db.pgc"
 int max_id = 0 ;
/* exec sql end declare section */
#line 773 "db.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select MAX ( id_pase_parque ) from pases_parques", ECPGt_EOIT, 
	ECPGt_int,&(max_id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 775 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf(ERROR_OBTENER_MAX_ID, sqlca.sqlcode);
        printf("sqlca.sqlcode: %d, sqlca.sqlerrm: %.*s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 780 "db.pgc"
 // Deshacer la transacción en caso de error
        return ERROR_SIGNAL; // señal de error
    }

    return max_id;
}
PASE_PARQUE insertarPaseParque(PASE_PARQUE pase_parque) {
    /* exec sql begin declare section */
       
       
       
       
       
     
    
#line 788 "db.pgc"
 int id_pase_parque_local = pase_parque . id_pase_parque ;
 
#line 789 "db.pgc"
 int id_parque_local = pase_parque . id_parque ;
 
#line 790 "db.pgc"
 int id_pase_local = pase_parque . id_pase ;
 
#line 791 "db.pgc"
 int id_precio_local = pase_parque . id_precio ;
 
#line 792 "db.pgc"
 bool incluye_parking_local = pase_parque . incluye_parking ;
 
#line 793 "db.pgc"
 char fecha_acceso_local [ MAX_FECHA_LENGTH ] ;
/* exec sql end declare section */
#line 794 "db.pgc"


    strncpy(fecha_acceso_local, pase_parque.fecha_accesso, sizeof(fecha_acceso_local));

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into pases_parques ( id_pase_parque , id_parque , id_pase , id_precio , incluye_parking , fecha_acceso ) values ( $1  , $2  , $3  , $4  , $5  , $6  )", 
	ECPGt_int,&(id_pase_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_parque_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_pase_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_precio_local),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_bool,&(incluye_parking_local),(long)1,(long)1,sizeof(bool), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(fecha_acceso_local),(long)MAX_FECHA_LENGTH,(long)1,(MAX_FECHA_LENGTH)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 799 "db.pgc"


    if (sqlca.sqlcode != SQL_SUCCESS) {
        printf("Error sql %ld\n", sqlca.sqlcode);
        { ECPGtrans(__LINE__, NULL, "rollback");}
#line 803 "db.pgc"

        pase_parque.id_pase_parque = ERROR_SIGNAL; // señal de error
        printf("sqlca.sqlcode: %d, sqlca.sqlerrm: %.*s\n", sqlca.sqlcode, sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        printf("DEBUG -> id_pase_parque: %d, id_parque: %d, id_pase: %d, incluye_parking: %d, fecha_acceso: %s\n",
            id_pase_parque_local, id_parque_local, id_pase_local, incluye_parking_local, fecha_acceso_local);
        printf("sqlca.sqlerrm.sqlerrmc: %.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        return pase_parque; // señal de error
    }

    { ECPGtrans(__LINE__, NULL, "commit");}
#line 812 "db.pgc"
 // Confirmar la transacción
    
    return pase_parque; // Retornar el pase parque con el ID asignado
}