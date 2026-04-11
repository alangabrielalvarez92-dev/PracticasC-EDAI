#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("datos.txt", "r");
    if (f == NULL) return 1;

    int *numeros = NULL;
    int n = 0, valor;

    while (fscanf(f, "%d", &valor) == 1) {
        numeros = (int *)realloc(numeros, (n+1)*sizeof(int));
        numeros[n] = valor;
        n++;
    }

    fclose(f);

    printf("Se leyeron %d numeros\n", n);

    for (int i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }

    free(numeros);
    return 0;
}