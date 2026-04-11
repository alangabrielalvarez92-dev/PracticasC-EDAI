#include<stdio.h>
int main(){
    int a,b;
    int *p1=&a;
    int*p2=&b;
    printf("Ingresa el primer número: ");
    scanf("%d",&a);
    b=*p1;
    printf("Ingresa el segundo número: ");
    scanf("%d",&b);

    printf("El numero a es: %d\n",a);
    printf("El número b es: %d\n",b);
    //a=*p2;
    //b=*p1;
    printf("El numero a es: %d\n",a);
    printf("El número b es: %d\n",b);



return 0;
}