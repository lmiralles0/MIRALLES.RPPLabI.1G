#ifndef PROVINCIA_H_INCLUDED
#define PROVINCIA_H_INCLUDED

typedef struct
{
    int id;
    char nombrePais[20];
} eProvincia;

void mostrarProvincias(eProvincia* arrayProvincia, int longitud);

#endif // PROVINCIA_H_INCLUDED
