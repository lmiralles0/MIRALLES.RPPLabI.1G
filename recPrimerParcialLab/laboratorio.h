#ifndef LABORATORIO_H_INCLUDED
#define LABORATORIO_H_INCLUDED

typedef struct
{
    int id;
    char nacionalidad[20];

} eLaboratorio;

void mostrarLaboratorios(eLaboratorio* arrayLaboratorio, int longitud);

#endif // LABORATORIO_H_INCLUDED
