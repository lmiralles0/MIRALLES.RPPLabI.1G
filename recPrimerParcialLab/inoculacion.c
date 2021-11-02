#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inoculacion.h"


static int buscarIndiceLibreInoculacion(eInoculacion* arrayInoculacion, int longitud);


int inicializarInoculacion(eInoculacion* arrayInoculacion, int longitud)
{
    int retorno = 1;
    if(arrayInoculacion != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            arrayInoculacion[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}



int altaInoculacion(eInoculacion* arrayInoculacion, int longtiudI, int* idInoculacion, ePaciente* arrayPaciente, int longitudP, eVacuna* arrayVacuna, int longitudV, eProvincia* arrayProvincia, int longitudPro, eCondicion* arrayCondicion, int longitudCon)
{
    int retorno = 1;
    int indice;
    eInoculacion newInoculacion;
    if(arrayInoculacion != NULL && longtiudI > 0 && idInoculacion != NULL && arrayPaciente != NULL && longitudP > 0 && arrayVacuna != NULL && longitudV > 0 && arrayProvincia != NULL && longitudPro > 0 && arrayCondicion && longitudCon > 0)
    {
        indice = buscarIndiceLibreInoculacion(arrayInoculacion, longtiudI);
        if(indice != -1)
        {
            mostrarPacientes(arrayPaciente, longitudP, arrayProvincia, longitudPro, arrayCondicion, longitudCon );
            if(get_EntradaInt(&newInoculacion.idPaciente, "Ingrese el N° de Id.\n", "Error al ingresar el N° de Id.\n", 1000, 0, 5) == 0)
            {
                if(arrayPaciente[buscarPaciente(arrayPaciente, longitudP, newInoculacion.idPaciente)].idCondicion == 3)
                {
                    printf("No se puede Inocular porque el paciente no es de riesgo.\n");
                }
                else
                {
                    newInoculacion.id = *(idInoculacion);
                    mostrarVacunas(arrayVacuna, longitudV);
                    if(get_EntradaInt(&newInoculacion.idVacuna, "Ingrese el Id de la vacuna.\n", "Error al ingresar Id de vacuna.\n", 20005, 20000, 5) == 0)
                    {
                        if((get_EntradaInt(&newInoculacion.fecha.dia, "Ingrese el dia.\n", "No es un dia valido.\n", 31, 1, 5) == 0) &&
                                (get_EntradaInt(&newInoculacion.fecha.mes, "Ingrese el mes.\n", "Error al ingresar el mes.\n", 12, 1, 5) == 0) &&
                                (get_EntradaInt(&newInoculacion.fecha.anio, "Ingrese el anio.(2020 - 2021)\n", "Error al ingresar anio", 2021, 2020, 5) == 0))
                        {
                            arrayInoculacion[indice] = newInoculacion;
                            arrayInoculacion[indice].isEmpty = 0;
                            (*idInoculacion) ++;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}


static int buscarIndiceLibreInoculacion(eInoculacion* arrayInoculacion, int longitud)
{
    int indice = -1;
    if(arrayInoculacion!= NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayInoculacion[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


void mostrarInoculacion(eInoculacion inoculacion, char* bufferNombre, char* bufferVacuna)
{
    printf("%d          %d               %10s                %10s               %d/%d/%d\n", inoculacion.id, inoculacion.idPaciente, bufferNombre, bufferVacuna, inoculacion.fecha.dia, inoculacion.fecha.mes, inoculacion.fecha.anio);
}


int mostrarInoculaciones(eInoculacion* arrayInoculacion, int longitudI, ePaciente* arrayPacientes, int longitudP, eVacuna* arrayVacunas, int longitudV)
{
    int retorno = 1;
    char buffer1[50];
    char buffer2[50];
    if(arrayInoculacion != NULL && longitudI > 0 && arrayPacientes != NULL && longitudP > 0 && arrayVacunas != NULL && longitudV >0)
    {
        retorno = 0;
        printf("ID        ID PACIENTES           NOMBRE                VACUNA                 FECHA\n");
        for(int i = 0; i < longitudI; i++)
        {
            if(arrayInoculacion[i].isEmpty == 0)
            {
                cargarDescripcionNombre(arrayPacientes, longitudP, arrayInoculacion[i].idPaciente, buffer1);
                cargarDescripcionVacuna(arrayVacunas, longitudV, arrayInoculacion[i].idVacuna, buffer2);
                mostrarInoculacion(arrayInoculacion[i], buffer1, buffer2);
            }
        }
    }
    else
    {
        printf("Error al mostrar Paciente.\n");
    }
    return retorno;
}


void cargarDescripcionNombre(ePaciente* arrayPacientes, int longitudP, int idPaciente, char* descripcionP)
{
    if(arrayPacientes != NULL && longitudP > 0 && descripcionP != NULL)
    {
        for(int i = 0; i < longitudP; i++)
        {
            if(arrayPacientes[i].id == idPaciente)
            {
                strcpy(descripcionP, arrayPacientes[i].nombre);
                break;
            }
        }
    }
}


void cargarDescripcionVacuna(eVacuna* arrayVacunas, int longitudV, int idVacunas, char* descripcionV)
{
    if(arrayVacunas != NULL && longitudV> 0 && descripcionV != NULL)
    {
        for(int i = 0; i < longitudV; i++)
        {
            if(arrayVacunas[i].id == idVacunas)
            {
                strcpy(descripcionV, arrayVacunas[i].nombre);
                break;
            }
        }
    }
}
