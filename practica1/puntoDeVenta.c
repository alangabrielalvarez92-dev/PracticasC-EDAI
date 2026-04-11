#include<stdio.h>
void registrarProducto(int contador,int r);
double calcularDescuento(double precio);
void clasificarProducto(char tipo);
int factorial (int n);

int main(){
    int opcion;
    int contProductos=0;
    int r;
    do{
        printf("\n===== Sistema de Punto de Venta =====\n");
        printf("1. Registrar producto.\n");
        printf("2. Calcular factorial promocional.\n");
        printf("3. Mostrar productos.\n");
        printf("4. Salir.\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            r=1;
            contProductos+=1;
           registrarProducto(contProductos,r);

            break;
        case 2:
            int numero;
            printf("Ingresa el número para el factorial: ");
            scanf("%d",&numero);

            if (numero<0)
            {
                printf("No existe factorial para números negativos.\n");
            }else{
                printf("Factorial de %d = %d\n",numero,factorial(numero));
            }
            
            break;
        case 3:
            r=2;
            
            registrarProducto(contProductos,r);

            break;
        case 4:
            printf("Gracias por su confianza. Buen dia\n");
            break;    
        default:
            printf("Opción no válida...\n");
            break;
        }
        
    }while (opcion!=3);
    return 0;
}
void registrarProducto(int contador,int r){
    int codigo;
    double precio;
    char tipo;
    char continuar;
    int cont=contador;
    int op=r;
    
 
    printf("\nIngresa el código del producto: ");
    scanf("%d",&codigo);

    printf("Ingresa el precio: ");
    scanf("%lf",&precio);

    printf("\nIngresa el tipo de producto, O=Orgánico, P=Procesado, L=Líquido: ");
    scanf(" %c",&tipo);

    registro(codigo,precio,tipo,cont,r);
    clasificarProducto(tipo);

    printf("¿Deseas simular un descuento? (s/n): ");
    scanf(" %c",&continuar);
    if (continuar=='s')
    {
        double descuento=calcularDescuento(precio);
        printf("Precio con descuento: %.2f\n",descuento);
        precio=descuento;
    }else{
        printf("El producto se queda con precio regular.\n");
    }
    
    printf("¿Deseas simular incremento de precio? (s/n): ");
    scanf(" %c",&continuar);

    while (continuar=='s')
    {
        precio+=5;
        printf("Nuevo precio: %.2f\n",precio);

        printf("¿Continuar incrementando? (s/n): ");
        scanf(" %c",&continuar);
    }

}
double calcularDescuento(double precio){
    double descuento=0;

    int i;
    for (i =1 ; i <=3; i++)    {
        descuento+=precio*0.02;
    }
 return precio-descuento;   
}
void clasificarProducto(char tipo){
switch (tipo)
{
case 'O':
    printf("Es un producto orgánico.\n");
    break;
case 'P':
    printf("Es un producto procesado.\n");
    break;
case 'L':
    printf("Es un producto líquido.\n");
default:
    printf("Tipo no válido.\n");
    break;
}
}
int factorial(int n){
    if (n<=1){
    return 1;
    }else{
        return n*factorial(n-1);
    }
    
}
