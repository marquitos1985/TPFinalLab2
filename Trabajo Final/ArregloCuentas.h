#ifndef ARREGLOCUENTAS_H_INCLUDED
#define ARREGLOCUENTAS_H_INCLUDED
#include "Cuenta.h"
#include "ListaMovimientos.h"
#include "ArregloCuentas.h"


typedef struct {
    stCeldaCuenta *arrCuentas;
    int val;
    int dim;
}stArregloCuentas;

int altaCuenta(stCeldaCuentas *arrCuentas, int val, int *dim, stCuenta nueva);
void mostrarArrCuentas(stCeldaCuentas arrCuentas[], int val);

#endif // ARREGLOCUENTAS_H_INCLUDED
