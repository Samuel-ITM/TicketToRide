#ifndef JUEGO_H
#define JUEGO_H
#include "Jugador.h"
#include "Residuo.h"
#include "zonaCartas.cpp"
#include "Baraja.cpp"
#include "Tablero.cpp"
#include <vector>
#include <iostream>
using namespace std;

class Juego {
public:
    vector<Jugador> jugadores;
    Baraja baraja;
    Residuo residuo;
    zonaCartas zona;
    Tablero tablero;

    Juego();
    void iniciar();
    void turno(int i);
    bool juegoTerminado();
    void mostrarGanador();
};

Juego::Juego() {
    jugadores.push_back(Jugador("Jugador 1",1));
    jugadores.push_back(Jugador("Jugador 2",2));
    baraja.barajar();
    for (int j = 0; j < jugadores.size(); j++) {
        for (int k = 0; k < 4; k++) {
                jugadores[j].agregarCarta(baraja.sacarCarta());
    }
     }
    tablero.inicializarTablero();
    zona.inicializar(baraja);
}

void Juego::iniciar() {
    while (!juegoTerminado()) {
        for (int i = 0; i < jugadores.size(); i++) {
            turno(i);
            if (juegoTerminado()) break;
        }
    }
    mostrarGanador();
}

void Juego::turno(int i) {
    cout << "\nTurno de " << jugadores[i].nombre << endl;
    jugadores[i].mostrarCartas();
    zona.mostrar();

    cout << "1. Robar cartas\n2. Reclamar trayecto\nOpcion: ";
    int opcion;
    cin >> opcion;

    if (opcion == 1) {
        for (int j = 0; j < 2; j++) {
            zona.mostrar();
            int indice;
            cout << "Escoge carta " << j+1 << " (1-" << zona.visibles.size() << "): ";
            cin >> indice;


            while (indice < 1 || indice > zona.visibles.size()) {
                cout << "Opción inválida. Escoge entre 1 y " << zona.visibles.size() << ": ";
                cin >> indice;
            }

            Carta c = zona.tomarCarta(indice - 1);
            jugadores[i].agregarCarta(c);
            zona.reponer(baraja, residuo);
        }
        jugadores[i].mostrarCartas();
    }
    else if (opcion == 2) {
        tablero.mostrarTablero();

        // ayuda visual
        cout << "\nColores:\n";
        cout << "0 = rojo, 1 = azul, 2 = verde, 3 = morado, 4 = gris, 5 = naranja\n";

        string ciudad1, ciudad2;
        int color, cantidad;
        cout << "Ciudad origen: "; cin >> ciudad1;
        cout << "Ciudad destino: "; cin >> ciudad2;
        cout << "Color (0-5): "; cin >> color;
        cout << "Cantidad de cartas: "; cin >> cantidad;

        if (jugadores[i].tieneCartas(color, cantidad) && jugadores[i].trenes >= cantidad) {
            jugadores[i].usarCartas(color, cantidad);
            jugadores[i].trenes -= cantidad;

            // sistema de puntos
            if (cantidad == 2) jugadores[i].puntos += 1;
            else if (cantidad == 3) jugadores[i].puntos += 2;
            else if (cantidad == 4) jugadores[i].puntos += 4;
            else if (cantidad == 5) jugadores[i].puntos += 6;
            else if (cantidad == 6) jugadores[i].puntos += 9;


            tablero.marcarTrayecto(ciudad1, ciudad2, '0' + jugadores[i].idJugador);


            for (int j = 0; j < cantidad; j++) {
                residuo.agregar(Carta(color));
            }

            cout << "¡Trayecto reclamado exitosamente!\n";
        } else {
            cout << "No puedes reclamar este trayecto. Revisa tus cartas o trenes.\n";
        }
    }

    tablero.mostrarTablero();
}


bool Juego::juegoTerminado() {
    for (int i = 0; i < jugadores.size(); i++) {
        if (jugadores[i].trenes < 5) return true;
    }
    return false;
}

void Juego::mostrarGanador() {
    cout << "\nJuego terminado. Puntajes finales:\n";
    int mayor = -1;
    string ganador;
    for (int i = 0; i < jugadores.size(); i++) {
        cout << jugadores[i].nombre << ": " << jugadores[i].puntos << " puntos\n";
        if (jugadores[i].puntos > mayor) {
            mayor = jugadores[i].puntos;
            ganador = jugadores[i].nombre;
        }
    }
    cout << "Ganador: " << ganador << endl;
}

#endif
