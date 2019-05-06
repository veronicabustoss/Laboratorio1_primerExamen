#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct
{
    int codigoJuego; //autoincremental
    char descripcion[51];
    float importe; //mayor a cero
    int isEmpty;
}eJuegos;


int inicializarJuegos(eJuegos* lista, int len);
/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en 1 en todas las posiciones del array.
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int menuDeOpciones();
/** \brief Muestra el menu de opciones
 * \return int Return, retorna la opcion que se elige
 */


int espacioLibreJuegos(eJuegos* lista, int len);
/** \brief Indica que posicion del array esta vacia
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna el lugar que se encuentra libre
 */


int mostrarUnJuego(eJuegos* lista, int indice);
/** \brief Muestra un unico juego
 * \param lista* eJuegos Puntero del array de juegos
 * \param indice int posicion del array a ser mostrada
* \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int mostrarTodosLosJuegos(eJuegos* lista, int len);
/** \brief Muestra una lista de juegos
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */


int buscarJuegoPorId(eJuegos* lista, int len, int id);
/** \brief Busca un juego recibiendo como parámetro de búsqueda su Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \param id int Id a ser registrado
 * \return Return Devuelve la posicion que coincide con el Id ingresado, de lo contrario, devuelve -1 como error
 *
 */


int agregarJuego(eJuegos* lista, int len);
/** \brief Agrega  un array de juegos
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int tamaño del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 **/


int removerJuego(eJuegos* lista, int len, int id);
/** \brief Da de baja al juego que se encuentra por Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int largo del array
 * \param id int Id a ser registrado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */


int modificarJuegos(eJuegos* lista,int len,  int id);
/** \brief Modifica el juego que se encuentra por Id
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int Largo del array
 * \param id int Id a ser modificado
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */


int mostrarJuegos(eJuegos* lista, int len);
/** \brief Ordena el array de juegos por Importe y Descripcion de manera ascendente y descendente ,
 * \param lista* eJuegos Puntero del array de juegos
 * \param len int Largo del array
 * \return int Return devuelve -1 si hay error, o devuelve 0 si esta todo bien
 */


int agregarJuegoConParametro(eJuegos* lista, char *descripcion , float precio,int len);
/** \brief Agrega juegos con parametros, la descripcion y el precio
 * \param eJuegos* lista Puntero del array de juego
 * \param char* descripcion la descripcion del juego
 * \param float precio el precio del juego
 * \param int len tamaño del array de juegos
 * \return int Return , retorna -1 si hay error, o retorna 0 si esta todo bien
 */



void hardcodearJuegos(eJuegos juegos[], int len);
/** \brief Se muestran distintos juegos cargados con la funcion agregarJuegoConParametros
 * \param eJuegos juegos[] cadena de juegos a ser utilizada
 * \param int len tamaño del array de juegos
 */




#endif
