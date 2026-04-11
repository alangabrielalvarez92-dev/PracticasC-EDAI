#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Creando un nuevo nodo
struct Nodo *crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevo == NULL) {
        printf("Error: no se puede asignar memoria.\n");
        return NULL;
    }

    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

// Insertar al final
void insertarFinal(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = crearNodo(valor);
    struct Nodo *actual;

    if (nuevo == NULL) {
        return;
    }

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        return;
    }

    actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

// Función para buscar un valor
struct Nodo *buscar(struct Nodo *cabeza, int valor) {
    struct Nodo *actual = cabeza;

    while (actual != NULL) {
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

// Función para eliminar un nodo por valor
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *eliminarNodo = buscar(*cabeza, valor);

    if (eliminarNodo == NULL) {
        printf("El valor %d no se encontró en la lista.\n", valor);
        return;
    }

    // Caso 1: es el primer nodo
    if (eliminarNodo->anterior == NULL) {
        *cabeza = eliminarNodo->siguiente;
        if (*cabeza != NULL) {
            (*cabeza)->anterior = NULL;
        }
    } else {
        eliminarNodo->anterior->siguiente = eliminarNodo->siguiente;
    }

    // Caso 2: no es el último nodo
    if (eliminarNodo->siguiente != NULL) {
        eliminarNodo->siguiente->anterior = eliminarNodo->anterior;
    }

    free(eliminarNodo);
    printf("Se eliminó el valor %d.\n", valor);
}

// Función para mostrar lista mediante sucesores
void mostrarAdelante(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;

    if (cabeza == NULL) {
        printf("Lista hacia adelante: vacía\n");
        return;
    }

    printf("Lista hacia adelante: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

// Función para mostrar lista mediante antecesores
void mostrarAtras(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;

    if (actual == NULL) {
        printf("Lista hacia atrás: vacía\n");
        return;
    }

    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    printf("Lista hacia atrás: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}

// Función para liberar memoria
void liberarLista(struct Nodo **cabeza) {
    struct Nodo *actual = *cabeza;
    struct Nodo *temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    *cabeza = NULL;
}

int main() {
    struct Nodo *lista = NULL;
    struct Nodo *encontrado;

    insertarFinal(&lista, 10);
    insertarFinal(&lista, 20);
    insertarFinal(&lista, 30);
    insertarFinal(&lista, 40);

    mostrarAdelante(lista);
    mostrarAtras(lista);

    encontrado = buscar(lista, 30);
    if (encontrado != NULL) {
        printf("Se encontró el valor: %d\n", encontrado->dato);
    } else {
        printf("No se encontró el valor...\n");
    }

    eliminar(&lista, 20);
    mostrarAdelante(lista);
    mostrarAtras(lista);

    eliminar(&lista, 50);
    mostrarAdelante(lista);
    mostrarAtras(lista);

    liberarLista(&lista);

    return 0;
}