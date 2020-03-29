#include "Tablero.h"


NodoTablero* Tablero::buscarColumna(int columna) {
	NodoTablero* temporal = this->raiz;
	while (temporal != 0)
	{
		if (temporal->columna == columna) {
			return temporal;
		}
		temporal = temporal->siguiente;
	}
	return NULL;
}

NodoTablero* Tablero::buscarFila(int fila) {
	NodoTablero* temporal = this->raiz;
	while (temporal != 0) {
		if (temporal->fila == fila) {
			return temporal;
		}
		temporal = temporal->abajo;
	}
	return NULL;
}

NodoTablero* Tablero::insertarColumna(NodoTablero* nuevo, NodoTablero* cabezaColumna) {
	NodoTablero* auxiliar = cabezaColumna;

	bool condicion = false;
	while (true) {
		if (auxiliar->columna == nuevo->columna) {
			auxiliar->fila = nuevo->fila;
			auxiliar->letra = nuevo->letra;
			return auxiliar;
		}
		else if (auxiliar->columna > nuevo->columna) {
			condicion = true;
			break;
		}

		if (auxiliar->siguiente != 0) {
			auxiliar = auxiliar->siguiente;
		}
		else {
			break;
		}
	}
	if (condicion) {
		nuevo->siguiente = auxiliar;
		auxiliar->anterior->siguiente = nuevo;
		nuevo->anterior = auxiliar->anterior;
		auxiliar->anterior = nuevo;
	}
	else {
		auxiliar->siguiente = nuevo;
		nuevo->anterior = auxiliar;
	}
	return nuevo;
}

NodoTablero* Tablero::insertarFila(NodoTablero* nuevo, NodoTablero* cabezaFila) {
	NodoTablero* auxiliar = cabezaFila;
	bool condicion = false;

	while (true) {
		if (auxiliar->fila == nuevo->fila) {
			auxiliar->columna = nuevo->columna;
			auxiliar->letra = nuevo->letra;
			return auxiliar;
		}
		else if (auxiliar->fila > nuevo->fila) {
			condicion = true;
			break;
		}

		if (auxiliar->abajo != 0) {
			auxiliar = auxiliar->abajo;
		}
		else {
			break;
		}
	}

	if (condicion) {
		nuevo->abajo = auxiliar;
		auxiliar->arriba->abajo = nuevo;
		nuevo->arriba = auxiliar->arriba;
		auxiliar->arriba = nuevo;
	}
	else {
		auxiliar->abajo = nuevo;
		nuevo->arriba = auxiliar;
	}
	return nuevo;
}

NodoTablero* Tablero::crearFila(int fila) {
	//NodoTablero* cabezaFila = this->raiz;
	//NodoTablero* auxiliar = new NodoTablero("x", fila, 0);
	//NodoTablero* filaa = insertarFila(auxiliar, cabezaFila);
	return insertarFila(new NodoTablero("", fila, 0), this->raiz);
}

NodoTablero* Tablero::crearColumna(int columna) {
	//NodoTablero* cabezaColumna = this->raiz;
	//NodoTablero* auxiliar = new NodoTablero("x", 0, columna);
	//NodoTablero* columnaa = insertarFila(auxiliar, cabezaColumna);
	return insertarColumna(new NodoTablero("", 0, columna), this->raiz);
}

