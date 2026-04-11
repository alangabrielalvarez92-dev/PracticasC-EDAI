#include <stdio.h>

#define MAX 5

struct Pila {
    int datos[MAX];
    int tope;
};

// Función para inicializar la PILA
void inicializar(struct Pila *p) {
    p->tope = -1;// Esto indica NULL
}


// Controles de casos vacío y lleno
int estaVacia(struct Pila *p) {
    return p->tope == -1;
}

int estaLlena(struct Pila *p) {
    return p->tope == MAX - 1;
}

// Operaciones PUSH y POP
void push(struct Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("La pila está llena.\n");
        return;
    }
    
    p->tope++;
    p->datos[p->tope] = valor;
}

int pop(struct Pila *p) {
    if (estaVacia(p)) {
        printf("La pila está vacía.\n");
        return -1;
    }

    return p->datos[p->tope--];
}

// Funciones complementarias
int top(struct Pila *p) {
    if (estaVacia(p)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return p->datos[p->tope];
}

void mostrar(struct Pila *p) {
    int i;

    if (estaVacia(p)) {
        printf("Pila vacía.\n");
        return;
    }

    for (i = p->tope; i >= 0; i--) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}

int main() {
    struct Pila pila;
    inicializar(&pila);

    push(&pila, 11);
    push(&pila, 22);
    push(&pila, 33);

    mostrar(&pila);

    printf("Tope: %d\n", top(&pila));
    printf("Elemento retirado: %d\n", pop(&pila));

    mostrar(&pila);

    return 0;
}