#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "clientes.h"
#include "utn.h"

static int generarNextId()
{
    static int id=0;

    id ++;

    return id;
}

int incializarClientes(eCliente* lista, int len)
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


int espacioLibreCliente(eCliente* lista, int len)
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

int mostrarUnCliente(eCliente* lista, int indice)
{
    int retorno=-1;
    if( lista!= NULL)
    {
        if(lista[indice].isEmpty==0)
        {
            printf("%d\t    %s\t    %s\t    %c\t    %s \n\n", lista[indice].codigoCliente, lista[indice].apellido, lista[indice].nombre,lista[indice].sexo, lista[indice].domicilio );
            retorno=0;
        }
    }
    return retorno;

}

int mostrarTodosLosClientes(eCliente* lista, int len)
{
    int retorno=-1;
    int i;
    if(lista!= NULL)
    {
        printf("ID\t    APELLIDO\t    NOMBRE\t    SEXO\t    DOMICILIO\n");
        for( i=0; i<len ; i ++ )
        {
            if(lista[i].isEmpty == 0)
            {
               mostrarUnCliente(lista, i);
                retorno=0;
            }
        }
    }
    return retorno;
}

int buscarClientePorId(eCliente* lista, int len, int id)
{
    int i;
    int retorno=-1;
    if( lista!= NULL)
    {
        for( i=0 ; i<len ; i++)
        {
            if(lista[i].codigoCliente == id && lista[i].isEmpty==0)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int agregarCliente(eCliente* lista, int len)
{
    eCliente auxiliarCliente;
    int lugarLibre = espacioLibreCliente(lista, len);
    int retorno=-1;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            getValidString("Ingrese apellido del cliente: ", "Error, ingrese nuevamente.", auxiliarCliente.apellido);//arreglar lo de los espacios
            getValidString("Ingrese nombre del cliente: ", "Error, ingrese nuevamente.", auxiliarCliente.nombre);//arreglar lo de los espacios
            getValidSexo("Ingrese sexo: ", &auxiliarCliente.sexo);
            getSuperAlfaNumerico("Ingrese domicilio del cliente: ", "Error, ingrese nuevamente.", auxiliarCliente.domicilio);
            auxiliarCliente.codigoCliente = generarNextId();
            auxiliarCliente.isEmpty=0;
            lista[lugarLibre]=auxiliarCliente;
            retorno=0;

        }
    }

    return retorno;
}

int agregarClienteConParametros(eCliente* lista, int len, char *apellido, char nombre[], char sexo, char* direccion)
{
    eCliente auxiliarCliente;
    int lugarLibre = espacioLibreCliente(lista, len);
    int retorno=-1;

    if(lista !=  NULL)
    {
        if(lugarLibre != -1)
        {
            strcpy(auxiliarCliente.apellido , apellido);
            strcpy(auxiliarCliente.nombre , nombre);
            auxiliarCliente.sexo = sexo;
            strcpy(auxiliarCliente.domicilio , direccion);
            auxiliarCliente.codigoCliente = generarNextId();
            auxiliarCliente.isEmpty=0;
            lista[lugarLibre]=auxiliarCliente;
            retorno=0;

        }
    }

    return retorno;
}

void hardcodearClientes(eCliente clientes[],int lenCliente)
{
    agregarClienteConParametros(clientes, lenCliente, "Gimenez", "Mabel", 'f', "Arieta 5263");
    agregarClienteConParametros(clientes, lenCliente, "Perez", "Carlos", 'm', "Santa Maria 1590");
    agregarClienteConParametros(clientes, lenCliente, "Perez", "Alejandra", 'f', "Falcon 1533");
    agregarClienteConParametros(clientes, lenCliente,"Rios", "Cristian", 'm', "Condarco 2155");
    agregarClienteConParametros(clientes, lenCliente,"Suarez", "Maria Monica Mabel", 'f', "Arieta 4222");
    agregarClienteConParametros(clientes, lenCliente,"Zarate", "Roberto", 'm', "Aguapey 4237");
    agregarClienteConParametros(clientes, lenCliente,"Zarate", "Ariela", 'f', "Condarco 4457");
    agregarClienteConParametros(clientes, lenCliente,"Zarate", "Fabio", 'm', "Corvalan 1245");

}

int removerCliente(eCliente* lista, int len, int id)
{
    int index;
    int retorno=-1;
    char pregunta;

    if(lista!=NULL)
    {
        printf("Ingrese el id del cliente que desea eliminar: ");
        scanf("%d",&id);
        index=buscarClientePorId(lista, len, id);

        if(index==-1)
        {
            printf("No existe ese id!! \n");
        }
        else
        {
            if(lista[index].isEmpty==0)
            {
                printf("ID\t   DESCRIPCION\t   IMPORTE\n");
                mostrarUnCliente(lista, index);
                printf("Desea eliminar este cliente?  s/n :");
                fflush(stdin);
                scanf("%c",&pregunta);
                if(pregunta=='s')
                {
                    printf("El cliente fue eliminado!\n");
                    lista[index].isEmpty=1;
                }
                else
                {
                    printf("Borrado cancelado\n");
                }
            }
        }
    }
    return retorno;
}

int modificarCliente(eCliente* lista,int len,  int id)
{
    int index;
    int cambiar;
    char nuevoApellido[51];
    char nuevoNombre[51];
    char nuevoSexo;
    char nuevoDomicilio[51];
    int retorno=-1;
    char continuar='n';

    printf("Ingrese el Id. del cliente que desea modificar:\n");
    scanf("%d", &id);
    index=buscarClientePorId(lista, len, id);

    if(lista!=NULL)
    {
        if(index >= 0)
        {
            do
            {
                printf("ID\t    APELLIDO\t    NOMBRE\t    SEXO\t    DOMICILIO\n");
                mostrarUnCliente(lista, index);
                //llamar funcion que me muesstra los datos de esa posicion
                printf("\n\nSeleccione la opcion que desea modificar:");
                printf("\n1. Apellido\n");
                printf("2. Nombre\n");
                printf("3. Sexo\n");
                printf("4. Domicilio\n");
                scanf("%d", &cambiar);
                switch(cambiar)
                {
                case 1:
                    getValidString("Ingrese nuevo apellido del cliente:  ", "Error, ingrese nuevamente.",nuevoApellido);
                    strcpy(lista[index].apellido, nuevoApellido);
                    break;

                case 2:
                    getValidString("Ingrese nuevo nombre del cliente:  ", "Error, ingrese nuevamente.",nuevoNombre);
                    strcpy(lista[index].nombre, nuevoNombre);
                    break;
                case 3:
                    getValidSexo("Ingrese nuevo sexo: ", &nuevoSexo);
                    lista[index].sexo= nuevoSexo;
                    break;
                case 4:
                    getSuperAlfaNumerico("Ingrese nuevo domicilio: ", "Error, ingrese nuevamente", nuevoDomicilio);
                    strcpy(lista[index].domicilio,nuevoDomicilio);
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

int mostrarCliente(eCliente* lista, int len)
{
    int retorno=-1;
    eCliente auxiliarCliente;
    int i, j ;
    if(lista!= NULL)
    {
            for( i =0 ; i<len -1 ; i ++)
            {
                for(j= i+1 ; j<len; j++)
                {

                    if(strcmp(lista[j].apellido,lista[i].apellido)<0)
                    {
                        auxiliarCliente = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarCliente;
                    }
                    else if((strcmp(lista[j].apellido,lista[i].apellido)==0) && (strcmp(lista[j].nombre,lista[i].nombre)<0)) /*&& lista[j].sector<lista[i].sector)*/
                    {
                        auxiliarCliente = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxiliarCliente;
                    }
                }
            }
                mostrarTodosLosClientes(lista, len);

        retorno=0;
    }

    return retorno;

}

