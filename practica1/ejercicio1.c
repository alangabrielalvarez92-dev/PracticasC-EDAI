#include<stdio.h>
	int main(){
	int numeros[10];
	int i,j;
	for(i=0;i<10;i++){
		printf("Ingresa el numero %d: ",i+1);
		scanf("%d",&numeros[i]);

	}
	for(j=0;j<10;j++){
		printf("El numero %d es: %d\n",j+1,numeros[j]);

	}
return 0;
}

