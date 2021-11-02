#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "laboratorio.h"

void mostrarLaboratorios(eLaboratorio* arrayLaboratorio, int longitud)
{
    if(arrayLaboratorio!= NULL && longitud > 0)
    {
         printf("ID                      NACIONALIDAD\n");
         for(int i = 0; i < longitud; i++)
         {
             printf("%d               %10s\n", arrayLaboratorio[i].id, arrayLaboratorio[i].nacionalidad);
         }
     }
}
