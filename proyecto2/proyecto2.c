#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
//estructura para el nodo de la lista doble
struct Nodo{
    int id;
    char nombre[MAX];
    float precio;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *crearNodo(int id, char nombre[],float precio){
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));

    if (nuevo == NULL){
        printf("Error: no se puede asignar memoria.\n");
        return NULL;
    }

    nuevo->id=id;
    nuevo->precio=precio;
    strcpy(nuevo->nombre, nombre);
    
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

void agregarProducto(struct Nodo **cabeza, int id, char nombre[], float precio ){
    struct Nodo *nuevo = crearNodo(id,nombre,precio);
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

struct Nodo *buscarProducto(struct Nodo *cabeza, int id) {
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

void eliminarProducto(struct Nodo **cabeza, int id) {
    struct Nodo *eliminarNodo;
    struct Nodo *ultimo;

    if (*cabeza == NULL) {
        printf("La lista está vacía. \n");
        return;
    }

    eliminarNodo= buscarProducto(*cabeza,id);

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

void mostrarProductoActual(struct Nodo *actual) {
    //struct Nodo *actual = actual;

    if (actual == NULL) {
        printf(" No hay productos.\n");
        return;
    }
    printf("\n-------Carrito de comprar------\n");
    printf("\nID: %d\n",actual->id);
    printf("Nombre: %s\n",actual->nombre);
    printf("Precio: %.2lf\n",actual->precio);
}

void siguienteProducto(struct Nodo *actual){
   
    if (actual != NULL){
        actual = actual->siguiente;
        mostrarProductoActual(actual);
    }
    
    printf("No hay productos. \n");
    return;
} 

void anteriorProducto(struct Nodo *actual) {

        if (actual != NULL){
        actual = actual->anterior;
        mostrarProductoActual(actual);
        }
    
    printf("No hay productos que mostrar. \n");
    return;
}

void mostrarProductos(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    int opcion;
    if (cabeza == NULL) {
        printf("Lista hacia adelante: vacía\n");
        return;
    }

    actual = cabeza;
    
    do {
        mostrarProductoActual(actual);
        printf("\n1. Producto anterior.\n");
        printf("2. Siguiente Producto.\n");
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

void mostrarTicket(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;

    if (cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    do {
        printf("\nID: %d\n", actual->id);
        printf("Nombre: %s\n", actual->nombre);
        printf("Precio: %.2lf\n", actual->precio);

        actual = actual->siguiente;
    } while (actual != cabeza);
}

void mostrarTicketAdelante(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;

    if (cabeza == NULL) {
        printf("Lista hacia adelante: vacía\n");
        return;
    }

    actual = cabeza;
    printf("Lista hacia adelante: ");
    
    do {
        printf("\nID: %d\n", actual->id);
        printf("Nombre: %s\n", actual->nombre);
        printf("Precio: %.2lf\n", actual->precio);
        actual = actual->siguiente;

    } while (actual != cabeza);
    printf("\n");
}

void mostrarTicketAtras(struct Nodo *cabeza) {
    struct Nodo *actual;

    if (cabeza == NULL) {
        printf("Lista hacia atrás: vacía\n");
        return;
    }

    actual = cabeza->anterior;
    printf("Lista hacia atrás: ");
    do {
        printf("\nID: %d\n", actual->id);
        printf("Nombre: %s\n", actual->nombre);
        printf("Precio: %.2lf\n", actual->precio);
        actual = actual->anterior;
    } while (actual != cabeza->anterior);
    printf("\n");
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
        printf("\n-----Carrito de compras-----\n");
        printf("1. Agregar Producto.\n");
        printf("2. Mostrar Producto.\n");
        printf("3. Mostrar ticket del primero al último\n");
        printf("4. Mostrar ticket del ultimo al primero.\n");
        printf("5. Buscar producto.\n");
        printf("6. Eliminar producto.\n");
        printf("7. Salir del programa.\n");
        printf("Elige una opción: ");
}

int main () {
    struct Nodo *lista = NULL;
    struct Nodo *encontrado;
    int opcion,id;
    float precio = 0;
    char nombre[MAX];
    

    do {
       mostrarMenu();
       scanf("%d",&opcion);
       getchar();
       switch (opcion)
       {
       case 1://Agregar producto
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();

            printf("Ingresa el nombre: ");
            fgets(nombre, MAX, stdin);
            nombre[strcspn(nombre, "\n")] = '\0';

            printf("Ingrese el precio: ");
            scanf("%f",&precio);
            getchar();

            agregarProducto(&lista,id,nombre,precio);  
        break;
        case 2: 
            mostrarProductos(lista);
        break;
        case 3: // Mostrar ticket de adelante
            mostrarTicketAdelante(lista);
        break;
        case 4:
            mostrarTicketAtras(lista);
        break;
        case 5: // Buscar
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();

            encontrado = buscarProducto(lista, id);
            if (encontrado != NULL) {
                printf("\nSe encontró el id: %d\n", encontrado->id);
            } else {
                printf("\nNo se encontró el id...\n");
            }

        break;
        case 6: // Eliminar producto
            printf("Ingrese el id: ");
            scanf("%d",&id);
            getchar();
            eliminarProducto(&lista,id);
        break;
        case 7: // Salir del programa
            printf("\nSaliendo del programa...\n");
            
        break; 
       default:
            printf("Opción no válida...\n");
        break;
       } 

    } while (opcion != 7);
    printf("\n------Ticket. Gracias por su compra.------\n");
    mostrarTicket(lista);

    liberarLista(&lista);
    return 0;
}