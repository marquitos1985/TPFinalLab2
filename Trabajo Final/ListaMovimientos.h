#ifndef LISTAMOVIMIENTOS_H_INCLUDED
#define LISTAMOVIMIENTOS_H_INCLUDED
#include "Movimientos.h"

typedef struct _nodoListaMovimiento {
    stMovimiento dato;
    struct _nodoListaMovimiento* sig;
} nodoListaMovimiento;

nodoListaMovimiento* inicListaMov();
nodoListaMovimiento* crearNodoListaMov(stMovimiento mov);
nodoListaMovimiento* agregarMovAlPpio(nodoListaMovimiento* listaMov, stMovimiento mov);
nodoListaMovimiento* agregarNodoMovAlPpio(nodoListaMovimiento* listaMov, nodoListaMovimiento* nuevo);

#endif // LISTAMOVIMIENTOS_H_INCLUDED
