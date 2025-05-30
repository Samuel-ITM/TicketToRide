#ifndef JUGADOR_H
#define JUGADOR_H
#include <vector>
#include "Carta.h"
#include <iostream>
using namespace std;

class Jugador {
public:
    int idJugador;
    vector<Carta> mano;
    int trenes;
    int puntos;
    string nombre;

    Jugador(string nombre,int id);
    void agregarCarta(Carta c);
    void mostrarCartas();
    bool tieneCartas(int color, int cantidad);
    void usarCartas(int color, int cantidad);
};

Jugador::Jugador(string nombre, int id) {
    this->nombre = nombre;
    idJugador = id;
    trenes = 18;
    puntos = 0;
}

void Jugador::agregarCarta(Carta c) {
    mano.push_back(c);
}

void Jugador::mostrarCartas() {
    cout << "Cartas de " << nombre << ": ";
    for (int i = 0; i < mano.size(); i++) {
        mano[i].mostrar();
        cout << " ";
    }
    cout << RESET << endl;
}

bool Jugador::tieneCartas(int color, int cantidad) {
    int cont = 0;
    for (int i = 0; i < mano.size(); i++) {
        if (mano[i].color == color) {
            cont++;
        }
    }
    return cont >= cantidad;
}

void Jugador::usarCartas(int color, int cantidad) {
    int usados = 0;
    for (int i = 0; i < mano.size() && usados < cantidad; i++) {
        if (mano[i].color == color) {
            mano.erase(mano.begin() + i);
            i--;
            usados++;
        }
    }
}

#endif
