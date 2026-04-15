#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
En toda esta sección ustedes tienen que colocar
códigos de Pila y Cola
*/
struct NodoPila
{
    int dato;
    struct NodoPila *sig;
};
void push(struct NodoPila **tope, int valor)
{
    struct NodoPila *nuevo;
    nuevo = (struct NodoPila *)malloc(sizeof(struct NodoPila));
    if (nuevo == NULL)
    {
        printf("No hay memoria disponible.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->sig = *tope;
    *tope = nuevo;
}
int pop(struct NodoPila **tope)
{
    struct NodoPila *temp;
    int valor;
    if (*tope == NULL)
    {
        printf("La pila está vacía.\n");
        return -1;
    }
    temp = *tope;
    valor = temp->dato;
    *tope = temp->sig;
    free(temp);
    return valor;
}
int top(struct NodoPila *tope)
{
    if (tope == NULL)
    {
        printf("La pila está vacía.\n");
        return -1;
    }
    return tope->dato;
}
int pilaVacia(struct NodoPila *tope)
{
    return tope == NULL;
}
void mostrarPila(struct NodoPila *tope)
{
    struct NodoPila *aux = tope;
    if (pilaVacia(tope))
    {
        printf("Pila vacía.\n");
        return;
    }
    printf("Contenido de la pila: ");
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}
void liberarPila(struct NodoPila **tope)
{
    struct NodoPila *temp;
    while (*tope != NULL)
    {
        temp = *tope;
        *tope = (*tope)->sig;
        free(temp);
    }
}
struct NodoCola
{

    int dato;
    struct NodoCola *sig;
};
struct Cola
{
    struct NodoCola *head;
    struct NodoCola *tail;
};
void inicializarCola(struct Cola *c)
{
    c->head = NULL;
    c->tail = NULL;
}
int colaVacia(struct Cola *c)
{
    return c->head == NULL;
}
void encolar(struct Cola *c, int valor)
{
    struct NodoCola *nuevo;
    nuevo = (struct NodoCola *)malloc(sizeof(struct NodoCola));
    if (nuevo == NULL)
    {
        printf("No hay memoria disponible.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->sig = NULL;
    if (colaVacia(c))
    {
        c->head = nuevo;
        c->tail = nuevo;
    }
    else
    {
        c->tail->sig = nuevo;
        c->tail = nuevo;
    }
}
int desencolar(struct Cola *c)
{
    struct NodoCola *temp;
    int valor;

    if (colaVacia(c))
    {
        printf("La cola está vacía.\n");
        return -1;
    }
    temp = c->head;
    valor = temp->dato;
    c->head = temp->sig;
    if (c->head == NULL)
    {
        c->tail = NULL;
    }
    free(temp);
    return valor;
}
int peek(struct Cola *c)
{
    if (colaVacia(c))
    {
        printf("La cola está vacía.\n");
        return -1;
    }
    return c->head->dato;
}
void mostrarCola(struct Cola *c)
{
    struct NodoCola *aux = c->head;
    if (aux == NULL)
    {
        printf("Cola vacía.\n");
        return;
    }
    printf("Contenido de la cola (del frente hacia el final): ");
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->sig;
    }
    printf("\n");
}

void liberarCola(struct Cola *c)
{
    struct NodoCola *temp;
    while (c->head != NULL)
    {
        temp = c->head;
        c->head = c->head->sig;
        free(temp);
    }
    c->tail = NULL;
}
// Se crea una función para hacer minusculas todos los caracteres de la
void convertirCadena(char *palabra)
{
    int tamaño = strlen(palabra);
    for (int i = 0; i < tamaño; i++)
    {
        palabra[i] = tolower(palabra[i]);
    }
}

int main()
{
    char palabra[100];
    int i;
    int esPalindromo = 1;
    char dePila, deCola;
    struct NodoPila *pila = NULL;
    struct Cola cola;
    inicializarCola(&cola);
    printf("Ingresa una palabra: ");
    fgets(palabra, sizeof(palabra), stdin);
    palabra[strcspn(palabra, "\n")] = '\0';
    convertirCadena(palabra);

    // Revisión de Palíndromo - Insertar palabra a
    // estructuras Pila y Cola
    for (i = 0; palabra[i] != '\0'; i++)
    {
        push(&pila, palabra[i]);
        encolar(&cola, palabra[i]);
    }
    // Revisión retirando de estructuras
    while (!pilaVacia(pila) && !colaVacia(&cola))
    {
        dePila = pop(&pila);
        deCola = desencolar(&cola);
        if (dePila != deCola)
        {
            esPalindromo = 0;
            break;
        }
    }
    if (esPalindromo)
    {
        printf("La palabra |%s| ¡ES UN PALINDROMO!.\n", palabra);
    }
    else
    {
        printf("La palabra |%s| NO es un palíndromo :c.\n", palabra);
    }
    liberarPila(&pila);
    liberarCola(&cola);
    return 0;
}