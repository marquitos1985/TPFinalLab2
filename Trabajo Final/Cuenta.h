#ifndef CUENTAS_H_INCLUDED
#define CUENTAS_H_INCLUDED
typedef struct {
    int id; /// campo único y autoincremental
    int idCliente; /// Id del Cliente dueño de la Cuenta;
    int monto;
    int nroCuenta;
    int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
    float costoMensual; /// Costo de mantenimiento del producto;
    int eliminado; /// 0 si está activo - 1 si está eliminado
}stCuenta;

void muestraUnaCuenta (stCuenta a);
stCuenta cargaUnaCuentaAleatoriamente (int idCliente, int tipoCuenta);
void cargaArchivoCuentas (char nombre []);
void muestraArchivoCuentas(char nombre []);
//void cargaUnaCuenta (char nombre [], int idClientePa, char tipoDeUsuario);
int cargaUnaCuenta (char nombre [], int idCliente, char tipoDeUsuario);
int muestraCuentasDeUnCliente (int idCuentas [],char nombre[] , int val);
int buscarCuentasActivasDeClientes (int idCuentas [], int idCliente,char nombre[] );
int validarCuentasParaAlta (FILE * archi, int tipoDeCuenta, int idCliente);
void bajaUnaCuenta (char nombre [], char nombreMovimientos[], int numeroDeCuenta);
void modificarArchivoCuenta(char nombre[], int idCliente);
void menuModificacionCuenta();
int validarNumeroCuenta (FILE* archi, int nro);
int buscaIDCunetaPorNroCuenta (int num, char nombre []);
int ultimoIdArchivoCuentas (char nombre []);
#endif // CUENTAS_H_INCLUDED
