#ifndef ARREGLOCUENTAS_H_INCLUDED
#define ARREGLOCUENTAS_H_INCLUDED
#include "Cuenta.h"
#include "ListaMovimientos.h"
#include "EstructuraArregloCuentas.h"


typedef struct {
    celdaCuentas *arrCuentas;
    int val;
    int dim;
}stArregloCuentas;

int altaCuenta(celdaCuentas *arrCuentas, int val, int *dim, stCuenta nueva);
void mostrarArrCuentas(celdaCuentas arrCuentas[], int val);

#endif // ARREGLOCUENTAS_H_INCLUDED
