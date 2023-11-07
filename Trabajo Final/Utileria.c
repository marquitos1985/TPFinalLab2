#include <stdio.h>
#include <stdlib.h>
#include "Cuenta.h"
#include "Movimientos.h"
#include "cliente.h"
#include "Utileria.h"
#include "conio.h"
#include "string.h"
/** \brief Recibe por parametro un entero mayor y un entero menor, retorna un numero aleatorio entre ellos.
 *
 * \param
 * \param
 * \return
 *
 */
int mayorMenor(int mayor, int menor)
{
    int aux = rand()%(mayor-menor)+menor;
    return aux;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un nombre al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_nombres(char a[])
{
    char nombres_lista [170][30] = {"Adriana", "Daniel", "Catalina", "Felipe", "Elena", "Ignacio", "Emilio", "Diana",
                                    "Alejandro", "Esperanza", "Camila", "Benjamin", "Carolina", "Gabriel", "Andrea",
                                    "Antonio", "Claudia", "Javier", "Emilia", "Guillermo", "Ana", "Alejandra", "Fernando",
                                    "Elizabeth", "Andres", "Beatriz", "Carlos", "Daniela", "Diego", "Alicia", "Ernesto",
                                    "Eva", "Federico", "Isabel", "Gonzalo", "Laura", "Horacio", "Lorena", "Hugo", "Maria",
                                    "Ivan", "Mariana", "Jaime", "Melissa", "Joel", "Natalia", "Jonathan", "Olga", "Jorge",
                                    "Patricia", "Jose", "Paula", "Juan", "Rebeca", "Julia", "Ricardo", "Luis", "Rosa",
                                    "Manuel", "Sandra", "Marco", "Silvia", "Mauricio", "Valentina", "Miguel", "Victoria",
                                    "Nicolas", "Ximena", "Oscar", "Yolanda", "Pablo", "Zoe", "Pedro", "Raquel", "Ricardo",
                                    "Rodrigo", "Ruben", "Samuel", "Santiago", "Sebastian", "Simon", "Tomas", "Valeria",
                                    "Victor", "Viviana", "Xavier", "Yasmin", "Zoe", "Abigail", "Adrian", "Agustin", "Alan",
                                    "Alejandro", "Alfonso", "Alfredo", "Amanda", "Amelia", "Ana", "Andres", "Angela",
                                    "Antonio", "Ariana", "Arturo", "Aurora", "Axel", "Barbara", "Brenda", "Bruno", "Caleb",
                                    "Camila", "Carla", "Carlos", "Carolina", "Cecilia", "Christian", "Claudia", "Cristian",
                                    "Cristina", "Daniel", "Daniela", "David", "Diego", "Dylan", "Eduardo", "Elena", "Elizabeth",
                                    "Emilia", "Emilio", "Emily", "Emma", "Enrique", "Erick", "Ernesto", "Esmeralda", "Esteban",
                                    "Eva", "Federico", "Fernanda", "Fernando", "Francisco", "Gabriel", "Gabriela", "German",
                                    "Gonzalo", "Gregorio", "Guadalupe", "Guillermo", "Gustavo", "Hector", "Hugo", "Ian",
                                    "Ignacio", "Iker", "Ivan", "Jacobo", "Jaime", "Javier", "Jennifer", "Jesus", "Jessica",
                                    "Joaquin", "Jorge", "Jose", "Josue", "Juan", "Julia", "Julio", "Laura", "Leticia", "Lorena"
                                   };
    strcpy(a, nombres_lista[mayorMenor(170,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un apellido al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_apellidos(char a[])
{
    char apellidos_lista [116][30] = {"Alvarez", "Andrade", "Araya", "Arce", "Avila", "Barahona", "Barrios", "Blanco",
                                      "Bustamante", "Campos", "Cardenas", "Carvajal", "Castillo", "Castro", "Chacon",
                                      "Chavez", "Contreras", "Corona", "Cortes", "Cruz", "Delgado", "Diaz", "Duarte",
                                      "Escalante", "Estrada", "Fernandez", "Flores", "Garcia", "Gonzalez", "Gutierrez",
                                      "Hernandez", "Herrera", "Jimenez", "Lara", "Lopez", "Marin", "Mendoza", "Molina",
                                      "Montero", "Montoya", "Morales", "Moreno", "Mora", "Navarro", "Ortega", "Ortiz",
                                      "Pacheco", "Padilla", "Perez", "Pineda", "Ramirez", "Reyes", "Rivas", "Rivera",
                                      "Rodriguez", "Romero", "Ruiz", "Salazar", "Sanchez", "Sandoval", "Soto", "Suarez",
                                      "Torres", "Urena", "Valdez", "Vargas", "Vega", "Velasquez", "Villalobos", "Zamora",
                                      "Zuniga", "Acosta", "Aguilar", "Aguirre", "Alvarado", "Arias", "Baez", "Barrantes",
                                      "Calderon", "Carrillo", "Cordero", "Cubero", "Duran", "Espinoza", "Fallas", "Fonseca",
                                      "Gamboa", "Garro", "Granados", "Guerrero", "Guzman", "Hidalgo", "Mendez", "Miranda",
                                      "Monge", "Monge", "Montenegro", "Morera", "Moya", "Murillo", "Ocampo", "Orozco",
                                      "Peralta", "Quesada", "Rojas", "Rosales", "Salas", "Sibaja", "Solano", "Solis",
                                      "Trejos", "Ugalde", "Ulloa", "Umana", "Vindas", "Zuniga"
                                     };
    strcpy(a, apellidos_lista[mayorMenor(116,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un email al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_email(char a[])
{
    char email_lista [81][50] = {"maritobaracus@hotmail.com", "wachinloquito@gmail.com", "juancarlos123@yahoo.com",
                                 "lauramendez22@gmail.com", "pedroalvarez45@hotmail.com", "anamaria17@yahoo.com", "carlosrodriguez@gmail.com",
                                 "sofiamartinez99@hotmail.com", "roberto_gomez@gmail.com", "lucia.lopez22@yahoo.com", "pablo.martinez@gmail.com",
                                 "mariaperez89@hotmail.com", "josefina78@gmail.com", "esteban_rivera@hotmail.com", "lucas.fernandez@yahoo.com",
                                 "danielaguerra34@gmail.com", "carolina_25@hotmail.com", "ramon.sanchez@yahoo.com", "camila_garcia@gmail.com",
                                 "julio87@hotmail.com", "valeria.torres@yahoo.com", "gabrielromero12@gmail.com", "luciana.mendoza@hotmail.com",
                                 "fernando.ramirez@yahoo.com", "natalia.gomez@gmail.com", "carlosalberto89@hotmail.com", "marielaperez@yahoo.com",
                                 "rodrigo_22@gmail.com", "marcela.martinez@hotmail.com", "alejandro.lopez@yahoo.com", "analia_18@gmail.com",
                                 "javier_rojas@hotmail.com", "lucasgonzalez99@yahoo.com", "maria.castro@gmail.com", "diego.santos@hotmail.com",
                                 "adrianareyes23@yahoo.com", "gustavo.molina@gmail.com", "rocio.mendez@hotmail.com", "fernandoperez45@yahoo.com",
                                 "sofiagonzalez@gmail.com", "pablorodriguez_25@hotmail.com", "valentinaramos@yahoo.com", "luciano_23@gmail.com",
                                 "andrearuiz@hotmail.com", "emilio.lopez@yahoo.com", "victoria_gomez@gmail.com", "martinaguilar@hotmail.com",
                                 "juanperez22@yahoo.com", "daniela_garcia@gmail.com", "jose_89@hotmail.com", "nataliaramirez@yahoo.com",
                                 "roberto_martinez@gmail.com", "esteban_22@hotmail.com", "carolina_gomez@yahoo.com", "lucasrodriguez@gmail.com",
                                 "mariaperez99@hotmail.com", "gabrielamolina@yahoo.com", "carlos_santos@gmail.com", "pablocastro@hotmail.com",
                                 "lucia_lopez@yahoo.com", "fernando_45@gmail.com", "lauragonzalez@hotmail.com", "rodrigo_martinez@yahoo.com",
                                 "valentina_gomez@gmail.com", "javier_18@hotmail.com", "sofiagonzalez99@yahoo.com", "maria_molina@gmail.com",
                                 "diegorodriguez@hotmail.com", "analia.gomez@yahoo.com", "gustavo_rodriguez@gmail.com", "rocio_martinez@hotmail.com",
                                 "fernandoperez22@yahoo.com", "natalia_garcia@gmail.com", "carlosalberto_45@hotmail.com", "marielaramirez@yahoo.com",
                                 "rodrigo.molina@gmail.com", "marcela_perez@hotmail.com", "alejandro.lopez99@yahoo.com", "analia_gomez@gmail.com",
                                 "javierrodriguez22@hotmail.com", "lucasgonzalez@yahoo.com"
                                };
    strcpy(a, email_lista[mayorMenor(81,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un DNI al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_documentos(char a[])
{
    char documentos_lista [144][30] = { "11011761", "20659651", "35541512", "28791467", "32848755", "36712663", "29645647",
                                        "14709102", "40797643", "30496834", "39258276", "23137797", "18304189", "35582654",
                                        "24543024", "19397973", "25593667", "33662439", "39572546", "42430907", "31323728",
                                        "37119615", "37288363", "36323595", "31530492", "19201832", "19552111", "28073618",
                                        "31500167", "37496031", "21868216", "30180835", "36202151", "38810020", "32421812",
                                        "28608010", "29443946", "38768738", "19584044", "21741944", "29472663", "42052934",
                                        "24577463", "36940151", "38812125", "43339024", "35487363", "26451492", "30138842",
                                        "36366662", "40676988", "20744306", "26991556", "33044769", "26024219", "28686841",
                                        "33813234", "22156036", "22837247", "35925568", "24352043", "43809824", "33419705",
                                        "24448853", "36183986", "27522237", "28432819", "36516375", "30619591", "29441396",
                                        "42694289", "43416502", "40079835", "30536604", "41149889", "43972405", "25086990",
                                        "36844909", "37205195", "23662295", "32112832", "41072255", "24962283", "30473684",
                                        "33477125", "24193206", "37805085", "28932017", "34838845", "34600241", "41274313",
                                        "23891262", "32203029", "32724961", "32419982", "40050648", "23806291", "29866654",
                                        "34916472", "26681552", "33522191", "40412744", "33570536", "31724584", "27813148",
                                        "43421966", "24494656", "23065261", "32583575", "36274846", "39879124", "42936452",
                                        "29902027", "30374557", "40229667", "40366754", "33620848", "30008743", "36642547",
                                        "24525704", "44237776", "27278632", "32876944", "32919788", "31633295", "35467118",
                                        "41485948", "23726776", "32402349", "35532212", "25314101", "36920784", "27047032",
                                        "32801462", "41618118", "33177007", "36713439", "35169606", "34224355", "34673767",
                                        "39422759", "38402467", "25618994", "34912766"
                                      };
    strcpy(a, documentos_lista[mayorMenor(144,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un telefono al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_telefonos(char a[])
{

    char numeros_lista [145][30] = {"2217684598", "1122144759", "2236724190", "3835971234", "2238541698", "3832915634",
                                    "3837314987", "2211870485", "2235748761", "3838225930", "2215334289", "2235687910",
                                    "3834896715", "2234495068", "2212778903", "3838221490", "2234493187", "2217684523",
                                    "3835972548", "2235687801", "2212778934", "3837314982", "3834897250", "2238541629",
                                    "3834899432", "2215334295", "2236724169", "2212778976", "3837314967", "2217684592",
                                    "3834897249", "2215334205", "2236724120", "2234493095", "3835971204", "2235748706",
                                    "3832915690", "2211870426", "3835971280", "2234493234", "3834897243", "3837314906",
                                    "2236724187", "3832915608", "3838221473", "2212778914", "2235748729", "2217684573",
                                    "3835971296", "3837314956", "2215334219", "2238541653", "2235687940", "3834899471",
                                    "3832915729", "2212778951", "2236724124", "3835971265", "2217684587", "3837314986",
                                    "3834899439", "2215334268", "2234493059", "3838221459", "3832915754", "2235748772",
                                    "2212778982", "3837314929", "2217684531", "3835972521", "3838221477", "2236724145",
                                    "2212778927", "3834897204", "3837314979", "2238541607", "3835972510", "2215334225",
                                    "2236724170", "2217684552", "3834897295", "2231806759", "3833135269", "2217170385",
                                    "2238882109", "3839274681", "2219154320", "2235486971", "3838239106", "2219730156",
                                    "2235992408", "3833520694", "2213357094", "2232530197", "3839128470", "2211902485",
                                    "2236183475", "3832465981", "2214590763", "2235260809", "3838412960", "2219348069",
                                    "2236470925", "3834265719", "2218340265", "2232976135", "3837704201", "2214085763",
                                    "2234821396", "3836897013", "2215779320", "2232389457", "3836380196", "2217960735",
                                    "2231882503", "3839487605", "2219816460", "2238975046", "3836921058", "2217798532",
                                    "2235984072", "3832476539", "2218391275", "2233528591", "3835669207", "2212235976",
                                    "2234538096", "3836542079", "2214253690", "2236930841", "3836117543", "2213750469",
                                    "2234206173", "3833397825", "2219745816", "2233149078", "3835917204", "2217438650",
                                    "2238316429", "3838905167", "2219584023", "2236213860", "3833290516", "2213358942",
                                    "223594836"
                                   };

    strcpy(a, numeros_lista[mayorMenor(145,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con una dirrecion al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_arreglo_dirreciones(char a[])
{
    char direcciones_lista [102][30] = {"Francia 29", "Constitucion 1892", "Alemania 45", "Avenida del Sol 567", "Belgica 78",
                                        "Mariano Moreno 1234", "Espana 98", "Libertador 5678", "Italia 12", "Rivadavia 3456",
                                        "Portugal 67", "San Martin 7890", "Brasil 23", "Alvear 4567", "Estados Unidos 89",
                                        "San Juan 890", "Colon 456", "Las Heras 901", "Suipacha 234", "Bolivar 567",
                                        "San Luis 123", "Peru 456", "Belgrano 789", "San Nicolas 234", "Cordoba 567",
                                        "Paseo Colon 890", "9 de Julio 1234", "Independencia 567", "Pueyrredon 890",
                                        "Santa Fe 123", "Callao 456", "Florida 789", "Sarmiento 234", "Corrientes 567",
                                        "Uruguay 901", "Lavalle 234", "Mayo 567", "Alsina 890", "Diagonal Norte 123",
                                        "Tacuari 456", "Reconquista 789", "Av. de Mayo 234", "Yrigoyen 567", "Peron 890",
                                        "Alem 123", "Montevideo 456", "Roque Saenz Pena 789", "Santa Cruz 234",
                                        "Hipolito Yrigoyen 567", "Avenida Santa Fe 890", "Jujuy 123", "Corrientes 456",
                                        "Cerrito 789", "Lima 234", "Callao 567", "Pellegrini 890", "Tucuman 123",
                                        "Uruguay 456", "Talcahuano 789", "Mendoza 234", "Sarmiento 567", "Paraguay 890",
                                        "Junin 123", "Esmeralda 456", "Florida 789", "Alsina 234", "Diagonal Roque Saenz Pena 567",
                                        "Cerrito 890", "Maipu 123", "Tucuman 456", "San Martin 789", "Carlos Pellegrini 234",
                                        "Avenida de Mayo 567", "Lavalle 890", "O'Higgins 123", "Corrientes 456", "Bolivar 789",
                                        "Peron 234", "Montevideo 567", "Esmeralda 890", "Paseo Colon 123", "Sarmiento 456",
                                        "Independencia 789", "San Jose 234", "Callao 567", "Santa Fe 890", "Rivadavia 123",
                                        "Cordoba 456", "Avenida 9 de Julio 789", "Misiones 234", "Belgrano 567", "Uruguay 890",
                                        "San Juan 123", "Salta 456", "San Martin 789", "Suipacha 234", "Corrientes 567",
                                        "Juncal 890", "Av. de los Incas 123", "Florida 456", "Santa Fe 789", "Yrigoyen 675"
                                       };
    strcpy(a, direcciones_lista[mayorMenor(102,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Recibe por parametro un string, sobrescribe dicho string con un detalle positivo al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_movimientos_positivos(char a[])
{
    char movimientos_positivos_lista [10][30] = {"Transferencia", "Jubilacion", "Plan progresar", "Loteria", "Sueldo", "Pension", "Deposito"
                                                 , "Credito", "Bono", "Subsidio",
                                                };
    strcpy(a, movimientos_positivos_lista[mayorMenor(10,0)]);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief  Recibe por parametro un string, sobrescribe dicho string con un detalle negativo al azar.
 *
 * \param
 * \param
 * \return
 *
 */
void carga_aleatoria_movimientos_negativos(char a[])
{
    char movimientos_negativos_lista [13][30] = {"Servicio de Luz", "Servicio de Gas", "Patente", "Seguro", "Credito Hipotecario",
    "Tarjeta de Credito","Transferencia a cuenta de terceros", "Cuota Escolar", "Comida", "Extraccion ATM", "Spotify", "Star+", "Mercado Libre"
                                                };

    strcpy(a, movimientos_negativos_lista[mayorMenor(13,0)]);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pantallaDeInicio(){
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t|||||||||||||||||[---------------]||||||||||||||||||||\n");
printf("\t\t\t\t|||||||||||||||||[BANCO BICICLETA]||||||||||||||||||||\n");
printf("\t\t\t\t|||||||||||||||||[---------------]||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||Copyright V2023.||||||||||||||||||||\n");
printf("\t\t\t\t||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
Sleep(4000);
system("cls");
}

void menuPrincipal (){
printf("\t\t\t\t------------------(MENU PRINCIPAL)--------------------\n\n");
printf("\t\t\t\t1) Ingresar como cliente.\n\n");
printf("\t\t\t\t2) Crea su usuario.\n\n");
printf("\t\t\t\t3) Ingresar como administrador del sistema.\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");
}

void menuIngresoCliente (){
printf("\t\t\t\t------------------(MENU CLIENTE)--------------------\n\n");
printf("\t\t\t\t1) Para mostrar informacion personal.\n\n");
printf("\t\t\t\t2) Para mostrar sus cuentas.\n\n");
printf("\t\t\t\t3) Para dar de alta una cuenta.\n\n");
printf("\t\t\t\t4) Modificar datos cliente.\n\n");
printf("\t\t\t\t5) Para dar de baja su usuario.\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");
}

void menuCuentas () {
printf("\t\t\t\t------------------(MENU CUENTAS)--------------------\n\n");
printf("\t\t\t\t1) Para mas operaciones sobre una cuenta.\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");
}

void menuMasOperacionesCuentas () {
printf("\t\t\t\t---------------(OPERACIONES AMPLIADAS)----------------\n\n");
printf("\t\t\t\t1) Alta movimiento.\n\n");
printf("\t\t\t\t2) Mostrar movimientos.\n\n");
printf("\t\t\t\t3) Dar de baja cuenta.\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");
}

void menuAdministrador (){
printf("\t\t\t\t---------------(OPERACIONES AMPLIADAS)----------------\n\n");
printf("\t\t\t\t1) Alta movimiento.\n\n");
printf("\t\t\t\t2) Mostrar movimientos.\n\n");
printf("\t\t\t\t3) Dar de baja cuenta.\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}
void menuPrincipalAdministrador(){
printf("\t\t\t\t---------------(ADMINISTRADOR - MENU PRINCIPAL)----------------\n\n");
printf("\t\t\t\t1) Alta de cliente.\n\n");
printf("\t\t\t\t2) Listar o modificar cliente, cuentas y movimientos\n\n");
printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}
void menuListarOmodificarCliente(){
printf("\t\t\t\t---------------(ADMINISTRADOR - LISTAR/MODIFICAR)----------------\n\n");
printf("\t\t\t\t1) Ver todos los clientes del banco.\n\n");
printf("\t\t\t\t2) Ver todas las cuentas del banco.\n\n");
printf("\t\t\t\t3) Ver todos los movimientos del banco\n\n");
printf("\t\t\t\t4) Ver movimientos por fecha.\n\n");
printf("\t\t\t\t5) Consultar por dato.\n\n");



printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}
void menuConsultaPorDato(){
printf("\t\t\t\t---------------(ADMINISTRADOR - CONSULTA POR DATO)----------------\n\n");
printf("\t\t\t\t1) Ver datos cliente.\n\n");
printf("\t\t\t\t2) Modificar datos cliente.\n\n");
printf("\t\t\t\t3) Alta de cuenta en cliente\n\n");
printf("\t\t\t\t4) Operaciones cuentas.\n\n");
printf("\t\t\t\t5) Dar de baja cliente\n\n");

printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}

void menuCuentasCliente(){
printf("\t\t\t\t---------------(ADMINISTRADOR - CUENTAS)----------------\n\n");
printf("\t\t\t\t1) Ver cuentas cliente.\n\n");
printf("\t\t\t\t2) Modificar cuenta.\n\n");
printf("\t\t\t\t3) Baja cuenta.\n\n");
printf("\t\t\t\t4) Operaciones movimientos.\n\n");
printf("\t\t\t\t5) Ver movimientos de cuenta.\n\n");

printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}

void menuMovimientosCuenta(){
printf("\t\t\t\t---------------(ADMINISTRADOR - MOVIMIENTOS)----------------\n\n");
printf("\t\t\t\t1) Alta movimiento.\n\n");
printf("\t\t\t\t2) Modificar movimiento.\n\n");
printf("\t\t\t\t3) Baja movimiento.\n\n");

printf("\t\t\t\t----------------(Para salir oprima ESC)---------------\n");
printf("\t\t\t\t------------------------------------------------------\n");

}

