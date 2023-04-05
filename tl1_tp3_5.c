#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main()
{
    int cantidad;
    char *buff, *nombre;
    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d", &cantidad);
    fflush(stdin);
    char **listaNombres = (char **)malloc(sizeof(char *) * cantidad);
    buff = (char *)malloc(sizeof(char *) * 100);

    for (int i = 0; i < cantidad; i++)
    {
        printf("Ingrese el nombre: ");
        gets(buff);
        *(listaNombres + i) = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(listaNombres + i), buff);
    }
    printf("|===========================|\n");
    printf("|---       MUESTREO      ---|\n");
    printf("|===========================|\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("\t %d- ", i + 1);
        puts(*(listaNombres + i));
    }

    for (int i = 0; i < cantidad; i++)
    {
        free(*(listaNombres + i));
    }
    free(listaNombres);
    free(buff);
}
