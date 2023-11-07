#ifndef MOVIMIENTOS_H_INCLUDED
#define MOVIMIENTOS_H_INCLUDED

typedef struct {
int id; /// campo único y autoincremental
int idCuenta; /// Id de la cuenta
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
char detalle[100];
float importe;
int eliminado;
}stMovimiento;

void cargaArchivoMovimientos (char nombre [], int cuentas);
void cargaUnMovimiento(int idCuenta, char nombre []);
void muestraUnMovimiento(stMovimiento m);
stMovimiento cargaUnMovimientoAleatorio (int cuentas);
void menuMuestraMoviemientos();
void bajaUnMovimiento (char nombre [], int idMovimiento);
void muestraArchivoMovimientos (char nombre []);
void modificarArchivoMovimiento(char nombre [], int idMovimiento);
void menuOpcionesTiposDeMovimientos (char a []);
void menuModificacionMovimientos();
int muestraMovimientosDeUnaCuenta (int id, char nombre []);
void consultaMovimientosPorFecha(char nombre[], int anio, int mes, int dia);
void muestraClientePorId (char nombre [], int id);
void verificacionFecha (int * anio1, int * mes1,int * dia1);
#endif // MOVIMIENTOS_H_INCLUDED
