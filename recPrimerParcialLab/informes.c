#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"



void mostrarVacunaPorLaboratorio(eVacuna* arrayVacunas, int longtidudV, eLaboratorio* arrayLaboratorio, int longitudL)
{
    int idLab;
    if(arrayVacunas != NULL && longtidudV > 0 && arrayLaboratorio != NULL && longitudL > 0)
    {
        mostrarLaboratorios(arrayLaboratorio, longitudL);
        if(get_EntradaInt(&idLab, "Ingrese el Id del Laboratorio.\n", "Error al ingresar Id", 1003, 1000, 5) == 0)
        {
            printf("\n");
            for(int i = 0; i < longtidudV; i++)
            {
                if(arrayVacunas[i].idLaboratorio == idLab)
                {

                    printf("%d      %10s         %0.2f \n", arrayVacunas[i].id, arrayVacunas[i].nombre, arrayVacunas[i].precio);
                }
            }
        }
    }
}



void mostrarPacientePorRiesgoProvincia(ePaciente* arrayPacientes, int longitudP, eProvincia* arrayProvincias, int longitudPro, eCondicion* arrayCondicion, int longitudCon)
{
    char grupoRiesgo;
    int idProvincia;
    int salida = 0;
    char buffer1[30];
    char buffer2[30];
    if(arrayPacientes != NULL && longitudP > 0 && arrayProvincias != NULL && longitudPro > 0)
    {
        mostrarProvincias(arrayProvincias, longitudPro);
        if(get_EntradaInt(&idProvincia, "Ingrese el Id de la provincia.\n", "Error al ingresar Id.\n", 5004, 5000, 5) == 0)
        {
            printf("Ingrese el el grupo de riesgo: ('s' o 'n').\n");
            scanf("%c", &grupoRiesgo);
            fflush(stdin);
            while(grupoRiesgo != 's' && grupoRiesgo != 'n')
            {
                printf("\nError.Ingrese el el grupo de riesgo: ('s' o 'n').\n");
                scanf("%c", &grupoRiesgo);
                fflush(stdin);
                salida++;
                if(salida > 5)
                {
                    break;
                }
            }
            for(int i = 0; i < longitudP; i++)
            {
                if(arrayPacientes[i].isEmpty == 0)
                {
                    if(arrayPacientes[i].idProvincia == idProvincia && arrayPacientes[i].grupoRiesgo == grupoRiesgo)
                    {
                        cargarDescripcionProvincia(arrayProvincias, longitudPro, arrayPacientes[i].idProvincia, buffer1);
                        cargarDescripcionCondicion(arrayCondicion, longitudCon, arrayPacientes[i].idCondicion, buffer2);
                        mostrarPaciente(arrayPacientes[i], buffer1, buffer2 );
                    }
                }
            }
        }
    }
}


void mostrarPorcentajePacienteRiesgo(ePaciente* arrayPaciente, int longitud)
{
    int pacientes = 0;
    int acumuladorRiesgo = 0;
    float porcentaje = 0;
    if(arrayPaciente != NULL && longitud > 0)
    {
        for(int i = 0; i < longitud; i++)
        {
            if(arrayPaciente[i].isEmpty == 0)
            {
                pacientes++;
                if(arrayPaciente[i].grupoRiesgo == 's')
                {
                    acumuladorRiesgo++;
                }
            }
        }
    }
    porcentaje = (float)acumuladorRiesgo/pacientes;
    if(acumuladorRiesgo == 0)
    {
        printf("No existen pacientes de riesgo.\n");
    }
    else
    {
        printf("El porcentaje de pacientes de riesgo es de %0.2f\n", porcentaje);
    }
}


void mostrarPacientesPorProvincias(ePaciente* arrayPaciente, int longitudPa, eProvincia* arrayProvincia, int longitudPr, eCondicion* arrayCondicion, int longitudCon)
{
    char buffer1[30];
    char buffer2[30];
    if(arrayPaciente != NULL && longitudPa > 0 && arrayProvincia != NULL && longitudPr > 0 && arrayCondicion != NULL && longitudCon > 0)
    {
        printf("\n");
        for(int i = 0; i < longitudPr ; i++)
        {
            for(int j = 0; j < longitudPa; j++)
            {
                if(arrayProvincia[i].id == arrayPaciente[j].idProvincia && arrayPaciente[j].isEmpty == 0)
                {
                    cargarDescripcionCondicion(arrayCondicion, longitudCon, arrayPaciente[j].idCondicion, buffer2);
                    cargarDescripcionProvincia(arrayProvincia, longitudPr, arrayPaciente[j].idProvincia, buffer1);
                    mostrarPaciente(arrayPaciente[j], buffer1, buffer2);
                }
            }
        }
    }
}


void mostrarVacunasMasInoculadas(eInoculacion* arrayInoculacion, int longitudI, eVacuna* arrayVacuna, int longtiduV)
{
    int mayorVacuna = 0;
    int vacuna[6];
    for(int i = 0; i < 6; i ++)
    {
        vacuna[i] = 0;
    }
    if(arrayInoculacion != NULL && longitudI > 0 && arrayVacuna != NULL && longtiduV > 0)
    {
        for(int x = 0; x < longitudI; x++)
        {
            if(arrayInoculacion[x].isEmpty == 0)
            {
                switch(arrayInoculacion[x].idVacuna)
                {
                case 20000:
                    vacuna[0]++;
                    break;
                case 20001:
                    vacuna[1]++;
                    break;
                case 20002:
                    vacuna[2]++;
                    break;
                case 20003:
                    vacuna[3]++;
                    break;
                case 20004:
                    vacuna[4]++;
                    break;
                case 20005:
                    vacuna[5]++;
                    break;
                }
            }
        }
        for(int y = 0; y < 6 ; y++)
        {
            if(vacuna[y] > mayorVacuna)
            {
                mayorVacuna = vacuna[y];
            }
        }
        for(int z = 0; z < 6; z++)
        {
            if(vacuna[z] == mayorVacuna)
            {
                printf("%d     %10s       %0.2f\n",arrayVacuna[z].id, arrayVacuna[z].nombre, arrayVacuna[z].precio);
            }
        }
    }
}

void mostrarVacunasMenosInoculadas(eInoculacion* arrayInoculacion, int longitudI, eVacuna* arrayVacuna, int longtiduV)
{
    int menorVacuna = 1;
    int vacuna[6];
    for(int i = 0; i < 6; i ++)
    {
        vacuna[i] = 0;
    }
    if(arrayInoculacion != NULL && longitudI > 0 && arrayVacuna != NULL && longtiduV > 0)
    {
        for(int x = 0; x < longitudI; x++)
        {
            if(arrayInoculacion[x].isEmpty == 0)
            {
                switch(arrayInoculacion[x].idVacuna)
                {
                case 20000:
                    vacuna[0]++;
                    break;
                case 20001:
                    vacuna[1]++;
                    break;
                case 20002:
                    vacuna[2]++;
                    break;
                case 20003:
                    vacuna[3]++;
                    break;
                case 20004:
                    vacuna[4]++;
                    break;
                case 20005:
                    vacuna[5]++;
                    break;
                }
            }
        }
        for(int y = 0; y < 6 ; y++)
        {
            if(vacuna[y] <= menorVacuna && vacuna[y] >= 1)
            {
                menorVacuna = vacuna[y];
            }
        }
        for(int z = 0; z < 6; z++)
        {
            if(vacuna[z] == menorVacuna)
            {
                printf("%d     %10s       %0.2f\n",arrayVacuna[z].id, arrayVacuna[z].nombre, arrayVacuna[z].precio);
            }
        }
    }
}
