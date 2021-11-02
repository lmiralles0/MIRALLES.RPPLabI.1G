#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "condicion.h"

void mostrarCondicion(eCondicion* arrayCondicion, int longitud)
{
    if(arrayCondicion != NULL && longitud > 0)
    {
         printf("ID                      Condicion\n");
         for(int i = 0; i < longitud; i++)
         {
             printf("%d               %10s\n", arrayCondicion[i].id, arrayCondicion[i].descripcion);
         }
     }
}
