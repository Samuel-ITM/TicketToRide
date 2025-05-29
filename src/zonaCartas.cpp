#include <iostream>
#include <vector>
#include "Carta.h"
#include "Residuo.h"
#include "./Baraja.cpp"
using namespace std;

class zonaCartas {
public:
    vector<Carta> visibles;

    void inicializar(Baraja &baraja);
    void reponer(Baraja &baraja, Residuo &residuo);
    Carta tomarCarta(int indice);
    void mostrar();
};

void zonaCartas::inicializar(Baraja &baraja) {
    for (int i = 0; i < 4; i++) {
        visibles.push_back(baraja.cartas[i]);
    }
}

void zonaCartas::reponer(Baraja &baraja, Residuo &residuo) {
    while (visibles.size() < 4) {
        if (baraja.vacias()) {
            vector<Carta> nuevas = residuo.vaciar();
            for (int i = 0; i < nuevas.size(); i++) {
                baraja.cartas.push_back(nuevas[i]);
            }
        }
        visibles.push_back(baraja.cartas.back());
        baraja.cartas.pop_back();
    }
}

Carta zonaCartas::tomarCarta(int indice) {
    Carta c = visibles[indice];
    visibles.erase(visibles.begin() + indice);
    return c;
}

void zonaCartas::mostrar() {
    cout << "Cartas en la zona: ";
    for (int i = 0; i < visibles.size(); i++) {
        cout << i+1 << ": ";
        visibles[i].mostrar();
        cout << "  ";
    }
    cout << RESET << endl;
}

