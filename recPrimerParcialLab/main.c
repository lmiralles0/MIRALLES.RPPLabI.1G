#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas_Get.h"
#include "lib.h"
#define SIZE 100



int main()
{
    eCliente lista[SIZE];
    eAlquiler lista2[SIZE];
    int idCliente = 1000;
    int idAlquier = 9000;
    int opcion;
    int opcion2;
    int opcionModificar;
    int flagInicio = 0;
    int flagListaCliente = 0;
    int flagListaAlquiler = 0;
    eEquipos aux[3] = {
    {1, "AMOLADORA"},
    {2, "MEZCLADORA"},
    {3, "TALADRO"},
    };


    do
    {
        if(flagInicio == 0)
        {
            inicializarAlquiler(lista2, SIZE);
            inicializarCliente(lista, SIZE);
            flagInicio = 1;
        }

        printf("  ***ABM MAQUINARIA*** \n\n");
        printf("1) Alta Cliente.\n");
        printf("2) Modificar datos Cliente.\n");
        printf("3) Baja Cliente.\n");
        printf("4) Alta alquiler.\n");
        printf("5) Fin Alquiler.\n");
        printf("6) Informes.\n");
        printf("10) Salir.\n\n");

        while(get_EntradaInt(&opcion, "Ingrese opcion del menu.\n", "Error al ingresar opcion.\n", 10, 1, 3) != 0)
        {
            get_EntradaInt(&opcion, "Ingrese opcion del menu\n", "Error al ingresar opcion.\n", 10, 1, 1);
        }
        switch(opcion)
        {
        case 1:
            system("cls");
            if(altaCliente(lista, SIZE, &idCliente) == 0)
            {
                printf("\nAlta existosa.\n");
                system("pause");
                system("cls");
                flagListaCliente = 1;
            }
            else
            {
                printf("Error al cargar Cliente.\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            system("cls");
            if(flagListaCliente == 1)
            {
                mostrarClientes(lista, SIZE);
                printf("\n");
                printf("1) Modificar Nombre.\n");
                printf("2) Modificar Apellido.\n");
                if(get_EntradaInt(&opcionModificar, "Ingrese opcion del menu.\n", "Erorr.\n", 2, 1, 5) == 0)
                {
                    modificarCLiente(lista, SIZE, opcionModificar);
                    printf("Modificacion exitosa.\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al seleccionar una opcion a modificar.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error, no se han cargado clientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            system("cls");
            if(flagListaCliente == 1)
            {
                if(bajaCliente(lista, SIZE) == 0)
                {
                    printf("Baja exitosa.\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("Error al dar de baja Cliente.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error, no se han cargado clientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            system("cls");
            if(flagListaCliente == 1)
            {
                if(altaAlquiler(lista2, SIZE, &idAlquier, lista, SIZE) == 0)
                {
                    printf("\nAlta existosa.\n");
                    system("pause");
                    system("cls");
                    flagListaAlquiler = 1;
                }
                else
                {
                    printf("Error al cargar Alquiler.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error, no se han cargado clientes.\n");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            system("cls");
            if(flagListaAlquiler == 1 && flagListaCliente == 1)
            {
                if(bajaAlquiler(lista2, SIZE, lista, SIZE, aux, 3) == 0)
                {
                    printf("Alquiler finalizado.\n");
                }
                else
                {
                    printf("Error al dar de baja alquiler.\n");
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                printf("Error, no se han cargado clientes ni alquileres.\n");
                system("pause");
                system("cls");
            }
            break;
        case 6:
            system("cls");
            if(flagListaAlquiler == 1 && flagListaCliente == 1)
            {
                printf("Informes:\n");
                printf("\t1- El nombre y apellido del asociado con más alquileres.\n");
                printf("\t2- El o los equipo/s más alquilado/s y su cantidad.\n");
                printf("\t3- El tiempo promedio real de alquiler de los equipos.\n");
                printf("\t4- Todos los clientes con sus alquileres.\n");
                while(get_EntradaInt(&opcion2, "Ingrese opcion del menu.\n", "Error al ingresar opcion.\n", 4, 1, 3) != 0)
                {
                    get_EntradaInt(&opcion2, "Ingrese opcion del menu\n", "Error al ingresar opcion.\n", 4, 1, 1);
                }
                switch(opcion2)
                {
                case 1:
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    if(equiposMasAlquilados(aux, 3, lista2, SIZE) == 0)
                    {
                        system("pause");
                        system("cls");
                    }
                    break;
                case 3:
                    system("cls");
                    printf("El promedio de los alquileres real es de: %0.2f\n", promedioAlquileresTiempo(lista2, SIZE));
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    system("cls");
                    if(clienteYAlquileres(lista, lista2, SIZE, SIZE, aux, 3) == 0)
                    {
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        system("pause");
                        system("cls");
                    }
                    break;
                }
            }
            else
            {
                printf("Aun no cargo cliente y alquiler.\n");
                system("pause");
                system("cls");
            }
            break;
        case 10:
            break;
        default:
            system("cls");
            system("pause");
            printf("Ingreso una opcion incorrecta.\n");
            break;
        }
    }
    while(opcion != 10);


    return 0;
}