void Tablero::insertar(string letra, int fila, int columna) {
	NodoTablero* nuevo = new NodoTablero(letra, fila, columna);
	NodoTablero* nodoColumna = buscarColumna(columna);
	NodoTablero* nodoFila = buscarFila(fila);

	if (nodoColumna == 0 && nodoFila == 0) {
		nodoColumna = crearColumna(columna);
		nodoFila = crearFila(fila);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna == 0 && nodoFila != 0) {
		nodoColumna = crearColumna(columna);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna != 0 && nodoFila == 0) {
		nodoFila = crearFila(fila);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna != 0 && nodoFila != 0) {
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
}
void Tablero::insertar(string letra, int fila, int columna, int valor) {
	NodoTablero* nuevo = new NodoTablero(letra, fila, columna, valor);
	NodoTablero* nodoColumna = buscarColumna(columna);
	NodoTablero* nodoFila = buscarFila(fila);

	if (nodoColumna == 0 && nodoFila == 0) {
		nodoColumna = crearColumna(columna);
		nodoFila = crearFila(fila);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna == 0 && nodoFila != 0) {
		nodoColumna = crearColumna(columna);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna != 0 && nodoFila == 0) {
		nodoFila = crearFila(fila);
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
	else if (nodoColumna != 0 && nodoFila != 0) {
		nuevo = insertarColumna(nuevo, nodoColumna);
		nuevo = insertarFila(nuevo, nodoFila);
		return;
	}
}

void Tablero::imprimir() {
	if (this->raiz == 0) {
		cout << "No hay letras en el tablero." << endl;
	}
	else {
		NodoTablero* temporal = this->raiz;
		NodoTablero* temporal2 = 0;
		int numerador = 1;
		while (temporal != 0)
		{
			
			temporal2 = temporal;
			while (temporal2 != 0)
			{
				cout <<"Fila "<<temporal->fila<< " Columna " <<temporal2->columna <<" Letra " <<temporal->letra << endl;
				temporal2 = temporal2->siguiente;
			}

			temporal = temporal->abajo;
		}
	}
}


void Tablero::graficar() {


	ofstream WriteFile("Discografia.dot");
	WriteFile << "digraph discografia{" << endl;
	WriteFile << "node [shape = rectangle]" << endl;
	bool vali = true;
	int grupo = 1;

	NodoTablero* temporal1 = raiz;
	NodoTablero* temporal2 = raiz;
	NodoTablero* constante = raiz;
	WriteFile << "x" << temporal1 << "[label = \"" << temporal1->fila << "\", width = 1.5, group = 1];" << endl;
	WriteFile << "e0[ shape = point, width = 0 ];" << endl;
	WriteFile << "e1[ shape = point, width = 0 ];" << endl;

	while (temporal1 != 0)
	{
		if (temporal1->arriba != 0) {
			grupo = grupo + 1;
			WriteFile << "x" << temporal1 << "[label = \"" << temporal1->fila << "\", width = 1.5, group = 1];" << endl;
		}

		WriteFile << endl;
		WriteFile << endl;
		temporal1 = temporal1->abajo;
	}
	temporal1 = raiz;
	while (temporal1 != 0) {
		if (temporal1->abajo == 0) {

		}
		else {
			if (temporal1->arriba != 0) {

				WriteFile << "x" << temporal1 << "->x" << temporal1->arriba << endl;
			}

			WriteFile << "x" << temporal1 << "->x" << temporal1->abajo << endl;
		}
		temporal1 = temporal1->abajo;
	}
	while (temporal2 != 0) {
		if (temporal2->anterior != 0) {
			WriteFile << "x" << temporal2 << "[label = \"" << temporal2->columna << "\", width = 1.5, group = 1];" << endl;
		}
		
		temporal2 = temporal2->siguiente;
	}

	temporal2 = raiz;
	temporal1 = raiz;

	while (temporal2 != 0) {
		if (temporal2->siguiente == 0) {
			temporal1 = temporal1->abajo;
			temporal2 = temporal1;
		}
		else
		{
			if (temporal2->anterior != 0) {
				WriteFile << "x" << temporal2 << "->x" << temporal2->anterior << endl;
			}
			WriteFile << "x" << temporal2 << "->x" << temporal2->siguiente << endl;

		}
		temporal2 = temporal2->siguiente;
	}
	temporal2 = raiz;
	string anidador = "";

	WriteFile << "{rank = same; Root" << endl;
	while (temporal2 != 0) {
		WriteFile << "; x" << temporal2 << endl;
		temporal2 = temporal2->siguiente;
	}
	WriteFile << "}" << endl << endl;

	grupo = 0;
	temporal1 = this->raiz;
	while (temporal1 != 0) {
		grupo = grupo + 1;
		WriteFile << "x" << temporal1 << "[label = \"" << temporal1->columna << "\", group = " << grupo << "]" << endl;
		temporal1 = temporal1->siguiente;
	}

	temporal2 = raiz;
	temporal1 = raiz;


	while (temporal2 != 0) {
		WriteFile << "y" << temporal2 << "[label = \"" << temporal2->letra << "\"]" << endl;
		temporal2 = temporal2->abajo;
	}
	temporal2 = raiz;
	temporal1 = raiz;
	while (temporal2 != 0) {

		WriteFile << "x" << temporal2 << "-> y" << temporal2 << "" << endl;
		if (temporal1 != 0) {
			if (temporal2->letra == temporal1->letra) {
				WriteFile << "x" << temporal1 << "-> y" << temporal2 << endl;
			}
			else {
				NodoTablero* auxiliar = temporal1;
				bool validador = true;
				while (validador)
				{
					if (auxiliar != 0) {
						if (auxiliar->letra == temporal2->letra) {
							WriteFile << "x" << auxiliar << "-> y" << temporal2 << endl;

						}
						auxiliar = auxiliar->siguiente;
					}
					else {
						validador = false;
					}
				}
			}

			temporal1 = temporal1->siguiente;
		}

		temporal2 = temporal2->abajo;

	}

	temporal1 = raiz;
	temporal2 = raiz;


	temporal2 = raiz;
	temporal1 = raiz;
	while (temporal2 != 0) {
		WriteFile << "{rank = same; x" << temporal2 << "; y" << temporal2 << "}" << endl;
		temporal2 = temporal2->siguiente;
	}



	WriteFile << "}" << endl;
	WriteFile.close();
	system("dot -Tpng Discografia.dot -o Discografia.png");
	system("Discografia.png");
}
