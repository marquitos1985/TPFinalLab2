#ifndef CELDACUENTAS_H_INCLUDED
#define CELDACUENTAS_H_INCLUDED
#include "Cuenta.h"
#include "ArregloCuentas.h"
#include "ListaMovimientos.h"

typedef struct {
    stCuenta dato;
    nodoListaMovimientos* listaMov;
}stCeldaCuenta;

stCeldaCuenta crearCeldaCuenta(stCuenta dato);


#endif // CELDACUENTAS_H_INCLUDED
