#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include "Cuenta.h"
#include "time.h"
#include "string.h"
#include "Utileria.h"

#define ENTER 13
#define ESC 27
/** \brief Agrega una cuenta al FILE de cuentas recibiendo por parametro el nombre del FILE y el id de cliente.
 *
 * \param char nombre [] - archivo de cuentas
 * \param int idCliente - id de cliente
 * \param char tipoDeUsuario - = 1 (administrador) o != 1 (cliente)
 * \return 1 si cargó la cuenta, 0 si no la cargó
 *
 */
int cargaUnaCuenta (char nombre [], int idCliente, char tipoDeUsuario)

{
    int idCuentas [3];
    int val;
    int aux;
    int exito = 0;
    char confirmacion [2];
    stCuenta a;
    FILE * archi= fopen(nombre, "a+b");
    if (archi)
    {
        fseek(archi,-sizeof(stCuenta),2);
        fread(&a, sizeof(stCuenta),1,archi);
        val=buscarCuentasActivasDeClientes(idCuentas, idCliente, nombre);
        muestraCuentasDeUnCliente(idCuentas, nombre, val);
        if(val!=3)
        {
            printf("Confirme si desea abrir una nueva: si / no\n");
            fflush(stdin);
            gets(confirmacion);
            system("cls");
            if (strcmp(confirmacion, "si")==0)
            {
                a.eliminado=0;
                a.id++;
                a.nroCuenta++;
                a.idCliente=idCliente;
                char opcion;
                char opcion1;
                do
                {
                    do
                    {
                        printf("Seleccione el tipo de cuenta: \n");
                        printf("| 1) Caja de ahorro en pesos.  | \n| 2) Caja de ahorro en dolares.|\n| 3) Cuenta corriente en pesos.|\n");
                        opcion=getch();
                        switch (opcion)
                        {
                        case 49:
                            printf("Selecciono la caja de ahorro en pesos.\n");
                            aux=validarCuentasParaAlta(archi, 1, a.idCliente);
                            if (aux==1)
                            {
                                a.tipoDeCuenta=1;
                            }
                            else
                            {
                                printf("Ustede ya posee una cuenta de este tipo, vuelva a intentarlo.\n");
                                getch();
                                system("cls");
                                opcion=0;
                            }
                            break;
                        case 50:
                            printf("Selecciono la caja de ahorro en dolares.\n");
                            aux=validarCuentasParaAlta(archi, 2, a.idCliente);
                            if (aux==1)
                            {
                                a.tipoDeCuenta=2;
                            }
                            else
                            {
                                printf("Ustede ya posee una cuenta de este tipo, vuelva a intentarlo.\n");
                                opcion=0;
                                getch();
                                system("cls");
                            }
                            break;
                        case 51:
                            printf("Selecciono la cuenta corriente en pesos.\n");
                            aux=validarCuentasParaAlta(archi, 3, a.idCliente);
                            if (aux==1)
                            {
                                a.tipoDeCuenta=3;
                            }
                            else
                            {
                                printf("Ustede ya posee una cuenta de este tipo, vuelva a intentarlo.\n");
                                opcion=0;
                                getch();
                                system("cls");
                            }
                            break;
                        default:
                            printf("Ingreso un valor erroneo por favor vuelva a intentar lo.");
                            getch();
                            system("cls");
                            break;
                        }
                    }
                    while (opcion!=49 && opcion!=50 && opcion!=51);
                    switch (opcion)
                    {
                    case 49:
                        a.costoMensual =0.0;
                        break;
                    case 50:
                        a.costoMensual= 10.55;
                        break;
                    case 51:
                        a.costoMensual=505.33;
                        break;
                    }
                    if (tipoDeUsuario == 1)
                    {
                        printf("Ingrese el monto de su cuenta: ");
                        fflush(stdin);
                        scanf("%d", &a.monto);
                    }
                    else
                    {
                        a.monto=0;
                    }

                    muestraUnaCuenta(a);
                    printf("Si los datos estan bien cargados ENTER.\n");
                    printf("Caso contrario cualquier otra tecla.\n");
                    fflush(stdin);
                    opcion1=getch();
                    system("cls");
                }
                while (opcion1!=ENTER);
                fseek(archi, 0,2);
                fwrite(&a, sizeof(stCuenta),1,archi);
                exito = 1;
            }

            else
            {
                printf("Su confirmacion fue negativa por lo tanto no se agregara una cuenta.\n");
                Sleep(4000);
                system("cls");
            }

        }
        else
        {
            printf("Ya posee los 3 tipos de cuentas que nuestro banco ofrece, gracias por elegirnos.\n");
            getch();
            system("cls");

        }
        fclose(archi);
    }
    return exito;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra una cuenta recibiendo por parametro un dato de tipo stCuenta.
 *
 * \param
 * \param
 * \return void
 *
 */
void muestraUnaCuenta (stCuenta a)
{
    printf("--------------------------------CUENTA---------------------------------------\n");
    printf("_____________________________________________________________________________\n");
    printf("Id ...........................................: %d\n", a.id);
    printf("Id cliente....................................: %d\n", a.idCliente);
    printf("Numero de cuenta..............................: %d\n", a.nroCuenta);

    switch(a.tipoDeCuenta)
    {
    case 1:
        printf("Tipo de cuenta................................: Caja de ahorro en pesos\n");
        printf("Coste mensual de mantenimiento de la cuenta...: $ %.2f\n", a.costoMensual);
        break;
    case 2:
        printf("Tipo de cuenta................................: Caja de ahorro en dolares\n");
        printf("Coste mensual de mantenimiento de la cuenta...: u$s %.2f\n", a.costoMensual);
        break;
    case 3:
        printf("Tipo de cuenta................................: Cuenta corriente en pesos\n");
        printf("Coste mensual de mantenimiento de la cuenta...: $ %.2f\n", a.costoMensual);
        break;
    }
    if (a.tipoDeCuenta==2)
    {
        printf("Saldo disponible..............................: u$s %d \n", a.monto );
    }
    else
    {
        printf("Saldo disponible..............................: $ %d \n", a.monto );
    }
    printf("_____________________________________________________________________________\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Carga una cuenta de forma aleatoria recibiendo por parametro el ID de cliente
 * y el tipo de cuenta (1 caja de ahorro en pesos; 2 caja de ahorro en dolares; 3 cuenta corriente), retorna un dato de tipo stCuenta.
 * \param
 * \param
 * \return estructura stCuenta
 *
 */
stCuenta cargaUnaCuentaAleatoriamente (int idCliente, int tipoCuenta)
{
    stCuenta cuenta;
    static int nnrcuenta =10000;
    static int staticid=-1;
    staticid++;
    nnrcuenta++;
    cuenta.id=staticid;
    cuenta.idCliente=idCliente;
    cuenta.tipoDeCuenta=tipoCuenta;
    cuenta.nroCuenta = nnrcuenta;
    cuenta.eliminado = 0;
    switch(tipoCuenta)
    {
    case 1:
        cuenta.monto= mayorMenor(1000000,300000);
        cuenta.costoMensual =0.0;
        break;
    case 2:
        cuenta.monto=mayorMenor(20000,500);
        cuenta.costoMensual= 10.55;
        break;
    case 3:
        cuenta.monto=mayorMenor(1000000,900000);
        cuenta.costoMensual=505.33;
        break;
    }
    return cuenta;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Pasa por todos los clientes pero carga de forma random las cuentas en ellos maximo una de cada tipo, al archivo de cuentas,
*como parametro recibe el nombre del FILE cuentas.
 *
 * \param
 * \param
 * \return void
 *
 */

void cargaArchivoCuentas (char nombre [])
{
    int id=-1;
    stCuenta a;
    FILE *archi = fopen(nombre, "wb");
    if(archi)
    {
        for(int i=0; i<150; i++)
        {
            for(int j=1; j<mayorMenor(5,1); j++)
            {
                a = cargaUnaCuentaAleatoriamente(0+i,j);
                fwrite(&a, sizeof(stCuenta),1, archi);
            }
        }
        fclose(archi);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra todas las cuentas (exceptuando las eliminadas), del archicbo de cuentas, recibe por parametro el nombre del FILE cuentas.
 *
 * \param
 * \param
 * \return
 *
 */
void muestraArchivoCuentas(char nombre [])
{
    stCuenta a;
    FILE * archi= fopen(nombre, "rb");
    if (archi)
    {
        while (fread(&a, sizeof(stCuenta), 1, archi)>0)
        {
            if (a.eliminado==0)
            {
                muestraUnaCuenta(a);
            }
        }
        fclose(archi);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca las cuentas relacionadas a un id de un cliente,
 *devuelve un arreglo con los id de las cuentas en el y los validos.
 *
 * \param cuentas, idCliente
 * \param
 * \return Arreglo de id de cuentas y validos
 *
 */

int buscarCuentasActivasDeClientes (int idCuentas [], int idCliente, char nombre[])
{
    int i=0;
    stCuenta a;
    FILE * archi = fopen(nombre, "rb");
    if (archi)
    {
        rewind(archi);
        while (fread(&a, sizeof(stCuenta),1,archi)>0)
        {
            if (a.idCliente==idCliente && a.eliminado!=1)
            {
                idCuentas [i]= a.id;
                i++;
            }
        }
        fclose(archi);
    }
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra las cuentas y devuelve la cantidad de cuentas del cliente
 *
 * \param
 * \param
 * \return
 *
 */

int muestraCuentasDeUnCliente (int idCuentas [],char nombre [], int val)
{
    stCuenta a;
    int i=0;
    if (val!=0)
    {
        FILE * archi = fopen(nombre, "rb");
        if (archi)
        {

            while ((i<val) && (fread(&a, sizeof(stCuenta),1,archi)>0))
            {
                if(a.id==idCuentas[i] && a.eliminado!=1)
                {
                    if (i==0)
                    {
                        printf("_____________________________________________________________________________\n");
                        printf("____________________|Usted posee las siguientes cuentas|_____________________\n");
                        printf("_____________________________________________________________________________\n");
                    }
                    muestraUnaCuenta(a);
                    i++;
                }
            }
            fclose(archi);
        }
    }
    else
    {
        printf("-----------------------------\n");
        printf("No posee cuenta el cliente. \n");
        printf("-----------------------------\n");
        system("pause");
    }
    return i;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion valida con 1 como verdadero y 0 como falso la validez de dar de un alta una nueva cuenta de un tipo en especifico.
 *
 * \param puntero del buffer que tiene abierto el archivo
 * \param Tipo de cuenta y el ID del cliente
 * \return
 *
 */
int validarCuentasParaAlta (FILE * archi, int tipoDeCuenta, int idCliente)
{
    int aux=1;
    stCuenta a;
    if (archi)
    {
        rewind(archi);
        while  ((aux==1) && (fread(&a, sizeof(stCuenta),1,archi)>0))
        {
            if((a.idCliente==idCliente) && (a.tipoDeCuenta==tipoDeCuenta))
            {
                aux--;
            }
        }
    }
    return aux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion da de baja una cuenta del archivo de cuentas, recibe por parametro el nombre del archivo y el ID del cliente.
 *
 * \param
 * \param
 * \return
 *
 */
void bajaUnaCuenta (char nombre [], char nombreMovimientos[], int numeroDeCuenta)
{
    stCuenta a;
    FILE * archi = fopen(nombre, "r+b");
    if (archi)
    {
        while(numeroDeCuenta!=a.nroCuenta && fread(&a, sizeof(stCuenta), 1, archi)>0)
        {
        }
        fseek(archi, (-1)*sizeof(stCuenta), SEEK_CUR);
        a.eliminado=1;
        fwrite(&a, sizeof(stCuenta), 1, archi);
        fclose(archi);
    }
    bajaMovimientosDeUnaCuenta(nombreMovimientos, a.id);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion ofrece modificar una cuenta de las que poseea un cliente, una vez modificada la sube al archivo, recibe por parametro el nombre del archivo y el ID del cliente.
 *
 * \param
 * \param
 * \return
 *
 */

void modificarArchivoCuenta(char nombre[], int idCliente)
{
    stCuenta a;
    int idCuentas [3];
    int val;
    int aux=0;
    int ID=0;
    char opcion1 [2];
    char opcion;

    FILE * archi = fopen(nombre, "r+b");
    if(archi)
    {
        val=buscarCuentasActivasDeClientes(idCuentas, idCliente, nombre);
        muestraCuentasDeUnCliente(idCuentas, nombre, val);
        printf("Ingrese el Nro. de cuenta que desea modificar?\n");
        fflush(stdin);
        scanf("%d", &aux);
        rewind(archi);
        while (a.nroCuenta!=aux)
        {
            fread(&a, sizeof (stCuenta),1,archi);
        }
        system("cls");
        fflush(stdin);
        muestraUnaCuenta(a);
        printf("Confirme si desea modificar este movimiento: si / no.\n");
        gets(opcion1);
        ID=a.id;
        system("cls");
        if (strcmp(opcion1, "si")==0)
        {
            do
            {
                menuModificacionCuenta();
                opcion=getch();
                system("cls");
                switch(opcion)
                {
                case 97:
                    printf("Ingrese el nuevo ID de cliente: \n");
                    scanf("%d", &a.idCliente);
                    break;
                case 98:
                    do
                    {
                        printf("Ingrese el nuevo Nro. de cuenta: \n");
                        scanf("%d", &a.nroCuenta);
                        aux=validarNumeroCuenta(archi, a.nroCuenta);
                        system("cls");
                    }
                    while (aux!=1);
                    break;
                case 99:
                    do
                    {
                        printf("Ingrese el nuevo tipo de cuenta: \n 1) Caja de ahorro en pesos. \n 2) Caja de ahorro en dolares. \n 3) Cuenta corriente en pesos.\n");
                        scanf("%d", &a.tipoDeCuenta);
                        system("cls");
                    }
                    while (a.tipoDeCuenta!=1 && a.tipoDeCuenta!=2 && a.tipoDeCuenta!=3);
                    break;
                case 100:
                    printf("Ingrese el nuevo saldo: \n");
                    scanf("%d", &a.monto);
                    break;
                default:
                    printf("Ingreso un valor erroneo por favor vuelva intentar lo.\n");
                    system("pause");
                    system("cls");
                }
                muestraUnaCuenta(a);
                printf("(Si desea terminar la modificacion de la cuenta oprima ESC.)\n");
                printf("(Caso contrario oprima cualquier otra tecla.)\n");
                fflush(stdin);
                opcion=getch();
                system("cls");
            }
            while (opcion!=ESC);
            fseek(archi,((ID-1)*sizeof(stCuenta)),0);
            fwrite(&a, sizeof(stCuenta),1,archi);
            printf("Se modificio correctamente la cuenta.\n");
            Sleep(2000);
        }
        else
        {
            printf("Esta cuenta no se modificara.\n");
            Sleep(2000);
        }
        fclose(archi);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuModificacionCuenta()
{
    printf("__________________________________\n");
    printf("(Seleccione la opcion a modificar)\n");
    printf("A) Cambiar ID cliente.\n");
    printf("B) Cambiar Nro de cuenta\n");
    printf("C) Tipo de cuenta.\n");
    printf("D) Saldo disponible.\n");
    printf("__________________________________\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion valida que el numero de cuenta a modificar no este repetido en el archivo de cuentas, recibe por parametro el puntero al buffer y el numero que se esta validando.
 *
 * \param
 * \param
 * \return 1 es valido cargar ese numero y 0 ya se encuentra en el archivo.
 *
 */
int validarNumeroCuenta (FILE * archi, int nro)
{
    int aux=1;
    stCuenta a;
    if (archi)
    {
        rewind(archi);
        while ((aux!=0) && (fread(&a,sizeof(stCuenta),1,archi)>0))
        {
            if (a.nroCuenta==nro)
            {
                aux=0;
            }
        }
    }
    return aux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Esta funcion busca el id de cuenta atraves del nru de cuenta.
 *
 * \param Nro. de cuenta y el nombre del archivo cuentas
 * \param
 * \return -1 no existe cuenta con ese numero, retorna el id de la cuenta caso contrario.
 *
 */
int buscaIDCunetaPorNroCuenta (int num, char nombre [])
{
    int aux=-1;
    stCuenta a;
    FILE * archi = fopen(nombre, "rb");
    if (archi)
    {
        while ((aux==-1) && (fread(&a, sizeof (stCuenta),1,archi)>0))
        {
            if (a.nroCuenta==num)
            {
                aux=a.id;
            }
        }
        fclose(archi);
    }
    return aux;
}
/** \brief Esta funcion recibe el nombre del archivo de cuentas y devuelve el ultimo id
 *
 * \param
 * \param
 * \return
 *
 */

int ultimoIdArchivoCuentas (char nombre [])
{
    int aux;
    FILE * archi = fopen(nombre,"rb");
    if (archi)
    {
        fseek(archi,0,2);
        aux= (ftell(archi)/sizeof(stCuenta));
        fclose(archi);
    }
    return aux;
}
