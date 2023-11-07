#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "Movimientos.h"
#include "cliente.h"
#include "time.h"
#include "string.h"
#include "Utileria.h"
#define ENTER 13
#define ESC 27

/** \brief carga un movimiento al archivo de movimientos abriendo el archivo y
 *leyendo el ultimo idMovimiento, trabajando apartir de ese id.
 * \param
 * \param
 * \return
 *
 */
void cargaUnMovimiento(int idCuenta, char nombre [])
{
    stMovimiento a;
    char opcion;
    FILE * archivo= fopen(nombre, "a+b");
    if (archivo)
    {
        fseek(archivo, -sizeof(stMovimiento),2);
        fread(&a, sizeof(stMovimiento), 1, archivo);
        a.id++;
        a.idCuenta=idCuenta;
        a.eliminado=0;
        menuOpcionesTiposDeMovimientos(a.detalle);
        do
        {
            printf("Monto: $  ");
            scanf("%f", &a.importe);
            printf("Para confirmar el monto: %.2f \n(OPRIMA ENTER)\n", a.importe);
            opcion=getch();
        }
        while (opcion!=ENTER);
        time_t now;
        time(&now);
        struct tm *local = localtime(&now);
        a.anio= local->tm_year+1900;
        a.mes= local->tm_mon+1;
        a.dia= local->tm_mday;
        fseek(archivo, 0,2);
        fwrite(&a, sizeof (stMovimiento), 1, archivo);
        system("cls");
        fclose(archivo);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Carga un movimiento aleatoriamente y devuelve un dato de tipo stMovimiento.
 *
 * \param
 * \param
 * \return
 *
 */
stMovimiento cargaUnMovimientoAleatorio (int cuentas)
{
    stMovimiento a;
    static int staticid=-1;
    staticid++;
    a.id=staticid;
    a.idCuenta=mayorMenor(cuentas,0);
    a.anio= mayorMenor(2024, 2005);
    if (a.anio==2023)
    {
        a.mes=mayorMenor(5,1);
    }
    else
    {
        a.mes=mayorMenor(13,1);
    }
    if (a.mes== 4 && a.mes== 6 && a.mes== 9 && a.mes== 11 )
    {
        a.dia= mayorMenor(31,1);
    }
    else if(a.mes==2)
    {
        a.dia=mayorMenor(29,1);
    }
    else
    {
        a.dia=mayorMenor(32,1);
    }
    a.importe= mayorMenor(900000,-10000)*10;
    if (a.importe<0)
    {
        carga_aleatoria_movimientos_negativos(a.detalle);
    }
    else
    {
        carga_aleatoria_movimientos_positivos(a.detalle);
    }
    a.eliminado=0;
    return a;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void muestraUnMovimiento(stMovimiento m)
{
    printf("-------------------------------MOVIMIENTO------------------------------------\n");
    printf("_____________________________________________________________________________\n");
    printf("ID............................................: %d\n", m.id);
    printf("ID Cuenta.....................................: %d\n", m.idCuenta);
    printf("Fecha.........................................: %02d/%02d/%d\n",m.dia, m.mes, m.anio);
    printf("Tipo de movimiento............................: %s\n",m.detalle);
    printf("Importe.......................................: $ %.2f\n",m.importe);
    printf("ELIMINADO.....................................: %d\n",m.eliminado);
    printf("_____________________________________________________________________________\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuMuestraMoviemientos()
{
    printf("--------------------------------------\n");
    printf("---------SELECCIONE UNA OPCION--------\n");
    printf("A)Pagar luz.\n");
    printf("B)Pagar gas.\n");
    printf("C)Pagar obra social.\n");
    printf("D)Pagar patente.\n");
    printf("E)Pagar seguro.\n");
    printf("F)Pagar tarjeta de credito.\n");
    printf("G)Transferencia.\n");
    printf("H)Transferencia a cuenta de terceros.\n");
    printf("--------------------------------------\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Modifica un movimiento del archivo cambiando el valor de eliminado a 1,
 * recibe como parametro el nombre del FILE y el id del movimiento para identificar lo.
 * \param
 * \param
 * \return
 *
 */
void bajaUnMovimiento (char nombre [], int idMovimiento)
{
    stMovimiento a;
    FILE * archivo= fopen(nombre, "r+b");
    if (archivo)
    {
        fseek(archivo, (idMovimiento) * sizeof(stMovimiento),0);
        fread(&a, sizeof(stMovimiento), 1, archivo);
        a.eliminado=1;
        fseek(archivo, (idMovimiento) * sizeof(stMovimiento),0);
        fwrite(&a, sizeof (stMovimiento), 1, archivo);
        fclose(archivo);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Carga de forma aleatoria un total de 1000 movimientos en un archivo, recibe como parametro el nombre del FILE.
 *
 * \param
 * \param
 * \return
 *
 */

void cargaArchivoMovimientos (char nombre [], int cuentas)
{
    stMovimiento a;
    FILE * archi = fopen(nombre, "wb");
    if (archi!=NULL)
    {
        for (int i =0 ; i<1000 ; i++)
        {
            a=cargaUnMovimientoAleatorio(cuentas);
            fwrite(&a, sizeof (stMovimiento), 1, archi);
        }
    }
    fclose(archi);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra el archivo de movimientos, filtrando los que estan eliminados, recibe por parametro el nombre del FILE.
 *
 * \param
 * \param
 * \return
 *
 */
void muestraArchivoMovimientos (char nombre [])
{
    stMovimiento a;
    FILE * archi = fopen(nombre, "rb");
    if (archi!=NULL)
    {
        while (fread(&a, sizeof (stMovimiento),1, archi)>0)
        {
            if (a.eliminado==0)
            {
                muestraUnMovimiento(a);
            }
        }
    }
    fclose(archi);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Modifica un movimiento buscado lo por su ID, recibe por parametro el nombre del FILE y el id del movimiento.
 *
 * \param
 * \param
 * \return
 *
 */
void modificarArchivoMovimiento(char nombre [], int idMovimiento)
{
    char opcion1 [2];
    char opcion;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    stMovimiento a;
    FILE * archi = fopen(nombre, "r+b");
    if(archi)
    {
        do
        {
            fread(&a, sizeof(stMovimiento), 1, archi);
        }
        while(a.id!=idMovimiento);
        muestraUnMovimiento(a);
        printf("Confirme si desea modificar este movimiento: si / no.\n");
        gets(opcion1);
        system("cls");
        if (strcmp(opcion1, "si")==0)
        {
            do
            {
                menuModificacionMovimientos();
                opcion=getch();
                system("cls");
                switch(opcion)
                {
                case 97:
                    menuOpcionesTiposDeMovimientos(a.detalle);
                    break;
                case 98:
                    system("cls");
                    printf("\nIngrese el monto: ");
                    scanf("%f", &a.importe);
                    system("cls");
                    break;
                case 99:
                    system("cls");
                    verificacionFecha(&a.anio, &a.mes, &a.dia);
                    system("cls");
                    break;
                case 100:
                    printf("\nIngrese el ID cuenta:  ");
                    scanf("%d", &a.idCuenta);
                    system("cls");
                    break;
                default:
                    printf("\nIngreso un dato erroneo, vuelva a intentarlo.\n");
                }
                muestraUnMovimiento(a);
                printf("(Si desea terminar la modificacion del movimiento oprima ESC.)\n");
                printf("(Caso contrario oprima cualquier otra tecla.)\n");
                fflush(stdin);
                opcion=getch();
                system("cls");
            }
            while(opcion!=ESC);
            printf("Se modificio correctamente el movimiento.\n");
            Sleep(2000);
        }
        else
        {
            printf("Este movimiento no se modificara.\n");
            Sleep(2000);
        }
        fclose(archi);
    }
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra un menu con las opciones de modificacion de un movimiento.
 *
 * \param
 * \param
 * \return
 *
 */
void menuModificacionMovimientos()
{
    printf("\n__________________________________");
    printf("\n(Seleccione la opcion a modificar)");
    printf("\nA) Cambiar referencia.");
    printf("\nB) Cambiar importe.");
    printf("\nC) Cambiar fecha.");
    printf("\nD) Cambiar ID cuenta.");
    printf("\n__________________________________");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra un menu con los tipos
 * de detalles de un movimiennto, recibe solo un string como parametro en el cual se guardara el nuevo detalle del movimiento.
 * \param
 * \param
 * \return
 *
 */
void menuOpcionesTiposDeMovimientos (char a [])
{
    int flag;
    char opcion;
    char opcion1;
    do
    {
        menuMuestraMoviemientos();
        fflush(stdin);
        opcion=getch();
        switch (opcion)
        {
        case 97:
            strcpy(a, "Servicio de Luz");
            flag=0;
            break;
        case 98:
            strcpy(a, "Servicio de gas");
            flag=0;
            break;
        case 99:
            strcpy(a, "Obra social");
            flag=0;
            break;
        case 100:
            strcpy(a, "Patente");
            flag=0;
            break;
        case 101:
            strcpy(a, "Seguro");
            flag=0;
            break;
        case 102:
            strcpy(a, "Tarjeta de credito");
            flag=0;
            break;
        case 103:
            strcpy(a, "Transferencia");
            flag=0;
            break;
        case 104:
            strcpy(a, "Transferencia a cuenta de terceros");
            flag=0;
            break;
        default:
            printf("Vuelva a intentar por favor.\n");
            flag=-1;
            Sleep(1000);
            system("cls");
            break;
        }
        if (flag==0)
        {
            printf("Si desea confirmar su seleccion: %s \n(OPRIMA ENTER)\n", a);
            fflush(stdin);
            opcion1=getch();
            system("cls");
        }
    }
    while (opcion1!=ENTER);
    system("cls");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion recibe el id de cuenta para poder ubicar los movimientos a imprimir y a su vez el nombre
del archivo que contiene los movimientos
 *
 * \param
 * \param
 * \return 0 si no tiene movimientos y != 0 si tiene movimientos
 *
 */
int muestraMovimientosDeUnaCuenta (int id, char nombre [])
{   int aux=0;
    stMovimiento a;
    FILE * archi =fopen(nombre,"rb");
    if (archi)
    {
        while (fread(&a, sizeof(stMovimiento),1,archi)>0)
        {
            if (a.idCuenta==id && a.eliminado!=1)
            {
                muestraUnMovimiento(a);
                aux++;
            }
        }
        fclose(archi);
    }
    return aux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion imprime los movimientos por la fecha solicitada
 *
 * \param Nombre del archivo el anio, el mes y la fecha
 * \param
 * \return
 *
 */

void consultaMovimientosPorFecha(char nombre[], int anio, int mes, int dia){

    stMovimiento a;
    FILE *archi = fopen(nombre, "rb");
    if(archi){

        while(fread(&a, sizeof(stMovimiento), 1, archi) > 0){
            if(a.anio == anio && a.mes == mes && a.dia == dia){
                muestraUnMovimiento(a);
            }
        }

        fclose(archi);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra un cliente con su id y el nombre del archivo recibido por parametro.
 *
 * \param
 * \param
 * \return
 *
 */

void muestraClientePorId (char nombre [], int id) {
    stCliente a;
    int flag = 0;
    FILE * archi = fopen(nombre, "rb");
    if (archi) {
        while (fread(&a, sizeof (stCliente),1, archi)>0 && flag == 0) {
            if(a.id == id){
                muestraUnCliente(a);
                flag = 1;
            }
        }
    }
    fclose(archi);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Solicita el dia mes y anio del movimiento y verifica que sean validos
 *
 * \param
 * \param
 * \return
 *
 */


void verificacionFecha (int * anio1, int * mes1,int * dia1){
time_t now;
time(&now);
struct tm *local = localtime(&now);
int anio;
int mes;
int dia;
                    do
                    {
                        printf("\nIngrese el anio(2005-2023):  ");
                        scanf("%d", &anio);
                        system("cls");
                    }
                    while (anio<2005 || anio>2023);
                    *anio1=anio;
                    if (anio==2023)
                    {
                        do
                        {
                            printf("\nIngrese el mes(1-%d):  ", local->tm_mon+1);
                            scanf("%d", &mes);
                            system("cls");
                        }
                        while (mes<0 || mes>(local->tm_mon+1));
                        *mes1=mes;
                    }
                    else
                    {
                        do
                        {
                            printf("\nIngrese el mes(1-12):  ");
                            scanf("%d",&mes);
                            system("cls");
                        }
                        while (mes<0 || mes>12);
                        *mes1=mes;
                    }
                    if (mes==local->tm_mon+1)
                    {
                        do
                        {
                            printf("\n Ingrese el dia(1-%d): ", local->tm_mday);
                            scanf("%d", &dia);
                            system("cls");
                        }
                        while (dia<0 || dia>local->tm_mday);
                        *dia1=dia;
                    }
                    else if (mes== 4 || mes== 6 || mes== 9 || mes== 11 )
                    {
                        do
                        {
                            printf("\n Ingrese el dia(1-30): ");
                            scanf("%d", &dia);
                            system("cls");
                        }
                        while (dia<0 || dia>30);
                        *dia1=dia;
                    }

                    else if(mes==2)
                    {
                        do
                        {
                            printf("\n Ingrese el dia(1-28): ");
                            scanf("%d", &dia);
                            system("cls");
                        }
                        while (dia<0 || dia>28);
                        *dia1=dia;
                    }

                    else
                    {
                        do
                        {
                            printf("\n Ingrese el dia(1-31): ");
                            scanf("%d", &dia);
                            system("cls");
                        }
                        while (dia<0 || dia>31);
                        *dia1=dia;
                    }
}
