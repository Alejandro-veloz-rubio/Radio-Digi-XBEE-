//Creación de la variable global de nuestra trama
uint8_t frame[] = {0x7E, 0x00, 0x39,
0x81,0x33,0x33,0x39,0x01,0x45,0x73,0x74,0x65,0x20,0x65,0x73,0x20,0x65,
0x6C,0x20,0x65,0x71,0x75,0x69,0x70,0x6F,0x20,0x33,0x20,0x64,0x65,0x20,
0x35,0x43,0x20,0x79,0x20,0x73,0x61,0x62,0x65,0x6D,0x6F,0x73,0x20,0x70,
0x72,0x6F,0x67,0x72,0x61,0x6D,0x61,0x72,0x20,0x65,0x6E,0x20,0x43,0x2B,
0x2B, 0xA3};
uint8_t lengthMessage = (0xFF*frame[1])+frame[2]; //Creación de la longitud de mensaje
struct { //Creación del struct
    int MAC[]={}; //Creación de la variable que retorna la mac (array)
    int LENGTH; //Declaración de la variable length que retorna (int)
    int OPTION; //Declaración de la variable option que retorna (int)
    int RSSI; //Declaración de la variable RSSI (calidad de la señal) que retorna (int)
    string PAYLOAD; //Declaración de la variable payload que retorna (string)
    string CHECKSUM; //Declaración de la variable checksum que retorna (string)
}_16_BIT_RECEIVE_PACKET; //Declaracion del nombre de la estructura

int binary(int num){//función llamada "binary" que retorna un valor entero, con un parámetro de entrada llamado "num" de tipo entero con valor de 4700
int sumadec=0;//variable llamada "sumadec" de tipo entero inicializada en 0
int expo=0;//variable llamada "expo" de tipo entero inicializada en 0

//nuestro ciclo for iniciara en 1 y se repetirá 8 veces, esto porque solo queremos los 8 bits menos significativos del parametro "num"
for(int i=1;i<=8;i++){
    if(num % 2 == 0){//se crea una condición donde si el residuo de "num" entre 2 es igual a 0
    sumadec+=(0*pow(2.0,expo));//cero se multiplicará por 2^al valor de la variable "expo" y el resultado de este proceso se sumará en cada ciclo a la variable "sumadec", la función "pow()" permite exponencializar un valor.
    expo++;//nuestra variable "expo" incrementará de uno en uno
        }else{//si no se cumple nuestra función anterior
            sumadec+=(1*pow(2.0,expo));//uno se multiplicará por 2^al valor de la variable "expo" y el resultado de este proceso se sumará en cada ciclo a la variable "sumadec"
            expo++;//nuestra variable "expo" también incrementará de uno en uno con cada ciclo que pase
        };
    num /= 2;// final en cada ciclo el valor de nuestra variable "num" se dividirá entre 2
}
    return sumadec;// cuando el ciclo for finalice regresará el valor de la variable "sumadec" que en este caso es en decimal 92 traducido en binario seria 01011100
}

class IEEE_802_15_4 { //Creación de la clase IEEE_802_15_4 pública
    public:
        void GET_MAC(); //Creación de la función GET_MAC en la clase IEEE_802_15_4
        void GET_LENGTH(); //Creación de la funcion GET_LENGTH en la clase IEEE_802_15_4

        void GET_OPTION(); //Creación de la funcion GET_OPTION en la clase IEEE_802_15_4
        void GET_RSSI(); //Creación de la función GET_RSSI en la clase IEEE_802_15_4
        void GET_PAYLOAD(); //Creación de la función GET_PAYLOAD en la clase IEEE_802_15_4
        void CHECKSUM(); //Creacion de la función CHECKSUM en la clase IEEE_802_15_4
};
void IEEE_802_15_4::GET_MAC(){ //Obtiene la función GET_MAC() de la clase IEEE_802_15_4
    printf("%x-", frame[4]); //Imprime en formato la posicion 4 de nuestro array frame
    printf("%x", frame[5]); //Imprime en formato la posicion 4 de nuestro array frame
    _16_BIT_RECEIVE_PACKET.MAC[0]=frame[4]; //Manda a llamar la estructura e iguale el valor retornado con la variable de la estructura
    _16_BIT_RECEIVE_PACKET.MAC[1]=frame[5]; //Manda a llamar la estructura e iguale el valor retornado con la variable de la estructura
}
void IEEE_802_15_4::GET_LENGTH(){ //Obtiene la función GET_LENGTH() de la clase IEEE_802_15_4
    printf("%d",lengthMessage); //Imprime en formato la variable lengthMessage
    _16_BIT_RECEIVE_PACKET.LENGTH=lengthMessage; //Manda a llamar la estructura e iguala el valor retornado con la variable retornada
}

