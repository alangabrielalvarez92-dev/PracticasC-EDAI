#include <stdio.h>
#include <stdlib.h>

// Definir el nodo
struct Nodo {
    int dato; 
    struct Nodo *siguiente;
};

// Insertar al inicio
void insertar(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Buscar un valor, se puede agregar un mensaje para indicar éxito en búsqueda
struct Nodo* buscar(struct Nodo* cabeza, int valor) {
    struct Nodo* actual = cabeza;

    while (actual != NULL) {
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

// Eliminar un valor
void eliminar(struct Nodo** cabeza, int valor) {
    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    // Si es el primero
    if (anterior == NULL) {
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

// Mostrar lista
void mostrarLista(struct Nodo* cabeza) {
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}


int main() {
    struct Nodo* lista = NULL;
    insertar(&lista, 30);
    insertar(&lista, 20);
    insertar(&lista, 10);

    mostrarLista(lista);

    if (buscar(lista, 20)) {
        printf("¡Elemento encontrado!\n");
    }

    eliminar(&lista, 20);
    mostrarLista(lista);
    
    return 0;
}