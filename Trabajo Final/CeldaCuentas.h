#ifndef CELDACUENTAS_H_INCLUDED
#define CELDACUENTAS_H_INCLUDED
#include "Cuenta.h"
#include "ListaMovimientos.h"
#include "EstructuraArregloCuentas.h"

typedef struct {
    stCuenta dato;
    nodoListaMovimiento* listaMov;
}stCeldaCuentas;

stCeldaCuentas crearCeldaCuenta(stCuenta cuenta);


#endif // CELDACUENTAS_H_INCLUDED
