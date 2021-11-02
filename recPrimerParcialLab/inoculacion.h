#include "paciente.h"
#include "vacuna.h"
#include "bibliotecas_Get.h"
#ifndef INOCULACION_H_INCLUDED
#define INOCULACION_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    int idPaciente;
    int idVacuna;
    int isEmpty;
    eFecha fecha;
} eInoculacion;


int inicializarInoculacion(eInoculacion* arrayInoculacion, int longitud);
int altaInoculacion(eInoculacion* arrayInoculacion, int longtiudI, int* idInoculacion, ePaciente* arrayPaciente, int longitudP, eVacuna* arrayVacuna, int longitudV, eProvincia* arrayProvincia, int longitudPro, eCondicion* arrayCondicion, int longitudCon);
void mostrarInoculacion(eInoculacion inoculacion, char* bufferNombre, char* bufferVacuna);
int mostrarInoculaciones(eInoculacion* arrayInoculacion, int longitudI, ePaciente* arrayPacientes, int longitudP, eVacuna* arrayVacunas, int longitudV);
void cargarDescripcionNombre(ePaciente* arrayPacientes, int longitudP, int idPaciente, char* descripcionP);
void cargarDescripcionVacuna(eVacuna* arrayVacunas, int longitudV, int idVacunas, char* descripcionV);

#endif // INOCULACION_H_INCLUDED
