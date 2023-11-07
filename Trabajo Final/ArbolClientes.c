#include <stdio.h>
#include <stdlib.h>
#include "ArbolClientes.h"
#include "string.h"
///PARA EL TP HAY Q HACER UNA OPCION DE BORRAR UN CLIENTE DEL ARBOL
nodoArbolCliente* inicArbol() {
    return NULL;
}

nodoArbolCliente* crearNodoArbol(stCliente cliente) {
    nodoArbolCliente* nuevo = (nodoArbolCliente*)malloc(sizeof(nodoArbolCliente));
    nuevo->dato = cliente;
    nuevo->arregloCuentas = NULL;
    nuevo->arregloCuentas.val = 0;
    nuevo->arregloCuentas.dim = 3;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbolCliente* agregarClienteAlArbolPorDNI(nodoArbolCliente* arbol, stCliente cliente) {
    return agregarNodoAlArbolPorDNI(arbol, crearNodoArbol(cliente));
}

nodoArbolCliente* agregarNodoAlArbolPorDNI(nodoArbolCliente* arbol, nodoArbolCliente* nuevo) {

    if(arbol == NULL) {
        arbol = nuevo;
    } else {
        if(strcmp(nuevo->dato.dni, arbol->dato.dni) < 0) {
            arbol->izq = agregarNodoAlArbolPorDNI(arbol->izq, nuevo);
        } else if(strcmp(nuevo->dato.dni, arbol->dato.dni) > 0) {
            arbol->der = agregarNodoAlArbolPorDNI(arbol->der, nuevo);
        }
    }
    return arbol;
}

int existeEnElAbolPorDNI(nodoArbolCliente* arbol, char dni[]) {
    int existe = 0;
    if(arbol) {
        if(strcmp(arbol->dato.dni, dni) == 0) {
            existe = 1;
        } else {
            if(strcmp(arbol->dato.dni, dni) < 0) {
                existe = existeEnElAbolPorDNI(arbol->izq, dni);
            } else {
                existe = existeEnElAbolPorDNI(arbol->der, dni);

            }
        }
    }
    return existe;
}

void mostrarArbolINORDER(nodoArbolCliente* arbol){
    if(arbol){
        mostrarArbolINORDER(arbol->izq);
        muestraUnCliente(arbol->dato);
        mostrarArbolINORDER(arbol->der);
    }
}

nodoArbolCliente* archivoClientesToArbolClientes(char nombreArchivo[], nodoArbolCliente* arbolClientes){
    FILE* archi = fopen(nombreArchivo, "rb");
    stCliente cliente;
    if(archi){
       while( fread(&cliente, sizeof(stCliente), 1, archi) > 0 ){

       }
        fclose(archi);
    }


}

void archivoToArregloClientes(FILE* archi, stCliente *arreglo, int *dim){
    stCliente cliente;
    int i = 0;
    fseek(archi, 0, SEEK_END);
    (*dim) = ftell(archi)/sizeof(stCliente);
    arreglo = (stCliente*)malloc((*dim)*sizeof(stCliente));
    fseek(archi, 0, SEEK_SET);
    while( fread(&cliente, sizeof(stCliente), 1, archi) > 0 ){
        arreglo[i] = cliente;
        i++;
    }


}
