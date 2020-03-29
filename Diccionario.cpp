#include "Diccionario.h"


void Diccionario::insertar(string palabra) {
	NodoDicc* nuevo = new NodoDicc(palabra);

	if (this->primero == 0) {
		this->primero = this->ultimo = nuevo;
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero->setAnterior(nuevo);
		this->primero = nuevo;
		this->primero->setAnterior(this->ultimo);
		this->ultimo->setSiguiente(this->primero);
	}
}

void Diccionario::recorrer() {
	if (this->primero != 0) {
		NodoDicc* aux = this->primero;
		int contadorPalabra = 0;
		do {
			cout << contadorPalabra++ << aux->getPalabra() << endl;
			aux = aux->getSiguiente();
		} while (aux != primero);
	}
	else {
		cout << "No haz ingresado nada al diccionario" << endl;
	}
}

void Diccionario::graficar() {
	if (this->primero != 0) {
		ofstream archivo("Diccionario.dot");
		archivo << "digraph a{" << endl;
		NodoDicc* aux = this->primero;
		do {
			archivo << "x" << aux << "[label = \"Palabra = "<<aux->getPalabra()<<"\"]" << endl;
			archivo << "x" << aux << "-> x" << aux->getSiguiente() << endl;
			aux = aux->getSiguiente();
		} while (aux != primero);
		archivo << "}" << endl;
		archivo.close();
	}
	else {
		cout << "Lo siento hermano no haz ingresado nada al diccionario" << endl;
	}
}