#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *sig;
};

struct Cola {
    struct Nodo *head;
    struct Nodo *tail;
};

void inicializar(struct Cola *c) {
    c->head = NULL;
    c->tail = NULL;
}

int estaVacia(struct Cola *c) {
    return c->head == NULL;
}

void encolar(struct Cola *c, int valor) {
    struct Nodo *nuevo;

    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("No hay memoria disponible.\n");
        return;
    }

    nuevo->dato = valor;
    nuevo->sig = NULL;

    if (estaVacia(c)) {
        c->head = nuevo;
        c->tail = nuevo;
    } else {
        c->tail->sig = nuevo;
        c->tail = nuevo;
    }
}

int desencolar(struct Cola *c) {
    struct Nodo *temp;
    int valor;

    if (estaVacia(c)) {
        printf("La cola está vacía.\n");
        return -1;
    }

    temp = c->head;
    valor = temp->dato;
    c->head = temp->sig;

    if (c->head == NULL) {
        c->tail = NULL;
    }

    free(temp);
    return valor;
}

int peek(struct Cola *c) {
    if (estaVacia(c)) {
        printf("La cola está vacía.\n");
        return -1;
    }

    return c->head->dato;
}

void mostrar(struct Cola *c) {
    struct Nodo *aux = c->head;

    if (aux == NULL) {
        printf("Cola vacía.\n");
        return;
    }

    printf("Contenido de la cola (del frente hacia el final): ");
    while (aux != NULL) {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void liberarCola(struct Cola *c) {
    struct Nodo *temp;

    while (c->head != NULL) {
        temp = c->head;
        c->head = c->head->sig;
        free(temp);
    }
    c->tail = NULL;
}

int main() {
    struct Cola cola;

    inicializar(&cola);

    encolar(&cola, 100);
    encolar(&cola, 200);
    encolar(&cola, 300);

    mostrar(&cola);

    printf("Frente: %d\n", peek(&cola));
    printf("Elemento retirado: %d\n", desencolar(&cola));

    mostrar(&cola);

    liberarCola(&cola);

    return 0;
}