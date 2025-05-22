#include <iostream>
#include "colors.h"
#include <string>

using namespace std;

class Carta{

    public:
        string paleta[6] = {BG_RED, BG_BLUE, BG_GREEN, BG_MAGENTA, BG_GRAY, BG_ORANGE};
        int color;

        void mostrar();
};


void Carta::mostrar(){
    cout<< paleta[color] << "  " << RESET ;
}