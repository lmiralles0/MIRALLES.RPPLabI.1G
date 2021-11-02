#ifndef CONDICION_H_INCLUDED
#define CONDICION_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eCondicion;


void mostrarCondicion(eCondicion* arrayCondicion, int longitud);

#endif // CONDICION_H_INCLUDED
