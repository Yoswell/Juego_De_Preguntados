#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<stdexcept>
#include<sstream>
#include<fstream>

/*AUTOR: Yoswel Badilla Toruño INICIO: 01 de agosto del 2022 FINALIZACION: 14 de agosto del 2022 Este programa trata sobre guardar datos y leerlos desde un archivo txt, en si es un juego de preguntados sobre el cuerpo humano*/
//Dato importante, en la lectura de las preguntas se usara una n en lugar de una ñ para la pregunta(3), ya que si usamos el Setlocale transforma los caracteres ASCCI que usamos para estetica en caracteres
//Ademas de que los archivos estan vacios, se llenaran sobre la marcha
using namespace std;

/*---- Prototipos de Funciones -----*/
void QuienSeraElJugador1y2(int CedulaJ1, int CedulaJ2, string Jugador1, string Jugador2, bool ok);
void EvaluarRespuesta(int Turno1, int CedulaJ1, int CedulaJ2, int PuntosJ1, int PuntosJ2, string Jugador1, string Jugador2);
void JuegoJugador1(int Turno1, int PuntosJ1);
void JuegoJugador2(int Turno1, int PuntosJ2);
void Ganador(int PuntosJ1, int PuntosJ2, string Jugador1, string Jugador2);

int main(){
srand(time(NULL));
string Jugador1 = "", Jugador2 = "", Linea;
int op, CedulaJ1 = 0, CedulaJ2 = 0, Turno1 = 1, PuntosJ1, PuntosJ2, ContadorLineas = 1;
bool continuar = true, saliendo = false, ok = false;
ofstream Archivo; ofstream Puntajes; ifstream Archivo2;
    do{
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272             BIENVENIDOS AL JUEGO" << right << setw(15) << "\272\n";
        cout << "\272           QUE TANTO SABES SOBRE EL" << right << setw(13) << "\272\n";
        cout << "\272                CUERPO HUMANO" << right << setw(19) << "\272\n";
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270\n" << endl;
        do{
            Puntajes.open("Puntos.txt", ios::out); //Abrimos el archivo donde vamos a guardar los nombres y las cedulas de los jugadores
            do{                                    //Do para el menu y en donde se van a ejecutar todas las funciones para el juego
                cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                cout << "\272" <<  "  MENU DE OPCIONES" << right << setw(29) << "\272" << endl;
                cout << "\272" <<  "  [1] Ingresar jugadores" << right << setw(23) << "\272" << endl;
                cout << "\272" <<  "  [2] Juego sobre las partes de cuerpo humano" << right << setw(2) << "\272" << endl;
                cout << "\272" <<  "  [3] Reporte de jugadores" << right << setw(21) << "\272" << endl;
                cout << "\272" <<  "  [4] Los 5 primeros juegos" << right << setw(20) << "\272" << endl;
                cout << "\272" <<  "  [5] Instrucciones del juego" << right << setw(18) << "\272" << endl;
                cout << "\272" <<  "  [0] Salir del juego" << right << setw(26) << "\272" << endl;
                cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                cout << "\n  Ingrese una opcion: ";
                cin >> op;                                                      //Leemos las opciones del switch
					switch(op){
                        case 1:
                            Puntajes.open("Puntos.txt", ios::out | ios::trunc); //Esto es para borrar los registros de las partidas en el archivo donde se guardan los puntajes, porque si desean registrar otros jugadores el registro continua con los anteriores jugadores
                            Puntajes.close();                                   //Aca lo cerramos y dejamos el archivo vacio
                            system("pause");
                            system("cls");
                            Archivo.open("Registros.txt", ios::out);            //Aca abrimos el archivo de los nombres y cedulas para guardar estos datos dentro de el
                                if(Archivo.fail()){                             //Esta condicion es por si es archivo se crea mal o algo pasa con el el programa automaticamente se sale
                                    cout << "No se pudo abrir el archivo..." << endl;
                                    exit(1);
                                }
                                do{                                             //Do para validar que la cedula sea de 9 digitos ejemplo 604780269
                                    do{                                         //Do para validar que no se digiten caracteres en los espacions de la cedula del jugador 1 porque es entero
                                        cout << "\nJugador, digite su numero de indentificacion: ";
                                        cin >> CedulaJ1;
                                        if(!cin.fail()){                        //If que valida la entrada de caracteres, estos condicionales para validar la entrada de datos fueron tomados de www.cristalab.com
                                            ok = true;                          //cita: (esutaraiki. 2010)
                                        } else {
                                            cin.clear();
                                            cin.ignore(256, '\n');
                                            cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                                        } if(CedulaJ1 > 999999999){
                                            cout << "\tEl numero de identificacion es muy grande..." << endl;
                                        } else if(CedulaJ1 < 100000000){
                                            cout << "\tEl numero de cedula es demasiado corto..." << endl;
                                        } else if(CedulaJ1 < 999999999 && CedulaJ1 > 100000000){
                                            cout << "\nJugador, digite su nombre: ";
                                            cin >> Jugador1;
                                            cout << "Bienvenido " << Jugador1 << " al juego sobre las partes del cuerpo humano" << endl;
                                        }
                                    }while(!ok);
                                }while(CedulaJ1 > 999999999 || CedulaJ1 < 100000000);
                                do{                                             //Do para validar que la cedula sea de 9 digitos ejemplo 604780269
                                    do{                                         //Do para validar que no se digiten caracteres en los espacions de la cedula del jugador 1 porque es entero
                                        cout << "\nJugador, digite su numero de indentificacion: ";
                                        cin >> CedulaJ2;
                                        if(!cin.fail()){                        //If que valida la entrada de caracteres
                                            ok = true;
                                        } else {
                                            cin.clear();
                                            cin.ignore(256, '\n');
                                            cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                                        } if(CedulaJ2 == CedulaJ1){
                                            cout << "\tEste numero de identificacion ya se encuentra registrado..." << endl;
                                        } else if(CedulaJ2 != CedulaJ1){
                                            if(CedulaJ2 > 999999999){
                                                cout << "El numero de identificacion es muy grande..." << endl;
                                            } else if(CedulaJ2 < 100000000){
                                                cout << "El numero de cedula es demasiado corto..." << endl;
                                            } else if(CedulaJ2 < 999999999 && CedulaJ2 > 100000000){
                                                cout << "\nJugador, digite su nombre: ";
                                                cin >> Jugador2;
                                                cout << "Bienvenido " << Jugador2 << " al juego sobre las partes del cuerpo humano" << endl;
                                            }
                                        }
                                    }while(!ok);
                                }while(CedulaJ2 > 999999999 || CedulaJ2 < 100000000 || CedulaJ2 == CedulaJ1);
                                 Archivo << CedulaJ1 << endl;   //Aca guardamos la cedula del jugador 1 en el archivo
                                 Archivo << Jugador1 << endl;   //Aca guardamos el nombre del jugador 1 en el archivo
                                 Archivo << CedulaJ2 << endl;   //Aca guardamos la cedula del jugador 2 en el archivo
                                 Archivo << Jugador2 << endl;   //Aca guardamos el nombre del jugador 1 en el archivo
                                 Archivo.close();break;         //Aca cerramos el archivo

                        case 2:
                            PuntosJ1 = 0;                                                                  //Cada vez que se registren nuevos jugadores estando dentro del juego su puntaje vuelve a ser 0
                            PuntosJ2 = 0;                                                                  //Cada vez que se registren nuevos jugadores estando dentro del juego su puntaje vuelve a ser 0
                                if(CedulaJ1 > 0 && CedulaJ1 > 0){                                          //If para condicionar que si ya se registraron los jugadores se procede con el juego
                                    system("pause"); system("cls");
                                        QuienSeraElJugador1y2(CedulaJ1, CedulaJ2, Jugador1, Jugador2, ok); //Funcion para validar quein sera el jugador 1 y el jugador 2
                                    system("pause"); system("cls");
                                        EvaluarRespuesta(Turno1, CedulaJ1, CedulaJ2, PuntosJ1, PuntosJ2, Jugador1, Jugador2); //Funcion para evaluar las respuestas de los jugadores
                                    system("pause"); system("cls");
                                } else if(CedulaJ1 <= 0 && CedulaJ2 <= 0){                                 //Si aun no se han registrado los jugadores todo el juego no se va a ejecutar hasta que se registren los jugadores
                                    cout << "\nPrimero debe de ingresar los datos de los jugadores..." << endl;
                                    cout << "" << endl;
                                }break;

                        case 3:
                            Jugador1 = Jugador1.substr(0, 3);          //Mosramos solo las primeras tres letras del nombre del jugador 1
                            Jugador2 = Jugador2.substr(0, 3);          //Mosramos solo las primeras tres letras del nombre del jugador 2
                            if(CedulaJ1 > 0 && CedulaJ2 > 0){          //If para condicionar que si ya se registraron los jugadores se procede con reportar los jugadores y sus cedulas
                                cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                                cout << "\272" << "  IDENTIFICACION " << right << setw(6) << "\272" << "  JUGADORES " << right << setw(12) << "\272" << endl;
                                cout << "\272" << "  " << CedulaJ1 << right << setw(12) << "\272" << "  " << Jugador1 << right << setw(19) << "\272" << endl;
                                cout << "\272" << "  " << CedulaJ2 << right << setw(12) << "\272" << "  " << Jugador2 << right << setw(19) << "\272" << endl;
                                cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                                system("pause");
                                system("cls");
                            } else if(CedulaJ1 <= 0 && CedulaJ2 <= 0){ //Si aun no se han registrado los jugadores todo el juego no se va a ejecutar hasta que se registren los jugadores
                                cout << "\nPrimero debe de ingresar los datos de los jugadores..." << endl; cout << "" << endl;
                            }break;

                        case 4:
                            Jugador1 = Jugador1.substr(0, 3); //Mosramos solo las primeras tres letras del nombre del jugador 1
                            Jugador2 = Jugador2.substr(0, 3); //Mosramos solo las primeras tres letras del nombre del jugador 2
                            if(CedulaJ1 > 0 && CedulaJ1 > 0){  //If para condicionar que si ya se registraron los jugadores se procede con reportar los jugadores y sus cedulas
                                cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
                                cout << "\272 Juegos  N.Identificacion  Jugadores   Puntos \272" << endl;
                                cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;

                                Archivo2.open("Puntos.txt", ios::in);   //Abrimos el archivo donde guardaremos los 5 primeros juegos
                                while(getline(Archivo2, Linea)){        //Leemos los datos que se encuentren en este archivo
                                    if(ContadorLineas < 11){            //If para solamente mostrar los 5 primeros juegos, cada juego contiene 2 jugadores y sus correspondietes puntajes 10 en total
                                    if(ContadorLineas == 1){            //Los siguientes if son para mostrar solo 5 juegos y acomodarlos en la tabla para una mejor estetica
                                        cout << "     [" << ContadorLineas << "]";
                                    } else if(ContadorLineas == 2){
                                        cout << "              ";
                                    } if(ContadorLineas == 3){
                                        cout << "     [" << ContadorLineas - 1 << "]";
                                    } else if(ContadorLineas == 4){
                                        cout << "              ";
                                    } if(ContadorLineas == 5){
                                        cout << "     [" << ContadorLineas - 2 << "]";
                                    } else if(ContadorLineas == 6){
                                        cout << "              ";
                                    } if(ContadorLineas == 7){
                                        cout << "     [" << ContadorLineas - 3 << "]";
                                    } else if(ContadorLineas == 8){
                                        cout << "              ";
                                    } if(ContadorLineas == 9){
                                        cout << "     [" << ContadorLineas - 4 << "]";
                                    } else if(ContadorLineas == 10){
                                        cout << "             ";
                                    }
                                        cout << "\t " << Linea << endl; //Imprimimos lo que el getline lea del archivo usando esta variable
                                    }
                                    ContadorLineas++;                   //Usamos un contador para leer linea por linea
                                }
                                Archivo2.close();                       //Cerramos el archivo
                                cout << endl;
                                } else if(CedulaJ1 <= 0 && CedulaJ2 <= 0){ //Si aun no se han registrado los jugadores todo el juego no se va a ejecutar hasta que se registren los jugadores
                                    cout << "\nPrimero debe de ingresar los datos de los jugadores..." << endl; cout << "" << endl;
                                }break;

                        case 5:
                            cout << "\n* Instrucciones: " << endl;
                            cout << "\t- Son 10 turnos para cada jugador, 20 turnos en total" << endl;
                            cout << "\t- Son 25 preguntas, las cuales son seleccionadas al azar" << endl;
                            cout << "\t- Todas las respuestas estan en minuscula, digiten sus respuestas tambien en minuscula" << endl;
                            cout << "\t- Los turno son de manera alternada" << endl;
                            cout << "\t- Se mostrara en el menu una tabla con los 5 primeros juegos asi que traten de darlo todo en los primeros juegos" << endl;
                            cout << "\t- Cada registro se reinicia cuando ingresen nuevos jugadores" << endl;
                            cout << "\nSuerte jugadores----EL CONOCIMIENTO ES UNA VIRTUD QUE NO MUCHOS POSEEN" << endl; cout << endl;break;

                        case 0:      //Case 0 para salir del menu y cerrar el programa
                            saliendo = true;
                            continuar = false;break;
                    }
                    if(!cin.fail()){ //If para validar que no se digiten caracteres en las opciones del menu
                            ok = true;
                    } else {
                        cin.clear();
                        cin.ignore(256,'\n');
                        cout << "Esto es un caracter, prueba con un numero..." << endl;
                    }
            }while(!ok);
        }while(saliendo == false);
    }while(continuar == true);
return 0;
}

