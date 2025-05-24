#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "Carta.h"
class Baraja {
	
	public:
		Carta cartas[72];
	    Baraja();
	    void mostrar();
	    void barajar();
	//	vector <zonaCartas> Repartir(int repartir);
};

Baraja :: Baraja(){
	
	int indice=0;
	for(int i=0; i<6; i++){
		for(int j=0; j<12; j++){
		
		indice =(12*i)+j;
		cartas[indice].color=i;
	}
	}
}

void Baraja:: mostrar(){
	int indice =0;
	for(int i=0; i<6; i++){
		cout<<" "<<endl;
		for(int j=0; j<12; j++){
		cartas[indice].mostrar();
		cout<<" ";
		indice++;
        }
 		
	}
	
	
}

void Baraja::barajar(){
	cout<<"\nSe barajaron las cartas"<<endl;   
    Carta aux;
       
    for (int i = 0; i < 2000; i++) {
        int a = rand() % 36; 
        int b = rand() % 36; 
          
        Carta aux = cartas[a];
        cartas[a] = cartas[b];
        cartas[b] = aux;
    }
}
