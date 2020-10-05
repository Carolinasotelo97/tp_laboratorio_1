#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArraysEmployee.h"
#include "MenuOpciones.h"

char menu ()
{
    char opcion;
    system("cls");

        printf("*** Menu de opciones*** \n\n");
        printf("1.- Alta\n");
        printf("2.- Modificar\n");
        printf("3.- Baja\n");
        printf("4.- Informar\n");
        printf("5.- Salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

    return opcion;
}

