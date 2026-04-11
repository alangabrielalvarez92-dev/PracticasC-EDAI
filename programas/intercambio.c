#include<stdio.h>
void interValores(int *x,int *y);
int main(){
    int a,b;
    printf("Ingresa el primer número: ");
    scanf("%d",&a);
    printf("Ingresa el segundo número: ");
    scanf("%d",&b);
    
    printf("Valor del primer número antes: %d\n",a);
    printf("Valor del segundo número antes: %d\n",b);
    //Se manda llamar la función interValores para intercambiarles el valor 
    //se mandan las direcciones de memoria
    interValores(&a,&b);
    
    printf("Valor del primer número ahora: %d\n",a);
    printf("Valor del segundo número ahora: %d\n",b);


    return 0;
}
void interValores(int *x,int*y){
int temp;
temp=*x;
*x=*y;
*y=temp;
}