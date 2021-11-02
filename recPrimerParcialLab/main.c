#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "data_WareHouse.h"
#include "bibliotecas_Get.h"
#include "inoculacion.h"
#include "informes.h"
#include "condicion.h"

int main()
{
    ePaciente list[1000];
    eInoculacion array[1000];
    int flagInicio = 0;
    int flagListarPacientes = 0;
    int flagListarInoculacion = 0;
    char opcion;
    int idInoculacion = 100;
    int idPaciente = 0;
    int opcion2;
    int opcionInformes;

    do
    {
        if(flagInicio == 0)
        {
            inicializarInoculacion(array, 1000);
            inicializarPaciente(list, 1000);
            flagInicio = 1;
        }
        printf("A. ALTA PACIENTE.\n");
        printf("B. MODIFICAR PACIENTE.\n");
        printf("C. BAJA PACIENTE.\n");
        printf("D. LISTAR PACIENTES.\n");
        printf("E. LISTAR PROVINCIAS.\n");
        printf("F. LISTAR LABORATORIOS.\n");
        printf("G. LISTAR VACUNAS.\n");
        printf("H. ALTA INOCULACION.\n");
        printf("I. LISTAR INOCULACIONES.\n");
        printf("J. INFORMES.\n");
        printf("Z. SALIR.\n\n");
        printf("Ingrese una opcion del menu: \n");
        scanf("%c", &opcion);
        fflush(stdin);
        system("cls");
        switch(opcion)
        {
        case 'A':
            system("cls");
            if(altaPaciente(list, 1000, &idPaciente, provincias, 5, condiciones, 4) == 0)
            {
                printf("Alta existosa.\n");
                system("pause");
                system("cls");
                flagListarPacientes = 1;
            }
            else
            {
                printf("Error al cargar Paciente.\n");
                system("pasue");
                system("cls");

            }
            break;
        case 'B':
            system("cls");
            if(flagListarPacientes == 1)
            {
                mostrarPacientes(list, 1000, provincias, 5, condiciones, 4);
                printf("\n");
                printf("1) Modificar provincia.\n");
                printf("2) Modificar riesgo.\n");
                printf("3)Modificar condicion.\n");
                if(get_EntradaInt(&opcion2, "Ingrese la opcion a modificar.\n", "Error\n", 3, 1, 5) == 0)
                {
                    modificarPaciente(list, 1000, opcion2, provincias, 5, condiciones, 4);
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al modificar pacientes.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error no se han cargado pacientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 'C':
            system("cls");
            if(flagListarPacientes == 1)
            {
                if(bajaPaciente(list, 1000, provincias, 5, condiciones, 4) == 0)
                {
                    printf("Baja exitosa.\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al dar de baja Paciente.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error no se han cargado pacientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 'D':
            system("cls");
            if(flagListarPacientes == 1)
            {
                listarPaciente(list, 1000, provincias, 5,condiciones, 4);
                system("pause");
                system("cls");
            }
            else
            {
                printf("Error no se han cargado Pacientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 'E':
            system("cls");
            mostrarProvincias(provincias, 5);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 'F':
            system("cls");
            mostrarLaboratorios(laboratorios, 4);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 'G':
            system("cls");
            mostrarVacunas(vacunas, 6);
            system("pause");
            system("cls");
            break;
        case 'H':
            system("cls");
            if(flagListarPacientes == 1)
            {
                if(altaInoculacion(array, 1000, &idInoculacion, list, 1000, vacunas, 6, provincias, 5, condiciones, 4) == 0)
                {
                    printf("Inoculacion cargada con exito.\n");
                    flagListarInoculacion = 1;
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al cargar Inoculacion.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error no se han cargado pacientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 'I':
            system("cls");
            if(flagListarInoculacion == 1)
            {
                mostrarInoculaciones(array, 1000, list, 1000, vacunas, 6);
                system("pause");
                system("cls");
            }
            else
            {
                printf("No se han cargado Inoculaciones.\n");
                system("pause");
                system("cls");
            }
            break;
        case 'J':
            system("cls");
            printf("1-Mostrar vacunas de un laboratorio seleccionado por el usuario.\n");
            printf("2-Pedir un grupo de riego y una provincia y mostrar los pacientes de ese grupo de riesgo y esa provincia.\n");
            printf("3-Informar el porcentaje de paciente que pertenecen al grupo de riesgo sobre el total.\n");
            printf("4-Mostrar un listado de los pacientes separados por provincia.\n");
            printf("5-Informar cual o cuales son las vacunas más inoculadas.\n");
            printf("6-Mostrar la vacuna que se ha inoculado menor cantidad de veces.\n");
            if(get_EntradaInt(&opcionInformes, "Ingrese el numero de informe.\n", "Error al ingresar informe.\n", 10, 1, 5) == 0)
            {
                switch(opcionInformes)
                {
                case 1:
                    system("cls");
                    mostrarVacunaPorLaboratorio(vacunas, 6, laboratorios, 4);
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    mostrarPacientePorRiesgoProvincia(list, 1000, provincias, 5, condiciones, 4);
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    mostrarPorcentajePacienteRiesgo(list, 1000);
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    if(flagListarPacientes == 1)
                    {
                        mostrarPacientesPorProvincias(list, 1000, provincias, 5, condiciones, 4);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("Error no se han cargado Pacientes.\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                case 5:
                    system("cls");
                    if(flagListarInoculacion == 1)
                    {
                        mostrarVacunasMasInoculadas(array, 1000, vacunas, 6);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No se han cargado Inoculaciones.\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                case 6:
                    system("cls");
                    if(flagListarInoculacion == 1)
                    {
                        mostrarVacunasMenosInoculadas(array, 1000, vacunas, 6);
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("No se han cargado Inoculaciones.\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                }

            }

            break;
        case 'Z':
            printf("  ");
            break;
        default :
            printf("Ingreso una opcion invalida.\n");
            system("pause");
            system("cls");
            break;
        }


    }
    while(opcion != 'Z');

    return 0;
}
