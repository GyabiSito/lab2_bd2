#include <stdio.h>

int main() {
    int opcion;
    do {
        printf("=== Menú ===\n");
        printf("1. Opción 1\n");
        printf("2. Opción 2\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: printf("Elegiste opción 1\n"); break;
            case 2: printf("Elegiste opción 2\n"); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opción inválida\n");
        }
    } while(opcion != 0);

    return 0;
}
