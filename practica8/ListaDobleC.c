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
    struct Nodo *ultimo;

    if (nuevo == NULL) {
        return;
    }

    // Si la lista es vacía
    if (*cabeza == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *cabeza = nuevo;
        return;
    }

    ultimo = (*cabeza)->anterior;

    nuevo->siguiente = *cabeza;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    (*cabeza)->anterior = nuevo;
}

// Función para buscar
struct Nodo *buscar(struct Nodo *cabeza, int valor) {
    struct Nodo *actual;

    if (cabeza == NULL) {
        return NULL;
    }

    actual = cabeza;

    do {
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return NULL;
}

// Función para eliminar por valor
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *eliminarNodo;
    struct Nodo *ultimo;

    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    eliminarNodo = buscar(*cabeza, valor);

    if (eliminarNodo == NULL) {
        printf("El valor %d no se encontró.\n", valor);
        return;
    }

    // Caso de un solo nodo
    if (eliminarNodo->siguiente == eliminarNodo) {
        free(eliminarNodo);
        *cabeza = NULL;
        printf("Se eliminó el valor %d.\n", valor);
        return;
    }

    // Reenlace de los vecinos
    eliminarNodo->anterior->siguiente = eliminarNodo->siguiente;
    eliminarNodo->siguiente->anterior = eliminarNodo->anterior;

    // Caso de eliminar la cabeza
    if (eliminarNodo == *cabeza) {
        *cabeza = eliminarNodo->siguiente;
    }

    ultimo = (*cabeza)->anterior;
    ultimo->siguiente = *cabeza;
    (*cabeza)->anterior = ultimo;

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

    actual = cabeza;
    printf("Lista hacia adelante: ");
    
    do {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("\n");
}

// Función para mostrar lista mediante antecesores
void mostrarAtras(struct Nodo *cabeza) {
    struct Nodo *actual;

    if (cabeza == NULL) {
        printf("Lista hacia atrás: vacía\n");
        return;
    }

    actual = cabeza->anterior;
    printf("Lista hacia atrás: ");
    do {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    } while (actual != cabeza->anterior);
    printf("\n");
}

// Función para liberar memoria
void liberarLista(struct Nodo **cabeza) {
    struct Nodo *actual;
    struct Nodo *temp;

    if (*cabeza == NULL) {
        return;
    }

    actual = (*cabeza)->siguiente;

    while (actual != *cabeza) {
        temp = actual->siguiente;
        free(actual);
        actual = temp;
    }

    free(*cabeza);
    *cabeza = NULL;
}

int main() {
    struct Nodo *lista = NULL;
    struct Nodo *encontrado;

    insertarFinal(&lista, 100);
    insertarFinal(&lista, 200);
    insertarFinal(&lista, 300);
    insertarFinal(&lista, 400);

    mostrarAdelante(lista);
    mostrarAtras(lista);

    encontrado = buscar(lista, 200);
    if (encontrado != NULL) {
        printf("Se encontró el valor: %d\n", encontrado->dato);
    } else {
        printf("No se encontró el valor...\n");
    }

    eliminar(&lista, 100);
    mostrarAdelante(lista);
    mostrarAtras(lista);

    eliminar(&lista, 500);
    mostrarAdelante(lista);
    mostrarAtras(lista);

    liberarLista(&lista);
    
    return 0;
}