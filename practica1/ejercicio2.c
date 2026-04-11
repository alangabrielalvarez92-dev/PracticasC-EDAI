#include<stdio.h>
int main (){
	int numeros[100];
	int i,n;
	int suma=0;
	double promedio=0;
	printf("Dame el valor de n (En un rango de 0 a 100): ");
	scanf("%d",&n);
	while (n<1||n>100){
		printf("Valor de n no valido... ingresa un valor de n entre 1 y 100");
		scanf("%d",&n);
	}
	printf("Ingresa %d numeros enteros: \n",n);
	for(i=0;i<n;i++){
		printf("Numero %d: ",i+1);
		scanf("%d",&numeros[i]);
		suma=suma+numeros[i];

	}
	promedio=suma/n;
	printf("El promedio final es: %lf\n", promedio);
return 0;
}
