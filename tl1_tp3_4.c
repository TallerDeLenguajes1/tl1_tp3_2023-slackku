#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
                                 // “CantidadProductosAPedir”
} typedef Cliente;

void reqQuantityClients(int *cantidad);
void memoryAssignment(int cantidad, Cliente *lista);
void memoryRelease(int cantidad, Cliente *lista);
void chargeProductsR(int cantidadProducts, Producto *lista, char **ypeProd);
void chargeClients(int cantidadClients, Cliente *lista, char **typeProd);
void showAll(int cantidadClients, Cliente *lista, char **typeProd);
float calculatePrice(Producto product);

void main()
{
    srand(time(NULL));
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int cantidad_Clientes;
    printf("|==================================|\n");
    printf("|   SISTEMA DE CARGA PREVENTISTAS  |\n");
    printf("|==================================|\n");

    reqQuantityClients(&cantidad_Clientes);
    Cliente *lista = (Cliente *)malloc(sizeof(Cliente) * cantidad_Clientes);
    memoryAssignment(cantidad_Clientes, lista);
    chargeClients(cantidad_Clientes, lista, TiposProductos);
    showAll(cantidad_Clientes, lista, TiposProductos);
    memoryRelease(cantidad_Clientes, lista);
}

void reqQuantityClients(int *cantidad)
{
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", cantidad);
    if (*cantidad > 5)
    {
        printf("Error. A superado la maxima cantidad\n");
        reqQuantityClients(cantidad);
    }
}

void memoryAssignment(int cantidadClients, Cliente *lista)
{

    for (int i = 0; i < cantidadClients; i++)
    {
        int cantidadProds = 1 + rand() % (5 - 1) + 1;
        (lista + i)->CantidadProductosAPedir = cantidadProds;
        (lista + i)->Productos = (Producto *)malloc(sizeof(Producto) * cantidadProds);
    }
}

void chargeProductsR(int cantidadProducts, Producto *lista, char **typeProd)
{
    for (int i = 0; i < cantidadProducts; i++)
    {
        (lista + i)->ProductoID = i + 1;
        (lista + i)->Cantidad = 1 + rand() % (10 - 1) + 1;
        (lista + i)->PrecioUnitario = 1 + rand() % (100 - 10) + 10;
        int type = rand() % (5 - 1) + 1;
        (lista + i)->TipoProducto = (char *)malloc(sizeof(char) * (strlen(*(typeProd + type)) + 1));
        strcpy((lista + i)->TipoProducto, *(typeProd + type));
    }
}

float calculatePrice(Producto product)
{
    return product.Cantidad * product.PrecioUnitario;
}

void chargeClients(int cantidadClients, Cliente *lista, char **typeProd)
{
    char *buffer = (char *)malloc(sizeof(char) * 50);
    for (int i = 0; i < cantidadClients; i++)
    {
        (lista + i)->ClienteID = 1 + i;
        printf("Cliente %d\n", i + 1);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(buffer);
        (lista + i)->NombreCliente = (char *)malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy((lista + i)->NombreCliente, buffer);
        chargeProductsR((lista + i)->CantidadProductosAPedir, (lista + i)->Productos, typeProd);
    }
    free(buffer);
}

void showAll(int cantidadClients, Cliente *lista, char **typeProd)
{
    for (int i = 0; i < cantidadClients; i++)
    {
        float finalPrice = 0;
        printf("|==================================|\n");
        printf("|             CLIENTE              |\n");
        printf("|==================================|\n");
        printf("Id del cliente: %d\n", (lista + i)->ClienteID);
        printf("Nombre del Cliente: %s\n", (lista + i)->NombreCliente);
        printf("Cantidad de productos: %d\n", (lista + i)->CantidadProductosAPedir);
        printf("|---------------------------------|\n");
        printf("|             PRODUCTOS           |\n");
        printf("|---------------------------------|\n");
        for (int j = 0; j < (lista + i)->CantidadProductosAPedir; j++)
        {
            printf("Id del producto : %d\n", (lista + i)->Productos[j].ProductoID);
            printf("Tipo de producto: %s\n", (lista + i)->Productos[j].TipoProducto);
            printf("Cantidad del producto: %d\n", (lista + i)->Productos[j].Cantidad);
            printf("Precio unitario: %.2f\n", (lista + i)->Productos[j].PrecioUnitario);
            printf("|-----------------------------------|\n");
            finalPrice += calculatePrice((lista + i)->Productos[j]);
        }
        printf("Costo total del producto: %.2f\n", finalPrice);
        printf("|==================================|\n");
    }
}

void memoryRelease(int cantidad, Cliente *lista)
{
    for (int i = 0; i < cantidad; i++)
    {
        free((lista + i)->Productos);
    }
    free(lista);
}