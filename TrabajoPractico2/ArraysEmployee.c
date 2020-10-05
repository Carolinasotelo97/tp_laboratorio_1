#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArraysEmployee.h"
#include "MenuOpciones.h"


int inicializarPersonas(eEmployee individuo[], int tam)
{
    int error = 1;

    if(individuo!= NULL && tam > 0)
    {
        for(int i=0; i< tam; i++)
        {
            individuo[i].isEmpty=1;
        }
        error=0;
    }

    return error;
}


void mostrarPersona(eEmployee persona)
{
    printf("   %4d  %20s  %20s  %4d  %1d\n", persona.id, persona.nombre, persona.apellido, persona.salario, persona.sector);

}

int mostrarPersonas(eEmployee individuo[], int tam)
{
    int error = 1;
    int flag = 0;
    if(individuo!= NULL && tam > 0)
    {

       // system("cls");
        printf(" id    Nombre    Apellido    Salario     Sector\n");
        printf("----------------------------------------------\n");

        for(int i=0; i < tam; i++)
        {
            if(individuo[i].isEmpty == 0)
            {
                mostrarPersona(individuo[i]);
                flag = 1;
            }
        }

        if(flag == 0)
        {
            printf("No hay personas en la lista.");
        }
        printf("\n\n");
    }

        return error;
}

