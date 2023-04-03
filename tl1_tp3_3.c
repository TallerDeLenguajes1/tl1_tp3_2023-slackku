#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE_LIST 5

void main()
{
    char *buff, *nombre;
    char **listaNombres = (char **)malloc(sizeof(char *) * SIZE_LIST);
    buff = (char *)malloc(sizeof(char *) * 100);

    for (int i = 0; i < SIZE_LIST; i++)
    {
        printf("Ingrese el nombre: ");
        gets(buff);
        *(listaNombres + i) = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(*(listaNombres + i), buff);
        printf("| Muestreo | %d: ", i + 1);
        puts(*(listaNombres + i));
    }
    for (int i = 0; i < SIZE_LIST; i++)
    {
        free(*(listaNombres + i));
    }
    free(listaNombres);
    free(buff);
}
