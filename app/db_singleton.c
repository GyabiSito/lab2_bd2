/* Processed by ecpg (17.5 (Debian 17.5-1.pgdg120+1)) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "db_singleton.pgc"
#include <stdlib.h>
#include <stdio.h>
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

#line 5 "db_singleton.pgc"


static DBSingleton* instancia = NULL;

DBSingleton* getInstance(void) {
    if (instancia == NULL) {
        instancia = malloc(sizeof(DBSingleton));
        if (instancia != NULL) {
            { ECPGconnect(__LINE__, 0, "lab02@127.0.0.1:5432" , "usuario" , NULL , NULL, 0); }
#line 13 "db_singleton.pgc"

            if (sqlca.sqlcode != 0) {
                printf("Error conectando a la BD: %d\n", sqlca.sqlcode);
                free(instancia);
                instancia = NULL;
            } else {
                instancia->conectado = 1;
            }
        }
    }
    return instancia;
}

void cerrar_conexion(void) {
    if (instancia != NULL) {
        { ECPGdisconnect(__LINE__, "CURRENT");}
#line 28 "db_singleton.pgc"

        free(instancia);
        instancia = NULL;
    }
}
