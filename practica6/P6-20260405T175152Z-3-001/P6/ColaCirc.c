#include <stdio.h>
#include <stdlib.h>

//Estructura Nodo de la cola circular
struct Nodo {
    int dato;
    struct Nodo *sig;
};

//Nodo circular
struct ColaCircular {
    struct Nodo *final;
};

//Inicializar la cola
void inicializarCola(struct ColaCircular *cola) {
    cola->final = NULL;
}

//Verificación de Cola Vacía
int estaVacia(struct ColaCircular *cola) {
    return cola->final == NULL;
}

//Operación enqueue
void encolar(struct ColaCircular *cola, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevo->dato = valor;

    if (estaVacia(cola)) {
        nuevo->sig = nuevo;
        cola->final = nuevo;
    } else {
        nuevo->sig = cola->final->sig;
        cola->final->sig = nuevo;
        cola->final = nuevo;
    }
}

//Operación dequeue
int desencolar(struct ColaCircular *cola, int *valor) {
    struct Nodo *frente;

    if (estaVacia(cola)) {
        return 0;
    }

    frente = cola->final->sig;
    *valor = frente->dato;

    if (cola->final == frente) {
        cola->final = NULL;
    } else {
        cola->final->sig = frente->sig;
    }

    free(frente);
    return 1;
}

void mostrarCola(struct ColaCircular *cola) {
    struct Nodo *actual;

    if (estaVacia(cola)) {
        printf("Cola vacía.\n");
        return;
    }

    actual = cola->final->sig;
    printf("Cola circular: ");

    do {
        printf("%d ", actual->dato);
        actual = actual->sig;
    } while (actual != cola->final->sig);
}

//Libera memoria
void liberarCola(struct ColaCircular *cola) {
    int valor;
    while (desencolar(cola, &valor)) {}
}

int main() {
    struct ColaCircular cola;
    int eliminado;

    inicializarCola(&cola);

    encolar(&cola, 10);
    encolar(&cola, 20);
    encolar(&cola, 30);
    mostrarCola(&cola);

    if (desencolar(&cola, &eliminado)) {
        printf("Elemento eliminado: %d\n", eliminado);
    }

    mostrarCola(&cola);

    encolar(&cola, 40);
    encolar(&cola, 50);
    mostrarCola(&cola);

    liberarCola(&cola);
    return 0;
}