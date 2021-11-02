#include "paciente.h"
#include "inoculacion.h"
#include "laboratorio.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

void mostrarVacunaPorLaboratorio(eVacuna* arrayVacunas, int longtidudV, eLaboratorio* arrayLaboratorio, int longitudL);
void mostrarPacientePorRiesgoProvincia(ePaciente* arrayPacientes, int longitudP, eProvincia* arrayProvincias, int longitudPro, eCondicion* arrayCondicion, int longitudCon);
void mostrarPorcentajePacienteRiesgo(ePaciente* arrayPaciente, int longitud);
void mostrarPacientesPorProvincias(ePaciente* arrayPaciente, int longitudPa, eProvincia* arrayProvincia, int longitudPr, eCondicion* arrayCondicion, int longitudCon);
void mostrarVacunasMasInoculadas(eInoculacion* arrayInoculacion, int longitudI, eVacuna* arrayVacuna, int longtiduV);
void mostrarVacunasMenosInoculadas(eInoculacion* arrayInoculacion, int longitudI, eVacuna* arrayVacuna, int longtiduV);

#endif // INFORMES_H_INCLUDED
