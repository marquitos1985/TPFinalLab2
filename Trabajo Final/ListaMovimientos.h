#ifndef LISTAMOVIMIENTOS_H_INCLUDED
#define LISTAMOVIMIENTOS_H_INCLUDED
#include "Movimientos.h"
#include "CeldaCuentas.h"

typedef struct _nodoListaMovimientos {
    stMovimiento dato;
    struct _nodoListaMovimientos* sig;
} nodoListaMovimientos;

nodoListaMovimientos* inicListaMov();
nodoListaMovimientos* crearNodoListaMov(stMovimiento mov);
nodoListaMovimientos* agregarMovAlPpio(nodoListaMovimientos* listaMov, stMovimiento mov);
nodoListaMovimientos* agregarNodoMovAlPpio(nodoListaMovimientos* listaMov, nodoListaMovimientos* nuevo);
nodoListaMovimientos* archivoMovimientosToListaMovConFiltroCuenta(char nombreArchivo[], stCeldaCuenta celda, nodoListaMovimientos* lista);

#endif // LISTAMOVIMIENTOS_H_INCLUDED
