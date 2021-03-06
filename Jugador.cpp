#include "Jugador.h"

void Usuarios::insertar(Jugador* nodo, string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones) {
	if (nodo != 0) {
		char* palabra2 = (char*)nodo->getNombre().c_str();
		char* palabra1 = (char*)nombre.c_str();

		if (nombre.size() > nodo->getNombre().size()) {
			//Lado izquierdo 
			if (nodo->getIzquierda() != 0) {
				insertar(nodo->getIzquierda(), nombre, diccionario, puntuaciones);

			}
			else {
				nodo->setIzquierda(new Jugador(nombre, diccionario, puntuaciones));
				cout << nodo->getNombre() << " nodo" << endl;
				cout << nombre << " izquierdo" << endl;
				//	this->osiosi = this->raiz;
			}
		}
		else if (nombre.size() < nodo->getNombre().size()) {
			//Lado derecho
			if (nodo->getDerecha() != 0) {
				insertar(nodo->getDerecha(), nombre, diccionario, puntuaciones);
			}
			else {
				nodo->setDerecho(new Jugador(nombre, diccionario, puntuaciones));
				cout << nombre << " derecho" << endl;

			}
		}
		else {
			cout << "Nombre repetido, ingresa otro por favor" << endl;
		}
	}

}

void Usuarios::insertar(string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones, Ficha* ficha) {
	if (this->raiz == 0) {
		this->raiz = new Jugador(nombre, diccionario, puntuaciones, ficha);
		cout << "Si" << endl;
		this->osiosi = raiz;
		return;
	}
	else {
		cout << "Entro" << endl;
		this->insertar(this->raiz, nombre, diccionario, puntuaciones, ficha);

	}
}


void Usuarios::insertar(Jugador* nodo, string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones, Ficha* ficha) {
	if (nodo != 0) {
		char* palabra2 = (char*)nodo->getNombre().c_str();
		char* palabra1 = (char*)nombre.c_str();

		if (nombre.size() > nodo->getNombre().size()) {
			//Lado izquierdo 
			if (nodo->getIzquierda() != 0) {
				insertar(nodo->getIzquierda(), nombre, diccionario, puntuaciones, ficha);

			}
			else {
				nodo->setIzquierda(new Jugador(nombre, diccionario, puntuaciones, ficha));
				cout << nodo->getNombre() << " nodo" << endl;
				cout << nombre << " izquierdo" << endl;
				//	this->osiosi = this->raiz;
			}
		}
		else if (nombre.size() < nodo->getNombre().size()) {
			//Lado derecho
			if (nodo->getDerecha() != 0) {
				insertar(nodo->getDerecha(), nombre, diccionario, puntuaciones, ficha);
			}
			else {
				nodo->setDerecho(new Jugador(nombre, diccionario, puntuaciones, ficha));
				cout << nombre << " derecho" << endl;

			}
		}
		else {
			cout << "Nombre repetido, ingresa otro por favor" << endl;
		}
	}

}

void Usuarios::insertar(string nombre, Diccionario* diccionario, ScoreBoard* puntuaciones) {
	if (this->raiz == 0) {
		this->raiz = new Jugador(nombre, diccionario, puntuaciones);
		cout << "Si" << endl;
		this->osiosi = raiz;
		return;
	}
	else {
		cout << "Entro" << endl;
		this->insertar(this->raiz, nombre, diccionario, puntuaciones);

	}
}

void Usuarios::innorden(Jugador* nodo) {
	if (nodo != 0) {
		ofstream archivo("innorden.dot");
		archivo << "digraph a{" << endl;
		archivo << "rankdir = LR" << endl;
		innorden(nodo->getIzquierda());
		if (nodo->getIzquierda() != 0) {
			controla += nodo->getIzquierda()->getNombre() + "->" + nodo->getNombre() + "\n";

		}
		else {
			if (nodo->getDerecha() != 0) {
				controla += nodo->getNombre() + "->" + nodo->getDerecha()->getNombre() + "\n";
			}
		}
		cout << nodo->getNombre() << endl;
		innorden(nodo->getDerecha());
		archivo << controla << endl;
		archivo << "}" << endl;
		archivo.close();
		system("dot -Tpng innorden.dot -o innorden.png");
		system("innorden.png");
	}
}

void Usuarios::innorden() {
	controla = "";
	innorden(this->raiz);
}


string ultimoNombre = "";
bool finalizquierda = false;

