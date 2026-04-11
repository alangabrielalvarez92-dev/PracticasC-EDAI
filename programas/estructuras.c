#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
int main(){
    char continuar='s';
    int j=0;
    struct materias
    {
        char nombre[MAX];
        char profesor[MAX];
        float promedio;
    };
    struct materias datos[MAX]; //arreglo de structs

    while (continuar=='s')  
    {
    
    printf("Ingresa el nombre de la materia: ");
    fgets(datos[j].nombre,MAX,stdin);  //se usa fgets para guardar cadenas
    datos[j].nombre[strcspn(datos[j].nombre,"\n")]='\0';

    printf("\nIngresa el nombre del profesor: ");
    fgets(datos[j].profesor,MAX,stdin);
    datos[j].profesor[strcspn(datos[j].profesor,"\n")]='\0';

    printf("\nIngresa el promedio: ");
    scanf(" %f",&datos[j].promedio);    //como se va a guardar un float en promedio se debe usar scanf

    j++;
    printf("¿Deseas seguir guardando materias? (s/n): \n");
    fgets(continuar,MAX,stdin);
    }

    for (int i = 0; i < j; i++)
    {
        printf("\n-------------Materia %d-------------\n",i+1);
        printf("Materia: %s\n",datos[i].nombre);
        printf("Profesor: %s\n",datos[i].profesor);
        printf("Promedio: %.2f\n",datos->promedio);
    }
    
   


    return 0;
}