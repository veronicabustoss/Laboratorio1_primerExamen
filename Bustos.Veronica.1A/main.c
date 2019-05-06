#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juegos.h"
#define JUEGOS 1000
#include "clientes.h"
#define CLIENTES 1000
#include "alquileres.h"
#define ALQUILERES 1000
#include "informes.h"

int main()
{
    char seguir  = 's';

    eJuegos juegosInfantiles[JUEGOS];
    eCliente clientes[CLIENTES];
    eAlquileres alquileres[ALQUILERES];
    int lugarLibreJuegos;
    int lugarLibreCliente;
    int flagJuegos=0;
    int flagClientes=0;
    int flagHardcodeo=0;
    int flagAlquileres=0;
    inicializarJuegos(juegosInfantiles, JUEGOS);
    incializarClientes(clientes, CLIENTES);
    inicializarAlquiler(alquileres, ALQUILERES);

    do
    {
        switch(menuDeOpciones())
        {
        case 1:
            flagJuegos=1;
            lugarLibreJuegos=espacioLibreJuegos(juegosInfantiles, JUEGOS );
            if(lugarLibreJuegos!=-1)
            {
                agregarJuego(juegosInfantiles, JUEGOS);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 2:
            if(flagJuegos==1)
            {
                modificarJuegos(juegosInfantiles, JUEGOS, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 3:
            if(flagJuegos==1)
            {
                removerJuego(juegosInfantiles, JUEGOS, lugarLibreJuegos);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            if(flagJuegos==1)
            {
                mostrarJuegos(juegosInfantiles, JUEGOS);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            flagClientes=1;
            lugarLibreCliente=espacioLibreCliente(clientes, CLIENTES );
            if(lugarLibreCliente!=-1)
            {
                agregarCliente(clientes, CLIENTES);
            }
            else
            {
                printf("No hay espacio libre!!\n");
            }

            system("pause");
            system("cls");
            break;
        case 6:
            if(flagClientes==1)
            {
                modificarCliente(clientes, CLIENTES, lugarLibreCliente);

            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            if(flagClientes==1)
            {
                removerCliente(clientes, CLIENTES, lugarLibreCliente);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            if(flagClientes==1)
            {
                mostrarCliente(clientes, CLIENTES);
            }
            else
            {
                printf("No se ingresaron datos!\n");
            }
            system("pause");
            system("cls");
            break;
        case 9:
            if(flagClientes==1 && flagJuegos==1)
            {
                altaAlquileres(alquileres, ALQUILERES, juegosInfantiles, JUEGOS, clientes, CLIENTES);
            }
            else
            {
                printf("No hay datos que mostrar!\n");
            }
            system("pause");
            system("cls");
            break;
        case 10:
            seguir  = 'n';
            break;
        case 11:
            if(flagHardcodeo==0)
            {
                hardcodearClientes(clientes, CLIENTES);
                hardcodearJuegos(juegosInfantiles, JUEGOS);
                hardcodearAlquileres(alquileres, ALQUILERES, clientes, CLIENTES, juegosInfantiles, JUEGOS);
                flagClientes = 1;
                flagJuegos = 1;
                flagHardcodeo=1;
                printf("Hardcodeo con exito!!\n");
            }
            else
            {
                printf("Ya se ha realizado el hardcodeo antes\n");
            }

            system("pause");
            system("cls");
            break;
        case 12:
            if((flagClientes != 0 && flagJuegos != 0 && flagAlquileres != 0 ) || flagHardcodeo !=0 )
            {
                system("cls");
                informes(alquileres, ALQUILERES, juegosInfantiles, JUEGOS, clientes, CLIENTES);
                system("pause");
            }
            else
            {
                printf("Error, no se ingresaron todos los datos.\n");
                system("pause");
                 system("cls");
            }


            break;
        default:
            printf("Se ingresaron mal los datos\n");
            system("pause");
            system("cls");
        }

    }
    while(seguir == 's');

    return 0;
}
