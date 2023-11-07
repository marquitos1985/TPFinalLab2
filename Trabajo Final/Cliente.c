#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "Cuenta.h"
#include "Movimientos.h"
#include "windows.h"
#include "Utileria.h"
#define ESC 27

/** \brief Carga los datos de un cliente, verificando que no exista en el archivo
 *
 * \param char nombreArchivo[] - cadena con el nombre del archivo de clientes
 * \param
 * \return 1 si la carga fue existosa, 0 si no pudo ser realizada (por no existir el DNI en el archivo o no poder abrir el mismo)
 *
 */

int cargaUnCliente(char nombreArchivo[]) {

    stCliente cliente;
    int opcion;
    int ultimoId;
    int exito = 0;

    FILE *archi = fopen(nombreArchivo, "r+b");

    if(archi) {
        setDNICliente(cliente.dni);

        if(posicionClienteEnArchivoPorDNI(archi, cliente.dni) == -1) {

            ultimoId = ultimoIdArchivoClientes(archi);
            ultimoId = ultimoId + 1;

            cliente.id = ultimoId;
            cliente.nroCliente = 1000+cliente.id;
            setNombreCliente(cliente.nombre);
            setApellidoCliente(cliente.apellido);
            setEmailCliente(cliente.email);
            setDomicilioCliente(cliente.domicilio);
            setTelefonoCliente(cliente.telefono);
            cliente.eliminado = 0;

            printf("\nDesea completar la carga con los datos anteriores? ESC para cancelar, cualquier tecla para confirmar: \n");
            fflush(stdin);
            opcion = getch();

            if(opcion != ESC) {
                fwrite(&cliente, sizeof(stCliente), 1, archi);
                exito = 1;
            }

        } else {
            printf("\nEl DNI ya existe en el archivo...\n");
            system("pause");
        }
        fclose(archi);

    } else {
        printf("\nNo se pudo abrir el archivo");
    }
    return exito;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Devuelve el ultimo id cargado en el archivo de clientes (sin importar si está ordenado o no)
 *
 * \param FILE * archi - puntero archivo de clientes
 * \param
 * \return -1 si no hay datos, sino el valor del id mayor que hay en el archivo
 *
 */

int ultimoIdArchivoClientes(FILE * archi) {
    stCliente cliente;
    int id = -1;
    if(archi) {
        fseek(archi, 0, SEEK_SET);

        while(fread(&cliente, sizeof(stCliente), 1, archi) > 0) {
            if(cliente.id > id) {
                id = cliente.id;
            }
        }
    }
    return id;
}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void muestraUnCliente(stCliente a) {
    printf("--------------------------------CLIENTE--------------------------------------\n");
    printf("_____________________________________________________________________________\n");
    printf("Nro de cliente................................: %d\n",a.nroCliente);
    printf("Nombre........................................: %s\n", a.nombre);
    printf("Apellido......................................: %s\n", a.apellido);
    printf("DNI...........................................: %s\n", a.dni);
    printf("Domicilio.....................................: %s\n", a.domicilio);
    printf("Telefono......................................: %s\n",a.telefono);
    printf("Email.........................................: %s\n", a.email);
    if(a.eliminado == 0) {
        printf("Estado de cliente.............................: ACTIVO\n");
    } else {
        printf("Estado de cliente......................: INACTIVO\n");
    }
    printf("_____________________________________________________________________________\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
stCliente cargaUnClienteAleatoriamente () {
    stCliente a;
    static int staticid=-1;
    staticid++;
    a.id=staticid;
    a.nroCliente= 1000+a.id;
    carga_aleatoria_arreglo_nombres(a.nombre);
    carga_aleatoria_arreglo_apellidos(a.apellido);
    carga_aleatoria_arreglo_documentos(a.dni);
    carga_aleatoria_arreglo_email(a.email);
    carga_aleatoria_arreglo_dirreciones(a.domicilio);
    carga_aleatoria_arreglo_telefonos(a.telefono);
    a.eliminado = 0;//agregué esto porque sino no los mostraba con la funcion muestraArchivoClientes
    return a;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Genera el archivo de clientes con cuentas aleatorias(datos aleatorios)
 *
 * \param char nombre [] - cadena con el nombre del archivo de clientes
 * \param
 * \return void
 *
 */

void cargaArchivoClientes (char nombre []) {
    stCliente a;
    FILE * archi = fopen(nombre, "wb");
    if (archi!=NULL) {
        for (int i =0 ; i<150 ; i++) {
            a=cargaUnClienteAleatoriamente();
            fwrite(&a, sizeof (stCliente), 1, archi);
        }
    }
    fclose(archi);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Muestra los clientes ACTIVOS del archivo
 *
 * \param char nombre[] - string que contiene el nombre del archivo a leer
 * \param
 * \return void
 *
 */

void muestraArchivoClientes (char nombre []) {
    stCliente a;
    FILE * archi = fopen(nombre, "rb");
    if (archi!=NULL) {
        while (fread(&a, sizeof (stCliente),1, archi)>0) {
            if (a.eliminado==0) {
                muestraUnCliente(a);
            }
        }
    } else {
        printf("\nNo se pudo leer el archivo.");
    }
    fclose(archi);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** \brief Setea eliminado = 1 y lo guarda en el archivo clientes
 *
 * \param FILE *archi - puntero al archivo de clientes
 * \param char dni[] - cadena del DNI a eliminar
 * \return void
 *
 */

void setEliminadoArchivoPorDNI(FILE *archi, char dni[]) {

    stCliente cliente;
    int posicion;

    if(archi) {
        fseek(archi, 0, SEEK_SET);
        posicion = posicionClienteEnArchivoPorDNI(archi, dni);
        fseek(archi, posicion*sizeof(stCliente), SEEK_SET);
        fread(&cliente, sizeof(stCliente), 1, archi);
        cliente.eliminado = 1;
        fseek(archi, -1*sizeof(stCliente), SEEK_CUR);
        fwrite(&cliente, sizeof(stCliente), 1, archi);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca un cliente en el archivo de clientes por DNI y devuelve la posicion en el archivo, si el cliente está activo(siendo 0 la primer posicion)
 * \param FILE *archi - puntero al archivo de clientes
 * \param  char dni[] - DNI a buscar la posicion en el archivo
 * \return -1 si no existe la posicion del cliente,
 * o la posicion en el archivo. Siendo la 1er posicion la nro 0
 *
 */

int posicionClienteEnArchivoPorDNI (FILE *archi,char dni[]) {
    stCliente cliente;
    int posicion = -1;//si el archivo esta vacio o no encuentra el cliente devuelve-1
    if (archi) {
        fseek(archi, 0, SEEK_SET);
        while(fread(&cliente,sizeof(stCliente),1,archi) > 0 && posicion == -1) {
            if(cliente.eliminado != 1 && strcmp(cliente.dni, dni) == 0) {
                posicion = (ftell(archi)/ sizeof(stCliente)) - 1;
            }
        }

    }

    return posicion;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca un cliente en el archivo de clientes por DNI y devuelve id de cliente si el cliente está activo(siendo 0 la primer posicion)
 * \param
 * \param
 * \return -1 si no existe el id, si existe devuelve el id
 *
 */

int posicionClienteEnArchivoPorDNI1 (char nombre [],char dni[]) {
    stCliente cliente;
    int id= -1;
    FILE * archi = fopen(nombre, "rb");
    if (archi) {
        while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
            if(cliente.eliminado != 1 && strcmp(cliente.dni, dni) == 0) {
                id= cliente.id;
            }
        }
        fclose(archi);
    }

    return id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca el cliente en el archivo a partir de la posicion del mismo
 *
 * \param FILE *archi - puntero archivo de clientes
 * \param int posicion - posicion en el archivo de clientes
 * \return Struct cliente
 *
 */

stCliente buscarClienteEnArchivoPorPosicion(FILE *archi, int posicion) {
    stCliente cliente;

    if(archi) {
        fseek(archi, posicion*sizeof(stCliente), SEEK_SET);
        fread(&cliente, sizeof(stCliente), 1, archi);
    }
    return cliente;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca el cliente en el archivo a partir de la posicion del mismo
 *
 * \param char nombre [] - nombre del archivo de clientes
 * \param int posicion - posicion del cliente en el archivo
 * \return Structura stCliente
 *
 */

stCliente buscarClienteEnArchivoPorPosicion1(char nombre [], int posicion) {
    stCliente cliente;
    FILE * archi = fopen(nombre, "rb");

    if(archi) {
        fseek(archi, posicion*sizeof(stCliente), SEEK_SET);
        fread(&cliente, sizeof(stCliente), 1, archi);
        fclose(archi);
    }
    return cliente;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Reeplaza la estructura del cliente a partir de la posicion
 *
 * \param FILE *archi - puntero archivo de clientes
 * \param int posicion -posicion del cliente en el archivo
 * \param stCliente cliente - estructura del cliente a reemplazar
 * \return void
 *
 */

void reemplazaClienteEnArchivoPorPosicion(FILE *archi, int posicion, stCliente cliente) {

    if(archi) {

        fseek(archi, posicion*sizeof(stCliente), SEEK_SET);
        fwrite(&cliente, sizeof(stCliente), 1, archi);

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menuModificarCliente() {

    printf("\t\t\t\t---------------(ADMINISTRADOR - CONSULTA POR DATO)----------------\n\n");
    printf("\t\t\t\tA) Modificar nombre.\n\n");
    printf("\t\t\t\tB) Modificar apellido\n\n");
    printf("\t\t\t\tC) Modificar DNI.\n\n");
    printf("\t\t\t\tD) Modificar email.\n\n");
    printf("\t\t\t\tE) Modificar domicilio.\n\n");
    printf("\t\t\t\tF) Modificar telefono.\n\n");

    printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
    printf("\t\t\t\t------------------------------------------------------\n");
}


/** \brief Busca el cliente a partir del DNI y solicita los datos a cambiar, luego lo guarda en el archivo
 *a partir de la posicion en la cual se encuentra la estructura
 * \param char nombreArchivo[] - nombre del archivo de clientes
 * \param  char dni[] - cadena del dni a modificar los datos
 * \return void
 *
 */

void modificarClienteArchivoPorDNI(char nombreArchivo[], char dni[]) {

    int opcion = 0;
    stCliente cliente;
    int posicion;

    FILE *archi = fopen(nombreArchivo, "r+b");
    if(archi) {

        posicion = posicionClienteEnArchivoPorDNI(archi, dni);
        cliente = buscarClienteEnArchivoPorPosicion(archi, posicion);

        while(posicion != -1 && opcion != ESC) {

            printf("\nIngrese la opcion a modificar: ");
            fflush(stdin);
            opcion = getch();

            switch(opcion) {
            case 97:
                setNombreCliente(cliente.nombre);
                printf("\n");
                break;
            case 98:
                setApellidoCliente(cliente.apellido);
                printf("\n");
                break;
            case 99:
                setDNICliente(cliente.dni);
                printf("\n");
                break;
            case 100:
                setEmailCliente(cliente.email);
                printf("\n");
                break;
            case 101:
                setDomicilioCliente(cliente.domicilio);
                printf("\n");
                break;
            case 102:
                setTelefonoCliente(cliente.telefono);
                printf("\n");
                break;
            case ESC:
                break;
            default:
                printf("\nLa opcion ingresada es incorrecta, vuelva a ingresar...");
            }
            if(opcion != ESC) {
                printf("\nDesea modificar otro valor? ESC para salir, cualquier tecla para continuar...");
                fflush(stdin);
                opcion = getch();
            }
        }
        reemplazaClienteEnArchivoPorPosicion(archi, posicion, cliente);
        fclose(archi);
    }

    if(posicion == -1) {
        printf("\nEl cliente no existe en el archivo...");
    }


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menuConsultaCliente() {

    printf("\t\t\t\t---------------(ADMINISTRADOR - CONSULTA CLIENTE POR DATO)----------------\n\n");
    printf("\t\t\t\tA) Consulta por DNI.\n\n");
    printf("\t\t\t\tB) Consulta por nombre\n\n");
    printf("\t\t\t\tC) Consulta por apellido.\n\n");
    printf("\t\t\t\tD) Consulta por domicilio.\n\n");
    printf("\t\t\t\tE) Consulta por telefono.\n\n");
    printf("\t\t\t\tF) Consulta por email.\n\n");
    printf("\t\t\t\tG) Ver todos los clientes ACTIVOS.\n\n");

    printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
    printf("\t\t\t\t------------------------------------------------------\n");

}

/** \brief Busca el/los cliente/s en el archivo por el dato solicitado, los guarda en otro archivo(debido a q no se sabe la cantiadd de resultados)
 * y luego muestra los datos leyendo ese archivo generado
 * \param char nombreArchivo[] - nombre del archivo de clientes
 * \param char clientesPorDato[] - nombre del archivo donde se guardan y luego se leen los datos de la consulta
 * \return void
 *
 */

void consultaClientesArchivo(char nombreArchivo[], char clientesPorDato[]) {
    int opcion = 0;
    stCliente cliente;
    int posicion;
    char dni[10];
    char nombre[30];
    char apellido[30];
    char domicilio[45];
    char telefono[12];
    char email[60];

    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi) {

        system("cls");
        menuConsultaCliente();
        fflush(stdin);
        opcion = getch();

        switch(opcion) {
        case 97:
            printf("\nIngrese el DNI a buscar: ");
            scanf("%s", dni);
            posicion = posicionClienteEnArchivoPorDNI(archi, dni);
            if(posicion != -1) {
                cliente = buscarClienteEnArchivoPorPosicion(archi, posicion);
                system("cls");
                muestraUnCliente(cliente);
            } else {
                printf("\nEl DNI no existe...");
            }
            printf("\n");
            system("\pause");
            break;
        case 98:
            printf("\nIngrese el nombre a buscar: ");
            scanf("%s", nombre);
            if(archivoDeConsultasPorDato(archi, nombre, clientesPorDato, opcion) > 0) {
                muestraArchivoClientes(clientesPorDato);
            } else {
                printf("\nNo se encontraron coincidencias...");
            }
            printf("\n");
            system("\pause");
            break;
        case 99:
            printf("\nIngrese el apellido a buscar: ");
            scanf("%s", apellido);
            if(archivoDeConsultasPorDato(archi, apellido, clientesPorDato, opcion) > 0) {
                muestraArchivoClientes(clientesPorDato);
            } else {
                printf("\nNo se encontraron coincidencias...");
            }
            printf("\n");
            system("\pause");
            break;
        case 100:
            printf("\nIngrese el domicilio a buscar: ");
            gets(domicilio);
            if(archivoDeConsultasPorDato(archi, domicilio, clientesPorDato, opcion) > 0) {
                muestraArchivoClientes(clientesPorDato);
            } else {
                printf("\nNo se encontraron coincidencias...");
            }
            printf("\n");
            system("\pause");
            break;
        case 101:
            printf("\nIngrese el telefono a buscar: ");
            scanf("%s", telefono);
            if(archivoDeConsultasPorDato(archi, telefono, clientesPorDato, opcion) > 0) {
                muestraArchivoClientes(clientesPorDato);
            } else {
                printf("\nNo se encontraron coincidencias...");
            }
            printf("\n");
            system("\pause");
            break;
        case 102:
            printf("\nIngrese el email a buscar: ");
            scanf("%s", email);
            if(archivoDeConsultasPorDato(archi, email, clientesPorDato, opcion) > 0) {
                muestraArchivoClientes(clientesPorDato);
            } else {
                printf("\nNo se encontraron coincidencias...");
            }
            printf("\n");
            system("\pause");
            break;
        case 103:
            muestraArchivoClientes(nombreArchivo);
            printf("\n");
            system("\pause");
            break;
        case ESC:
            printf("\nHasta luego...");
            break;
        default:
            printf("\nLa opcion ingresada es incorrecta, vuelva a ingresar...");
        }

        fclose(archi);
    } else {
        printf("\nNo se pudo abrir el archivo...");
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Busca un cliente en el archivo de clientes por dato(nombre, apellido, etc) y lo guarda en el archivo clientesPorDato para luego poder leerlo. Cada vez
*que es cargado el archivo se borra el contenido(se utiliza un archivo para resolver la complejidad de la limitancion de cantidad utilizando un arreglo)
*Si la consulta es existosa genera un archivo con los registros coincidentes y devuelve tambien la cantidad de registros cargados. (0 si no encuentra, >0 si encuentra)
 * \param File *archi - puntero a archivo base de datos clientes
 * \param char dato[] - Dato a buscar en la base de datos
 * \param char clientesPorDato[] - Archivo que se genera para guardar la consulta
 * \param int tipo - valor asignado a la opcion de busqueda(98 - nombre, 99 - apellido, 100 - domicilio, 101 - telefono, 102 - email)
 * \return registros cargados
 *
 *
 */

int archivoDeConsultasPorDato(FILE *archi,char dato[], char clientesPorDato[], int tipo) {
    stCliente cliente;
    int registros;
    if (archi) {

        FILE *archiPorDato = fopen(clientesPorDato, "wb");
        if(archiPorDato) {
            switch(tipo) {
            case 98:
                fseek(archi, 0, SEEK_SET);
                while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
                    if(strcmpi(cliente.nombre, dato) == 0) {
                        fwrite(&cliente, sizeof(stCliente), 1, archiPorDato);
                    }
                }
                registros = ftell(archiPorDato)/sizeof(stCliente);
                break;

            case 99:
                fseek(archi, 0, SEEK_SET);
                while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
                    if(strcmpi(cliente.apellido, dato) == 0) {
                        fwrite(&cliente, sizeof(stCliente), 1, archiPorDato);
                    }
                }
                registros = ftell(archiPorDato)/sizeof(stCliente);
                break;
            case 100:
                fseek(archi, 0, SEEK_SET);
                while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
                    if(strcmpi(cliente.domicilio, dato) == 0) {
                        fwrite(&cliente, sizeof(stCliente), 1, archiPorDato);
                    }
                }
                registros = ftell(archiPorDato)/sizeof(stCliente);
                break;
            case 101:
                fseek(archi, 0, SEEK_SET);
                while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
                    if(strcmpi(cliente.telefono, dato) == 0) {
                        fwrite(&cliente, sizeof(stCliente), 1, archiPorDato);
                    }
                }
                registros = ftell(archiPorDato)/sizeof(stCliente);
                break;
            case 102:
                fseek(archi, 0, SEEK_SET);
                while(fread(&cliente,sizeof(stCliente),1,archi) > 0) {
                    if(strcmpi(cliente.email, dato) == 0) {
                        fwrite(&cliente, sizeof(stCliente), 1, archiPorDato);
                    }
                }
                registros = ftell(archiPorDato)/sizeof(stCliente);
                break;
            }
        }

        fclose(archiPorDato);

    }
    return registros;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//A continuacion hay un conjunto de funciones, las cuales definen los datos del cliente, incluyendo las verificaciones de cada dato
void setNombreCliente(char nombre[]) {
    int valido;
    do {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(nombre);
        valido = verificarNombreApellido(nombre);
        if(valido == 0) {
            printf("\nEl nombre ingresado es invalido...");
        }
    } while(valido == 0);
}

void setApellidoCliente(char apellido[]) {
    int valido;
    do {
        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(apellido);
        valido = verificarNombreApellido(apellido);
        if(valido == 0) {
            printf("\nEl apellido ingresado es invalido...");
        }
    } while(valido == 0);
}

void setDNICliente(char dni[]) {

    do {
        printf("\nIngrese el DNI (sin puntos): ");
        fflush(stdin);
        gets(dni);
        if (verificarDNICliente(dni)==0) {
            printf("\n El dni ingresado no es valido, vuelva a ingresarlo...");
        }
    } while (verificarDNICliente(dni) != 1);

}
void setDomicilioCliente(char domicilio[]) {

    char nombreCalle[30];
    char altura[10];
    int validoN=0;
    int validoA=0;
    do {
        printf("\nIngrese nombre de la calle: ");
        fflush(stdin);
        gets(nombreCalle);
        validoN=verificarNombreCalle(nombreCalle);
        if (validoN == 0) {
            printf("El nombre de la calle es invalido...");
        }
    } while(validoN == 0);
    do {
        printf("\nIngrese altura del domicilio: ");
        fflush(stdin);
        gets(altura);
        validoA=verificarAlturaCalle(altura);
        if (validoA == 0) {
            printf("La altura es invalida...");
        }
    } while(validoA == 0);
    if (validoA == 1 && validoN == 1) {
        strcat(nombreCalle," ");
        strcat(nombreCalle,altura);
        strcpy(domicilio,nombreCalle);
    }
}
void setEmailCliente(char email[]) {
    do {
        printf("\nIngrese el email: ");
        fflush(stdin);
        gets(email);
        if(verificarEmail(email) == 0) {
            printf("\nEl email ingresado no es valido, vuelva a ingresarlo...");
        }
    } while(verificarEmail(email) != 1);

}
void setTelefonoCliente(char telefono[]) {
    int valido;
    do {
        printf("\nIngrese el telefono (sin guiones): ");
        fflush(stdin);
        gets(telefono);
        valido = verificarTelefono(telefono);
        if(valido == 0) {
            printf("\nEl telefono ingresado es invalido...");
        }
    } while(valido == 0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica la validez del DNI del cliente en los caracteres
 *
 * \param char dni[] - cadena DNI del cliente
 * \param
 * \return 1 si es valido, 0 si no es valido
 *
 */

int verificarDNICliente(char dni[]) {
    int dniValido = 0;

    if (verificarLetras(dni) == 0 && verificarSimbolos(dni) == 0 && strlen(dni)== 8) {
        dniValido = 1;
    }
    return dniValido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica la validez del nombre o apellido (segun lo ingresado en dato) del cliente
 *
 * \param char dato[] - cadena a verificar
 * \param
 * \return 1 si es valido, 0 si no es valido
 *
 */
int verificarNombreApellido(char dato[]) {

    int valido = 0;
    if(verificarNumeros(dato) == 0 && verificarSimbolos(dato) == 0 && strlen(dato)>1) {
        valido = 1;
    }

    return valido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica la validez del domicilio del cliente
 *
 * \param char nombre[] - cadena a verificar
 * \param
 * \return 1 si es valido, 0 si no es valido
 *
 */

int verificarNombreCalle(char nombre[]) {
    int valido = 0;
    if(verificarSimbolos(nombre) == 0 && verificarNumeros(nombre) == 0 && strlen(nombre)>1) {
        valido = 1;
    }
    return valido;
}
int verificarAlturaCalle (char altura[]) {
    int valido=0;
    if (verificarLetras(altura)== 0 && verificarSimbolos(altura)== 0 && strlen(altura)>1) {
        valido = 1;
    }
    return valido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica la validez del telefono del cliente
 *
 * \param char dato[] - cadena a verificar
 * \param
 * \return 1 si es valido, 0 si no es valido
 *
 */
int verificarTelefono(char dato[]) {

    int valido = 0;
    if(verificarSimbolos(dato) == 0 && verificarLetras(dato) == 0 && strlen(dato)>1) {
        valido = 1;
    }

    return valido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica si el  string "dato" no contenga numeros
 * \param char dato[] - cadena a verificar
 * \param
 * \return 0 si no contiene numeros, 1 si contiene numeros
 *
 */

int verificarNumeros(char dato[]) {
    char numSimb []= "0123456789";
    int valido = 1;

    /*
    La función strcspn() toma dos strings como entrada, string_1 y string_2 como argumento y busca string_1 recorriendo cualquier carácter
     que esté presente en string_2 . La función devolverá la longitud de string_1 si ninguno de los caracteres de string_2 se encuentra en string_1.
    */

    if(strcspn(dato, numSimb) == strlen(dato)) {
        valido = 0;
    }
    return valido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica que el  string "dato" no contenga simbolos
 *
 * \param char dato[] - cadena a verificar
 * \param
 * \return 0 si contiene simbolos, 1 si no contiene
 *
 */

int verificarSimbolos(char dato[]) {
    char Simb []= "°@|¬¡!#$%&/(=?\'.*~[]{},:-+";
    int valido = 1;

    /*
    La función strcspn() toma dos strings como entrada, string_1 y string_2 como argumento y busca string_1 recorriendo cualquier carácter
     que esté presente en string_2 . La función devolverá la longitud de string_1 si ninguno de los caracteres de string_2 se encuentra en string_1.
    */

    if(strcspn(dato, Simb) == strlen(dato)) {
        valido = 0;
    }
    return valido;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica que un string "dato" no contenga letras
 *
 * \param char dato[] - cadena a verificar
 * \param
 * \return 0 si no contiene, 1 si contiene
 *
 */

int verificarLetras (char arreglo[]) {
    char abc []= "abcdefghijklmnñopqrstuvwxyzABCDEFGHIJKLMNÑOPQRSTUVWXYZ";//(´ no lo toma para verificar)
    int validez = 1;
    /*
    La función strcspn() toma dos strings como entrada, string_1 y string_2 como argumento y busca string_1 recorriendo cualquier carácter
     que esté presente en string_2 . La función devolverá la longitud de string_1 si ninguno de los caracteres de string_2 se encuentra en string_1.
    */
    if (strcspn(arreglo, abc) == strlen(arreglo)) {
        validez = 0;
    }
    return validez;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Verifica la validez del email
 *
 * \param char dato[] - cadena a verificar
 * \param
 * \return 1 si es valido; 0 si es invalido
 *
 */

int verificarEmail(char email[]) {
    int emailValido = 1;

    if(strstr(email, "@") == NULL || strstr(email, ".com") == NULL || strstr(email, " ") != NULL) {
        emailValido = 0;
    }

    return emailValido;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Da de baja un cliente recibiendo por parametro el id, nombres de los archivos. Tambien elimina las cuentas y movimientos del cliente
 *
 * \param char nombreCliente [] - archivo clientes
 * \param char nombreCuenta [] - archivo cuentas
 * \param char nombreMovimiento[] - archivo movimientos
 * \param int id - id de cliente
 * \return
 *
 */

void bajaClientePorId (char nombreCliente [],char nombreCuenta [],char nombreMovimiento[], int id)
{
    int contador =0;
    int idCuentas [3];
    int val;
    int x=0;
    int aux=0;
    stCliente a;
    stCuenta b;
    stMovimiento c;
    FILE * archi = fopen(nombreCliente, "r+b");
    if (archi)
    {
        while (fread(&a, sizeof (stCliente),1, archi) > 0 && a.id != id)
        {
        }
        if(a.id == id)
        {
            printf("Se elimino el cliente %d\n", id);
            a.eliminado = 1;
        }
        fseek(archi,-sizeof(stCliente),1);
        fwrite(&a, sizeof (stCliente),1,archi);
        fclose(archi);
    }
    val=buscarCuentasActivasDeClientes(idCuentas, id, nombreCuenta);
    FILE * archi1 = fopen(nombreCuenta, "r+b");
    if (archi1)
    {
        for (int i =0 ; i<val; i ++)
        {
            while (fread(&b,sizeof(stCuenta),1,archi1)>0 && b.id!=idCuentas[i])
            {

            }
            if (b.id==idCuentas[i])
            {
                b.eliminado=1;
                fseek(archi1,-sizeof(stCuenta),1);
                fwrite(&b, sizeof (stCuenta),1,archi1);
                printf("Se elimino la cuenta %d\n", idCuentas[i]);
            }
            rewind(archi1);
        }
        fclose(archi1);
    }
    x=0;
    int y=0;
    int finale=0;
    FILE * archi2 = fopen(nombreMovimiento, "r+b");
    if (archi2)
    {
        fseek(archi2,0,2);
        finale=(ftell(archi2)/sizeof(stMovimiento));
        rewind(archi2);
        while(x<val)
        {
            while (y<finale)
            {
                fread(&c,sizeof(stMovimiento),1,archi2);
                if(c.idCuenta==idCuentas[x]&& c.eliminado!=1)
                {
                    c.eliminado=1;
                    fseek(archi2,-1*sizeof(stMovimiento),1);
                    fwrite(&c,sizeof(stMovimiento),1,archi2);
                }
                y++;
            }
            x++;
            fseek(archi2,0,0);
            y=0;
        }
        fclose(archi2);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Da de baja las cuentas y movimientos, buscando por id de cliente
 *
 * \param char nombreCuenta - string archivo de cuentas
 * \param char nombreMovimientos - string archivo de movimientos
 * \param int id - id de cliente
 * \return
 *
 */

void bajaCuentasYMovimientos (char nombreCuenta [], char nombreMovimientos [], int id)
{
    int idCuentas [3];
    int val;
    int x=0;
    int aux=0;
    stMovimiento c;
    stCuenta b;
    val=buscarCuentasActivasDeClientes(idCuentas, id, nombreCuenta);
    FILE * archi1 = fopen(nombreCuenta, "r+b");
    if (archi1)
    {
        for (int i =0 ; i<val; i ++)
        {
            while (fread(&b,sizeof(stCuenta),1,archi1)>0 && b.id!=idCuentas[i])
            {

            }
            if (b.id==idCuentas[i])
            {
                b.eliminado=1;
                fseek(archi1,-sizeof(stCuenta),1);
                fwrite(&b, sizeof (stCuenta),1,archi1);
                printf("Se elimino la cuenta %d\n", idCuentas[i]);
            }
            rewind(archi1);
        }
        fclose(archi1);
    }
    x=0;
    int y=0;
    int finale=0;
    FILE * archi2 = fopen(nombreMovimientos, "r+b");
    if (archi2)
    {
        fseek(archi2,0,2);
        finale=(ftell(archi2)/sizeof(stMovimiento));
        rewind(archi2);
        while(x<val)
        {
            while (y<finale)
            {
                fread(&c,sizeof(stMovimiento),1,archi2);
                if(c.idCuenta==idCuentas[x]&& c.eliminado!=1)
                {
                    c.eliminado=1;
                    fseek(archi2,-1*sizeof(stMovimiento),1);
                    fwrite(&c,sizeof(stMovimiento),1,archi2);
                }
                y++;
            }
            x++;
            fseek(archi2,0,0);
            y=0;
        }
        fclose(archi2);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Da de baja los movimientos, buscando por id de cuenta
 *
 *
 * \param char nombreMovimientos - string archivo de movimientos
 * \param int idCuenta - id de cuenta
 * \return
 *
 */
void bajaMovimientosDeUnaCuenta (char nombreMovimientos [], int idCuenta)
{
    stMovimiento c;
    int x=0;
    int y=0;
    int finale=0;
    FILE * archi2 = fopen(nombreMovimientos, "r+b");
    if (archi2)
    {
        fseek(archi2,0,2);
        finale=(ftell(archi2)/sizeof(stMovimiento));
        rewind(archi2);
        while (y<finale)
        {
            fread(&c,sizeof(stMovimiento),1,archi2);
            if(c.idCuenta==idCuenta && c.eliminado!=1)
            {
                c.eliminado=1;
                fseek(archi2,-1*sizeof(stMovimiento),1);
                fwrite(&c,sizeof(stMovimiento),1,archi2);
            }
            y++;
        }
        x++;
        fseek(archi2,0,0);
        y=0;

        fclose(archi2);
    }
}
