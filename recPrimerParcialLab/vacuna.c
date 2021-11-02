#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vacuna.h"

void mostrarVacunas(eVacuna* arrayVacuna, int longitud)
{
    if(arrayVacuna != NULL && longitud > 0)
    {
         printf("ID                   NOMBRE         PRECIO\n");
         for(int i = 0; i < longitud; i++)
         {
             printf("%d           %10s           %0.2f\n", arrayVacuna[i].id, arrayVacuna[i].nombre, arrayVacuna[i].precio);
         }
     }
}
