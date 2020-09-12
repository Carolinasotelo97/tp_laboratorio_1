#include <stdio.h>
#include <stdlib.h>

char menu()
{
    char opcion;
    system("cls");

    printf("*** Menu de opciones*** \n\n");
    printf("1.- Ingrese el primer operando: \n");
    printf("2.- Ingresar el segundo operando: \n");
    printf("3.- Elija la operacion que desee realizar: \n");
    printf("a suma\n");
    printf("b resta\n");
    printf("c division\n");
    printf("d multiplicacion\n");
    printf("e factorial\n");
    printf("4.- Salir\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = tolower(opcion);

    return opcion;
}


int suma(int a, int b)
{
    int resultadoSuma;

    resultadoSuma = a + b;

    return resultadoSuma;
}

int resta(int a, int b)
{
    int resultadoResta;

    resultadoResta= a - b;

    return resultadoResta;
}

float division(float a, float b)
{
    float resultadoDivision;

    resultadoDivision= a / b;

    return resultadoDivision;
}

int multiplicacion(int a, int b)
{
    int resultadoMultiplicacion;

    resultadoMultiplicacion= a * b;

  return resultadoMultiplicacion;
}

long long int factorial(int numero)
{
     long long int fact = 1;

     if (numero>0)
    {
        for (int i = numero; i>0; i--)
       {
           fact = fact * i;
       }
    }

    if(numero<0)
    {
        fact = -1;
    }
    return fact;
}
