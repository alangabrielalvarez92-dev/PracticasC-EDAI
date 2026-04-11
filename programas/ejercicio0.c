#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

struct cifradoC
{
    char textoOriginal[MAX];
    char textoCifrado[MAX];
    int desplazamiento;
};

char alfabeto[]="abcdefghijklmnñopqrstuvwxyz";

//Función para encontrar índice de una letra en el alfabeto
int obtenerIndice(char c){
    for (int i = 0; i < 27; i++)
    {
        if (alfabeto[i]==c)
        {
            return i;
        }
        
    }
    return -1;
    
}

//Función de cifrado César
void cifrar (struct cifradoC *datos) 
{
    int i;
    for ( i = 0; i < datos->textoOriginal[i]!='\0'; i++)
    {
        char c=tolower(datos->textoOriginal[i]);
        int =obtenerIndice(c);
        if (indice!=-1)
        {
            int nuevoIndice=(indice)
        }
        
    }

    
};
int main (){
    struct cifradoC datos;
    printf("Ingresa el texto a cifrar: ");
    fgets(datos.textoOriginal,MAX,stdin);
    //sE ELIMINA EL SALTO DE LINEA
    datos.textoOriginal[strcspn(datos.textoOriginal,"\n")]='\0';

    printf("Ingresa el valor de desplazamiento: ");
    scanf("%d", &datos.textoOriginal);

    return 0;
}

