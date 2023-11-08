#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "ArbolClientes.h"

typedef struct{

int id; /// campo único y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
char email[60];
char domicilio[45];
char telefono[12];
int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;


void muestraUnCliente(stCliente cliente);
void eliminaCliente(stCliente cliente);
stCliente cargaUnClienteAleatoriamente ();
void cargaArchivoClientes (char nombre []);
void muestraArchivoClientes (char nombre []);


int cargaUnCliente(char nombreArchivo[]);
void muestraUnCliente(stCliente cliente);
void altaCliente(char nombreArchivo[]);
void adicionClienteArchivo(char nombreArchivo[],stCliente cliente);
void setEliminadoArchivoPorDNI(FILE *archi, char dni[]);
int posicionClienteEnArchivoPorDNI (FILE *archi,char dni[]);
stCliente buscarClienteEnArchivoPorPosicion(FILE *archi, int posicion) ;
void reemplazaClienteEnArchivoPorPosicion(FILE *archi, int posicion, stCliente cliente);
void modificarClienteArchivoPorDNI(char nombreArchivo[], char dni[]) ;
void consultaClientesArchivo(char nombreArchivo[], char clientesPorNombre[]);
int archivoDeConsultasPorDato(FILE *archi,char dato[], char clientesPorDato[], int tipo) ;
int verificarDNICliente(char dni[]);
int verificarEmail(char email[]);
void setNombreCliente(char nombre[]);
void setApellidoCliente(char apellido[]);
void setDNICliente(char dni[]);
void setDomicilioCliente(char domicilio[]);
void setEmailCliente(char email[]);
void setTelefonoCliente(char telefono[]);
int posicionClienteEnArchivoPorDNI1 (char nombre [] ,char dni[]);
stCliente buscarClienteEnArchivoPorPosicion1(char nombre [], int posicion);
void bajaClientePorId (char nombreCliente [],char nombreCuenta [],char nombreMovimiento[], int id);
#endif // CLIENTE_H_INCLUDED
