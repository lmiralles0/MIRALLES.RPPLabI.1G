#ifndef BIBLIOTECAS_GET_H_INCLUDED
#define BIBLIOTECAS_GET_H_INCLUDED


int get_Texto(char* pResultado, int longitud, char* mensaje, char* mensajeError, int intentos);
//
int get_EntradaInt(int* pResultado, char* mensaje, char* mensajeError, int maximo, int minimo, int intentos);
//
int get_EntradaFloat(float* pResultado, char* mensaje, char* mensajeError,float maximo,float minimo, int intentos);


#endif // BIBLIOTECAS_GET_H_INCLUDED
