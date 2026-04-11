#include<stdio.h>
int main(){
    int num;
    int *p=&num;
    printf("Ingresa un numero entero: ");
    scanf("%d",&num);
    printf("Número original: %d\n",num);
    *p=*p*2;
    printf("Número cambiando: %d\n",num);

return 0;
}