#include "laboratorio.h"
#include "provincia.h"
#include "vacuna.h"
#include "condicion.h"

#ifndef DATA_WAREHOUSE_H_INCLUDED
#define DATA_WAREHOUSE_H_INCLUDED

eLaboratorio laboratorios[4] = {
    {1000, "Chino"},
    {1001, "Ingles"},
    {1002, "USA"},
    {1003, "Ruso"}
};

eProvincia provincias[5] = {
    {5000, "BsAs"},
    {5001, "Mendoza"},
    {5002, "Cordoba"},
    {5003, "San Luis"},
    {5004, "Corrientes"}
};

eVacuna vacunas[6] = {
    {20000, "Pfyzer", 450, 1002},
    {20001, "Moderna", 500, 1002},
    {20002, "Cancino", 400, 1000},
    {20003, "Synopharm", 410, 1000},
    {20004, "Sputnik", 390, 1003},
    {20005, "Jhonson", 470, 1001}
};


eCondicion condiciones[4] = {
    {0, "Salud"},
    {1, "Policia"},
    {2, "Cajero"},
    {3, "No esencial"}
};

#endif // DATA_WAREHOUSE_H_INCLUDED

