#include<stdio.h>
void calcPromPares (int *, int n);
int main(){
    int n;
    int num[500];
    int*p=&num[0];
    float promedio;

    printf("¿Cuántos datos vas a ingresar? ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
     printf("Ingresa el dato %d ",i+1) ;
     scanf("%d",&num[i]);
     
    }
    calcPromPares(num,n);
    
    return 0;
}

void calcPromPares(int *num,int n){
    float sumaPar=0;
    int contPar,contImp=0;
    float sumaImp=0;
    //Ciclo para recorrer el arreglo con apuntador
    for (int i = 0; i < n; i++)
    {
        if ((*(num+i))%2==0)
        {
            sumaPar+=*(num+i);
            contPar++;      
        }
        else{
            sumaImp+=(*num+i);
            contImp++;
        }
        
    }
    printf("El promedio de los elementos pares es: %.3f\n",sumaPar/contPar);
    printf("El promedio de los elementos impares es: %.3f\n",sumaImp/contImp);
    
    
}

