#include <iostream>
#include "colors.h"
#include <string>

using namespace std;

class casilla{

    public:
        string paleta[8] = {BG_RED, BG_BLUE, BG_GREEN, BG_MAGENTA, BG_GRAY, BG_ORANGE, BG_BLACK, BG_WHITE};
        int color;

        void mostrar();
};


void casilla::mostrar(){
    cout<< paleta[color] << "  " << RESET ;
}