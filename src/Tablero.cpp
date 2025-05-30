#include <iostream>
#include <string>
#include <map>
#include <utility>

#include "colors.h"


using namespace std;
class Tablero {

    public:
        map<pair<int,int>, pair<string, string>> tablero;



        void mostrarTablero();
        void inicializarTablero();
        void marcarTrayecto(string origen, string destino, char jugadorID);
};



void Tablero::inicializarTablero(){

    for (int fila = 1; fila <= 14; ++fila) {
        for (int col = 1; col <= 20; ++col) {
            tablero[{fila, col}] = {BG_WHITE, "   "};
        }
    }


    //A
    tablero[{8,1}] = {BG_BLACK, " A "};
    //B
    tablero[{5,3}] = {BG_BLACK, " B "};
    //C
    tablero[{14,3}] = {BG_BLACK, " C "};
    //D
    tablero[{1,4}] = {BG_BLACK, " D "};
    //E
    tablero[{4,6}] = {BG_BLACK, " E "};
    //F
    tablero[{8,6}] = {BG_BLACK, " F "};
    //G
    tablero[{12,6}] = {BG_BLACK, " G "};
    //H
    tablero[{8,10}] = {BG_BLACK, " H "};
    //I
    tablero[{5,11}] = {BG_BLACK, " I "};
    //J
    tablero[{2,12}] = {BG_BLACK, " J "};
    //K
    tablero[{8,13}] = {BG_BLACK, " K "};
    //L
    tablero[{12,13}] = {BG_BLACK, " L "};
    //M
    tablero[{14,14}] = {BG_BLACK, " M "};
    //N
    tablero[{2,15}] = {BG_BLACK, " N "};
    //O
    tablero[{4,17}] = {BG_BLACK, " O "};
    //P
    tablero[{8,17}] = {BG_BLACK, " P "};
    //Q
    tablero[{12,17}] = {BG_BLACK, " Q "};
    //R
    tablero[{6,20}] = {BG_BLACK, " R "};
    //S
    tablero[{10,20}] = {BG_BLACK, " S "};


    //intersecciones
    //A B rojo
    tablero[{5,1}] = {BG_RED, "   "};
    tablero[{5,2}] = {BG_RED, "   "};
    tablero[{6,1}] = {BG_RED, "   "};
    tablero[{7,1}] = {BG_RED, "   "};

    //A F azul
    tablero [{8,2}] = {BG_BLUE, "   "};
    tablero [{8,3}] = {BG_BLUE, "   "};
    tablero [{8,4}] = {BG_BLUE, "   "};
    tablero [{8,5}] = {BG_BLUE, "   "};

    //D E gris, remplaza el marron
    tablero[{1,5}] = {BG_GRAY, "   "};
    tablero[{1,6}] = {BG_GRAY, "   "};
    tablero[{2,6}] = {BG_GRAY, "   "};
    tablero[{3,6}] = {BG_GRAY, "   "};

    //E F verde
    tablero[{5,6}] = {BG_GREEN, "   "};
    tablero[{6,6}] = {BG_GREEN, "   "};
    tablero[{7,6}] = {BG_GREEN, "   "};

    //F G naranja
    tablero[{9,6}] = {BG_ORANGE, "   "};
    tablero[{10,6}] = {BG_ORANGE, "   "};
    tablero[{11,6}] = {BG_ORANGE, "   "};

    //C G gris
    tablero[{12,5}] = {BG_GRAY, "   "};
    tablero[{12,4}] = {BG_GRAY, "   "};
    tablero[{12,3}] = {BG_GRAY, "   "};
    tablero[{13,3}] = {BG_GRAY, "   "};

    //F H naranja
    tablero[{8,7}] = {BG_ORANGE, "   "};
    tablero[{8,8}] = {BG_ORANGE, "   "};
    tablero[{8,9}] = {BG_ORANGE, "   "};

    //H L rojo
    tablero[{9,10}] = {BG_RED, "   "};
    tablero[{10,10}] = {BG_RED, "   "};
    tablero[{11,10}] = {BG_RED, "   "};
    tablero[{12,10}] = {BG_RED, "   "};
    tablero[{12,11}] = {BG_RED, "   "};
    tablero[{12,12}] = {BG_RED, "   "};

    //H K azul
    tablero[{8,11}] = {BG_BLUE, "   "};
    tablero[{8,12}] = {BG_BLUE, "   "};

    //K L naranja
    tablero[{9,13}] = {BG_ORANGE, "   "};
    tablero[{10,13}] = {BG_ORANGE, "   "};
    tablero[{11,13}] = {BG_ORANGE, "   "};

    //K I morado
    tablero[{7,13}] = {BG_MAGENTA, "   "};
    tablero[{6,13}] = {BG_MAGENTA, "   "};
    tablero[{6,12}] = {BG_MAGENTA, "   "};
    tablero[{6,11}] = {BG_MAGENTA, "   "};

    //I O azul
    tablero[{4,11}] = {BG_BLUE, "   "};
    tablero[{4,12}] = {BG_BLUE, "   "};
    tablero[{4,13}] = {BG_BLUE, "   "};
    tablero[{4,14}] = {BG_BLUE, "   "};
    tablero[{4,15}] = {BG_BLUE, "   "};
    tablero[{4,16}] = {BG_BLUE, "   "};

    //J N rojo
    tablero[{2,13}] = {BG_RED, "   "};
    tablero[{2,14}] = {BG_RED, "   "};

    //N O verde
    tablero[{2,16}] = {BG_GREEN, "   "};
    tablero[{2,17}] = {BG_GREEN, "   "};
    tablero[{3,17}] = {BG_GREEN, "   "};

    //O P naranja
    tablero[{5,17}] = {BG_ORANGE, "   "};
    tablero[{6,17}] = {BG_ORANGE, "   "};
    tablero[{7,17}] = {BG_ORANGE, "   "};

    //K P verde
    tablero[{8,14}] = {BG_GREEN, "   "};
    tablero[{8,15}] = {BG_GREEN, "   "};
    tablero[{8,16}] = {BG_GREEN, "   "};

    //P Q verde
    tablero[{9,17}] = {BG_GREEN, "   "};
    tablero[{10,17}] = {BG_GREEN, "   "};
    tablero[{11,17}] = {BG_GREEN, "   "};

    //M Q morado
    tablero[{13,17}] = {BG_MAGENTA, "   "};
    tablero[{14,17}] = {BG_MAGENTA, "   "};
    tablero[{14,16}] = {BG_MAGENTA, "   "};
    tablero[{14,15}] = {BG_MAGENTA, "   "};

    //Q S gris
    tablero[{12,18}] = {BG_GRAY, "   "};
    tablero[{12,19}] = {BG_GRAY, "   "};
    tablero[{12,20}] = {BG_GRAY, "   "};
    tablero[{11,20}] = {BG_GRAY, "   "};

    //O R morado
    tablero[{4,18}] = {BG_MAGENTA, "   "};
    tablero[{4,19}] = {BG_MAGENTA, "   "};
    tablero[{4,20}] = {BG_MAGENTA, "   "};
    tablero[{5,20}] = {BG_MAGENTA, "   "};

}



