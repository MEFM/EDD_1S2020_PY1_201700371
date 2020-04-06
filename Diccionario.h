#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class NodoDicc {
private:
	NodoDicc* siguiente;
	NodoDicc* anterior;
	string palabra;
public:
	NodoDicc(string palabra) {
		this->palabra = palabra;
		siguiente = 0;
		anterior = 0;
	}

	void setSiguiente(NodoDicc* nuevo) {
		this->siguiente = nuevo;
	}
	void setAnterior(NodoDicc* nuevo) {
		this->anterior = nuevo;
	}
	void setPalabra(string palabra) {
		this->palabra = palabra;
	}

	NodoDicc* getSiguiente() {
		return this->siguiente;
	}
	NodoDicc* getAnterior() {
		return this->anterior;
	}
	string getPalabra() {
		return this->palabra;
	}

};

class Diccionario
{
private:
	NodoDicc* primero;
	NodoDicc* ultimo;
public:
	void insertar(string palabra);
	bool buscar(string palabra);
	void recorrer();
	void graficar(); //Exclusivo para modulo de reportes

};

