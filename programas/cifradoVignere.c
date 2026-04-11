#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

//Struct para cifrador
struct vigenere
{
    char textoOriginal[MAX];
    char textoCifrado[MAX];
    char clave[MAX];
};

char alfabeto[]="abcdefghijklmnñopqrstuvwxyz";

//función para obtener índice de una letra

int obtenerIndice(char c){

    for (int i = 0; i < 27; i++)
    {
        if (alfabeto[i]==c)
        {
            return i;
        }
        return -1;
        
    }
    
}

//función para cifrar con criterio Vigenere
void cifrar(struct vigenere *datos) {
    int i,j=0;
    int lenTexto=strlen(datos->textoOriginal);
    int lenClave=strlen(datos->clave);
    
    for ( i = 0; i < lenTexto; i++)
    {
        char letraTexto= tolower(datos->textoOriginal[i]);

        int indiceTexto=obtenerIndice(letraTexto);

        if (indiceTexto!=-1)
        {
            char letraClave=tolower(datos->clave[j%lenClave]);
            int indiceClave= obtenerIndice(letraClave);

            int nuevoIndice= (indiceTexto+indiceClave)%27;

            datos->textoCifrado[i]=alfabeto[nuevoIndice];

            j++; //Avance de cifrado
        } else{
            //Se conserva espacios y simbolos
            datos->textoCifrado[i]=datos->textoCifrado[i];
        }
        
    }
    datos->textoCifrado[i]='\0';

}
int main(){
    struct vigenere datos;

    printf("Ingrese el texto a cifrar: ");
    fgets(datos.textoOriginal,MAX,stdin);
    datos.textoOriginal[strcspn(datos.textoOriginal,"\n")]='\0';

    printf("Ingrese la clave: ");
    fgets(datos.clave,MAX,stdin);
    datos.clave[strcspn(datos.clave,"\n")]='\0';

    cifrar(&datos);

    printf("\nTexto original: %s\n", datos.textoOriginal);
    printf("Clave: %s\n",datos.clave);
    printf("Texto cifrado: %s\n",datos.textoCifrado);
    

    return 0;
}