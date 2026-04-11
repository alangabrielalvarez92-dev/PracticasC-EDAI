#include <stdio.h>

void registrarProducto();
void mostrarproductos();
double calcularDescuento(double precio);
void clasificarProducto(char tipo);
int factorial(int n);


int codigo[40];
double precio[40];
char tipo[40];
int productostotales = 0;
int i;


int main() {
    int opcion;

    do {
        printf("\n===== Sistema de Punto de Venta =====\n");
        printf("1. Registrar producto.\n");
        printf("2. Calcular factorial promocional.\n");
        printf("3. Mostrar los productos registrados\n");
        printf("4. Salir.\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarProducto();
                break;

            case 2: {
                int numero;
                printf("Ingresa el número para el factorial: ");
                scanf("%d", &numero);

                if (numero < 0) {
                    printf("No existe factorial para números negativos.\n");
                } else {
                    printf("Factorial de %d = %d\n", numero, factorial(numero));
                }
                break;
            }

            case 3:
                mostrarproductos();
                break;

            case 4:
                printf("Saliendo del sistema...\n");
                break;

            default:
                printf("Opción no válida...\n");
        }

    } while (opcion != 4);

    return 0;
}


void registrarProducto() {

    if(productostotales >= 40){
        printf("Se llego al limite de productos registrados\n");
        return ;
    }

    printf("\nIngresa el código del producto: ");
    scanf("%d", &codigo[productostotales]);

    printf("Ingresa el precio: ");
    scanf("%lf", &precio[productostotales]);

    printf("Ingresa el tipo O=Orgánico, P=Procesado, L=Líquido: ");
    scanf(" %c", &tipo[productostotales]);

    char continuar;

    printf("¿Deseas simular un descuento? (s/n): ");
    scanf(" %c", &continuar);

    if (continuar == 's') {
        double descuento = calcularDescuento(precio[productostotales]);
        printf("Precio con descuento: %.2f\n", descuento);
        precio[productostotales] = descuento;
    }

    clasificarProducto(tipo[productostotales]);

    printf("¿Deseas simular incremento de precio? (s/n): ");
    scanf(" %c", &continuar);

    while (continuar == 's') {
        precio[productostotales] += 5;
        printf("Nuevo precio: %.2f\n", precio[productostotales]);

        printf("¿Continuas incrementando? (s/n): ");
        scanf(" %c", &continuar);
    }

    productostotales++;
}

void mostrarproductos() {

    if(productostotales == 0){
        printf("No hay productos registrados\n");
        return;
    }

    for( i=0;i<productostotales;i++){
        printf("\nProducto %d\n", i+1);
        printf("Codigo: %d\n", codigo[i]);
        printf("Precio: %.2f\n", precio[i]);
        printf("Tipo: %c\n", tipo[i]);
    }
}

double calcularDescuento(double precio) {
    double descuento = 0;

    for (i = 1; i <= 3; i++) {
        descuento += precio * 0.02;
    }

    return precio - descuento;
}

void clasificarProducto(char tipo) {
    switch (tipo) {
        case 'O': printf("Producto orgánico\n"); break;
        case 'P': printf("Producto procesado\n"); break;
        case 'L': printf("Producto líquido\n"); break;
        default: printf("Tipo no válido\n");
    }
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
