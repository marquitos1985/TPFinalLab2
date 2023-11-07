#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArregloCuentas.h"
#include "ListaMovimientos.h"
#include "CeldaCuentas.h"


int altaCuenta(stArregloCuentas *arrCuentas, stCuenta nueva){

    if(arrCuentas.val == 0){
        arrCuentas = (stCeldaCuentas*)malloc((nodoCliente.arregloCuentas.dim)*sizeof(stCeldaCuentas));
    }else if(nodoCliente.arregloCuentas.val == nodoCliente.arregloCuentas.dim){
        arrCuentas.dim = 2*(arrCuentas.dim);
        arrCuentas = (stCeldaCuentas*)realloc((nodoCliente.arregloCuentas.dim)*sizeof(stCeldaCuentas));
    }

    arrCuentas[arrCuentas.val] = altaCeldaCuenta(nueva);
    arrCuentas.val++;

    return arrCuentas.val;
}

void mostrarArrCuentas(celdaCuentas arrCuentas[], int val){
    for(int i = 0; i < val; i++){

    }
}
