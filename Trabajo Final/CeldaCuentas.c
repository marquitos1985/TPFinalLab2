#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ListaMovimientos.h"
#include "CeldaCuentas.h"

stCeldaCuenta crearCeldaCuenta(stCuenta dato){
    stCeldaCuenta nueva;
    nueva.dato = dato;
    nueva.listaMov = inicListaMov();

    return nueva;
}

void mostrarCeldaCuenta(stCeldaCuenta celda){
    muestraUnaCuenta(celda->dato);
}
