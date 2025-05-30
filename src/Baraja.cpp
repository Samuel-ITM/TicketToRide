
#ifndef BARAJA_H
#define BARAJA_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Carta.h"
using namespace std;

class Baraja {
public:
    vector<Carta> cartas;

    Baraja();
    void mostrar();
    void barajar();
    bool vacias();
    Carta sacarCarta();
};

Baraja::Baraja() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 12; j++) {
            cartas.push_back(Carta(i));
        }
    }
}

void Baraja::mostrar() {
    for (int i = 0; i < cartas.size(); i++) {
        cartas[i].mostrar();
        cout << " ";
    }
    cout << RESET << endl;
}

void Baraja::barajar() {
    cout << "\nSe barajaron las cartas" << endl;
    for (int i = 0; i < 100; i++) {
        int a = rand() % cartas.size();
        int b = rand() % cartas.size();
        Carta aux = cartas[a];
        cartas[a] = cartas[b];
        cartas[b] = aux;
    }
}

bool Baraja::vacias() {
    return cartas.empty();
}

Carta Baraja::sacarCarta() {
    Carta c = cartas.back();
    cartas.pop_back();
    return c;
}

#endif
