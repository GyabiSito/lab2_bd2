/* Processed by ecpg (17.5 (Debian 17.5-1.pgdg120+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "main.pgc"
#include <stdio.h>
#include <stdlib.h>
#include "db_singleton.h"


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

#line 5 "main.pgc"

/* exec sql begin declare section */
 
 
 
 

#line 7 "main.pgc"
 int id_parque ;
 
#line 8 "main.pgc"
 int id_ubicacion ;
 
#line 9 "main.pgc"
 char nombre [ 51 ] ;
 
#line 10 "main.pgc"
 int capacidad_maxima_diaria ;
/* exec sql end declare section */
#line 11 "main.pgc"


/* exec sql whenever sqlerror  sqlprint ; */
#line 13 "main.pgc"

/* exec sql whenever sql_warning  sqlprint ; */
#line 14 "main.pgc"


int main()
{
    // Llama al singleton para obtener la conexión activa
    DBSingleton* db = getInstance();
    if (!db || !db->conectado) {
        printf("No se pudo conectar a la base de datos.\n");
        return 1;
    }

    /* declare cursor_parque cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques */
#line 26 "main.pgc"


    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cursor_parque cursor for select id_parque , id_ubicacion , nombre , capacidad_maxima_diaria from parques", ECPGt_EOIT, ECPGt_EORT);
#line 28 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 28 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 28 "main.pgc"


    while (1)
    {
        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch cursor_parque", ECPGt_EOIT, 
	ECPGt_int,&(id_parque),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(id_ubicacion),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(nombre),(long)51,(long)1,(51)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(capacidad_maxima_diaria),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 32 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 32 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 32 "main.pgc"

        if (sqlca.sqlcode != 0)
        {
            if (sqlca.sqlcode == 100)
            {
                break; // Fin del cursor
            }
            else
            {
                printf("Error al obtener datos: %d\n", sqlca.sqlcode);
                cerrar_conexion(); // Cierra conexión antes de salir
                exit(1);
            }
        }

        printf("Parque ID: %d, Ubicación ID: %d, Nombre: %s, Capacidad Máxima Diaria: %d\n",
               id_parque, id_ubicacion, nombre, capacidad_maxima_diaria);
    }

    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cursor_parque", ECPGt_EOIT, ECPGt_EORT);
#line 51 "main.pgc"

if (sqlca.sqlwarn[0] == 'W') sqlprint();
#line 51 "main.pgc"

if (sqlca.sqlcode < 0) sqlprint();}
#line 51 "main.pgc"


    cerrar_conexion(); // Desconectar y limpiar al final
    return 0;
}
