#include <stdio.h>
#include <stdlib.h>

int main() {
    float *precios = NULL;
    int total = 0;
    int opcion;

    do {
        printf("\n1. Agregar producto\n2. Total\n3. Salir\nOpcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            precios = (float *)realloc(precios, (total + 1) * sizeof(float));

            printf("Precio: ");
            scanf("%f", &precios[total]);

            total++;
        }

        if (opcion == 2) {
            float suma = 0;
            for (int i = 0; i < total; i++) {
                suma += precios[i];
            }
            printf("Total: %.2f\n", suma);
        }
    } while (opcion != 3);
    
    free(precios);
    return 0;
}