#ifndef VACUNA_H_INCLUDED
#define VACUNA_H_INCLUDED

typedef struct
{
    int id;
    char nombre[25];
    float precio;
    int idLaboratorio;
} eVacuna;

void mostrarVacunas(eVacuna* arrayVacuna, int longitud);

#endif // VACUNA_H_INCLUDED