int buscarLibre(eEmployee individuo[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i ++)
    {
        if(individuo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaPersona(eEmployee individuo[], int tam, int id)
{
    int error = 1;
    int indice;
    eEmployee nuevaPersona;

    if(individuo != NULL && tam > 0 && id > 0 )
    {
        system("cls");
        printf(" ****ALTA DE PERSONAS****\n\n");

        indice = buscarLibre(individuo, tam);

      if(indice == -1)
        {
            printf("El sistema esta completo.\n");
        }else
        {
            nuevaPersona.id = id;
            nuevaPersona.isEmpty = 0;

            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(nuevaPersona.nombre);

            printf("Ingrese Apellido: ");
            fflush(stdin);
            scanf("%s", nuevaPersona.apellido);

            printf("Ingrese Salario: ");
            scanf("%d", &nuevaPersona.salario);

            printf("Ingrese Sector: ");
            fflush(stdin);
            scanf("%d", &nuevaPersona.sector);

            individuo[indice] = nuevaPersona;

            error = 0;
        }
    }

    return error;
}


int buscarPersona(eEmployee individuo[], int tam, int id)
{
      int indice = -1;

    for(int i=0; i < tam; i ++)
    {
        if(individuo[i].id == id && individuo[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int bajaPersona(eEmployee individuo[], int tam)
{
    int error = 1;
    int id;
    int indice;
    char confirma;

    if(individuo != NULL && tam > 0)
    {
        system("cls");
        printf("   *** Baja de persona *** \n\n");

        mostrarPersonas(individuo, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarPersona(individuo, tam, id);

        if(indice == -1)
        {
            printf("No existe una persona con ese id\n\n");
        }else
        {
            mostrarPersona(individuo[indice]);
            printf("Confirma baja: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                individuo[indice].isEmpty = 1;
                error = 0;
            }else
            {
                printf("La baja se ha cancelado por el usuario\n\n");
            }
        }
    }

    return error;
}

int modificarPersona(eEmployee individuo[], int tam)
{

    int error = 1;
    int indice;
    int id;
    char confirma;
    char opcionMod;
    char nombreAux[51];
	char apellidoAux[51];
	int salarioAux;
	int sectorAux;
	eEmployee nuevosDatos;

    if(individuo != NULL && tam > 0)
    {

        system("cls");
        printf("   *** Modificar persona *** \n\n");

        mostrarPersonas(individuo, tam);
        printf("Ingrese el id: ");
        scanf("%d", &id);

        indice = buscarPersona(individuo, tam, id);

        if(indice == -1)
        {
            printf("No existe una persona con ese id\n\n");
        }else
        {
            mostrarPersona(individuo[indice]);

            system("cls");
            printf("****MODIFICACION****\n\n");
            printf("\n a.- Nombre\n");
            printf("\n b.- Apellido\n");
            printf("\n c.- Salario\n");
            printf("\n d.- Sector\n");
            printf("\n Ingrese la opcion que desee modificar: ");
            fflush(stdin);
            scanf("%c", &opcionMod);

            system("cls");
            switch(opcionMod)
            {
                case 'a':
                    mostrarPersona(individuo[indice]);
                    printf("\n Ingrese nuevo nombre: ");
                    gets(nombreAux);
                 break;
                case 'b':
                    mostrarPersona(individuo[indice]);
                    printf("\n Ingrese nuevo apellido: ");
                    fflush(stdin);
                    scanf("%c", apellidoAux);
                break;
                case 'c':
                    mostrarPersona(individuo[indice]);
                    printf("\n Ingrese nuevo salario: ");
                    scanf("%d", &salarioAux);
                break;
                case 'd':
                    mostrarPersona(individuo[indice]);
                    printf("\n Ingrese nuevo sector: ");
                    scanf("%d", &sectorAux);
                 break;
                default:
                     printf("Opcion invalida!!!\n");
            }
            system("pause");

            printf("\nConfirma modificacion?: ");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                strcpy(individuo[indice].nombre, nombreAux);
                strcpy(individuo[indice].apellido, apellidoAux);
                individuo[indice].salario = salarioAux;
                individuo[indice].sector = sectorAux;
                mostrarPersona(nuevosDatos);
                error = 0;
            }else
            {
                error=2;

            }
        }

    }
    return error;
}



int ordernarPersonasNombre(eEmployee individuo[], int tam, int criterio)
{
    int error = 1;
    eEmployee auxPersona;

    if(individuo != NULL && tam > 0 && criterio >= 0 && criterio <= 1)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i +1; j < tam; j++)
            {
                if(strcmp(individuo[i].nombre, individuo[j].nombre) > 0 && criterio)
                {
                    auxPersona = individuo[i];
                    individuo[i] = individuo[j];
                    individuo[j] = auxPersona;
                }else if(strcmp(individuo[i].nombre, individuo[j].nombre) >  0 && !criterio)
                 {
                    auxPersona = individuo[i];
                    individuo[i] = individuo[j];
                    individuo[j] = auxPersona;
                 }
            }
        }
        error =0;
    }
    return error;
}

int ordernarPersonasApellidoSector(eEmployee individuo[], int tam)
{
   int error = 1;
    eEmployee auxPersona;

    if(tam >0 && individuo != NULL )
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i +1; j < tam; j++)
            {
                if(individuo[i].isEmpty == 0 && individuo[j].isEmpty== 0)
                {
                    if(individuo[i].sector > individuo[j].sector && stricmp(individuo[i].nombre, individuo[j].nombre)>0)
                    {
                        auxPersona = individuo[i];
                        individuo[i] = individuo[j];
                        individuo[j] = auxPersona;

                    }else if( individuo[i].sector < individuo[j].sector && stricmp(individuo[i].nombre, individuo[j].nombre)<0)
                     {
                        auxPersona = individuo[i];
                        individuo[i] = individuo[j];
                        individuo[j] = auxPersona;
                     }
                }
                error =0;
            }

        }
    }
    return error;
}

void informarPersonas(eEmployee individuo[], int tam)
{
    char opcSalario;
    int cantPersonas;
    int cantidadPersonasMasSalario;
    float total;
    int error = 1;
    char confirma ='s';
    float promedioSalarios;


        if(individuo != NULL && tam >0)
        {
                system("cls");
                printf(" ****** INFORMAR *****\n\n");
                printf("\n a.- Listado ordenado alfabeticamente por apellido y sector\n");
                printf("\n b.- Total y promedio de salarios\n");
                printf("\n Ingrese opcion: ");
                fflush(stdin);
                scanf("%c", &opcSalario);
                mostrarPersonas(individuo, tam);

                system("cls");

                    switch(opcSalario)
                    {
                        case 'a':
                            mostrarPersonas(individuo, tam);
                            ordernarPersonasApellidoSector(individuo, tam);
                            error =0;
                        break;
                        case 'b':
                            mostrarPersonas(individuo, tam);
                            total = totalSalarios(individuo, tam);
                            cantPersonas = contarPersonas(individuo, tam);
                            promedioSalarios = total / cantPersonas;
                            cantidadPersonasMasSalario = contarPersonasMasSalario(individuo, tam, promedioSalarios);
                            mostrarSalarios(total, promedioSalarios, cantidadPersonasMasSalario);
                            error = 0;
                        break;
                        default:
                            printf("\n Opcion invalida");
                    }

                     if(confirma == 's')
                    {

                        error = 0;
                    }else
                    {
                        error = -1;
                    }
         }
         return error;
}




int contarPersonasMasSalario(eEmployee individuo[], int tam,  float promedioSalarios)
{
    int contadorPersonas = 0;

    for(int i = 0; i < tam; i++)
    {
        if(individuo[i].isEmpty == 0 && individuo[i].salario > promedioSalarios)
        {
            contadorPersonas++;
        }
    }
    return contadorPersonas;
}

int contarPersonas(eEmployee individuo[], int tam)
{
    int contadorPersona = 0;

    for(int i= 0; i < tam; i++)
    {
        if(individuo[i].isEmpty == 0)
        {
            contadorPersona++;
        }
    }

    return contadorPersona;
}


float totalSalarios(eEmployee individuo[], int tam)
{
    int totalSalario = 0;

    for(int i = 0; i < tam; i++)
    {
        if(individuo[i].isEmpty == 0)
        {
            totalSalario= totalSalario + individuo[i].salario;
        }
    }

    return totalSalario;
}

int mostrarSalarios(float total, float promedioSalarios, int cantPersonasMasSalario)
{
    system("cls");
    printf("Total salarios:   %.3f   ||   Promedio de sario:   %.3f     ||    Persona con mas salario:    %d\n", total, promedioSalarios, cantPersonasMasSalario);

    return 0;
}
