#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ListaMovimientos.h"

nodoListaMovimiento* inicListaMov(){
    return NULL;
}

nodoListaMovimiento* crearNodoListaMov(stMovimiento mov){
    nodoListaMovimiento* nuevo = (nodoListaMovimiento*)malloc(sizeof(nodoListaMovimiento));
    nuevo->dato = mov;
    nuevo->sig = NULL;
    return nuevo;
}

nodoListaMovimiento* agregarMovAlPpio(celdaCuentas cuenta, nodoListaMovimiento* listaMov, stMovimiento mov){
    return agregarNodoMovAlPpio(cuenta, listaMov, crearNodoListaMov(mov));
}

nodoListaMovimiento* agregarNodoMovAlPpio(celdaCuentas cuenta, nodoListaMovimiento* listaMov, nodoListaMovimiento* nuevo){
    if(listaMov == NULL){
        listaMov = nuevo;
    }else{
        nuevo->sig = listaMov;
        listaMov = nuevo;
    }
    return listaMov;
}

void mostrarListaMov(nodoListaMovimiento* listaMov){
    nodoListaMovimiento* aux = listaMov;
    while(aux){
        muestraUnMovimiento(aux->dato);
        aux = aux->sig;
    }
}

