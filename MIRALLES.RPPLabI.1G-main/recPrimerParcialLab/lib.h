#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[51];
    char apellido[51];
    int isEmpty;
} eCliente;

typedef struct
{
    int codigoAlquiler;
    eCliente clienteAlquiler;
    int tiempo;
    int equipo;
    char operador[51];
    int isEmpty;
} eAlquiler;

typedef struct
{
    int id;
    char descripcion[20];
} eEquipos;



int inicializarCliente(eCliente* arrayCliente, int longitud);
int altaCliente(eCliente* arrayCliente, int longitud, int* idCliente);
int modificarCLiente(eCliente* arrayCliente, int longitud, int opcion);
int bajaCliente(eCliente* arrayCliente, int longitud);
int mostrarClientes(eCliente* arrayCliente, int longitud);
int buscarCliente(eCliente* arrayCliente, int longitud, int idCliente);
void mostrarCliente(eCliente arrayCliente);
/////////Cliente
int inicializarAlquiler(eAlquiler* arrayAlquiler, int longitudA);
int altaAlquiler(eAlquiler* arrayAlquiler, int longitudA, int* idAlquileres, eCliente* arrayCliente, int longitudC);
int bajaAlquiler(eAlquiler* arrayAlquiler, int longitudA, eCliente* arrayCliente, int longitudC, eEquipos* arrayEquipos, int longitudE);
int buscarAlquiler(eAlquiler* arrayAlquiler, int longitudA, int id);
int mostrarAlquileres(eAlquiler* arraysAlquiler, int longitudA, eCliente* arrayCliente, int longitudC, eEquipos* arrayEquipos, int longitudE);
/////////Alquiler
int clienteConMasAlquileres(eCliente* arrayCliente, int longitudC, eAlquiler* arrayAlquiler, int longitudA);
int equiposMasAlquilados(eEquipos* arrayEquipos, int longitudE, eAlquiler* arrayAlquiler, int longitudA);
int clienteYAlquileres(eCliente* arrayCliente, eAlquiler* arrayAlquiler, int longitudC, int longitudA, eEquipos* arrayEquipo, int longitudE);
float promedioAlquileresTiempo(eAlquiler* arrayAlquiler, int longitudA);


/////////Informe

#endif // LIB_H_INCLUDED