void QuienSeraElJugador1y2(int CedulaJ1, int CedulaJ2, string Jugador1, string Jugador2, bool ok){ //Funcion para validar quein sera el jugador 1 y el jugador 2
 int BusCCedula1, BusCCedula2;
 string Lectura1, Lectura2, Lectura3, Lectura4;
 string Comprobacion1 = to_string(CedulaJ1), Comprobacion2 = to_string(CedulaJ2); //Las lecturas de los archivos se hacen en string y las variables de las cedulas son int asi que las pasamos a string para poder comparar

 ifstream Archivo;
 Archivo.open("Registros.txt", ios::in); //Abrimos el archivo para leer
     if(Archivo.fail()){                 //If por si la apertura del archivo falla el programa automaticamente termina
        cout << "No se pudo abrir el archivo..." << endl;
        exit(1);
     }

     if(!Archivo.eof()){     //If la apertura del programa es correcta se procede con lo siguiente
        Archivo >> Lectura1; //Leemos la primera linea del archivo
        Archivo >> Lectura2; //Leemos la segunda linea del archivo, esta no la necesitamos porque es el de nombre y ocupamos la cedula
        Archivo >> Lectura3; //Leemos la tercera linea del archivo
        Archivo >> Lectura4; //Leemos la cuarta linea del archivo esta no la necesitamos porque es el de nombre y ocupamos la cedula
        do{                  //Do para validar que la que la el numero de cedula que el jugador digita sea igual al primer numero de cedula ingresado
            do{              //Do para validar la entrada de caracteres a un int
                cout << "\nQUE TANTO SABES SOBRE EL CUERPO HUMANO" << endl;
                cout << "Quien sera el jugador [1]...Ingrese su numero de identificacion: ";
                cin >> BusCCedula1;
                if(!cin.fail()){    //If para validar la entrada de caracteres a un int
                        ok = true;
                    } else {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                    }
                    if(Lectura1 == Comprobacion1){                     //Si la lectura en la primera linea del archivo es igual a la cedula del jugador 1 se hace lo sigueinte
                        if(to_string(BusCCedula1) != Comprobacion1){   //Si el numero de cedula que el jugador digito es igual al numero de cedula en la primera linea del archivo este sera el jugador 1
                            cout << "El numero de identificacion no esta registrado intenta con otro..." << endl;
                        } else if(to_string(BusCCedula1) == Lectura1){ //Sino se repetira hasta que sea igual
                            cout << "\nFelicidades " << Lectura2 << " tu eres el jugador [1]..." << endl;
                        }
                    }
            }while(!ok);
        }while(to_string(BusCCedula1) != Lectura1);
        do{                  //Do para validar que la que la el numero de cedula que el jugador digita sea igual al primer numero de cedula ingresado
            do{              //Do para validar la entrada de caracteres a un int
                cout << "\nQUE TANTO SABES SOBRE EL CUERPO HUMANO" << endl;
                cout << "Quien sera el jugador [2]...Ingrese su numero de identificacion: ";
                cin >> BusCCedula2;
                if(!cin.fail()){    //If para validar la entrada de caracteres a un int
                        ok = true;
                    } else {
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "\tEsto es un caracter, prueba con un numero..." << endl;
                    }
                    if(Lectura3 == Comprobacion2){                     //Si la lectura en la tercera linea del archivo es igual a la cedula del jugador 1 se hace lo sigueinte
                        if(to_string(BusCCedula2) != Comprobacion2){   //Si el numero de cedula que el jugador digito es igual al numero de cedula en la tercera linea del archivo este sera el jugador 2
                            cout << "El numero de identificacion no esta registrado intenta con otro..." << endl;
                        } else if(to_string(BusCCedula2) == Lectura3){ //Sino se repetira hasta que sea igual
                            cout << "\nFelicidades " << Lectura4 << " tu eres el jugador [2]..." << endl;
                        }
                    }
            }while(!ok);
        }while(to_string(BusCCedula2) != Lectura3);
    }
}

