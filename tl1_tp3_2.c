#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarMatriz(int matriz[5][12]);
void mostrarMatriz(int matriz[5][12]);
void promedioAnio(int matriz[5][12]);
void mostrarMinMaxMatriz(int matriz[5][12]);
void main()
{
    srand(time(NULL));
    int produccion[5][12];
    printf("Desarrollo del punto 2.a (Carga)\n...\n");
    cargarMatriz(produccion);
    printf("Desarrollo del punto 2.b\n");
    mostrarMatriz(produccion);
    printf("Desarrollo del punto 2.c\n");
    promedioAnio(produccion);
    printf("Desarrollo del punto 2.d\n");
    mostrarMinMaxMatriz(produccion);
}

void cargarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = 1 + rand() % (50000 - 10000) + 10000;
        }
    }
}

void mostrarMatriz(int matriz[5][12])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("| %d ", matriz[i][j]);
            if (j == 11)
            {
                printf("|");
            }
        }
        printf("\n");
    }
}

void promedioAnio(int matriz[5][12])
{
    float promedio = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            promedio += matriz[i][j];
        }
        promedio /= 12;
        printf("Promedio Mes %d: %.2f\n", i + 1, promedio);
        promedio = 0;
    }
}

void mostrarMinMaxMatriz(int matriz[5][12])
{
    int min = matriz[0][0];
    int max = matriz[0][0];
    int w_year_min, w_year_max, w_month_max, w_month_min;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                w_year_max = i + 1;
                w_month_max = j + 1;
            }
            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                w_year_min = i + 1;
                w_month_min = j + 1;
            }
        }
    }
    printf("Minimo: %d. Obtenido en el anio %d, mes %d\n", min, w_year_min, w_month_min);
    printf("Maximo: %d. Obtenido en el anio %d, mes %d\n", max, w_year_max, w_month_max);
}
