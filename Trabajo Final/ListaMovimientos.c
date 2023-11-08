#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ListaMovimientos.h"

nodoListaMovimientos* inicListaMov(){
    return NULL;
}

nodoListaMovimiento* crearNodoListaMov(stMovimiento mov){
    nodoListaMovimientos* nuevo = (nodoListaMovimientos*)malloc(sizeof(nodoListaMovimientos));
    nuevo->dato = mov;
    nuevo->sig = NULL;
    return nuevo;
}

nodoListaMovimientos* agregarMovAlPpio(nodoListaMovimientos* listaMov, stMovimiento mov){
    return agregarNodoMovAlPpio(listaMov, crearNodoListaMov(mov));
}

nodoListaMovimientos* agregarNodoMovAlPpio(nodoListaMovimientos* listaMov, nodoListaMovimientos* nuevo){
    if(listaMov == NULL){
        listaMov = nuevo;
    }else{
        nuevo->sig = listaMov;
        listaMov = nuevo;
    }
    return listaMov;
}

void mostrarListaMov(nodoListaMovimientos* listaMov){
    nodoListaMovimientos* aux = listaMov;
    while(aux){
        muestraUnMovimiento(aux->dato);
        aux = aux->sig;
    }
}

nodoListaMovimientos* archivoMovimientosToListaMovConFiltroCuenta(char nombreArchivo[], stCeldaCuenta celda, nodoListaMovimientos* lista){
    FILE* archi = fopen(nombreArchivo, "rb");
    stMovimiento mov;
    if(archi){
        while(fread(&mov, sizeof(stMovimiento), 1, archi) > 0){
            if(mov.idCuenta == celda.dato.id){
                lista = agregarMovAlPpio(lista, mov);
            }
        }
        fclose(archi);
    }

    return lista;
}
