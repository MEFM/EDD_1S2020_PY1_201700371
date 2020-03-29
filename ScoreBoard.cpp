#include "ScoreBoard.h"

void ScoreBoard::insertarSB(string nombre, int puntuacion) {
	NodoSB* nuevo = new NodoSB(nombre, puntuacion);
	if (this->primero != 0) {
		this->primero = nuevo;
	}
	else {
		nuevo->setSiguiente(primero);
		this->primero = nuevo;
	}
}

void ScoreBoard::insertarUser(int puntuacion) {
	NodoSB* nuevo = new NodoSB(puntuacion);

	if (this->primero != 0) {
		this->primero = nuevo;
	}
	else {
		nuevo->setSiguiente(this->primero);
		this->primero = nuevo;
	}
}

void ScoreBoard::imprimirUser() {
	if (this->primeroUser != 0) {
		NodoSB* aux = this->primeroUser;
		int cantidad = 0;
		while (aux != 0) {
			cout << ++cantidad << ". Puntaje: " << aux->getPuntaje() << endl;
			aux = aux->getSiguiente();
		}
	}
	else {
		cout << "" << endl;
	}
}

void ScoreBoard::imprimirSB() {
	if (this->primero != 0) {
		NodoSB* aux = this->primero;
		int cantidad = 0;
		while (aux != 0) {
			cout << ++cantidad << ". Puntaje: " << aux->getPuntaje() << endl;
			aux = aux->getSiguiente();
		}
	}
	else {
		cout << "" << endl;
	}
}

void ScoreBoard::graficar() {
	if (this->primero != 0) {
		ofstream archivo("CalificacionTT.dot");
		archivo << "digraph a{" << endl;
		NodoSB* aux = this->primero;

		while (aux != 0) {
			archivo << "x" << aux << "[label = \"Nombre = " << aux->getNombre() << "\nPuntaje = " << aux->getPuntaje() << " \"]" << endl;
			aux = aux->getSiguiente();
		}

		archivo << "}" << endl;
		archivo.close();
		//Poner generador de reportes
	}
	else {
		cout << "No se puede, no hay puntajes aun" << endl;
	}
}

void ScoreBoard::graficarUser() {
	if (this->primeroUser != 0) {
		ofstream archivo("CalificacionUser.dot");
		archivo << "digraph a{" << endl;
		NodoSB* aux = this->primeroUser;

		while (aux != 0) {
			archivo << "x" << aux << "[label = \"Nombre = " << aux->getNombre() << "\nPuntaje = " << aux->getPuntaje() << " \"]" << endl;
			aux = aux->getSiguiente();
		}

		archivo << "}" << endl;
		archivo.close();
		//Poner generador de reportes
	}
	else {
		cout << "No se puede, no hay puntajes aun" << endl;
	}
}