#include <stdio.h>
#include <stdlib.h>

// Definir el nodo
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Insertar al final, para considerar la creación de círculo
void insertar(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    
    if (*cabeza == NULL) {
        nuevo->siguiente = nuevo;
        *cabeza = nuevo;
        return;
    }

    struct Nodo* actual = *cabeza;

    while (actual->siguiente != *cabeza) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;
    nuevo->siguiente = *cabeza;
}

// Buscar un valor
struct Nodo* buscar(struct Nodo* cabeza, int valor) {
    if (cabeza == NULL) return NULL;

    struct Nodo* actual = cabeza;

    do{
        if (actual->dato == valor) {
            return actual;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return NULL;
}

// Eliminar un valor
void eliminar(struct Nodo** cabeza, int valor) {
    if (*cabeza == NULL) return;

    struct Nodo* actual = *cabeza;
    struct Nodo* anterior = NULL;

    do {
        if (actual->dato == valor) {
            // Caso de un solo nodo
            if (actual->siguiente == actual) {
                free(actual);
                *cabeza = NULL;
                return;
            }

            // Caso de eliminar la cabeza de la lista
            if (actual == *cabeza) {
                struct Nodo* temp = *cabeza;

                while (temp->siguiente != *cabeza) {
                    temp = temp->siguiente;
                }

                *cabeza = actual->siguiente;
                temp->siguiente = *cabeza;
                free(actual);
                return;
            }

            // Caso general
            anterior->siguiente = actual->siguiente;
            free(actual);
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);
}

// Mostrar lista
void mostrarLista(struct Nodo* cabeza) {
    if (cabeza == NULL) return;

    struct Nodo* actual = cabeza;

    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(circular)\n");
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

    eliminar(&lista, 10);
    mostrarLista(lista);
    
    return 0;
}