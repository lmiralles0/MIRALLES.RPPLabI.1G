#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "bibliotecas_Get.h"



static int buscarIndiceLibreCliente(eCliente* arrayCliente, int longitud);
static int buscarIndiceLibreAlquileres(eAlquiler* arrayAlquiler, int longitudA);
static int apellidoYNombre(char* buffer, eCliente* arrayCliente, int longitudC, int idCliente);
static int cargarDescripcionEquipos(char* buffer, eEquipos* arrayEquipos, int longitudE, int idEquipos);


////////ALQUILER
int inicializarCliente(eCliente* arrayCliente, int longitud)
{
    int retorno = 1;
    if(arrayCliente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            arrayCliente[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int altaCliente(eCliente* arrayCliente, int longitud, int* idCliente)
{
    int retorno = 1;
    int indice;
    eCliente nuevoCliente;
    if(arrayCliente != NULL && longitud > 0 && idCliente != NULL)
    {
        indice = buscarIndiceLibreCliente(arrayCliente, longitud);
        if(indice != -1)
        {
            nuevoCliente.id = *(idCliente);
            if(get_Texto(nuevoCliente.nombre, 51, "Ingrese nombre del Cliente:\n", "Error al ingresar nombre.\n", 5) == 0)
            {
                if( get_Texto(nuevoCliente.apellido, 51, "Ingrese apellido del Cliente:\n", "Error al ingresar apellido.\n", 5) == 0)
                {
                    if(get_EntradaInt(&nuevoCliente.dni, "Ingrese el numero de DNI:\n", "N° de DNI invalido.\n", 99999999, 11111111, 5) == 0)
                    {
                        arrayCliente[indice] = nuevoCliente;
                        arrayCliente[indice].isEmpty = 0;
                        (*idCliente)++;
                        retorno = 0;
                    }
                }
            }
        }
    }
    return retorno;
}

int modificarCLiente(eCliente* arrayCliente, int longitud, int opcion)
{
    int retorno = 1;
    int id;
    int indice = -1;
    char nombre[51];
    char apellido[51];
    int salida = 0;

    if(arrayCliente != NULL && longitud > 0)
    {
        if(get_EntradaInt(&id, "Ingrese el Id del cliente.\n", "Error al ingresar Id por favor ingrese un N° valido.\n", 1100, 1000, 5) == 0)
        {
            indice = buscarCliente(arrayCliente, longitud, id);
            if( indice > -1 && opcion == 1)
            {
                while(get_Texto(nombre, 51, "Ingrese el nuevo nombre del Cliente.\n", "Error al ingresar nombre.\n", 0) != 0)
                {
                    get_Texto(nombre, 51, "Ingrese el nuevo nombre del Cliente.\n", "Error al ingresar nombre.\n", 0);
                    salida++;
                    if(salida == 3)
                    {
                        break;
                    }
                }
                if(salida < 3)
                {
                    strcpy(arrayCliente[indice].nombre, nombre);
                    retorno = 0;
                }
                else
                {
                    printf("Error al modicar nombre del Cliente.\n");
                }
            }
            else if(indice > -1 && opcion == 2)
            {
                while(get_Texto(apellido, 51, "Ingrese el nuevo apellido del Cliente.\n", "Error al ingresar apellido.\n", 0) != 0)
                {
                    get_Texto(apellido, 51, "Ingrese el nuevo apellido del Cliente.\n", "Error al ingresar apellido.\n", 0);
                    salida ++;
                    if(salida == 3)
                    {
                        break;
                    }
                }
                if(salida < 3)
                {
                    strcpy(arrayCliente[indice].apellido, apellido);
                    retorno = 0;
                }
                else
                {
                    printf("Error al modicar apellido del Cliente.\n");
                }
            }
        }
        else
        {
            printf("Error al intentar modificar cliente.\n");
        }
    }
    return retorno;
}

int bajaCliente(eCliente* arrayCliente, int longitud)
{
    int retorno = 1;
    int indice = -1;
    int id;
    if(arrayCliente != NULL && longitud > 0)
    {
        mostrarClientes(arrayCliente, longitud);
        if(get_EntradaInt(&id, "Ingrese el ID del cliente a dar de baja.\n", "Error al ingresar ID.\n", 1100, 100, 3) == 0)
        {
            indice = buscarCliente(arrayCliente, longitud, id);
            if(indice > -1 && arrayCliente[indice].isEmpty == 0)
            {
                arrayCliente[indice].isEmpty = 1;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int buscarCliente(eCliente* arrayCliente, int longitud, int idCliente)
{
    int indice = -1;
    if(arrayCliente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayCliente[i].isEmpty == 0 && arrayCliente[i].id == idCliente)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

static int buscarIndiceLibreCliente(eCliente* arrayCliente, int longitud)
{
    int indice = -1;
    if(arrayCliente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayCliente[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarCliente(eCliente arrayCliente)
{
    printf("%d       %10s          %10s            %d\n", arrayCliente.id, arrayCliente.nombre, arrayCliente.apellido, arrayCliente.dni);
}

int mostrarClientes(eCliente* arrayCliente, int longitud)
{
    int retorno = 1;
    if(arrayCliente != NULL && longitud > 0)
    {
        retorno = 0;
        printf("ID             NOMBRE            APELLIDO         DNI\n");
        for(int i = 0; i < longitud; i++)
        {
            if(arrayCliente[i].isEmpty == 0)
            {
                mostrarCliente(arrayCliente[i]);
            }
        }
    }
    else
    {
        printf("Error al mostrar clientes.\n");
    }
    return retorno;

}
/////////ALQUILER

int inicializarAlquiler(eAlquiler* arrayAlquiler, int longitudA)
{
    int retorno = 1;
    if(arrayAlquiler != NULL && longitudA > 0)
    {
        retorno = 0;
        for(int i = 0; i < longitudA; i++)
        {
            arrayAlquiler[i].isEmpty = 1;
        }
    }
    return retorno;
}


int altaAlquiler(eAlquiler* arrayAlquiler, int longitudA, int* idAlquileres, eCliente* arrayCliente, int longitudC)
{
    int retorno = 1;
    int indice;
    eAlquiler aux;
    if(arrayAlquiler != NULL && longitudA > 0 && idAlquileres != NULL && arrayCliente != NULL && longitudC > 0)
    {
        indice = buscarIndiceLibreAlquileres(arrayAlquiler, longitudA);
        if(indice > -1)
        {
            mostrarClientes(arrayCliente, longitudC);
            if(get_EntradaInt(&aux.clienteAlquiler.id, "Ingrese el N° de Id.\n", "Error Id invalid.\n", 1100, 1000, 5) == 0)
            {
                if(get_EntradaInt(&aux.equipo, "Ingrese el equipo a alquilar: 1-MOLADORA 2-MEZCLADORA 3-TALADRO.\n", "Error al ingresar equipo.\n", 3, 1, 5) == 0)
                {
                    if(get_EntradaInt(&aux.tiempo, "Ingrese tiempo de alquiler: (dias)\n", "Error.\n", 5, 1, 5) == 0)
                    {
                        if(get_Texto(aux.operador, 51,"Ingresen nombre del operador.\n","Error.\n", 5) == 0)
                        {
                            aux.codigoAlquiler = *(idAlquileres);
                            aux.isEmpty = 0;
                            arrayAlquiler[indice] = aux;
                            (*idAlquileres)++;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}



int bajaAlquiler(eAlquiler* arrayAlquiler, int longitudA, eCliente* arrayCliente, int longitudC, eEquipos* arrayEquipos, int longitudE)
{
    int retorno = 1;
    int indice = -1;
    int id;
    if(arrayAlquiler != NULL && longitudA > 0)
    {
        mostrarAlquileres(arrayAlquiler, longitudA, arrayCliente, longitudC,arrayEquipos, longitudE);
        if(get_EntradaInt(&id, "Ingrese el ID del cliente a dar de baja.\n", "Error al ingresar ID.\n", 1100, 100, 3) == 0)
        {
            indice = buscarCliente(arrayCliente, longitudA, id);
            if(indice > -1 && arrayAlquiler[indice].isEmpty == 0)
            {
                arrayAlquiler[indice].isEmpty = 1;
                retorno = 0;
            }
        }
    }
    return retorno;
}


int buscarAlquiler(eAlquiler* arrayAlquiler, int longitudA, int id)
{
    int indice = -1;
    if(arrayAlquiler != NULL && longitudA > 0)
    {
        for(int i = 0; i < longitudA; i++)
        {
            if(arrayAlquiler[i].isEmpty == 0 && arrayAlquiler[i].codigoAlquiler == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int mostrarAlquileres(eAlquiler* arraysAlquiler, int longitudA, eCliente* arrayCliente, int longitudC, eEquipos* arrayEquipos, int longitudE)
{
    int retorno = 1;
    char aux[51];
    char aux2[20];
    if(arraysAlquiler != NULL && longitudA > 0)
    {
        printf("ID               EQUIPO               OPERADOR             TIEMPO            CLIENTE\n");
        for(int i = 0; i < longitudA; i ++)
        {
            if(arraysAlquiler[i].isEmpty == 0)
            {
                cargarDescripcionEquipos(aux2, arrayEquipos, longitudE, arraysAlquiler[i].equipo);
                apellidoYNombre(aux, arrayCliente, longitudC, (arraysAlquiler[i].clienteAlquiler.id));
                printf("%d            %10s         %10s            %d (dias)          %15s\n", arraysAlquiler[i].codigoAlquiler, aux2,
                       arraysAlquiler[i].operador, arraysAlquiler[i].tiempo, aux);
            }
        }
    }
    return retorno;
}

static int buscarIndiceLibreAlquileres(eAlquiler* arrayAlquiler, int longitudA)
{
    int indice = -1;
    if(arrayAlquiler != NULL && longitudA > 0)
    {
        for(int i = 0; i < longitudA; i++)
        {
            if(arrayAlquiler[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


static int apellidoYNombre(char* buffer, eCliente* arrayCliente, int longitudC, int idCliente)
{
    int retorno = 1;
    if(buffer != NULL && arrayCliente != NULL && longitudC > 0)
    {
        for(int i = 0; i < longitudC; i ++)
        {
            if(arrayCliente[i].isEmpty == 0 && arrayCliente[i].id == idCliente)
            {
                strcpy(buffer, arrayCliente[i].nombre);
                strcat(buffer, " ");
                strcat(buffer, arrayCliente[i].apellido);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int cargarDescripcionEquipos(char* buffer, eEquipos* arrayEquipos, int longitudE, int idEquipos)
{
    int retorno = 1;
    if(buffer != NULL && arrayEquipos != NULL && longitudE > 0)
    {
        for(int i = 0; i < longitudE; i ++)
        {
            if(arrayEquipos[i].id == idEquipos)
            {
                strcpy(buffer, arrayEquipos[i].descripcion);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/////////INFORME

/*int clienteConMasAlquileres(eCliente* arrayCliente, int longitudC, eAlquiler* arrayAlquiler, int longitudA)
{
    int retorno = 1;
    if(arrayCliente != NULL && arrayAlquiler != NULL && longitudA > 0 && longitudC > 0)
    {
        for(int i = 0; i < longitudC; i++)
        {
            for(int j = 0; j < longitudA; j++)
            {
                if(arrayCliente[i].isEmpty == 1 || arrayAlquiler[j].isEmpty == 1)
                {
                    break;
                }
                if(arrayAlquiler[j].clienteAlquiler == arrayCliente[i].id)
                {

                }
            }
        }
    }
    return retorno;
}
*/

int equiposMasAlquilados(eEquipos* arrayEquipos, int longitudE, eAlquiler* arrayAlquiler, int longitudA)
{
    int retorno = 1;
    int maximo = 0;
    int indice;
    int contador[3] = {0,0,0};
    if(arrayEquipos != NULL && arrayAlquiler != NULL && longitudA > 0 && longitudE> 0)
    {
        for(int i = 0; i < longitudA; i++)
        {
            for(int j = 0; j < longitudE; j++)
            {
                if(arrayAlquiler[i].isEmpty == 1)
                {
                    break;
                }
                if(arrayAlquiler[i].equipo == arrayEquipos[j].id)
                {
                    switch(arrayEquipos[j].id)
                    {
                    case 1:
                        contador[0]++;
                        break;
                    case 2:
                        contador[1]++;
                        break;
                    case 3:
                        contador[2]++;
                        break;
                    }
                }
            }
        }
        for(int x = 0; x < 3; x++)
        {
            if(contador[x] > maximo)
            {
                maximo = contador[x];
                indice = x;
            }
        }
        for(int y = 0; y < 3; y++)
        {
            if(contador[indice] == contador[y])
            {
                printf("%d         %10s          %d (cantidad) \n", arrayEquipos[y].id, arrayEquipos[y].descripcion, contador[indice]);
                retorno = 0;
            }
        }
    }
    return retorno;
}


int clienteYAlquileres(eCliente* arrayCliente, eAlquiler* arrayAlquiler, int longitudC, int longitudA, eEquipos* arrayEquipo, int longitudE)
{
    int retorno = 1;
    char buffer[20];
    if(arrayAlquiler != NULL && arrayCliente != NULL && longitudC > 0 && longitudA > 0)
    {
        printf("NOMBRE        APELLIDO        DNI            EQUIPO           TIEMPO \n");
        for(int i = 0; i < longitudC; i++)
        {
            for(int j = 0; j < longitudA; j++)
            {
                if(arrayCliente[i].isEmpty == 1)
                {
                    break;
                }
                if(arrayAlquiler[j].isEmpty == 0 && arrayCliente[i].id == arrayAlquiler[j].clienteAlquiler.id)
                {
                    cargarDescripcionEquipos(buffer, arrayEquipo, longitudE, arrayAlquiler[j].equipo);
                    printf("%10s        %10s         %d           %10s             %d (ALQUILADO).\n", arrayCliente[i].nombre, arrayCliente[i].apellido, arrayCliente[i].dni, buffer,arrayAlquiler[j].tiempo);
                }
                if(arrayAlquiler[j].isEmpty == 1 && arrayCliente[i].id == arrayAlquiler[j].clienteAlquiler.id)
                {
                    cargarDescripcionEquipos(buffer, arrayEquipo, longitudE, arrayAlquiler[j].equipo);
                    printf("%10s        %10s         %d           %10s             %d (FINALIZADO).\n", arrayCliente[i].nombre, arrayCliente[i].apellido, arrayCliente[i].dni, buffer,arrayAlquiler[j].tiempo);

                }
            }
        }
        retorno = 0;
    }
    return retorno;

}


float promedioAlquileresTiempo(eAlquiler* arrayAlquiler, int longitudA)
{
    float retorno;
    float promedio = 0;
    float contadorAlquileres = 0;
    if(arrayAlquiler != NULL && longitudA > 0)
    {
        for(int i = 0; i < longitudA; i++)
        {
            if(arrayAlquiler[i].isEmpty == 0)
            {
                promedio += (float)arrayAlquiler[i].tiempo;
                contadorAlquileres++;
            }
        }
        retorno = promedio/contadorAlquileres;
    }
    return retorno;;
}