void IEEE_802_15_4::GET_OPTION(){ //Obtiene la función GET_OPTION() de la clase IEEE_802_15_4
    if (frame[3]==0x81){ //Se hace una sentencia if para: si nuestra posición 3 del array es igual a 0x81 mandé que es de 16 bits y si no que mande que es de diferente tipo
    cout << "16-bit Receive Packet"; //Salida de texto que dice que es de 16 bits
    }
     else { //Sentencia else por si no cumple con el if
            cout << "Different Type of Packet Received"; //Salida de texto por consola que dice que es de diferente tipo
        }
    _16_BIT_RECEIVE_PACKET.OPTION=frame[3]; //Manda a llamar la estructura e iguale el valor retornado con la variable de la estructura
}
void IEEE_802_15_4::GET_RSSI(){ //Obtiene la función GET_RSSI() de la clase IEEE_802_15_4
    int rssi=frame[6]; //Declaración de la variable (int) rssi que se iguala con la posición 6 del vector
    cout<< "-"<<rssi<<" dBm"; //Salida de texto por consola de la calidad del paquete
    _16_BIT_RECEIVE_PACKET.RSSI=rssi; //Manda a llamar la estructura e iguale el valor retornado con la variable de la estructura
}
void IEEE_802_15_4::GET_PAYLOAD(){ //Obtiene la función GET_PAYLOAD() de la clase IEEE_802_15_4
string frame2=" "; //Declaración de la variable (string) frame2
for(int i=8; i<=lengthMessage+2; i++){ //Creación del ciclo for que va a recorrer desde la posicion 8 del vector hasta la longitud de la variable lengthMessage +2
    cout <<frame[i]; //Salida de texto por consola
    frame2+=frame[i]; //Concatenación de frame2 y frame
}
_16_BIT_RECEIVE_PACKET.PAYLOAD=frame2; //Manda a llamar la estructura e iguala el valor retornado con la variable retornada
}

//definicion del metodo "CHECKSUM()" de la clase "IEEE_802_15_4" que nos permite comprobar si nuestra trama está corrupta o no
void IEEE_802_15_4::CHECKSUM(){
    int valor=0xFF,resta;//el variable "valor" vale 255 en decimal y 0xFF en hexadecimal,
    //se crea una variable llamada "resta" de tipo entero
    uint8_t chectrama=frame[60];//se crea una variable de tipo sin signo de 8 bits,en donde tomamos el último valor del array "frame",con valor en decimal de 163 y en hexadecimal de A3
    int suma=0;//variable de tipo entero llamada "suma" inicializada en 0
    //se crea un ciclo for que irá sumando cada elemento del array "frame" iniciando desde la posición 3 del array "frame" a la posición 59 del array "frame"
    for(int i = 3; i<=lengthMessage+2;i++){
        suma+=frame[i];//cada valor del array "frame" se suma en decimal a la variable "suma"
    }
    int bms=binary(suma);//se crea una variable del tipo entera "bms" que se valor será igual al rectorado por la función "binary" pasando como parametro la variable "suma"(DEC:4700,HEX:125C,BIN:1 00100101 1100), que es la suma total de todos los valores correspondientes del array "frame".
    resta=valor-bms; // la variable resta albergará el resultado de la resta de la variable "valor" menos "bms",( dec:255-92=163, HEX: FF-5C=A3.)
    if(resta==chectrama){// se establece una condición donde si el valor de la variable "resta"(DEC:163,HEX:A3), es igual a el valor de la variable "chectrama"(DEC:163,HEX:A3) regresará el siguiente mensaje "TRUE: TRAMA NO CORRUPTA"
        cout<<"TRUE: TRAMA NO CORRUPTA"<<endl;
        _16_BIT_RECEIVE_PACKET.CHECKSUM="true"; // ademas guardará en nuestra estructura "_16_BIT_RECEIVE_PACKET", en la variable "CHECKSUM", el string "true"
    }
        else{//si no se cumple la condición anterior mostrará el siguiente mensaje "FALSE: TRAMA CORRUPTA"
        cout<<"FALSE: TRAMA CORRUPTA"<<endl;
        _16_BIT_RECEIVE_PACKET.CHECKSUM="false"; //y se guardará en nuestra estructura "_16_BIT_RECEIVE_PACKET", en la variable "CHECKSUM",el string "false"
        }
}