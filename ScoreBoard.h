#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class NodoSB {
private:
	NodoSB* siguiente;
	NodoSB* siguienteUser;
	string nombre;
	int puntaje;
public:
	NodoSB(string nombre, int puntaje) {
		this->siguiente = 0;
		this->nombre = nombre;
		this->puntaje = puntaje;
	}
	NodoSB(int puntaje) {
		this->siguienteUser = 0;
		this->puntaje = puntaje;
	}

	void setSiguiente(NodoSB* nuevo) {
		this->siguiente = nuevo;
	}
	void setSiguieteUser(NodoSB* nuevo) {
		this->siguienteUser = nuevo;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setPuntaje(int puntaje) {
		this->puntaje = puntaje;
	}

	NodoSB* getSiguiente() {
		return this->siguiente;
	}
	NodoSB* getSiguienteUser() {
		return this->siguienteUser;
	}
	string getNombre() {
		return this->nombre;
	}
	int getPuntaje() {
		return this->puntaje;
	}
};

class ScoreBoard
{
private:
	NodoSB* primero;
	NodoSB* primeroUser;
public:
	void insertarSB(string nombre, int puntaje); // Esta va directo para reportes
	void insertarUser(int puntaje); //Esta va directo para el jugador en cuestion
	void imprimirSB();//Esta es la que ser ve en el menu de juego general
	void imprimirUser();//Esta se ve unicamente buscando al jugador
	void graficar();
	void graficarUser();

};

