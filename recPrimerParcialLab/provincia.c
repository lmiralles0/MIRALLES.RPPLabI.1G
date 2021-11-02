#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provincia.h"

 void mostrarProvincias(eProvincia* arrayProvincia, int longitud)
 {
     if(arrayProvincia != NULL && longitud > 0)
     {
         printf("ID                      Provincia\n");
         for(int i = 0; i < longitud; i++)
         {
             printf("%d               %10s\n", arrayProvincia[i].id, arrayProvincia[i].nombrePais);
         }
     }
 }
