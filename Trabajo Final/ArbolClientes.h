#ifndef ARBOLCLIENTES_H_INCLUDED
#define ARBOLCLIENTES_H_INCLUDED
#include "Cliente.h"
#include "ArregloCuentas.h"

typedef struct _nodoArbolCliente {
    stCliente dato;
    celdaCuentas* arregloCuentas;
    struct _nodoArbolCliente* izq;
    struct _nodoArbolCliente* der;
} nodoArbolCliente;

nodoArbolCliente* inicArbol();
nodoArbolCliente* crearNodoArbol(stCliente cliente);
nodoArbolCliente* agregarClienteAlArbolPorDNI(nodoArbolCliente* arbol, stCliente cliente) ;
nodoArbolCliente* agregarNodoAlArbolPorDNI(nodoArbolCliente* arbol, nodoArbolCliente* nuevo) ;
int existeEnElAbolPorDNI(nodoArbolCliente* arbol, char dni[]) ;
void mostrarArbolINORDER(nodoArbolCliente* arbol);
nodoArbolCliente* archivoClientesToArbolClientes(char nombreArchivo[], nodoArbolCliente* arbol);


#endif // ARBOLCLIENTES_H_INCLUDED
