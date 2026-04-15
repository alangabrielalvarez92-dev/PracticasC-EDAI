#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
//estructura para el nodo de la lista doble
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

void mostrarMenu(){
        printf("\n-----Carrucel de anuncios-----\n");
        printf("1. Agregar anuncio.\n");
        printf("2. Mostrar carrucel de anuncios.\n");
        printf("3. Mostrar lista de anuncios.\n");
        printf("4. Buscar anuncio.\n");
        printf("5. Eliminar anuncio.\n");
        printf("6. Salir del programa.\n");
        printf("Elige una opción: ");
}

int main () {
    struct Nodo *lista = NULL;
    struct Nodo *encontrado;
    int opcion,id;
    char titulo[MAX];
    char descripcion[MAX];

    do {
       mostrarMenu();
       scanf("%d",&opcion);
       getchar();
       switch (opcion)
       {
       case 1://Agregar anuncio
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();

            printf("Ingresa el título: ");
            fgets(titulo, MAX, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            printf("Ingresa la descripción: ");
            fgets(descripcion, MAX, stdin);
            descripcion[strcspn(descripcion, "\n")] = '\0';

            insertarAnuncio(&lista,id,titulo,descripcion);  
        break;
        case 2: // Mostrar carrucel de anuncios
            mostrarAnuncios(lista);
        break;
        case 3: // Mostrar la lista completa de anuncios
            mostrarLista(lista);
        break;
        case 4: // Buscar anuncio
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();

            encontrado = buscarAnuncio(lista, id);
            if (encontrado != NULL) {
                printf("\nSe encontró el id: %d\n", encontrado->id);
            } else {
                printf("\nNo se encontró el id...\n");
            }

        break;
        case 5: // Eliminar anuncio
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();
            eliminarAnuncio(&lista,id);
        break;
        case 6: // Salir del programa
            printf("\nSaliendo del programa...\n");
        break; 
       default:
            printf("Opción no válida...\n");
        break;
       } 

    } while (opcion != 6);
    liberarLista(&lista);
    return 0;
}

