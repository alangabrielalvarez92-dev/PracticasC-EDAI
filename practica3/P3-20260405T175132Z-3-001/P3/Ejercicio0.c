#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct CifradoC {
    char textoOriginal[MAX];
    char textoCifrado[MAX];
    int desplazamiento;
};

char alfabeto[] = "abcdefghijklmnñopqrstuvwxyz";

//Función para encontrar índice de una letra en el alfabeto
int obtenerIndice(char c) {
    for (int i = 0; i < 27; i++) {
        if (alfabeto[i] == c) {
            return i;
        }
    }
    return -1;
}

//Función de Cifrado César
void cifrar(struct CifradoC *datos) {
    int i;
    for (i = 0; datos->textoOriginal[i] != '\0'; i++) {
        char c = tolower(datos->textoOriginal[i]);

        int indice = obtenerIndice(c);

        if (indice != -1) {
            int nuevoIndice = (indice + datos->desplazamiento) % 27;
            datos->textoCifrado[i] = alfabeto[nuevoIndice];
        } else {
            datos->textoCifrado[i] = datos->textoOriginal[i];
        }
    }
    datos->textoCifrado[i]='\0';
}

int main() {
    struct CifradoC datos;

    printf("Ingresa el texto a cifrar: ");
    fgets(datos.textoOriginal, MAX, stdin);

    //Se elimina el salto de línea de fgets
    datos.textoOriginal[strcspn(datos.textoOriginal, "\n")] = "\0";

    printf("Ingresa el valor de desplazamiento: ");
    scanf("%d", &datos.desplazamiento);

    cifrar(&datos);

    printf("\nTexto original: %s\n", datos.textoOriginal);
    printf("Texto cifrado: %s\n", datos.textoCifrado);
    
    return 0;
}