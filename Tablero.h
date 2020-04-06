#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <string>


using namespace std;

class NodoTablero {
public:
	string letra;
	int fila;
	int columna;
	int valor;
	NodoTablero* siguiente;
	NodoTablero* anterior;
	NodoTablero* arriba;
	NodoTablero* abajo;
	NodoTablero* front;
	NodoTablero* back;

	
	NodoTablero(string letra, int fila, int columna) {
		this->letra = letra;
		this->fila = fila;
		this->columna = columna;
		this->siguiente = 0;
		this->anterior = 0;
		this->arriba = 0;
		this->abajo = 0;
		this->front = 0;
		this->back = 0;
	}
	NodoTablero(string letra, int fila, int columna, int valor) {
		this->letra = letra;
		this->fila = fila;
		this->columna = columna;
		this->siguiente = 0;
		this->anterior = 0;
		this->arriba = 0;
		this->abajo = 0;
		this->front = 0;
		this->back = 0;
	}

	string getLetra() {
		return this->letra;
	}


};

class Tablero
{
private:
	NodoTablero* raiz;
public:
	Tablero() {
		this->raiz = new NodoTablero("", -1, -1);
		this->raiz = new NodoTablero("", -1, -1, 0);
	}

	int node_idgraph(NodoTablero* temp);
	int group_columnGraph(NodoTablero* temp);
	int id_columnGraph(NodoTablero* temp);
	NodoTablero* buscarColumna(int columna);
	NodoTablero* buscarFila(int fila);
	NodoTablero* insertarColumna(NodoTablero*, NodoTablero*);
	NodoTablero* insertarFila(NodoTablero*, NodoTablero*);
	NodoTablero* crearFila(int);
	NodoTablero* crearColumna(int);

	void imprimir();
	void graficar();
	void insertar(string, int, int, int);
	void insertar(string, int, int);

};

