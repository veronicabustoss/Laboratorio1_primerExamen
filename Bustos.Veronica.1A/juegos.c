#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "juegos.h"
#include "utn.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int inicializarJuegos(eJuegos* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL )
    {
        for(i=0; i<len ; i ++)
        {
            lista[i].isEmpty=1;
        }
        retorno = 0;
    }

    return retorno;

}

int menuDeOpciones()
{
    int opcion;
    //system("cls");
    printf("-----Menu de opciones Juegos-----\n\n");
    printf("1. Alta juego \n");
    printf("2. Modificar juego \n");
    printf("3. Baja  juego \n");
    printf("4. Listar juegos \n");
    printf("-----Menu de opciones Clientes-----\n\n");
    printf("5. Alta cliente\n");
    printf("6. Modificar cliente\n");
    printf("7. Baja cliente\n");
    printf("8. Listar clientes\n");
    printf("-----Menu de opciones Alquileres-----\n\n");
    printf("9. Alta a alquiler \n");
    printf("10. Salir\n");
    printf("---------------------------\n");
    printf("11. Hardcodear juegos y clientes\n\n");
    printf("12. Informes \n\n");
    printf("Elija una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int espacioLibreJuegos(eJuegos* lista, int len)
{
    int i;
    int retorno=-1;
    if( lista != NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].isEmpty==1)
            {
                retorno=i;
                break;
            }
        }

    }
    return retorno;
}

int mostrarUnJuego(eJuegos* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
            printf("%d\t    %s\t    %.2f \n\n", lista[indice].codigoJuego, lista[indice].descripcion, lista[indice].importe);
            retorno=0;
        }
    }
    return retorno;

}

int mostrarTodosLosJuegos(eJuegos* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    DESCRIPCION\t    IMPORTE\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnJuego(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarJuegoPorId(eJuegos* lista, int len, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].codigoJuego == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarJuego(eJuegos* lista, int len)
{
    eJuegos auxiliarJuegos;
    int lugarLibre = espacioLibreJuegos(lista, len);
    int retorno=-1;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            getSuperAlfaNumerico("Ingrese descripcion del Juego: ", "Error, ingrese nuevamente.", auxiliarJuegos.descripcion);//arreglar lo de los espacios
            //getValidString("Ingrese descripcion del Juego: ", "Error, ingrese nuevamente.", auxiliarJuegos.descripcion);
            auxiliarJuegos.importe = getValidFloat("Ingrese importe del juego: ", "Error, ingrese nuevamente.", 1, 10000);
            auxiliarJuegos.codigoJuego = generarNextId();
            printf("Esta todo ok =%d \n",auxiliarJuegos.codigoJuego );
            auxiliarJuegos.isEmpty=0;
            lista[lugarLibre]=auxiliarJuegos;
            retorno=0;
        }
    }

    return retorno;
}

///Hardecoen

int agregarJuegoConParametro(eJuegos* lista, char *descripcion , float precio,int len)
{
    eJuegos auxiliarJuegos;
    int lugarLibre = espacioLibreJuegos(lista, len);
    int retorno=-1;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            strcpy(auxiliarJuegos.descripcion, descripcion );
            auxiliarJuegos.importe = precio;
            auxiliarJuegos.codigoJuego = generarNextId();
            auxiliarJuegos.isEmpty=0;
            lista[lugarLibre]=auxiliarJuegos;
            retorno=0;
        }
    }

    return retorno;
}

void hardcodearJuegos(eJuegos juegos[], int len)
{
    agregarJuegoConParametro(juegos, "Metal Slug 4", 534.54, len );
    agregarJuegoConParametro(juegos, "Earthworm Jim 2", 342.99, len );
    agregarJuegoConParametro(juegos, "Zombies", 511.43, len );
    agregarJuegoConParametro(juegos, "Stardew Valley", 511.43, len );
    agregarJuegoConParametro(juegos, "Sims", 431.49, len );
    agregarJuegoConParametro(juegos, "Overwatch", 999.99, len );
    agregarJuegoConParametro(juegos, "Albatroz", 999.99, len );
    agregarJuegoConParametro(juegos, "Dispara y acierta 2", 999.99, len );
    agregarJuegoConParametro(juegos, "Sonic 3", 204.19, len );
    agregarJuegoConParametro(juegos, "Mario Bros", 100.99, len );

}

int removerJuego(eJuegos* lista, int len, int id)
{
    int index;
    int retorno=-1;
    char pregunta;

    if(lista!=NULL)
    {
        printf("Ingrese el id del juego que desea eliminar: ");
        scanf("%d",&id);
        index=buscarJuegoPorId(lista, len, id);

        if(index==-1)
        {
            printf("No existe ese id!! \n");
        }
        else
        {
            if(lista[index].isEmpty==0)
            {
                printf("ID\t   DESCRIPCION\t   IMPORTE\n");
                mostrarUnJuego(lista, index);
                printf("Desea eliminar este juego?  s/n :");
                fflush(stdin);
                scanf("%c",&pregunta);
                if(pregunta=='s')
                {
                    printf("El juego fue eliminado!\n");
                    lista[index].isEmpty=1;
                }
                else
                {
                    printf("Borrado cancelado\n");
                }
            }
        }
        retorno=0;
    }
    return retorno;
}

int modificarJuegos(eJuegos* lista,int len,  int id)
{
    int index;
    int cambiar;
    char nuevaDescripcion[51];
    float nuevoImporte;
    int retorno=-1;
    char continuar='n';

    printf("Ingrese el Id. del juego que desea modificar:\n");
    scanf("%d", &id);
    index=buscarJuegoPorId(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t   DESCRIPCION\t   IMPORTE\n");
                mostrarUnJuego(lista, index);
                //llamar funcion que me muesstra los datos de esa posicion
                printf("\n\nSeleccione la opcion que desea modificar:");
                printf("\n1. Descripcion\n");
                printf("2. Importe\n");
                scanf("%d", &cambiar);
                switch(cambiar)
                {
                case 1:
                    getSuperAlfaNumerico("Ingrese nueva descripcion del juego:  ", "Error, ingrese nuevamente.",nuevaDescripcion);
                    strcpy(lista[index].descripcion, nuevaDescripcion);
                    break;

                case 2:
                    nuevoImporte= getValidFloat("Ingrese nuevo importe del juego: ","Error,ingrese nuevamente.", 0, 2023);
                    lista[index].importe= nuevoImporte;
                    break;
                default :
                    printf("Dato no valido\n");
                }

                printf("Desea continuar? s/n \n :");
                fflush(stdin);
                scanf("%c",&continuar);
                system("pause");
                system("cls");
            }
            while(continuar=='s' || continuar=='S');
        }
        else if(index < 0)
        {
            printf("No existe ese Id. \n");
        }

        retorno=0;

    }

    return retorno;
}

int mostrarJuegos(eJuegos* lista, int len)
{
    int retorno=-1;
    eJuegos auxiliarJuegos;
    int i, j ;
    if(lista!= NULL)
    {
        for( i =0 ; i<len -1 ; i ++)
        {
            for(j= i+1 ; j<len; j++)
            {

                if(lista[j].importe>lista[i].importe)
                {
                    auxiliarJuegos = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxiliarJuegos;
                }
                else if(lista[j].importe == lista[i].importe && (strcmp(lista[j].descripcion,lista[i].descripcion)<0))
                {
                    auxiliarJuegos = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxiliarJuegos;
                }
            }


        }
        mostrarTodosLosJuegos(lista, len);
        printf("\nOpcion completada con exito.\n");

        retorno=0;
    }

    return retorno;

}


