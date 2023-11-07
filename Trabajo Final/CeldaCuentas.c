#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ListaMovimientos.h"
#include "CeldaCuentas.h"

stCeldaCuenta crearCeldaCuenta(stCuenta cuenta){
    celdaCuentas nueva;
    nueva.dato = cuenta;
    nueva.listaMov = inicListaMov();
    return nueva;
}

void mostrarCeldaCuenta(stCeldaCuenta celda){
    muestraUnaCuenta(celda->dato);
}
