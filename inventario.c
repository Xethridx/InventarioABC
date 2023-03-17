#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estructura para los productos
typedef struct {
    char nombre[50];
    int cantidad;
    float costo;
    float total;
} Producto;

// Función para calcular el total y la clasificación ABC
void calcularABC(Producto productos[], int n) {
    int i, j;
    float sum = 0.0, porc = 0.0;
    // Calcular el total
    for (i = 0; i < n; i++) {
        productos[i].total = productos[i].cantidad * productos[i].costo;
        sum += productos[i].total;
    }
    // Calcular el porcentaje acumulado y la clasificación
    for (i = 0; i < n; i++) {
        porc += productos[i].total / sum * 100;
        if (porc <= 80.0) {
            printf("%-10s %-10d %-10.2f %-10.2f A\n", productos[i].nombre, productos[i].cantidad, productos[i].costo, productos[i].total);
        } else if (porc <= 95.0) {
            printf("%-10s %-10d %-10.2f %-10.2f B\n", productos[i].nombre, productos[i].cantidad, productos[i].costo, productos[i].total);
        } else {
            printf("%-10s %-10d %-10.2f %-10.2f C\n", productos[i].nombre, productos[i].cantidad, productos[i].costo, productos[i].total);
        }
    }
}

int main() {
    int n, i;
    Producto productos[MAX];
    // Pedir el número de productos
    printf("Ingrese el número de productos: ");
    scanf("%d", &n);
    // Pedir los datos de cada producto
    for (i = 0; i < n; i++) {
        printf("\nIngrese los datos del producto %d:\n", i + 1);
        printf("Nombre: ");
        scanf("%s", productos[i].nombre);
        printf("Cantidad: ");
        scanf("%d", &productos[i].cantidad);
        printf("Costo unitario: ");
        scanf("%f", &productos[i].costo);
    }
    // Mostrar la tabla de clasificación ABC
    printf("\nTabla de clasificación ABC:\n");
    printf("%-10s %-10s %-10s %-10s %-10s\n", "Nombre", "Cantidad", "Costo", "Total", "Clasificación");
    calcularABC(productos, n);
    // Mostrar el listado de productos A, B y C
    printf("\nListado de productos:\n");
    printf("Productos A:\n");
    for (i = 0; i < n; i++) {
        if (productos[i].total / productos[0].total * 100 <= 80.0) {
            printf("%s\n", productos[i].nombre);
        }
    }
    printf("\nProductos B:\n");
    for (i = 0; i < n; i++) {
        if (productos[i].total / productos[0].total * 100 > 80.0 && productos[i].total / productos[0].total * 100 <= 95.0) {
            printf("%s\n", productos[i].nombre);
        }
    }
 // Mostrar los productos C
printf("\nProductos C:\n");
for (i = 0; i < n; i++) {
if (productos[i].total / productos[0].total * 100 > 95.0) {
printf("%s\n", productos[i].nombre);
}
}
return 0;
}
