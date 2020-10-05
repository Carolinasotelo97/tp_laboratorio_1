#ifndef ARRAYSEMPLOYEE_H_INCLUDED
#define ARRAYSEMPLOYEE_H_INCLUDED



typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    int salario;
    int sector;
    int isEmpty;
}eEmployee;


#endif // ARRAYSEMPLOYEE_H_INCLUDED


/** \brief muestra los empleados cargados en la lista
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int
 *
 */
int mostrarPersonas(eEmployee individuo[], int tam);
/** \brief muestra los datos ingresados por el usuario
 *
 * \param persona eEmployee
 * \return void
 *
 */
void mostrarPersona(eEmployee persona);
/** \brief Indica que el array este vacio usando isEmpty
 *
 * \param individuo[] eEmployee guarda los datos
 * \param tam int marca el tamaño del array
 * \return int devuelve 1 si hay error
 *
 */
int inicializarPersonas(eEmployee individuo[], int tam);
/** \brief agrega los valores recibidos en una lista
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int me devuelve -1 si el vector esta lleno o si el indice de la primer estructura disponible.
 *
 */
int buscarLibre(eEmployee individuo[], int tam); //
/** \brief Para agregar una persona a la lista existente
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \param id int
 * \return int  devuelve 0 si pudo dar de alta y devuelve 1 si no pudo dar de alta
 *
 */
int altaPersona(eEmployee individuo[], int tam, int id);
/** \brief elimina un empleado de la lista
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int
 *
 */
int bajaPersona(eEmployee individuo[], int tam);
/** \brief modifica un dato del arrays y lo reemplaza
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int devuelve 1 si se dio la baja o 0 si cancelo la operacion
 *
 */
int modificarPersona(eEmployee individuo[], int tam);
/** \brief busca espacios libres dentro del array
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \param id int
 * \return int devuelve el indice de la posicion
 *
 */
int buscarPersona(eEmployee individuo[], int tam, int id);
/** \brief ordena la cantidad de personas cargadas en orden alfabetico
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \param criterio int es el que marca el sentido del ordenamiento 1 arriba, 0 abajo
 * \return int
 *
 */
int ordernarPersonasNombre(eEmployee individuo[], int tam, int criterio);
/** \brief ordena las personas cargadas por orden alfabetico y por sector
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int
 *
 */
int ordernarPersonasApellidoSector(eEmployee individuo[], int tam);
/** \brief muestra la opcion de ver alfabeticamente o mostrar el promedio de salarios
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return void
 *
 */
void informarPersonas(eEmployee individuo[], int tam);
/** \brief cuenta la cantidad de personas que hay cargadas
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return int devuelve la cantidad de personas
 *
 */
int contarPersonas(eEmployee individuo[], int tam);
/** \brief cuenta la cantidad de personas cargadas con mas salarios
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \param promedioSalarios float calcula el promedio de salarios
 * \return int
 *
 */
int contarPersonasMasSalario(eEmployee individuo[], int tam,  float promedioSalarios);
/** \brief suma la cantidad de salarios
 *
 * \param individuo[] eEmployee
 * \param tam int
 * \return float
 *
 */
float totalSalarios(eEmployee individuo[], int tam);
int mostrarSalarios(float totalSalarios, float promedioSalarios, int cantPersonasMasSalario);
/** \brief muestra el total de todas las operaciones
 *
 * \param
 * \param
 * \return
 *
 */
