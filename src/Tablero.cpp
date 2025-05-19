#include <iostream>
#include <string>
#include "colors.h"
#include <map>

using namespace std;
class Tablero {

    public:
        map<pair<int,int>, string> tablero;
        //string paleta[7] = {BG_RED, BG_BLUE, BG_GREEN, BG_MAGENTA, BG_GRAY, BG_ORANGE, BG_BLACK};
        
        
        void mostrarTablero();
        void inicializarTablero();      
};

void Tablero::inicializarTablero(){
    
    for (int fila = 1; fila <= 14; ++fila) {
        for (int col = 1; col <= 20; ++col) {
            tablero[{fila, col}] = BG_WHITE;
        }
    }
    
    
    //intersecciones
    //A B rojo
    tablero[{5,1}] = BG_RED;
    tablero[{5,2}] = BG_RED;
    tablero[{6,1}] = BG_RED;
    tablero[{7,1}] = BG_RED;

    //A F azul
    tablero [{8,2}] = BG_BLUE;
    tablero [{8,3}] = BG_BLUE;
    tablero [{8,4}] = BG_BLUE;
    tablero [{8,5}] = BG_BLUE;

    //D E gris, remplaza el marron
    tablero[{1,5}] = BG_GRAY;
    tablero[{1,6}] = BG_GRAY;
    tablero[{2,6}] = BG_GRAY;
    tablero[{3,6}] = BG_GRAY;

    //E F verde
    tablero[{5,6}] = BG_GREEN;
    tablero[{6,6}] = BG_GREEN;
    tablero[{7,6}] = BG_GREEN;
    
    //F G naranja
    tablero[{9,6}] = BG_ORANGE;
    tablero[{10,6}] = BG_ORANGE;
    tablero[{11,6}] = BG_ORANGE;

    //C G gris
    tablero[{12,5}] = BG_GRAY;
    tablero[{12,4}] = BG_GRAY;
    tablero[{12,3}] = BG_GRAY;
    tablero[{13,3}] = BG_GRAY;

    //F H naranja
    tablero[{8,7}] = BG_ORANGE;
    tablero[{8,8}] = BG_ORANGE;
    tablero[{8,9}] = BG_ORANGE;

    //H L rojo
    tablero[{9,10}] = BG_RED;
    tablero[{10,10}] = BG_RED;
    tablero[{11,10}] = BG_RED;
    tablero[{12,10}] = BG_RED;
    tablero[{12,11}] = BG_RED;
    tablero[{12,12}] = BG_RED;

    //H K azul
    tablero[{8,11}] = BG_BLUE;
    tablero[{8,12}] = BG_BLUE;

    //K L naranja
    tablero[{9,13}] = BG_ORANGE;
    tablero[{10,13}] = BG_ORANGE;
    tablero[{11,13}] = BG_ORANGE;

    //K I morado
    tablero[{7,13}] = BG_MAGENTA;
    tablero[{6,13}] = BG_MAGENTA;
    tablero[{6,12}] = BG_MAGENTA;
    tablero[{6,11}] = BG_MAGENTA;

    //I O azul
    tablero[{4,11}] = BG_BLUE;
    tablero[{4,12}] = BG_BLUE;
    tablero[{4,13}] = BG_BLUE;
    tablero[{4,14}] = BG_BLUE;
    tablero[{4,15}] = BG_BLUE;
    tablero[{4,16}] = BG_BLUE;

    //J N naranja
    tablero[{2,13}] = BG_ORANGE;
    tablero[{2,14}] = BG_ORANGE;

    //N O verde
    tablero[{2,16}] = BG_GREEN;
    tablero[{2,17}] = BG_GREEN;
    tablero[{3,17}] = BG_GREEN;

    //O P naranja
    tablero[{5,17}] = BG_ORANGE;
    tablero[{6,17}] = BG_ORANGE;
    tablero[{7,17}] = BG_ORANGE;

    //K P verde
    tablero[{8,14}] = BG_GREEN;
    tablero[{8,15}] = BG_GREEN;
    tablero[{8,16}] = BG_GREEN;

    //P Q verde
    tablero[{9,17}] = BG_GREEN;
    tablero[{10,17}] = BG_GREEN;
    tablero[{11,17}] = BG_GREEN;

    //M Q morado
    tablero[{13,17}] = BG_MAGENTA;
    tablero[{14,17}] = BG_MAGENTA;
    tablero[{14,16}] = BG_MAGENTA;
    tablero[{14,15}] = BG_MAGENTA;

    //Q S gris
    tablero[{12,18}] = BG_GRAY;
    tablero[{12,19}] = BG_GRAY;
    tablero[{12,20}] = BG_GRAY;
    tablero[{11,20}] = BG_GRAY;

    //O R morado
    tablero[{4,18}] = BG_MAGENTA;
    tablero[{4,19}] = BG_MAGENTA;
    tablero[{4,20}] = BG_MAGENTA;
    tablero[{5,20}] = BG_MAGENTA;


}



void Tablero::mostrarTablero(){

    for (int fila = 1; fila <= 14; ++fila) {
        for (int col = 1; col <= 20; ++col) {
            cout << tablero[{fila, col}]<< "  " <<RESET;// dos espacios el tamano
            //cout << "a";
        }
        cout << endl;
    }


}