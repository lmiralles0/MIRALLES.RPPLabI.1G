#include "provincia.h"
#include "condicion.h"
#include "bibliotecas_Get.h"

#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int edad;
    char grupoRiesgo;
    int idProvincia;
    int isEmpty;
    int idCondicion;
} ePaciente;

int inicializarPaciente(ePaciente* arrayPaciente, int longitud);
int altaPaciente(ePaciente* arrayPaciente, int longitud, int* idPaciente, eProvincia* arrayProvincias, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon);
int modificarPaciente(ePaciente* arrayPaciente, int longitud, int opcion2, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon);
int bajaPaciente(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon);
int listarPaciente(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longtiduCon);
int mostrarPacientes(ePaciente* arrayPaciente, int longitud, eProvincia* arrayProvincia, int longitudProvincias, eCondicion* arrayCondicion, int longitudCon);
int buscarPaciente(ePaciente* arrayPaciente, int longitud, int idPaciente);
void mostrarPaciente(ePaciente arrayPaciente, char* descripcionProvincia, char* descripcionCondicion);
void cargarDescripcionProvincia(eProvincia* arrayProvincia, int longitudProvincias, int idProvincia, char* descripcion);
void cargarDescripcionCondicion(eCondicion* arrayCondicion, int longitudCondicion, int idCondicion, char* descripcionCon);

#endif // PACIENTE_H_INCLUDED
