#include <stdio.h>
#include <stdlib.h>

//Estructura Nodo de la cola circular
struct Nodo {
    int dato;
    struct Nodo *sig;
    struct Nodo *ant;
};

//Nodo circular
struct ColaDoble {
    struct Nodo *frente;
    struct Nodo *final;
};

//Inicializar la cola
void inicializarCola(struct ColaDoble *cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

//Verificación de Cola Vacía
int estaVacia(struct ColaDoble *cola) {
    return cola->frente == NULL;
}

//Insertar al frente
void insertarFrente(struct ColaDoble *cola, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->ant = NULL;
    nuevo->sig = cola->frente;

    if (estaVacia(cola)) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->frente->ant = nuevo;
        cola->frente = nuevo;
    }
}

//Insertar por el final
void insertarFinal(struct ColaDoble *cola, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;
    nuevo->ant = cola->final;

    if (estaVacia(cola)) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->sig = nuevo;
        cola->final = nuevo;
    }
}

//Eliminar por frente
int eliminarFrente(struct ColaDoble *cola, int *valor) {
    struct Nodo *temp;

    if (estaVacia(cola)) {
        return 0;
    }

    temp = cola->frente;
    *valor = temp->dato;

    if (cola->frente == cola->final) {
        cola->frente = NULL;
        cola->final = NULL;
    } else {
        cola->frente = temp->sig;
        cola->frente->ant = NULL;
    }

    free(temp);
    return 1;
}

//Eliminar por frente
int eliminarFinal(struct ColaDoble *cola, int *valor) {
    struct Nodo *temp;

    if (estaVacia(cola)) {
        return 0;
    }

    temp = cola->final;
    *valor = temp->dato;

    if (cola->frente == cola->final) {
        cola->frente = NULL;
        cola->final = NULL;
    } else {
        cola->final = temp->ant;
        cola->final->sig = NULL;
    }

    free(temp);
    return 1;
}

//Mostrar del frente al final
void mostrarIzqDer(struct ColaDoble *cola) {
    struct Nodo *actual = cola->frente;

    if (estaVacia(cola)) {
        printf("Cola doble vacía.\n");
        return;
    }

    printf("Cola doble del frente al final: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }
    printf("\n");
}

//Mostrar del final al frente
void mostrarDerIzq(struct ColaDoble *cola) {
    struct Nodo *actual = cola->final;

    if (estaVacia(cola)) {
        printf("Cola doble vacía.\n");
        return;
    }

    printf("Cola doble del final al frente: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->ant;
    }
    printf("\n");
}

//Libera memoria
void liberarCola(struct ColaDoble *cola) {
    int valor;
    while (eliminarFrente(cola, &valor)) {}
}

int main() {
    struct ColaDoble deque;
    int eliminado;

    inicializarCola(&deque);

    insertarFinal(&deque, 10);
    insertarFinal(&deque, 20);
    insertarFrente(&deque, 5);
    insertarFrente(&deque, 1);

    mostrarIzqDer(&deque);
    mostrarDerIzq(&deque);

    if (eliminarFrente(&deque, &eliminado)) {
        printf("Eliminado del frente: %d\n", eliminado);
    }

    if (eliminarFinal(&deque, &eliminado)) {
        printf("Eliminado del final: %d\n", eliminado);
    }

    mostrarIzqDer(&deque);
    mostrarDerIzq(&deque);

    liberarCola(&deque);
    return 0;
}