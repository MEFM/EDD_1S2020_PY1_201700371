#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include "ScoreBoard.h"
#include "Diccionario.h"
#include "Ficha.h"


using namespace std;

class Jugador
{
private:
	Jugador* izquierda;
	Jugador* derecha;
	string nombre;
	Diccionario* diccionario;
	ScoreBoard* puntajes; //Nada mas el normal mierda
public:
	Jugador(string nombre, Diccionario* diccionario, ScoreBoard* puntajes) {
		this->izquierda = 0;
		this->derecha = 0;
		this->nombre = nombre;
		this->diccionario = diccionario;
		this->puntajes = puntajes;
	}
	void setIzquierda(Jugador* nuevo) {
		this->izquierda = nuevo;
	}
	void setDerecho(Jugador* nuevo) {
		this->derecha = nuevo;
	}
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
	void setDiccionario(Diccionario* diccionario) {
		this->diccionario = diccionario;
	}
	void setPuntajes(ScoreBoard* puntajes) {
		this->puntajes = puntajes;
	}

	Jugador* getIzquierda() {
		return this->izquierda;
	}
	Jugador* getDerecha() {
		return this->derecha;
	}
	string getNombre() {
		return this->nombre;
	}
	Diccionario* getDiccionario() {
		return this->diccionario;
	}
	ScoreBoard* getPuntajes() {
		return this->puntajes;
	}
};

class Usuarios {
	//Arbol de usuarios
private:
	Jugador* raiz;
	Jugador* osiosi;
	string controla;
	void insertar(Jugador* nodo, string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones);
	//Los metodos de recorridos serviran para hacer reportes
	void innorden(Jugador* nodo);
	void preorden(Jugador* nodo);
	void postorden(Jugador* nodo);
	void graficar(Jugador* nodo);
	void buscar(Jugador* nodo, string nombre);
	Jugador* caracteristicas(Jugador* nodo, string nombre);

public:
	Usuarios() {
		this->raiz = 0;
		this->osiosi = 0;
	}
	void insertar(string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones);
	void innorden();
	void preorden();
	void postorden();
	void graficar();
	void buscar(string nombre);
	Jugador* caracteristicas(string nombre);

};

