#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED
#endif // CALCULADORA_H_INCLUDED

/** \brief  devuelve el menu de opciones
 *
 * \return char muestra el menu
 *
 */
char menu();
/** \brief devuelve la suma de los parametros
 *
 * \param a int primer valor a sumar
 * \param b int segundo valor a sumar
 * \return int la suma de los parametros
 *
 */
int suma(int a, int b);
/** \brief devuelve la resta de los parametros
 *
 * \param a int primer valor a restar
 * \param b int segundo valor a restar
 * \return int la resta de los parametros
 *
 */
int resta(int a, int b);
/** \brief devuelve la division de los parametros
 *
 * \param a float primer valor a dividir
 * \param b float segundo valor a dividir
 * \return float la division de los parametros
 *
 */
float division(float a, float b);
/** \brief devuelve la multiplicacion de los parametros
 *
 * \param a int primer valor a multiplicar
 * \param b int segundo valor a multiplicar
 * \return int la multiplicacion de los paramentros
 *
 */
int multiplicacion(int a, int b);
/** \brief devuelve el factorial de los parametros
 *
 * \param numero int valor para hacer factorial
 * \return long long int el factorial del parametro
 *
 */
long long int factorial(int numero);

