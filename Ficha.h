#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class NodoFicha {
private:
	NodoFicha* siguienteUsuario;
	NodoFicha* siguiente;
	string letra;
	int valor;
	int cantidad;
public:
	NodoFicha(string letra, int valor, int cantidad) {
		this->siguiente = 0;
		this->siguienteUsuario = 0;
		this->letra = letra;
		this->valor = valor;
		this->cantidad = cantidad;
	}

	void setSiguiente(NodoFicha* nuevo) {
		this->siguiente = nuevo;
	}
	void setLetra(string letra) {
		this->letra = letra;
	}
	void setValor(int valor) {
		this->valor = valor;
	}
	void setCantidad(int cantidad) {
		this->cantidad = cantidad;
	}
	void setSiguienteUsuario(NodoFicha* nodo) {
		this->siguienteUsuario = nodo;
	}

	NodoFicha* getSiguienteUsuario() {
		return this->siguienteUsuario;
	}
	NodoFicha* getSiguiente() {
		return this->siguiente;
	}
	string getLetra() {
		return this->letra;
	}
	int getCantidad() {
		return this->cantidad;
	}
	int getValor() {
		return this->valor;
	}
};

class Ficha
{
private:
	NodoFicha* primero;
	NodoFicha* ultimo;
public:
	void insertar();
	void insertar(string letra, int valor, int cantidad);
	void pilaFichas(string letra, int valor, int cantidad);
	void mostrar();
	void graficar();//Exclusivo para los reportes
};

