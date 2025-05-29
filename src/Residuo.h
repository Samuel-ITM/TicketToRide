#ifndef RESIDUO_H
#define RESIDUO_H
#include <vector>
#include "Carta.h"
using namespace std;

class Residuo {
public:
    vector<Carta> descartadas;

    void agregar(Carta c);
    vector<Carta> vaciar();
};

void Residuo::agregar(Carta c) {
    descartadas.push_back(c);
}

vector<Carta> Residuo::vaciar() {
    vector<Carta> nuevas = descartadas;
    descartadas.clear();
    return nuevas;
}

#endif
