#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

 float promedioYTotalImporteJuegos(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);
/** \brief Calcula el promedio y total de los juegos alquilados
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna el promedio de los juegos alquilados si esta todo bien
 *
 */

int juegosQueNoSuperanPromedio(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);
/** \brief Muestra la cantidad de juegos cuyo Importe NO superan el promedio anterior (Los juegos no alquilados se incluyen)
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

 int clientesQueAlquilaronJuegoDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Muestra los clientes que alquilaron un juego determinado
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

 int juegosQueFueronAlquiladosPorClienteDeterminado(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Muestra los juegos que fueron alquilados por un cliente determinado
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */


int juegosMenosAlquilados(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos);
/** \brief Muestra los juegos que fueron alquilados menos cantidad de veces (incluyendo los juegos no alquilados)
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

 int clienteConMasAlquileres(eAlquileres* listaAlquileres, int lenAlquileres, eCliente* listaClientes,int lenClientes);
/** \brief Muestra los clientes que realizaron muchos alquileres
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */
 int juegoAlquiladosEnFechaDeterminada(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Muestra los juegos que fueron alquilados en una determinada fecha
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */


 int clientesQueAlquilaronEnFechaDeterminada(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Muestra los clientes que alquilaron en una fecha determinada
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */


 int listarJuegoPorBurbujeoDescendente(eJuegos *listaJuegos, int lenJuegos);
/** \brief Lista todos los juegos ordenados por Importe(descendente) con el metodo de burbujeo
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

int ordenarClientesPorInsercion(eCliente *pClientes, int largoClientes);
/** \brief Lista todos los clientes por metodo de insercion por apellido ascendente
 *
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

 int informes(eAlquileres* listaAlquileres, int lenAlquileres, eJuegos* listaJuegos,int lenJuegos,eCliente* listaCliente,int lenCliente );
/** \brief Muestra una lista de todos los informes
 *
 * \param eAlquileres* listaAlquileres Puntero del array de alquileres
 * \param int lenAlquileres Tamaño del array de alquileres
 * \param eJuegos* listaJuegos Puntero del array de juegos
 * \param int lenJuegos Tamaño del array de juegos
 * \param eCliente* listaCliente Puntero del array de clientes
 * \param int lenClientes Tamaño del array de clientes
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 *
 */

#endif
