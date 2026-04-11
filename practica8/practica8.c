#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Nodo{
    int id;
    char titulo[MAX];
    char descripcion[MAX];
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *crearNodo(int id, char titulo[],char descripcion[]){
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevo == NULL){
        printf("Error: no se puede asignar memoria.\n");
        return NULL;
    }

    nuevo->id=id;
    strcpy(nuevo->titulo, titulo);
    strcpy(nuevo->descripcion,descripcion);
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

//Para insertar un anuncio, se toma código de inserción al final

void insertarAnuncio(struct Nodo **cabeza, int id, char titulo[], char descripcion[] ){
    struct Nodo *nuevo = crearNodo(id,titulo,descripcion);
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

struct Nodo *buscarAnuncio(struct Nodo *cabeza, int id) {
    struct Nodo *actual;
    if (cabeza == NULL) {
        return NULL;
    }

    actual = cabeza;

    do {
        if (actual->id == id){
            return actual;
        }
        actual = actual->siguiente;

    } while (actual != cabeza);

    return NULL;

}

void eliminarAnuncio(struct Nodo **cabeza, int id) {
    struct Nodo *eliminarNodo;
    struct Nodo *ultimo;

    if (*cabeza == NULL) {
        printf("La lista está vacía. \n");
        return;
    }

    eliminarNodo= buscarAnuncio(*cabeza,id);

    if (eliminarNodo == NULL) {
        printf("El id %d no se encontró. \n",id);
        return;
    }

    //Caso de un solo nodo
    if (eliminarNodo->siguiente == eliminarNodo) {
        free(eliminarNodo);
        *cabeza = NULL;
        printf("Se eliminó el id %d. \n",id);
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
    printf("Se eliminó el id %d.\n",id);
}

void mostrarAnuncioActual(struct Nodo *actual) {
    //struct Nodo *actual = actual;

    if (actual == NULL) {
        printf(" No hay anuncios.\n");
        return;
    }
    printf("\n-------Carrucel de Anuncios------\n");
    printf("\nID: %d\n",actual->id);
    printf("Título: %s\n",actual->titulo);
    printf("Descripción: %s\n",actual->descripcion);
}

void siguienteAnuncio(struct Nodo *actual){
    //struct Nodo *actual = actual;
    
    if (actual != NULL){
        actual = actual->siguiente;
        mostrarAnuncioActual(actual);
    }
    
    printf("No hay anuncios que mostrar. \n");
    return;
} 

void retrocederAnuncio(struct Nodo *actual) {
   // struct Nodo *actual = actual;

        if (actual != NULL){
        actual = actual->anterior;
        mostrarAnuncioActual(actual);
        }
    
    printf("No hay anuncios que mostrar. \n");
    return;
}


void mostrarAnuncios(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    int opcion;
    if (cabeza == NULL) {
        printf("Lista hacia adelante: vacía\n");
        return;
    }

    actual = cabeza;
    
    do {
        mostrarAnuncioActual(actual); //Muestra el anuncio actual
        printf("\n1. Anuncio anterior.\n");
        printf("2. Siguiente Anuncio.\n");
        printf("3. Dejar de mostrar.\n");
        scanf("%d", &opcion);
        getchar();
        switch (opcion)
        {
        case 1:
            actual = actual->anterior;
            break;
        case 2:
            actual = actual->siguiente;
            break;
        case 3:
            return;
            break;
        default:
            printf("Opción no válida...\n");
            break;
        }
    } while (opcion != 3);
    printf("\n");
}

void mostrarLista(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;

    if (cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    do {
        printf("\nID: %d\n", actual->id);
        printf("Título: %s\n", actual->titulo);
        printf("Descripción: %s\n", actual->descripcion);

        actual = actual->siguiente;
    } while (actual != cabeza);
}

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

int main () {
    struct Nodo *lista = NULL;
    struct Nodo *encontrado;

    insertarAnuncio(&lista, 1234,"Tacos","Ricos Tacos de cabeza");
    insertarAnuncio(&lista, 1235,"Tortas","Ricas Tortas");
    insertarAnuncio(&lista, 1236,"Aguas","Aguas frescas de horchata y jamaica");
    insertarAnuncio(&lista, 1237,"Pumagua","Pumagua la bebida oficial de los paristas");
    insertarAnuncio(&lista, 1238,"Mcdonals","Me encanta");

    mostrarAnuncios(lista);
   

    encontrado = buscarAnuncio(lista, 1236);
    if (encontrado != NULL) {
        printf("\nSe encontró el id: %d\n", encontrado->id);
    } else {
        printf("\nNo se encontró el id...\n");
    }

    eliminarAnuncio(&lista, 1239);
    mostrarLista(lista);
    

    eliminarAnuncio(&lista, 1236);
    mostrarLista(lista);

    liberarLista(&lista);
    return 0;
}

