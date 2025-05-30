#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include "Colors.h"
#include <string>

using namespace std;

class Carta{

    public:
        string paleta[6] = {BG_RED, BG_BLUE, BG_GREEN, BG_MAGENTA, BG_GRAY, BG_ORANGE};
        int color;
        Carta();
        Carta(int color);
        void mostrar();
};
Carta::Carta(){
	color=0;
}
Carta::Carta(int color){
	
	this->color=color;
}
void Carta::mostrar(){
    cout<< paleta[color] << " " << RESET ;
}

#endif