void EvaluarRespuesta(int Turno1, int CedulaJ1, int CedulaJ2, int PuntosJ1, int PuntosJ2, string Jugador1, string Jugador2){ //Funcion para evaluar respuestas y lecturas
int SeguirJugando;                             //Variable para validar si desena terminar el juego antes de los 10 tuenos
    while(Turno1 <= 10){                       //While que repite el juego hasta que se hayan completado los 10 turnos para cada jugador
    JuegoJugador1(Turno1, PuntosJ1);           //Funcion que muestra al jugador, los turnos y el numero de aciertos
        ifstream Archivo;
        Archivo.open("Preguntas.txt",ios::in); //Abrimos el archivo de preguntas para comenzar con el juego
            int Contador = 1, Respuestas[25], Preguntas[25], LlenarR = 2, LlenarP = 3, NumAleatorio = 1 + rand() % 24, NumAleatorio2 = 0;
            int Contador2 = 1, Respuestas2[25], Preguntas2[25], LlenarR2 = 2, LlenarP2 = 3;
            string Linea, Leer = "", Pregunta = "", RespuestaALAPregunta = "", Leer2 = "", Pregunta2 = "", RespuestaALAPregunta2 = "";
            for(int i = 1; i < 26; i++){       //Las respuestas a las preguntas estan a cada tres lineas por eso llenamos este vector cada tres posiciones para despues guardar las respuestas en el
                Respuestas[i] = LlenarR;
                LlenarR+=3;
            } for(int j = 1; j < 26; j++){     //Las preguntas del juego estan a cada tres lineas por eso llenamos este vector cada tres posiciones para despues guardar las respuestas en el
                Preguntas[j] = LlenarP;
                LlenarP+=3;
            }
            while(getline(Archivo, Linea)) {                     //Leemos el archivo de las preguntas
                if(NumAleatorio == 1){                           //Estos if son para escoger preguntas aleatorioas
                    if(Respuestas[1] == Contador){               //Muy importantes aca igualamos este vector en la posicion[1] con el contador, LlenarR empieza en 2 por eso cuando el vector en la posicion[1] osea el 2 sea igual al contador vamos a guardar esa linea del archivo en una variable
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[1] == Contador){              //Muy importantes aca igualamos este vector en la posicion[1] con el contador, LlenarP empieza en 3 por eso cuando el vector en la posicion[1] osea el 3 sea igual al contador vamos a guardar esa linea del archivo en una variable
                        Pregunta = Linea; cout << Linea << endl; //Y siempre en todos los ssiguientes if imprimimos la preguntas, todo lo anterior pasa con los siguientes if, asi que no hace falta comentarlos
                    }
                } else if(NumAleatorio == 2){
                    if(Respuestas[2] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[2] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 3){
                    if(Respuestas[3] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[3] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 4){
                    if(Respuestas[4] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[4] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 5){
                    if(Respuestas[5] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[5] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 6){
                    if(Respuestas[6] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[6] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 7){
                    if(Respuestas[7] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[7] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 8){
                    if(Respuestas[8] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[8] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 9){
                    if(Respuestas[9] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[9] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 10){
                    if(Respuestas[10] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[10] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 11){
                    if(Respuestas[11] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[11] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 12){
                    if(Respuestas[12] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[12] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 13){
                    if(Respuestas[13] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[13] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 14){
                    if(Respuestas[14] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[14] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 15){
                    if(Respuestas[15] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[15] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 16){
                    if(Respuestas[16] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[16] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 17){
                    if(Respuestas[17] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[17] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 18){
                    if(Respuestas[18] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[18] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 19){
                    if(Respuestas[19] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[19] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 20){
                    if(Respuestas[20] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[20] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 21){
                    if(Respuestas[21] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[21] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 22){
                    if(Respuestas[22] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[22] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 23){
                    if(Respuestas[23] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[23] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 24){
                    if(Respuestas[24] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[24] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio == 25){
                    if(Respuestas[25] == Contador){
                       RespuestaALAPregunta = Linea;
                    } if(Preguntas[25] == Contador){
                        Pregunta = Linea; cout << Linea << endl;
                    }
                }
                Contador++;                              //Llevamos un contador para contar linea por linea dentro del archivo
            } cout << "\nJugador cual es la respuesta a esta pregunta? : ";
              cin >> Leer;
                if(Leer == RespuestaALAPregunta){        //Comparamos si la respuesta que el jugador nos da es igual a la variable que almacena la repuesta pasa lo siguiente
                    cout << "La respuesta es correcta..." << endl;
                    NumAleatorio2 = 1 + rand() % 24;     //Esto es muy importante porque si el jugador contesta correctamente la pregunta, se crea un nuevo numero aleatorio para elegir el numero de pregunta del jugador 2
                    PuntosJ1++;
                } else if(Leer != RespuestaALAPregunta){ //Si el jugador 1 falla la pregunta, el numero aleatorio del jugador 2 sera igual al del jugador 1, por ende le correspondera contestar la misma pregunta
                    cout << "La respuesta es incorrecta..." << endl;
                    NumAleatorio2 = NumAleatorio;
                }
        Archivo.close(); //Cerramos el archivo

        JuegoJugador2(Turno1, PuntosJ2); //Funcion que muestra al jugador 2, su turno y su numero de aciertos, todo lo demas es igual y funciona igual que el codigo anterior asi que no lo vamos a comentar
        ifstream Archivo2;
        Archivo2.open("Preguntas.txt",ios::in); //Leemos lo que hay dentro del archivo de preguntas
            for(int i = 1; i < 26; i++){
                Respuestas2[i] = LlenarR2;
                LlenarR2+=3;
            } for(int j = 1; j < 26; j++){
                Preguntas2[j] = LlenarP2;
                LlenarP2+=3;
            }
            while(getline(Archivo2, Linea)) {
                if(NumAleatorio2 == 1){
                    if(Respuestas2[1] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[1] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 2){
                    if(Respuestas2[2] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[2] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 3){
                    if(Respuestas2[3] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[3] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 4){
                    if(Respuestas2[4] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[4] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 5){
                    if(Respuestas2[5] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[5] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 6){
                    if(Respuestas2[6] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[6] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 7){
                    if(Respuestas2[7] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[7] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 8){
                    if(Respuestas2[8] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[8] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 9){
                    if(Respuestas2[9] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[9] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 10){
                    if(Respuestas2[10] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[10] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 11){
                    if(Respuestas2[11] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[11] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 12){
                    if(Respuestas2[12] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[12] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 13){
                    if(Respuestas2[13] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[13] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 14){
                    if(Respuestas2[14] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[14] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 15){
                    if(Respuestas2[15] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[15] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 16){
                    if(Respuestas2[16] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[16] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 17){
                    if(Respuestas2[17] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[17] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 18){
                    if(Respuestas2[18] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[18] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 19){
                    if(Respuestas2[19] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[19] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 20){
                    if(Respuestas2[20] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[20] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 21){
                    if(Respuestas2[21] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[21] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 22){
                    if(Respuestas2[22] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[22] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 23){
                    if(Respuestas2[23] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[23] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 24){
                    if(Respuestas2[24] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[24] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                } else if(NumAleatorio2 == 25){
                    if(Respuestas2[25] == Contador2){
                       RespuestaALAPregunta2 = Linea;
                    } if(Preguntas2[25] == Contador2){
                        Pregunta2 = Linea; cout << Linea << endl;
                    }
                }
                Contador2++;
            } cout << "\nJugador cual es la respuesta a esta pregunta? : ";
              cin >> Leer2;
                if(Leer2 == RespuestaALAPregunta2){ //Si el jugador 2 hacierta la pregunta suma puntos igual que como el jugador 1
                    cout << "La respuesta es correcta..." << endl;
                    PuntosJ2++;
                } else if(Leer2 != RespuestaALAPregunta2){
                    cout << "La respuesta es incorrecta..." << endl;
                }
        Archivo2.close(); //Cerramos el archivo
        Turno1++;         //Contamos los turnos de ambos jugadores
        do{               //Este do es para verificar que solo se acepten el 1 o el 0 como entrada
            cout << "Desea seguir jugando? [1/0] : ";
            cin >> SeguirJugando;
            if(SeguirJugando > 1 || SeguirJugando < 0){ //If para validar que solo se acepte el 1 o el 0 como entrada
                cout << "La opcion que acabas de digitar es invalida..." << endl;
            }
        }while(SeguirJugando > 1 || SeguirJugando < 0);
        if(SeguirJugando == 1){                         //Si la entrada es igual a 1, el juego continua hasta que se cumplan los 10 tuenos para cada uno, esto pasa al final de cada turno despues que ambos jugadores hayan respondido su pregunta
            cout << "\nEn ora buena continuamos con la siguiente ronda..." << endl;
        } else if(SeguirJugando == 0){                  //Sino si la entrada es 0 es valor de la variable turno sera igual a 11 y el bucle finalizara
            Turno1 = 11;
        }
        system("pause"); system("cls");
    }
    Ganador(PuntosJ1, PuntosJ2, Jugador1, Jugador2);    //Funcion para mostrar en pantalla si hay un ganador o si hay un empate entre los jugadores

    fstream Puntajes;
    Puntajes.open("Puntos.txt", ios::app);              //Esto es muy improtante ya que para mostrar los 5 primeros juegos debemos de añadir nuevos datos y no sobreescribirlos asi que para poder hacer esto usamos ios::app
        Puntajes << CedulaJ1;                           //Guardamos la cedula del jugador 1
        Puntajes << "       " << Jugador1;              //Guardamos el nombre del jugador 1 con espacios antes para que en la lectura aparescan previamente ordenado
        Puntajes << "      " << PuntosJ1 << endl;       //Guardamos los puntos del jugador 1 con espacios antes para que en la lectura aparescan previamente ordenado
        Puntajes << CedulaJ2;                           //Guardamos la cedula del jugador 2
        Puntajes << "       " << Jugador2;              //Guardamos el nombre del jugador 2 con espacios antes para que en la lectura aparescan previamente ordenado
        Puntajes << "      " << PuntosJ2 << endl;       //Guardamos los puntos del jugador 2 con espacios antes para que en la lectura aparescan previamente ordenado
    Puntajes.close();
}

void JuegoJugador1(int Turno1, int PuntosJ1){ //Funcion para mostrar en pantalla el jugador que esta en curso, en este caso el jugador 1
    if(Turno1 < 10){ //Estos if son para condicionar los turnos y evitar que cuando sea un numero de dos cifras osea(10) descuadre la tabla de muestra
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272  Jugador[1]" << right << setw( 20 ) << "Turno: " << Turno1 << right << setw( 30 ) << "Numero de asiertos: " << PuntosJ1 << right << setw(3) << "\272"<< endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    } else if(Turno1 == 10){ // Cunco sea 10 se le quita un 1 a el primer setw
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272  Jugador[1]" << right << setw( 19 ) << "Turno: " << Turno1 << right << setw( 30 ) << "Numero de asiertos: " << PuntosJ1 << right << setw(3) << "\272"<< endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    }
}

void JuegoJugador2(int Turno1, int PuntosJ2){ //Funcion para mostrar en pantalla el jugador que esta en curso, en este caso el jugador 1
     if(Turno1 < 10){ //Estos if son para condicionar los turnos y evitar que cuando sea un numero de dos cifras osea(10) descuadre la tabla de muestra
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272  Jugador[2]" << right << setw( 20 ) << "Turno: " << Turno1 << right << setw( 30 ) << "Numero de asiertos: " << PuntosJ2 << right << setw(3) << "\272"<< endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    } else if(Turno1 == 10){ // Cunco sea 10 se le quita un 1 a el primer setw
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272  Jugador[2]" << right << setw( 19 ) << "Turno: " << Turno1 << right << setw( 30 ) << "Numero de asiertos: " << PuntosJ2 << right << setw(3) << "\272"<< endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    }
}

void Ganador(int PuntosJ1, int PuntosJ2, string Jugador1, string Jugador2){ //Funcion para mostrar el ganador o si hay un empate entre jugadores
    if(PuntosJ1 > PuntosJ2){                                                //Si los puntos del jugador 1 son mayores que los del jugador 2 gana el jugador 1
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272     ---EN ORA BUENA TENEMOS UN GANADOR--- " << right << setw(4) << "\272" << endl;
        cout << "\272 El JUGADOR GANADOR ES : " << Jugador1 << right << setw(19) << "\272" << endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    } else if(PuntosJ2 > PuntosJ1){                                         //Si los puntos del jugador 2 son mayores que los del jugador 1 gana el jugador 2
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272     ---EN ORA BUENA TENEMOS UN GANADOR--- " << right << setw(4) << "\272" << endl;
        cout << "\272 El JUGADOR GANADOR ES : " << Jugador2 << right << setw(19) << "\272" << endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    } else if(PuntosJ2 == PuntosJ1){                                        //Si los puntos son iguales entre jugadores hay un empate
        cout << "\n\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
        cout << "\272     ---EN ORA BUENA TENEMOS UN EMPATE--- " << right << setw(5) << "\272" << endl;
        cout << "\272 LOS JUGADORES EMPATADOS SON : " << Jugador1 << " y " << Jugador2 << right << setw(7) << "\272" << endl;
        cout << "\270\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\270" << endl;
    }
}
/* Referencias Bibliograficas:
esutoraiki. (29 de noviembre del 2010). Validacion de tipos de datos en C++. www.cristalab.com https://www.cristalab.com/tutoriales/validacion-de-tipos-de-datos-en-c--c92149l/*/
