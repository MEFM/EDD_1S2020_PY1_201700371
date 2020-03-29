#include "Ficha.h"

void Ficha::insertar() {
	char letras[] = { 'A','B','C','D','E','F','G','H','I','J','K','L',
		'M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	for (int i = 0; i < 26; i++) {
		srand(time(NULL));
		int valor = 1 + rand() % (11);
		int cantidad;
		switch (valor)
		{
		case 1:
			cantidad = 4 + rand() % (13 - 4);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 2:
			cantidad = 3 + rand() % (11 - 3);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 3:
			cantidad = 3 + rand() % (10 - 3);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 4:
			cantidad = 2 + rand() % (9 - 2);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 5:
			cantidad = 1 + rand() % (6 - 1);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 8:
			cantidad = 1 + rand() % (5 - 1);
			insertar(letras[i] + "", valor, cantidad);
			break;
		case 10:
			cantidad = 1 + rand() % (3 - 1);
			insertar(letras[i] + "", valor, cantidad);
			break;
		default:
			i--;
			break;
		}
	}
}

void Ficha::insertar(string letra, int valor, int cantidad) {
	NodoFicha* nuevo = new NodoFicha(letra, valor, cantidad);

	if (this->primero == 0) {
		this->primero = this->ultimo = nuevo;
	}
	else {
		NodoFicha* aux = this->primero;
		while (aux->getSiguiente() != 0) {
			aux = aux->getSiguiente();
		}
		if (aux->getSiguiente() == 0) {
			aux->setSiguiente(nuevo);
			this->ultimo = nuevo;
		}
	}
}

void Ficha::mostrar() {
	if (this->primero != 0) {
		NodoFicha* aux = this->primero;

		cout << "VALOR LETRA CANTIDAD" << endl;
		while (aux != 0) {
			cout << aux->getValor() << " " << aux->getLetra() << " " << aux->getCantidad() << endl;
			aux = aux->getSiguiente();
		}
	}
	else {
		cout << "No hay nada para mostrar" << endl;
	}
}


void Ficha::pilaFichas(string letra, int valor, int cantidad) {

}

void Ficha::graficar() {
	if (this->primero != 0) {
		cout << "No hay fichas bro, ingresalas desde el archivo" << endl;
	}
	else {
		ofstream archivo("cola.dot");
		archivo << "digraph a{" << endl;
		archivo << "rankdir = LR;" << endl;
		archivo << "node[shape = square]" << endl;

		NodoFicha* auxiliar = this->primero;

		while (auxiliar != 0) {
			archivo << "x" << auxiliar << "[label = \"" << auxiliar->getLetra() << "\"]" << endl;
			archivo << "x" << auxiliar << "-> x" << auxiliar->getSiguiente() << endl;
			auxiliar = auxiliar->getSiguiente();
		}

		archivo << "}" << endl;
		archivo.close();
		system("dot -Tpng cola.dot -o cola.png");
		system("cola.png");
	}
}
