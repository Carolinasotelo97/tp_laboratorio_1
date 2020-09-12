#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main()
{
    char seguir = 's';
    char confirma;
    char opcion;
    int resultado;
    int numero1;
    int numero2;
    int fact;

    do
    {
        printf("Digite el primer numero: \n");
        scanf("%d", &numero1);
        printf("Digite el segundo numero: \n");
        scanf("%d", &numero2);
        //printf("Resultado: %d\n", &resultado);
       // scanf("%d", &opcion);

        switch(menu())
        {
            case 'a':
                printf("La suma es: %d\n", suma(numero1, numero2));
                getch();
                break;
            case 'b':
                printf("La resta es: %d\n", resta(numero1, numero2));
                getch();
                break;
            case 'c':
               printf("La division es: %.1f\n", division (numero1, numero2));
                getch();
                 if(numero2 == 0)
                {
                    printf("No se puede dividir por 0. Digite otro numero\n");
                }else
                {
                    printf("Resultado: %.1f\n", &resultado);
                }
                break;
            case 'd':
              printf("La multiplicacion es: %d\n", multiplicacion(numero1, numero2));
                getch();
                break;
            case 'e':
                if(numero1<0)
                {
                    printf("No hay factorial de numero negativo\n");
                }else
                {
                    printf("El factorial de %d es: %lld\n", numero1, factorial(numero1));
                }
                getch();
                break;
            case 'f':
                printf("Confirma salida?\n: ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            default:
                printf("Opcion invalida\n");
        }
        system("pause");

    }
    while (seguir == 's');

 return 0;
}

