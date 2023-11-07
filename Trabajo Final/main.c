#include <stdio.h>
#include <stdlib.h>
#include "Cuenta.h"
#include "Movimientos.h"
#include "Utileria.h"
#include "string.h"
#include "cliente.h"
#include "time.h"
#include "conio.h"
#include "windows.h"
#define USUARIO "admin"
#define CONTRASENA "admin"

#define ESC 27
int main()
{
    srand(time(NULL));
    //system("color F0");
    int idcuentas [3];
    int val;
    int aux;
    int aux1;
    char DNI [10];
    int idCuenta;
    int idCliente;
    int nroCuenta;
    int idMovimiento;
    int anio;
    int mes;
    int dia;
    char opcion;
    char opcionAdmin;
    char opcionL[2];
    char us[30];
    char pass[30];
    int adminValido;
    char listaClientes [20]= {"Clientes"};
    char listaCuentas [20]= {"Cuentas"};
    char listaMovimientos [20]= {"Movimientos"};
    char listaClientesPorDato[] = "ClientesPorDato";
    ///cargaArchivoClientes(listaClientes);
    ///cargaArchivoCuentas(listaCuentas);
    ///aux=ultimoIdArchivoCuentas(listaCuentas);
    ///cargaArchivoMovimientos(listaMovimientos, aux);
    /// pantallaDeInicio();

    do
    {
        menuPrincipal();
        opcion=getch();
        switch(opcion)
        {
        case 49:
            do
            {
                setDNICliente(DNI);
                aux=idCliente=posicionClienteEnArchivoPorDNI1(listaClientes, DNI);
                if (aux==-1)
                {
                    printf("Su cliente esta eliminado o no existe.\n");
                    system("pause");
                    system("cls");
                }
            }
            while (aux==-1);
            system("cls");
            do
            {
                system("cls");
                menuIngresoCliente();
                opcion=getch();
                switch (opcion)
                {
                case 49:
                    muestraClientePorId(listaClientes, idCliente);
                    system("pause");
                    system("cls");
                    break;
                case 50:
                    val=buscarCuentasActivasDeClientes(idcuentas, idCliente, listaCuentas);
                    if (val!=0)
                    {
                        aux = muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                        fflush(stdin);
                        if (aux!=0)
                        {
                            printf("Desea operar sobre alguna cuenta: si / no\n");
                            gets(opcionL);
                        }
                        else
                        {
                            printf("Usted no posee cuentas activas.\n");
                        }
                        system("cls");
                        if (strcmp(opcionL,"si")==0)
                        {
                            do
                            {
                                menuCuentas();
                                opcion=getch();
                                switch(opcion)
                                {
                                case 49:
                                    muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                                    printf("Ingrese el numero de cuenta : \n");
                                    scanf("%d", &nroCuenta);
                                    aux= buscaIDCunetaPorNroCuenta(nroCuenta, listaCuentas);
                                    system("cls");
                                    do
                                    {
                                        menuMasOperacionesCuentas();
                                        fflush(stdin);
                                        opcion=getch();
                                        system("cls");
                                        switch(opcion)
                                        {
                                        case 49:
                                            cargaUnMovimiento(aux, listaMovimientos);
                                            break;
                                        case 50:
                                            system("cls");
                                            aux1=muestraMovimientosDeUnaCuenta(aux, listaMovimientos);
                                            system("pause");
                                            system("cls");
                                            break;
                                        case 51:
                                            bajaUnaCuenta(listaCuentas, listaMovimientos, nroCuenta);
                                            printf("Su cuenta se elimino correctamente.\n");
                                            system("pause");
                                            system("cls");
                                            break;
                                        default:
                                            if (opcion!=ESC)
                                            {
                                                printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                                                system("pause");
                                                system("cls");
                                            }
                                        }
                                    }
                                    while (opcion!=ESC);
                                    opcion=49;
                                    break;
                                default:
                                    if (opcion!=ESC)
                                    {
                                        printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                                        system("pause");
                                        system("cls");
                                    }
                                }
                            }
                            while (opcion!=ESC);
                            opcion= 50;
                        }
                        else
                        {
                            printf("No se modificara ninguna cuenta.\n");
                            system("pause");
                            system("cls");
                        }
                    }
                    else
                    {
                        printf("No posee cuentas, por favor abra una.\n");
                        system("pause");
                        system("cls");
                    }
                    system("cls");
                    break;
                case 51:
                    cargaUnaCuenta(listaCuentas,idCliente, opcion);
                    break;
                case 52:
                    printf("\nIngrese el DNI a modificar: ");
                    fflush(stdin);
                    gets(DNI);
                    system("cls");

                    aux = posicionClienteEnArchivoPorDNI1(listaClientes, DNI);
                    if(aux != -1)
                    {
                        muestraClientePorId(listaClientes, aux);
                        menuModificarCliente();
                        modificarClienteArchivoPorDNI(listaClientes, DNI);
                        system("cls");
                        printf("\nDatos finales cliente...\n");
                        muestraClientePorId(listaClientes, aux);

                    }
                    else
                    {
                        printf("\nEl DNI no existe...");
                    }

                    system("pause");
                    break;
                case 53:
                    bajaClientePorId(listaClientes, listaCuentas, listaMovimientos, idCliente);
                    opcion=27;
                    printf("Su usuario se dio de baja.\n");
                    system("pause");
                    system("cls");
                    break;
                default:
                    if (opcion!=ESC)
                    {
                        printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                        system("pause");
                        system("cls");
                    }
                }
            }
            while (opcion!=ESC);
            opcion= 49;
            system("cls");
            break;
        case 50:
            cargaUnCliente(listaClientes);
            system("pause");
            system("cls");
            break;
        //////////////////////////////////////////////////////// ADMINISTRADOR ///////////////////////////////////////////////////////////////////////
        case 51:
            do
            {
                adminValido = 0;
                system("cls");
                printf("\t\t\t\t---------------(ADMINISTRADOR)----------------\n\n");
                printf("\t\t\t\tSe solicitara usuario y contrasenia. Desea continuar? si / no : ");
                fflush(stdin);
                gets(opcionL);

                if(strcmp(opcionL, "si") == 0)
                {
                    printf("\t\t\t\tUsuario: ");
                    fflush(stdin);
                    gets(us);
                    printf("\t\t\t\tContrasenia: ");
                    fflush(stdin);
                    gets(pass);

                    if(strcmp(us, USUARIO) == 0 && strcmp(pass, CONTRASENA) == 0)
                    {
                        adminValido = 1;
                    }
                    else
                    {
                        printf("\nUsuario o contrasena invalidos...\n");
                        printf("\nDesea volver a cargar? si / no: ");
                        fflush(stdin);
                        gets(opcionL);
                    }
                }

            }
            while(adminValido == 0 && strcmp(opcionL, "no") != 0);
            if(adminValido == 0 && strcmp(opcionL, "no") == 0)
            {
                system("cls");
                break;
            }
            else
            {
                do
                {

                    system("cls");
                    menuPrincipalAdministrador();
                    fflush(stdin);
                    opcionAdmin = getch();
                    switch(opcionAdmin)
                    {
                    case 49:
                        printf("\nDesea cargar un cliente? si / no : ");
                        fflush(stdin);
                        gets(opcionL);
                        if(strcmp(opcionL, "si") == 0)
                        {
                            if(cargaUnCliente(listaClientes) == 1)
                            {

                                FILE *archi = fopen(listaClientes, "rb");
                                if(archi)
                                {
                                    idCliente = ultimoIdArchivoClientes(archi);
                                    fclose(archi);
                                }
                                do
                                {
                                    if(cargaUnaCuenta(listaCuentas, idCliente, 1) == 1)
                                    {
                                        idCuenta = ultimoIdArchivoCuentas(listaCuentas);
                                        do
                                        {
                                            printf("\nDesea cargar un movimiento? si / no : ");
                                            fflush(stdin);
                                            gets(opcionL);
                                            if(strcmp(opcionL, "si") == 0)
                                            {
                                                cargaUnMovimiento(idCuenta, listaMovimientos);
                                            }

                                        }
                                        while(strcmp(opcionL, "si") == 0);
                                    }

                                    printf("\nDesea cargar otra cuenta? si / no : ");
                                    fflush(stdin);
                                    gets(opcionL);

                                }
                                while(strcmp(opcionL, "si") == 0);

                            }
                        }
                        break;
                    case 50:
                        do
                        {
                            system("cls");
                            menuListarOmodificarCliente();
                            fflush(stdin);
                            opcionAdmin = getch();

                            switch(opcionAdmin)
                            {
                            case 49:
                                muestraArchivoClientes(listaClientes);
                                printf("\n");
                                system("pause");
                                break;
                            case 50:
                                muestraArchivoCuentas(listaCuentas);
                                printf("\n");
                                system("pause");
                                break;
                            case 51:
                                muestraArchivoMovimientos(listaMovimientos);
                                printf("\n");
                                system("pause");
                                break;
                            case 52:
                                printf("\nIgrese la fecha a buscar los movimientos:");
                                verificacionFecha(&anio, &mes, &dia);
                                consultaMovimientosPorFecha(listaMovimientos,anio, mes, dia);
                                system("pause");
                                break;
                            case 53:
                                do
                                {
                                    system("cls");
                                    menuConsultaPorDato();
                                    fflush(stdin);
                                    opcionAdmin = getch();

                                    switch(opcionAdmin)
                                    {
                                    case 49:
                                        system("cls");
                                        consultaClientesArchivo(listaClientes,listaClientesPorDato);

                                        break;
                                    case 50:
                                        printf("\nIngrese el DNI a modificar: ");
                                        fflush(stdin);
                                        gets(DNI);
                                        system("cls");

                                        aux = posicionClienteEnArchivoPorDNI1(listaClientes, DNI);
                                        if(aux != -1)
                                        {
                                            muestraClientePorId(listaClientes, aux);
                                            menuModificarCliente();
                                            modificarClienteArchivoPorDNI(listaClientes, DNI);
                                            system("cls");
                                            printf("\nDatos finales cliente...\n");
                                            muestraClientePorId(listaClientes, aux);
                                        }
                                        else
                                        {
                                            printf("\nEl DNI no existe...");
                                        }

                                        system("pause");
                                        break;
                                    case 51:
                                        ////CARGA UNA CUENTA////
                                        printf("\nIngrese el DNI del cliente a cargar una cuenta: ");
                                        fflush(stdin);
                                        gets(DNI);
                                        system("cls");

                                        aux = posicionClienteEnArchivoPorDNI1(listaClientes, DNI);

                                        if(aux != -1)
                                        {
                                            muestraClientePorId(listaClientes, aux);
                                            printf("\n");
                                            idCliente = buscarClienteEnArchivoPorPosicion1(listaClientes, aux).id;


                                            if(cargaUnaCuenta(listaCuentas, idCliente, 1) == 1)
                                            {
                                                idCuenta = ultimoIdArchivoCuentas(listaCuentas);
                                                do
                                                {
                                                    printf("\nDesea cargar un movimiento? si / no : ");
                                                    fflush(stdin);
                                                    gets(opcionL);
                                                    if(strcmp(opcionL, "si") == 0)
                                                    {
                                                        cargaUnMovimiento(idCuenta, listaMovimientos);
                                                    }
                                                }
                                                while(strcmp(opcionL, "si") == 0);
                                            }
                                        }

                                        break;
                                    case 52:

                                        printf("\nIngrese el DNI del cliente para trabajar en la administracion de cuentas: ");
                                        fflush(stdin);
                                        gets(DNI);
                                        idCliente = posicionClienteEnArchivoPorDNI1(listaClientes, DNI);

                                        if(idCliente != -1)
                                        {

                                            do
                                            {
                                                system("cls");
                                                muestraClientePorId(listaClientes, idCliente);
                                                menuCuentasCliente();
                                                fflush(stdin);
                                                opcionAdmin = getch();
                                                val=buscarCuentasActivasDeClientes(idcuentas, idCliente, listaCuentas);
                                                switch(opcionAdmin)
                                                {
                                                case 49:
                                                    if (val!=0)
                                                    {
                                                        aux = muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                                                    }
                                                    else
                                                    {
                                                        printf("\nEl cliente no posee cuentas...\n");
                                                    }

                                                    system("pause");
                                                    break;
                                                case 50:
                                                    system("cls");
                                                    modificarArchivoCuenta(listaCuentas, idCliente);
                                                    system("pause");
                                                    break;
                                                case 51:
                                                    val=buscarCuentasActivasDeClientes(idcuentas, idCliente, listaCuentas);
                                                    if(val != 0)
                                                    {
                                                        aux = muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                                                        if(aux != 0)
                                                        {
                                                            printf("\nIngrese el numero de cuenta a dar de baja: ");
                                                            fflush(stdin);
                                                            scanf("%d", &nroCuenta);
                                                            bajaUnaCuenta(listaCuentas, listaMovimientos, nroCuenta);
                                                            printf("\nLa cuenta se dio de baja exitosamente...\n");
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\nEl cliente no posee cuentas...\n");
                                                    }

                                                    system("pause");
                                                    break;
                                                case 52:
                                                    system("cls");
                                                    muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                                                    printf("\nIngrese el id de cuenta en donde trabajar el movimiento: ");
                                                    fflush(stdin);
                                                    scanf("%d", &idCuenta);
                                                    do
                                                    {
                                                        system("cls");
                                                        menuMovimientosCuenta();
                                                        fflush(stdin);
                                                        opcion = getch();
                                                        switch(opcion)
                                                        {
                                                        case 49:
                                                            cargaUnMovimiento(idCuenta, listaMovimientos);
                                                            system("pause");
                                                            break;
                                                        case 50:
                                                            aux=muestraMovimientosDeUnaCuenta(idCuenta, listaMovimientos);
                                                            if (aux!=0)
                                                            {
                                                                printf("\nIngrese el id de movimiento a cambiar: ");
                                                                fflush(stdin);
                                                                scanf("%d", &idMovimiento);
                                                                modificarArchivoMovimiento(listaMovimientos, idMovimiento);
                                                            }
                                                            else
                                                            {
                                                                printf("Su cuenta no tiene movimientos. \n");
                                                            }
                                                            system("pause");
                                                            break;
                                                        case 51:
                                                            aux=muestraMovimientosDeUnaCuenta(idCuenta, listaMovimientos);

                                                            if (aux!=0)
                                                            {
                                                                printf("\nIngrese el id de movimiento a cambiar: ");
                                                                fflush(stdin);
                                                                scanf("%d", idMovimiento);
                                                                fflush(stdin);
                                                                bajaUnMovimiento(listaMovimientos, idMovimiento);
                                                            }
                                                            else
                                                            {
                                                                printf("Su cuenta no tiene movimientos. \n");
                                                            }
                                                            system("pause");
                                                            break;
                                                        case 27:
                                                            system("cls");
                                                            break;
                                                        default:
                                                            printf("\nIngreso un valor erroneo, vuelva a intentarlo.\n");
                                                        }
                                                    }
                                                    while(opcion!= ESC);
                                                    opcion=1;
                                                    break;
                                                case 53:
                                                    aux = muestraCuentasDeUnCliente(idcuentas, listaCuentas, val);
                                                    if(aux != 0)
                                                    {
                                                        printf("\nIngrese el id de la cuenta: ");
                                                        fflush(stdin);
                                                        scanf("%d", &nroCuenta);
                                                        idCuenta=buscaIDCunetaPorNroCuenta(nroCuenta, listaCuentas);
                                                        aux=muestraMovimientosDeUnaCuenta(idCuenta, listaMovimientos);
                                                    }
                                                    if(aux==0)
                                                    {
                                                        printf("No posee cuentas.\n");
                                                    }
                                                    system("pause");
                                                    break;
                                                case 27:
                                                    system("cls");
                                                    break;
                                                default:
                                                    printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                                                }

                                            }
                                            while(opcionAdmin != ESC);
                                        }
                                        else
                                        {
                                            printf("\nEl cliente no existe...\n");
                                        }
                                        opcionAdmin=52;
                                        break;
                                    case 53:
                                        ////////BAJA CLIENTE///////
                                        printf("\nIngrese el DNI del cliente a ser eliminado: ");
                                        fflush(stdin);
                                        gets(DNI);

                                        idCliente = posicionClienteEnArchivoPorDNI1(listaClientes, DNI);
                                        if(idCliente != -1)
                                        {
                                            muestraClientePorId(listaClientes, idCliente);
                                            printf("\nDesea continuar con la baja? si / no : ");
                                            fflush(stdin);
                                            scanf(opcionL);
                                            if(strcmp(opcionL, "si") == 0)
                                            {
                                                bajaClientePorId(listaClientes, listaCuentas, listaMovimientos, idCliente);
                                                printf("\nEl cliente se ha dado de baja con exito...");
                                            }

                                        }
                                        printf("\n");
                                        system("pause");
                                        break;
                                    case 27:
                                        system("cls");
                                        break;
                                    default:
                                        printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                                        system("pause");
                                        system("cls");
                                    }

                                }
                                while(opcionAdmin != ESC);
                                opcionAdmin=1;
                                break;
                            case 27:
                                system("cls");
                                break;
                            default:
                                printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                                system("pause");
                                system("cls");

                            }
                        }
                        while(opcionAdmin != ESC);
                        opcionAdmin=1;
                        break;
                    case 27:
                        system("cls");
                        break;
                    default:
                        printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                        system("pause");
                        system("cls");

                    }


                }
                while(opcionAdmin != ESC);
            }
            opcionAdmin=1;
            break;
        default:
            if (opcion!=ESC)
            {
                printf("Ingreso un valor erroneo, vuelva a intentarlo.\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Gracias por elegirnos.\n");
                system("pause");
                system("cls");
            }
        }
    }
    while (opcion!=ESC);

    return 0;
}
