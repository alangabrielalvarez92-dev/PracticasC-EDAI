#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
En toda esta sección ustedes tienen que colocar
códigos de Pila y Cola
*/

int main() {
    char palabra[100];
    int i;
    int esPalindromo = 1;
    char dePila, deCola;

    struct Nodo *pila = NULL;
    struct Cola cola;

    inicializarCola(&cola);

    printf("Ingresa una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';

    //Revisión de Palíndromo - Insertar palabra a
    //estructuras Pila y Cola
    for (i = 0; palabra[i] != '\0'; i++) {
        push(&pila, palabra[i]);
        encolar(&cola, palabra[i]);
    }
    //Revisión retirando de estructuras
    while (!pilaVacia(pila) && !colaVacia(&cola)) {
        dePila = pop(&pila);
        deCola = desencolar(&cola);

        if (dePila != deCola) {
            esPalindromo = 0;
            break;
        }
    }

    if (esPalindromo) {
        printf("La palabra |%s| ¡ES UN PALINDROMO!.\n", palabra);
    } else {
        printf("La palabra |%s| NO es un palíndromo :c.\n", palabra);
    }
    liberarPila(&pila);
    liberarCola(&cola);

    return 0;
}