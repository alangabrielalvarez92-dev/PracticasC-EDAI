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
// Solo se agrega insertar (encolar) en un sentido

// Es equivalente a desencolar en ColaDoble
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

// Espacio para función mostrar

// Espacio para operaciones en usuarios normales
// La función atender es equivalente a desencolar
// en Cola Circular

// Atención Mixta

void atenderSiguiente(struct ColaVIP *vip, struct ColaNormal *normal) {
    int turno;
    char nombre[50];

    if (atenderVIP(vip, &turno, nombre)) {
        printf("\nSe atiende a usuario VIP:\n");
        printf(" Turno VIP %d - %s\n", turno, nombre);
    } else if (atenderNormal(normal, &turno, nombre)) {
        printf("\nSe atiende a usuario normal:\n");
        printf(" Turno normal %d - %s\n", turno, nombre);
    } else {
        printf("\nNo hay usuarios en espera.\n");
    }
}

// Para liberar memoria se usan las de cola doble y cola circular
// Espacio para implementar la liberación de memoria.

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
        printf("=== SISTEMA MIXTO DE ATENCION ===\n");
        printf("1. Registrar usuario VIP\n");
        printf("2. Registrar usuario Normal\n");
        printf("3. Atender siguiente usuario\n");
        printf("4. Mostrar colas\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre del usuario VIP: ");
                fgets(nombre, sizeof(nombre), stdin);
                limpiarSaltoLinea(nombre);

                insertarVIP(&colaVIP, contadorVIP, nombre);
                printf("Usuario VIP registrado con turno VIP %d.\n", contadorVIP);
                contadorVIP++;
                break;
            
            case 2:
                printf("Ingrese el nombre del usuario normal: ");
                fgets(nombre, sizeof(nombre), stdin);
                limpiarSaltoLinea(nombre);

                insertarNormal(&colaNormal, contadorNormal, nombre);
                printf("Usuario normal registrado con turno %d.\n", contadorVIP);
                contadorNormal++;
                break;

            case 3:
                atenderSiguiente(&colaVIP, &colaNormal);
                break;

            case 4:
                printf("\n--- ESTADO ACTUAL DE LAS COLAS ---\n");
                mostrarVIP(&colaVIP);
                mostrarNormal(&colaNormal);
                break;

            case 5:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida....\n");
        }
    } while (opcion != 5);
    
    liberarVIP(&colaVIP);
    liberarNormal(&colaNormal);

    return 0;
}