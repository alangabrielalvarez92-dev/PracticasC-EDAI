#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Se definen structs para usuarios VIP

struct NodoVIP {
    int turno;
    char nombre[50];
    struct NodoVIP *ant;
    struct NodoVIP *sig;
};

struct ColaVIP {
    struct NodoVIP *frente;
    struct NodoVIP *final;
};

// Se definen estructuras para usuarios normales

struct NodoNormal {
    int turno;
    char nombre[50];
    struct NodoNormal *sig;
};

struct ColaNormal {
    struct NodoNormal *final;
};

// Funciones de apoyo

void limpiarSaltoLinea(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        if (cadena[i] == '\n') {
            cadena[i] = '\0';
        }
        i++;
    }
}

// Espacio de operaciones de ColaVIP (ColaDoble)
void inicializarColaVIP(struct ColaVIP *cola) {
    cola->frente = NULL;
    cola->final = NULL;
}

int colaVIPVacia(struct ColaVIP *cola) {
    return cola->frente == NULL;
}

// Solo se agrega insertar (encolar) en un sentido
void insertarVIP(struct ColaVIP *cola, int contVIP,char nombre[]) {
    struct NodoVIP *nuevo = (struct NodoVIP *)malloc(sizeof(struct NodoVIP));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    
    nuevo->turno = contVIP;
    strcpy(nuevo->nombre,nombre); //para copiar la cadena nombre que recibe la funciÃ³n en nuevo->nombre
    nuevo->sig = NULL;
    nuevo->ant = cola->final;

    if (colaVIPVacia(cola)) {
        cola->frente = nuevo;
        cola->final = nuevo;
    } else {
        cola->final->sig = nuevo;
        cola->final = nuevo;
    }
}
// Es equivalente a desencolar (por el frente) en ColaDoble
int atenderVIP(struct ColaVIP *cola, int *turno, char nombre[]) {
    struct NodoVIP *temp;

    if (colaVIPVacia(cola)) {
        return 0;
    }

    temp = cola->frente;
    *turno = temp->turno;
    strcpy(nombre, temp->nombre);

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

// Espacio para funciÃ³n mostrar
void mostrarVIP(struct ColaVIP *cola) { //Muestra de izquierda a derecha
    struct NodoVIP *actual = cola->frente;

    if (colaVIPVacia(cola)) {
        printf("Cola doble vacÃ­a.\n");
        return;
    }

    printf("\nCola VIP del frente al final: \n");
    while (actual != NULL) {
        printf("Turno VIP:%d Nombre: %s\n", actual->turno,actual->nombre);
        actual = actual->sig;
    }
    printf("\n");
}


// Espacio para operaciones en usuarios normales
void inicializarColaNormal(struct ColaNormal *cola) {
    cola->final = NULL;
}

int colaNormalVacia(struct ColaNormal *cola) {
    return cola->final == NULL;
}

void insertarNormal(struct ColaNormal *cola, int contadorNormal, char nombre []) {
    struct NodoNormal *nuevo = (struct NodoNormal *)malloc(sizeof(struct NodoNormal));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }

    nuevo->turno = contadorNormal;
    strcpy(nuevo->nombre,nombre);

    if (colaNormalVacia(cola)) {
        nuevo->sig = nuevo;
        cola->final = nuevo;
    } else {
        nuevo->sig = cola->final->sig;
        cola->final->sig = nuevo;
        cola->final = nuevo;
    }
}
// La funciÃ³n atender es equivalente a desencolar
// en Cola Circular
int atenderNormal(struct ColaNormal *cola,int *turno,char nombre []){
    struct NodoNormal *frente;

    if (colaNormalVacia(cola)) {
        return 0;
    }

    frente = cola->final->sig;
    *turno = frente->turno;
    strcpy(nombre, frente->nombre);

    if (cola->final == frente) {
        cola->final = NULL;
    } else {
        cola->final->sig = frente->sig;
    }

    free(frente);
    return 1;

}

void mostrarNormal(struct ColaNormal *cola) {
    struct NodoNormal *actual;

    if (colaNormalVacia(cola)) {
        printf("Cola vacÃ­a.\n");
        return;
    }

    actual = cola->final->sig;
    printf("Cola circular:\n");

    do {
        printf("Turno Normal: %d, Nombre: %s\n ", actual->turno,actual->nombre);
        actual = actual->sig;
    } while (actual != cola->final->sig);
}

// AtenciÃ³n Mixta

void atenderSiguiente(struct ColaVIP *vip, struct ColaNormal *normal) {
    int turno;
    char nombre[50];

    if (atenderVIP(vip, &turno, nombre)) {
        printf("\nSe atiende a usuario VIP:\n");
        printf(" Turno %d - %s\n", turno, nombre);
    } else if (atenderNormal(normal, &turno, nombre)) {
        printf("\nSe atiende a usuario normal:\n");
        printf(" Turno %d - %s\n", turno, nombre);
    } else {
        printf("\nNo hay usuarios en espera.\n");
    }
}

// Para liberar memoria se usan las de cola doble y cola circular
// Espacio para implementar la liberaciÃ³n de memoria.

void liberarVIP(struct ColaVIP *cola) {
    int valor;
    char nombre[50];
    while (atenderVIP(cola, &valor,nombre)) {}
}

void liberarNormal(struct ColaNormal *cola) {
    int valor;
    char nombre[50];
    while (atenderNormal(cola, &valor,nombre)) {}
}

int main () {
    struct ColaVIP colaVIP;
    struct ColaNormal colaNormal;

    int opcion;
    int contadorVIP = 1;
    int contadorNormal = 1;
    char nombre[50];

    inicializarColaVIP(&colaVIP);
    inicializarColaNormal(&colaNormal);

    do {
        printf("\n=== SISTEMA MIXTO DE ATENCION ===\n");
        printf("1. Registrar usuario VIP\n");
        printf("2. Registrar usuario Normal\n");
        printf("3. Atender siguiente usuario\n");
        printf("4. Mostrar colas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: // Inserta un usuario VIP
                printf("Ingrese el nombre del usuario VIP: ");
                fgets(nombre, sizeof(nombre), stdin);
                limpiarSaltoLinea(nombre);

                insertarVIP(&colaVIP, contadorVIP, nombre);
                printf("Usuario VIP registrado con turno VIP %d.\n", contadorVIP);
                contadorVIP++;
                break;
            
            case 2: // Inserta un usuario Normal
                printf("Ingrese el nombre del usuario normal: ");
                fgets(nombre, sizeof(nombre), stdin);
                limpiarSaltoLinea(nombre);

                insertarNormal(&colaNormal, contadorNormal, nombre);
                printf("Usuario normal registrado con turno %d.\n", contadorNormal);
                contadorNormal++;
                break;

            case 3: // AtenciÃ³n Mixta
                atenderSiguiente(&colaVIP, &colaNormal);
                break;

            case 4: //Ver el estado de las colas
                printf("\n--- ESTADO ACTUAL DE LAS COLAS ---\n");
                mostrarVIP(&colaVIP);
                mostrarNormal(&colaNormal);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("OpciÃ³n no vÃ¡lida....\n");
        }
    } while (opcion != 5);
    
    liberarVIP(&colaVIP);
    liberarNormal(&colaNormal);

    return 0;
}