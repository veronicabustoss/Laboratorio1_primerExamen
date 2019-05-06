#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "utn.h"

typedef struct
{
    int codigoCliente;
    char apellido[51];
    char nombre[51];
    char sexo; //validar
    char domicilio[51]; //validar
    int isEmpty;

}eCliente;


int incializarClientes(eCliente* lista, int len);
/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eCliente Puntero del array de clientes
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int espacioLibreCliente(eCliente* lista, int len);
/** \brief Indica que posicion del array esta vacia
 * \param lista* eCliente Puntero del array de clientes
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */


int mostrarUnCliente(eCliente* lista, int indice);
/** \brief Muestra un unico cliente
 * \param lista* eCliente Puntero del array de clientes
 * \param indice int posicion del array a ser mostrada
 */


int mostrarTodosLosClientes(eCliente* lista, int len);
/** \brief Muestra una lista de clientes
 * \param lista* eCliente Puntero del array de clientes
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int buscarClientePorId(eCliente* lista, int len, int id);
/** \brief Busca un cliente recibiendo como parámetro de búsqueda su Id
 * \param lista* eCliente Puntero del array de clientes
 * \param len int tamaño del array
 * \param id int Id a ser registrado
 * \return Return Devuelve la posicion que coincide con el Id ingresado, de lo contrario, devuelve -1 como error
 *
 */


int agregarCliente(eCliente* lista, int len);
/** \brief Agrega en un array de cliente
 * \param lista* eCliente Puntero del array de clientes
 * \param len int tamaño del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 **/


int removerCliente(eCliente* lista, int len, int id);
/** \brief Da de baja al cliente que se encuentra por Id
 * \param lista* eCliente Puntero del array de clientes
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */


int modificarCliente(eCliente* lista,int len,  int id);
/** \brief Modifica el cliente que se encuentra por Id
 * \param lista* eCliente Puntero del array de clientes
 * \param len int Largo del array
 * \param id int Id a ser modificado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */


int mostrarCliente(eCliente* lista, int len);
/** \brief Ordena el array de clientes por Apellido y Nombre de manera ascendente .
 * \param lista* eCliente Puntero del array de clientes
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */

int agregarClienteConParametros(eCliente* lista, int len, char *apellido, char nombre[], char sexo, char* direccion);
/** \brief Agrega clientes con parametros, el apellido,  nombre, sexo y direccion
 * \param eCliente* lista Puntero del array de cliente
 * \param int len tamaño del array de clientes
 * \param char* apellido el apellido del cliente
 * \param char  nombre el nombre del cliente
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


void hardcodearClientes(eCliente clientes[], int lenCliente);
/** \brief Se muestran distintos clientes cargados con la funcion agregarClienteConParametros
 * \param eCliente clientes[] cadena de clientes a ser utilizada
 * \param int lenCliente tamañ del array de clientes
 */

#endif
