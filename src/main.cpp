#include <iostream>
#include <string>
#include <map>
#include "./Baraja.cpp"
#include "./Tablero.cpp"
#include "Carta.h"

int main() {
    system("cls");
    system("pause");
    Baraja barajita;
    Tablero tablero;
    tablero.inicializarTablero();
   // tablero.mostrarTablero();
    barajita.mostrar();
    barajita.barajar();
    barajita.mostrar();
    

    system("PAUSE");
    

    return 0;
}