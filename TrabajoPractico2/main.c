#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArraysEmployee.h"
#include "MenuOpciones.h"
#define TAM 1000
#define ASC 1
#define DESC 0


int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 2000;
    int respuesta;
    eEmployee lista[TAM];


    if(inicializarPersonas(lista, TAM)== 0)
    {
        printf("Personas inicializadas con exito!\n");
    }else
    {
        printf("Problemas al inicializar personas.\n");
    }

   do
    {
        switch(menu())
       {
        case '1':
            if(altaPersona(lista, TAM, proximoId) == 0)
            {
                proximoId++;
                printf("Alta exitosa\n");
            }else
            {
                printf("Problemas para realizar el alta\n");
            }
            break;
        case '2':
            respuesta = modificarPersona(lista, TAM);

            if(respuesta == 0)
            {
                printf("Modificacion exitosa!!\n\n");
            }else if(respuesta == 2)
            {
                printf("La modificaciones se ha cancelado\n\n");
            }else
            {
                printf("Se ha producido un error en la modificacion\n\n");
            }
            break;
        case '3':

            respuesta = bajaPersona(lista, TAM);
            if(respuesta == 0)
            {
                printf("Baja exitosa!!\n\n");
            }else if(respuesta == 2)
            {
                printf("La baja se ha cancelado\n\n");
            }else
            {
                printf("Se ha producido un error en la baja\n\n");
            }
            break;
        case '4':
            informarPersonas(lista, TAM);
            if(respuesta == 1)
            {
                printf("Cargue alguna personas a la lista primero");
            }
            break;
        case '5':
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
                {
                    seguir = 'n';
                }
            break;
        default:
            printf("Opcion invalida!!!\n");
        }
            system("pause");
    }
    while(seguir == 's');

        return 0;

}

