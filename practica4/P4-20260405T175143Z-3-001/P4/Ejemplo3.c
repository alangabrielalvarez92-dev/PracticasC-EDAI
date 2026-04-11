#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Número de alumnos: ");
    scanf("%d", &n);

    float *calif = (float *)malloc(n * sizeof(float));
    if (calif == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Calificación %d: ", i+1);
        scanf("%f", &calif[i]);
    }

    float promedio = 0;
    for (int i = 0; i < n; i++) {
        promedio += calif[i];
    }

    printf("Promedio: %.2f\n", promedio / n);

    free(calif);
    return 0;
}