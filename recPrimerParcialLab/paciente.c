#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "provincia.h"

static int buscarIndiceLibrePaciente(ePaciente* arrayPaciente, int longitud);




int inicializarPaciente(ePaciente* arrayPaciente, int longitud)
{
    int retorno = 1;
    if(arrayPaciente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            arrayPaciente[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int altaPaciente(ePaciente* arrayPaciente, int longitud, int* idPaciente, eProvincia* arrayProvincias, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon)
{
    int retorno = 1;
    int indice;
    ePaciente nuevoPaciente;
    if(arrayPaciente != NULL && longitud > 0 && idPaciente != NULL)
    {
        indice = buscarIndiceLibrePaciente(arrayPaciente, longitud);
        if(indice != -1)
        {
            nuevoPaciente.id = *(idPaciente);
            mostrarCondicion(arrayCondicion, longitudCon);
            if(get_EntradaInt(&nuevoPaciente.idCondicion, "Ingrese el Id de la condicion del paciente.\n", "Error al ingresar Id.\n", 3, 0, 5) == 0)
            {
                if(get_Texto(nuevoPaciente.nombre, 20, "Ingrese nombre del Paciente:\n", "Error al ingresar nombre.\n", 5) == 0)
                {
                    printf("Ingrese si es grupo de riesgo: 's' o 'n'\n");
                    scanf("%c", &nuevoPaciente.grupoRiesgo);
                    fflush(stdin);
                    if(get_EntradaInt(&nuevoPaciente.edad, "Ingrese la edad del Paciente.\n", "Edad invalida.\n", 100, 1, 5) == 0)
                    {
                        printf("\n");
                        mostrarProvincias(arrayProvincias, longitudProvincias);
                        if(get_EntradaInt(&nuevoPaciente.idProvincia, "Ingrese el Id de la localidad:\n", "Error no es una localidad valida.\n", 5004, 5000, 4) == 0)
                        {
                            arrayPaciente[indice] = nuevoPaciente;
                            arrayPaciente[indice].isEmpty = 0;
                            (*idPaciente)++;
                            retorno = 0;
                        }
                    }
                }
            }

        }
    }
    return retorno;
}

int modificarPaciente(ePaciente* arrayPaciente, int longitud, int opcion2, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon)
{
    int retorno = 1;
    int id;
    int indice = -1;
    char riesgo;
    int idProvincia;
    int idCondicion;
    int salida = 0;
    if(arrayPaciente != NULL && longitud > 0)
    {
        mostrarPacientes(arrayPaciente, longitud, arrayProvincia, longitudProvincias, arrayCondicion, longitudCon);
        if(get_EntradaInt(&id, "Ingrese el Id del Paciente.\n", "Error al ingresar Id por favor ingrese un N° valido.\n", 1000, 0, 5) == 0)
        {
            indice = buscarPaciente(arrayPaciente, longitud, id);
            if( indice > -1 && opcion2 == 1)
            {
                mostrarProvincias(arrayProvincia, longitudProvincias);
                while(get_EntradaInt(&idProvincia, "Ingrese el Id de la provincia.\n", "Error al ingresar ID.\n", 5004, 5000, 4) != 0)
                {
                    get_EntradaInt(&idProvincia, "Ingrese el Id de la provincia.\n", "Error al ingresar ID.\n", 5004, 5000, 4);
                    salida++;
                    if(salida == 3)
                    {
                        break;
                    }
                }
                if(salida < 3)
                {
                    arrayPaciente[indice].idProvincia = idProvincia;
                    retorno = 0;
                }
                else
                {
                    printf("Error al provincia del Paciente.\n");
                }
            }
            else if(indice > -1 && opcion2 == 2)
            {
                printf("Presione 's' o 'n' para modioficar si el paciente es de riesgo.\n");
                scanf("%c", &riesgo);
                fflush(stdin);
                while(riesgo != 's' && riesgo != 'n')
                {
                    printf("Error al modificar el riesgo.\n");
                    printf("Presione 's' o 'n' para modioficar si el paciente es de riesgo.\n");
                    scanf("%c", &riesgo);
                    fflush(stdin);
                    salida++;
                }
                if(salida < 3)
                {
                    arrayPaciente[indice].grupoRiesgo = riesgo;
                    retorno = 0;
                }
                else
                {
                    printf("Error al modicar la situacion de riesgo del paciente.\n");
                }
            }
            else if(indice > -1 && opcion2 == 3)
            {
                mostrarCondicion(arrayCondicion, longitudCon);
                while(get_EntradaInt(&idCondicion, "Ingrese el Id de la condicion.\n", "Error al ingresar ID.\n", 4, 0, 4) != 0)
                {
                    get_EntradaInt(&idCondicion, "Ingrese el Id de la condicion.\n", "Error al ingresar ID.\n", 4, 0, 4);
                    salida++;
                    if(salida == 3)
                    {
                        break;
                    }
                }
                if(salida < 3)
                {
                    arrayPaciente[indice].idCondicion= idCondicion;
                    retorno = 0;
                }
                else
                {
                    printf("Error al provincia del Paciente.\n");
                }

            }
        }
        else
        {
            printf("Error al intentar modificar Paciente.\n");
        }
    }
    return retorno;
}

int bajaPaciente(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon)
{
    int retorno = 1;
    int indice = -1;
    int id;
    if(arrayPaciente != NULL && longitud > 0)
    {
        mostrarPacientes(arrayPaciente, longitud, arrayProvincia, longitudProvincias, arrayCondicion, longitudCon);
        if(get_EntradaInt(&id, "Ingrese el ID del Paciente a dar de baja.\n", "Error al ingresar ID.\n", 1000, 0, 3) == 0)
        {
            indice = buscarPaciente(arrayPaciente, longitud, id);
            if(indice > -1 && arrayPaciente[indice].isEmpty == 0)
            {
                arrayPaciente[indice].isEmpty = 1;
                retorno = 0;
            }
        }
    }
    return retorno;
}

int listarPaciente(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longtiduCon)
{
    int retorno = 1;
    ePaciente aux;
    if(arrayPaciente != NULL && longitud > 0 && arrayProvincia != NULL && longitudProvincias > 0)
    {
        for(int i = 0; i < longitud - 1; i++)
        {
            for(int j = i + 1; j < longitud; j++)
            {
                if((arrayPaciente[i].idProvincia > arrayPaciente[j].idProvincia) ||
                        ((arrayPaciente[i].idProvincia == arrayPaciente [j].idProvincia) && (arrayPaciente[i].grupoRiesgo > arrayPaciente[j].grupoRiesgo)))
                {
                    aux = arrayPaciente[i];
                    arrayPaciente[i] = arrayPaciente[j];
                    arrayPaciente[j] = aux;
                }
            }
            retorno = 0;
        }
        mostrarPacientes(arrayPaciente, longitud, arrayProvincia, longitudProvincias, arrayCondicion, longtiduCon);
    }
    return retorno;
}


int buscarPaciente(ePaciente* arrayPaciente, int longitud, int idPaciente)
{
    int indice = -1;
    if(arrayPaciente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayPaciente[i].isEmpty == 0 && arrayPaciente[i].id == idPaciente)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


static int buscarIndiceLibrePaciente(ePaciente* arrayPaciente, int longitud)
{
    int indice = -1;
    if(arrayPaciente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayPaciente[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}



void mostrarPaciente(ePaciente arrayPaciente, char* descripcionProvincia, char* descripcionCondicion)
{
    printf("%d           %10s           %d             %c             %10s            %10s\n", arrayPaciente.id, arrayPaciente.nombre, arrayPaciente.edad, arrayPaciente.grupoRiesgo, descripcionProvincia, descripcionCondicion);
}


int mostrarPacientes(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon)
{
    int retorno = 1;
    char buffer1[20];
    char buffer2[20];
    if(arrayPaciente != NULL && longitud > 0)
    {
        retorno = 0;
        printf("ID             NOMBRE         EDAD             RIESGO           PROVINCIA         CONDICION\n");
        for(int i = 0; i < longitud; i++)
        {
            if(arrayPaciente[i].isEmpty == 0)
            {
                cargarDescripcionCondicion(arrayCondicion, longitudCon, arrayPaciente[i].idCondicion, buffer2);
                cargarDescripcionProvincia(arrayProvincia, longitudProvincias, arrayPaciente[i].idProvincia, buffer1);
                mostrarPaciente(arrayPaciente[i], buffer1, buffer2);
            }
        }
    }
    else
    {
        printf("Error al mostrar Paciente.\n");
    }
    return retorno;
}


void cargarDescripcionProvincia(eProvincia* arrayProvincia, int longitudProvincias, int idProvincia, char* descripcion)
{
    if(arrayProvincia != NULL && longitudProvincias > 0 && descripcion != NULL)
    {
        for(int i = 0; i < longitudProvincias; i++)
        {
            if(arrayProvincia[i].id == idProvincia)
            {
                strcpy(descripcion, arrayProvincia[i].nombrePais);
                break;
            }
        }
    }
}


void cargarDescripcionCondicion(eCondicion* arrayCondicion, int longitudCondicion, int idCondicion, char* descripcionCon)
{
    if(arrayCondicion != NULL && longitudCondicion> 0 && descripcionCon != NULL)
    {
        for(int i = 0; i < longitudCondicion; i++)
        {
            if(arrayCondicion[i].id == idCondicion)
            {
                strcpy(descripcionCon, arrayCondicion[i].descripcion);
                break;
            }
        }
    }
}