void Usuarios::preorden(Jugador* nodo) {
	if (nodo != 0) {
		ofstream archivo("preorden.dot");
		archivo << "digraph a {" << endl;
		archivo << "rankdir = LR" << endl;



		cout << nodo->getNombre() << endl;

		if (nodo->getIzquierda() != 0) {
			controla += nodo->getNombre() + "->" + nodo->getIzquierda()->getNombre() + "\n";
			ultimoNombre = nodo->getIzquierda()->getNombre();
		}
		else {
			if (nodo->getDerecha() != 0) {
				if (finalizquierda == false) {
					controla += ultimoNombre + "->" + nodo->getDerecha()->getNombre() + "\n";
					finalizquierda = true;
				}
				else {
					//controla += ultimoNombre + "->" + nodo->getDerecha()->getNombre() + "\n";
					controla += nodo->getNombre() + "->" + nodo->getDerecha()->getNombre() + "\n";
				}

			}
		}

		preorden(nodo->getIzquierda());
		preorden(nodo->getDerecha());

		archivo << controla << endl;
		archivo << "}" << endl;
		archivo.close();

		system("dot -Tpng preorden.dot -o preorden.png");
		system("preorden.png");

	}

}

void Usuarios::preorden() {
	controla = "";
	preorden(this->raiz);
}

void Usuarios::postorden(Jugador* nodo) {
	if (nodo != 0) {
		ofstream archivo("postorden.dot");
		archivo << "digraph a{" << endl;
		archivo << "rankdir = LR" << endl;
		archivo << "node[shape = box]" << endl;

		postorden(nodo->getIzquierda());
		postorden(nodo->getDerecha());
		cout << nodo->getNombre() << endl;
		if (nodo->getIzquierda() != 0 && nodo->getDerecha() != 0) {
			controla += nodo->getIzquierda()->getNombre() + "->" + nodo->getDerecha()->getNombre() + "\n";
		}
		else {
			if (nodo->getDerecha() != 0) {
				controla += nodo->getNombre() + "->" + nodo->getDerecha()->getNombre() + "\n";
			}
		}

		archivo << controla << endl;
		archivo << "}" << endl;
		archivo.close();
		system("dot -Tpng postorden.dot -o postorden.png");
		system("postorden.png");
	}
}

void Usuarios::postorden() {
	controla = "";
	postorden(this->raiz);
}



void Usuarios::graficar(Jugador* nodo) {
	if (nodo != 0) {
		ofstream archivo("Usuarios.dot");
		archivo << "digraph a{" << endl;
		archivo << "node [shape = circle];" << endl;

		if (nodo->getIzquierda() != 0) {
			controla += nodo->getNombre() + "->" + nodo->getIzquierda()->getNombre() + "\n";
		}
		if (nodo->getDerecha() != 0) {
			controla += nodo->getNombre() + "->" + nodo->getDerecha()->getNombre() + "\n";
		}
		graficar(nodo->getIzquierda());
		graficar(nodo->getDerecha());
		archivo << controla << endl;
		archivo << "}" << endl;
		archivo.close();

		system("dot -Tpng Usuarios.dot -o usuarios.png");
		system("usuarios.png");

	}
	else {

		return;
	}
}

void Usuarios::graficar() {
	if (this->raiz == 0) {
		cout << "No hay usuarios para mostrar en este momento" << endl;
	}
	else {
		controla = "";
		graficar(this->raiz);
	}
}

void Usuarios::buscar(Jugador* nodo, string nombre) {
	if (nodo != 0) {
		const char* palabra1 = nombre.c_str();
		const char* palabra2 = nodo->getNombre().c_str();

		if (strcmp(palabra1, palabra2) == 0 && nodo->getNombre() == nombre) {
			cout << "Que quieres ver?" << endl;
			cout << "1. Diccionario de palabras" << endl;
			cout << "2. Puntuaciones" << endl;
			cout << "3. Letras en posecion" << endl;
			int seleccion;
			cin >> seleccion;
			switch (seleccion)
			{
			case 1:
				nodo->getDiccionario()->recorrer();
				break;
			case 2:
				nodo->getPuntajes()->imprimirUser();
				break;
			case 3:
				//Aca ira la cosita de las fichas!!!
				break;

			}
		}
		else if (strcmp(palabra1, palabra2) < 0) {
			if (nodo->getIzquierda() != 0) {
				buscar(nodo->getIzquierda(), nombre);
			}
		}
		else {
			if (nodo->getDerecha() != 0) {
				buscar(nodo->getDerecha(), nombre);
			}
		}
	}
}

void Usuarios::buscar(string nombre) {
	this->buscar(this->raiz, nombre);
}

Jugador* Usuarios::caracteristicas(string nombre) {
	if (this->raiz != 0) {
		return caracteristicas(this->raiz, nombre);
	}
	else {
		return  0;
	}
}

Jugador* Usuarios::caracteristicas(Jugador* nodo, string nombre) {
	if (nodo == 0) {
		return 0;
	}
	else {
		const char* nombre1 = (char*)nombre.c_str();
		const char* nombre2 = (char*)nodo->getNombre().c_str();
		if (nodo->getNombre() == nombre) {
			return nodo;
		}
		else if (nombre.size() < nodo->getNombre().size()) {
			if (nodo->getIzquierda() != 0) {
				caracteristicas(nodo->getIzquierda(), nombre);
			}
		}
		else {
			if (nodo->getDerecha() != 0) {
				caracteristicas(nodo->getDerecha(), nombre);
			}
		}
	}
}