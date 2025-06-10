#ifndef DB_SINGLETON_H
#define DB_SINGLETON_H


typedef struct {
    int conectado;
} DBSingleton;

DBSingleton* getInstance(void);
void cerrar_conexion(void);

#endif