void Tablero::mostrarTablero(){

    for (int fila = 1; fila <= 14; ++fila) {
        for (int col = 1; col <= 20; ++col) {

            cout << tablero[{fila,col}].first
            <<tablero[{fila, col}].second
            << RESET;

        }
        cout << endl;
    }


}
void Tablero::marcarTrayecto(string origen, string destino, char jugadorID) {
    string marca = string(" ") + jugadorID + " ";


    if ((origen == "A" && destino == "B") || (origen == "B" && destino == "A")) {
        tablero[{5,1}] = {BG_BLACK, marca};
        tablero[{5,2}] = {BG_BLACK, marca};
        tablero[{6,1}] = {BG_BLACK, marca};
        tablero[{7,1}] = {BG_BLACK, marca};
    }
    else if ((origen == "A" && destino == "F") || (origen == "F" && destino == "A")) {
        tablero[{8,2}] = {BG_BLACK, marca};
        tablero[{8,3}] = {BG_BLACK, marca};
        tablero[{8,4}] = {BG_BLACK, marca};
        tablero[{8,5}] = {BG_BLACK, marca};
    }
    else if ((origen == "D" && destino == "E") || (origen == "E" && destino == "D")) {
        tablero[{1,5}] = {BG_BLACK, marca};
        tablero[{1,6}] = {BG_BLACK, marca};
        tablero[{2,6}] = {BG_BLACK, marca};
        tablero[{3,6}] = {BG_BLACK, marca};
    }
    else if ((origen == "E" && destino == "F") || (origen == "F" && destino == "E")) {
        tablero[{5,6}] = {BG_BLACK, marca};
        tablero[{6,6}] = {BG_BLACK, marca};
        tablero[{7,6}] = {BG_BLACK, marca};
    }
    else if ((origen == "F" && destino == "G") || (origen == "G" && destino == "F")) {
        tablero[{9,6}] = {BG_BLACK, marca};
        tablero[{10,6}] = {BG_BLACK, marca};
        tablero[{11,6}] = {BG_BLACK, marca};
    }
    else if ((origen == "C" && destino == "G") || (origen == "G" && destino == "C")) {
        tablero[{12,5}] = {BG_BLACK, marca};
        tablero[{12,4}] = {BG_BLACK, marca};
        tablero[{12,3}] = {BG_BLACK, marca};
        tablero[{13,3}] = {BG_BLACK, marca};
    }
    else if ((origen == "F" && destino == "H") || (origen == "H" && destino == "F")) {
        tablero[{8,7}] = {BG_BLACK, marca};
        tablero[{8,8}] = {BG_BLACK, marca};
        tablero[{8,9}] = {BG_BLACK, marca};
    }
    else if ((origen == "H" && destino == "L") || (origen == "L" && destino == "H")) {
        tablero[{9,10}] = {BG_BLACK, marca};
        tablero[{10,10}] = {BG_BLACK, marca};
        tablero[{11,10}] = {BG_BLACK, marca};
        tablero[{12,10}] = {BG_BLACK, marca};
        tablero[{12,11}] = {BG_BLACK, marca};
        tablero[{12,12}] = {BG_BLACK, marca};
    }
    else if ((origen == "H" && destino == "K") || (origen == "K" && destino == "H")) {
        tablero[{8,11}] = {BG_BLACK, marca};
        tablero[{8,12}] = {BG_BLACK, marca};
    }
    else if ((origen == "K" && destino == "L") || (origen == "L" && destino == "K")) {
        tablero[{9,13}] = {BG_BLACK, marca};
        tablero[{10,13}] = {BG_BLACK, marca};
        tablero[{11,13}] = {BG_BLACK, marca};
    }
    else if ((origen == "K" && destino == "I") || (origen == "I" && destino == "K")) {
        tablero[{7,13}] = {BG_BLACK, marca};
        tablero[{6,13}] = {BG_BLACK, marca};
        tablero[{6,12}] = {BG_BLACK, marca};
        tablero[{6,11}] = {BG_BLACK, marca};
    }
    else if ((origen == "I" && destino == "O") || (origen == "O" && destino == "I")) {
        tablero[{4,11}] = {BG_BLACK, marca};
        tablero[{4,12}] = {BG_BLACK, marca};
        tablero[{4,13}] = {BG_BLACK, marca};
        tablero[{4,14}] = {BG_BLACK, marca};
        tablero[{4,15}] = {BG_BLACK, marca};
        tablero[{4,16}] = {BG_BLACK, marca};
    }
    else if ((origen == "J" && destino == "N") || (origen == "N" && destino == "J")) {
        tablero[{2,13}] = {BG_BLACK, marca};
        tablero[{2,14}] = {BG_BLACK, marca};
    }
    else if ((origen == "N" && destino == "O") || (origen == "O" && destino == "N")) {
        tablero[{2,16}] = {BG_BLACK, marca};
        tablero[{2,17}] = {BG_BLACK, marca};
        tablero[{3,17}] = {BG_BLACK, marca};
    }
    else if ((origen == "O" && destino == "P") || (origen == "P" && destino == "O")) {
        tablero[{5,17}] = {BG_BLACK, marca};
        tablero[{6,17}] = {BG_BLACK, marca};
        tablero[{7,17}] = {BG_BLACK, marca};
    }
    else if ((origen == "K" && destino == "P") || (origen == "P" && destino == "K")) {
        tablero[{8,14}] = {BG_BLACK, marca};
        tablero[{8,15}] = {BG_BLACK, marca};
        tablero[{8,16}] = {BG_BLACK, marca};
    }
    else if ((origen == "P" && destino == "Q") || (origen == "Q" && destino == "P")) {
        tablero[{9,17}] = {BG_BLACK, marca};
        tablero[{10,17}] = {BG_BLACK, marca};
        tablero[{11,17}] = {BG_BLACK, marca};
    }
    else if ((origen == "M" && destino == "Q") || (origen == "Q" && destino == "M")) {
        tablero[{13,17}] = {BG_BLACK, marca};
        tablero[{14,17}] = {BG_BLACK, marca};
        tablero[{14,16}] = {BG_BLACK, marca};
        tablero[{14,15}] = {BG_BLACK, marca};
    }
    else if ((origen == "Q" && destino == "S") || (origen == "S" && destino == "Q")) {
        tablero[{12,18}] = {BG_BLACK, marca};
        tablero[{12,19}] = {BG_BLACK, marca};
        tablero[{12,20}] = {BG_BLACK, marca};
        tablero[{11,20}] = {BG_BLACK, marca};
    }
    else if ((origen == "O" && destino == "R") || (origen == "R" && destino == "O")) {
        tablero[{4,18}] = {BG_BLACK, marca};
        tablero[{4,19}] = {BG_BLACK, marca};
        tablero[{4,20}] = {BG_BLACK, marca};
        tablero[{5,20}] = {BG_BLACK, marca};
    }
}
