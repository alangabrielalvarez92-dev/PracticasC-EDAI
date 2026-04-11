#include <stdio.h>

int main() {
    int arreglo[100];
    int n, i;
    int mayor, menor;

    printf("Ingrese la cantidad de elementos (1-100): ");
    scanf("%d", &n);

    while (n < 1 || n > 100) {
        printf("Valor invalido. Ingrese un numero entre 1 y 100: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        printf("Ingrese el valor %d: ", i + 1);
        scanf("%d", &arreglo[i]);
    }

    mayor = arreglo[0];
    menor = arreglo[0];

    for (i = 1; i < n; i++) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
        if (arreglo[i] < menor) {
            menor = arreglo[i];
        }
    }

    printf("El valor mayor es: %d\n", mayor);
    printf("El valor menor es: %d\n", menor);

    return 0;
}
