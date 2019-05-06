#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "alquileres.h"
#include "utn.h"
#include "clientes.h"
#include "juegos.h"
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaIngreso;
    int isEmpty;

}eAlquileres;


int inicializarAlquiler(eAlquileres* lista, int len);
/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */


int espacioLibreAlquiler(eAlquileres* lista, int len);
/** \brief Indica que posicion del array esta vacia
 * \param lista* eAlquileres Puntero del array de alquileres
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */


int altaAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Agrega un array de clientes
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenCliente tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int elegirJuego(eJuegos* listaJuegos, int len);
/** \brief elige un juego existente por id
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int len tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna el id del juego que se encontro
 */


int elegirCliente(eCliente* listaCliente, int len);
/** \brief elige un cliente existente por id
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int len tamaño del array de cliente
 * \return int Return , retorna -1 si hay error, o retorna el id del cliente que se encontro
 */


int mostrarUnAlquiler(eAlquileres* lista, int indice);
/** \brief Muestra un alquiler
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int indice indice del cliente a ser mostrado
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int mostrarTodosLosAlquileres(eAlquileres* lista, int len);
/** \brief Muestra una lista de alquileres
 * \param eCliente* listaCliente Puntero del array de cliente
 * \param int indice indice del cliente a ser mostrado
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int altaAlquileresConParametros(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente , int idJuego, int idCliente, int dia, int mes, int anio );
/** \brief Agrega alquileres con parametros
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenCliente tamaño del array de clientes
 * \param int idJuego id de juego a ser cargado
 * \param int idCliente id de cliente a ser cargado
 * \param int dia dia a ser cargado
 * \param int mes mes a ser cargado
 * \param int anio anio a ser cargado
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


void hardcodearAlquileres(eAlquileres alquileres[], int lenAlquileres , eCliente cliente[], int lenCliente, eJuegos juegos[], int lenJuegos);
/** \brief Se muestran distintos alquileres cargados con la funcion altaAlquileresConParametros
 * \param eAlquileres alquileres[] Array de cliente
 * \param int lenAlquileres tamaño del array de alquileres
 * \param eCliente cliente[]  Array de cliente
 * \param int lenCliente tamaño del array de cliente
 * \param eJuegos juegos[] Array de cliente
 * \param int lenJuegos tamaño del array de juegos
 */


#endif
