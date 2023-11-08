#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArregloCuentas.h"
#include "ListaMovimientos.h"
#include "CeldaCuentas.h"


stArregloCuentas inicArregloCuentas(){
    stArregloCuentas arreglo;
    arreglo.dim = 10;
    arreglo.val = 0;
    arreglo.arrCuentas = (stCeldaCuenta*) malloc(dim*sizeof(stCeldaCuenta));

    return arreglo;
}

stArregloCuentas redimensionarArreglo(stArregloCuentas arreglo){
    arreglo.dim = 2*arreglo.dim;
    arreglo.arrCuentas = (stCeldaCuenta*)realloc(&arreglo, dim*sizeof(stCeldaCuenta));

    return arreglo;
}

int agregarCeldaCuenta(stArregloCuentas arreglo, stCeldaCuenta nueva){//agrega una cuenta en el arreglo
    if(arreglo.dim == arreglo.val){
        arreglo = redimensionarArreglo(arreglo);
    }
    arreglo[arreglo.val].arrCuentas = nueva;
    arreglo.val++;

    return arreglo.val;
}

int archivoCuentasToArregloCuentasConFiltroCliente(char nombreArchivo[], nodoArbolCliente* nodoCliente){
    FILE* archi = fopen(nombreArchivo, "rb");
    stCuenta cuenta;
    if(archi){
        while(fread(&cuenta, sizeof(stCuenta), 1, archi) > 0){
            if(cuenta.idCliente == nodoCliente.dato.id){
                nodoCliente.arregloCuentas = agregarCeldaCuenta(nodoCliente.arregloCuentas, crearCeldaCuenta(cuenta));
            }
        }
        fclose(archi);
    }

    return lista;
}

