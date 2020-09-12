#include <stdio.h>
#include <stdlib.h>
#include "Calculadora.h"

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
        switch(menu())
        {
            case '1':
                printf("Primer numero: \n");
                scanf("%d", &numero1);
                getch();
                break;
            case '2':
                 printf("Segundo numero: \n");
                 scanf("%d", &numero2);
                 getch();
                 break;
            case '3':
                printf("Opcion: \n");
                scanf("%d", &opcion);
                getch();
                break;
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
                    printf("Resultado: %.1f\n", division(numero1, numero2));
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
            case '4':
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

