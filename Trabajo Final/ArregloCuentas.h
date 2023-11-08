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

stArregloCuentas inicArregloCuentas();
stArregloCuentas redimensionarArreglo(stArregloCuentas arreglo);
int agregarCeldaCuenta(stArregloCuentas arreglo, stCeldaCuenta nueva);

#endif // ARREGLOCUENTAS_H_INCLUDED
