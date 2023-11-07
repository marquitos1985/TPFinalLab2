#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ListaMovimientos.h"
#include "CeldaCuentas.h"

stCeldaCuentas crearCeldaCuenta(stCuenta cuenta){
    celdaCuentas nueva;
    nueva.dato = cuenta;
    nueva.listaMov = inicListaMov();
    return nueva;
}

void mostrarCeldaCuenta(stCeldaCuentas celda){
    muestraUnaCuenta(celda->dato);
}
