#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

void push(struct Nodo **tope, int valor) {
    struct Nodo *nuevo;
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("No hay memoria disponible.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = *tope;
    *tope = nuevo;
}

int pop(struct Nodo **tope) {
    struct Nodo *temp;
    int valor;

    if (*tope == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }

    temp = *tope;
    valor = temp->dato;
    *tope = temp->sig;
    free(temp);

    return valor;
}

int top(struct Nodo *tope) {
    if (tope == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }

    return tope->dato;
}

void mostrar(struct Nodo *tope) {
    struct Nodo *aux = tope;

    if (aux == NULL) {
        printf("Pila vacía.\n");
        return;
    }

    printf("Contenido de la pila: ");
    while (aux != NULL) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void liberarMemoria(struct Nodo **tope) {
    struct Nodo *temp;

    while (*tope != NULL) {
        temp = *tope;
        *tope = (*tope)->sig;
        free(temp);
    }
}

int main() {
    struct Nodo *tope = NULL;

    push(&tope, 5);
    push(&tope, 15);
    push(&tope, 25);

    mostrar(tope);

    printf("Tope de pila: %d\n", top(tope));
    printf("Elemento retirado: %d\n", pop(&tope));

    mostrar(tope);

    liberarMemoria(&tope);

    return 0;
}