#include<conio.h> //librería para ingresar datos por teclado usando getch()
#include <stdint.h> //libreria para usar variables de tipo entero ,"uint8_t", en nuestro archivo IEEE_802_15_4.h
#include <iostream> //librería para ejecutar nuestro programa
#include <string>//libreria para usar strings
#include <cmath>//libreria para usar funciones matemáticas como en este código poder elevar un valor a determinada potencia
using namespace std;//
#include "IEEE_802_15_4.h"//incluimos nuestra librería local llamada IEEE_802_15_4.h en la cual contendrá un clase con los metodos para regresar

//regresar la dirección MAC, la longitud del mensaje, tipo de trama , el mensaje oculto, y corroborar si nuestro mensaje esta oculto
IEEE_802_15_4 obj;//creamos nuestra instancia de nombre "obj" de la clase IEEE_802_15_4 con el nombre "obj"
    int main() // la función principal que nos permitirá ejecutar nuestro codigo
{
int opcion; //variable donde guardaremos nuestros valores insertados por medio del teclado

//se crea un ciclo do while, en donde primero ejecutaremos nuestro codigo y despues con la condicional ejecutaremos de nuevo nuestro código
do{
//mostramos las siguientes opciones con el fin de que el usuario pueda escoger que desea ver de la trama o si desea salir del menú
    cout << "1. Mostrar direccion MAC de origen." <<endl;//muestra dirección MAC
    cout << "2. Mostrar longitud de mensaje." << endl;//muestra longitud de mensaje
    cout << "3. Mostrar tipo de trama o paquete." <<endl;//muestra tipo de trama
    cout << "4. Mostrar la calidad de la senal." << endl;//muestra la calidad de la senal
    cout << "5. Mostrar mensaje." << endl;//muestra el mensaje oculto
    cout << "6. Mostrar si el paquete esta corrupto." << endl;// mostrar si nuestro paquete está corrupto
    cout << "0. Salir" << endl << endl;//salir del menú
    opcion=getch();//nuestros valores insertados por el teclado se
    guardarán en la variable opción
switch(opcion)//creamos un switch-case en el cual si el valor de la variable opción se encuentra la tomara en caso de que no mostrara un
//mensaje "entrada no válida"
{
    case '1'://en caso de ser 1
        cout << "Mostrando direccion MAC de origen:" << endl;//mostrara este mensaje
        obj.GET_MAC();//llamará al método GET_MAC() en la clase IEEE_802_15_4
        cout<< endl << endl; //saltos de línea
        break;//rompe el case 1
    case '2'://en caso de ser 2
        cout << "Mostrando longitud de mensaje:" << endl;//mostrará este mensaje
        obj.GET_LENGTH();//llamará al método GET_LENGTH() en la clase IEEE_802_15_4
        cout<< endl << endl;//saltos de línea
        break;//rompe el case 2
    case '3'://en caso de ser 3
        cout << "Mostrando tipo de trama o paquete:" << endl;//mostrará este mensaje
        obj.GET_OPTION();//llamará al método GET_OPTION() en la clase IEEE_802_15_4
        cout<< endl << endl;//saltos de línea
        break;//rompe el case 3
    case '4'://en caso de ser 4
        cout << "Mostrando la calidad de la senal:" << endl;//mostrará este mensaje
        obj.GET_RSSI();//llamará al método GET_RSSI() en la clase IEEE_802_15_4
        cout<< endl << endl;//saltos de línea
        break;//rompe el case 4
    case '5'://en caso de ser 5
        cout << "Mostrando mensaje:" << endl;//mostrará este mensaje
        obj.GET_PAYLOAD();//llamará al método GET_PAYLOAD() en la clase IEEE_802_15_4
        cout<< endl << endl;//saltos de línea
        break;//rompe el case 5
    case '6'://en caso de ser 6
        cout << "Mostrando si el paquete esta corrupto:" << endl;//mostrará este mensaje
        obj.CHECKSUM();//llamará al método CHECKSUM() en la clase IEEE_802_15_4
        cout<< endl << endl;//saltos de linea
        break;//rompe el case 6
    case '0'://en caso de ser 0
        return 0;//retorna a 0 la función main y lo termina la ejecucion del programa
        default://en caso de insertar un valor que no esté contemplado dentro de nuestra condición while
        cout << "Selección no valida" << endl << endl;//mostrará el siguiente mensaje
        break;//rompe el case 0
}
    }while(opcion>=1 || opcion<=5);//mientras nuestro valor insertado mayor o igual a 1 o menor o igual a 5 se repetirá el ciclo do-while
}