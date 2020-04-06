#include "Tablero.h"


NodoTablero* Tablero::buscarColumna(int columna) {
	NodoTablero* temporal = this->raiz;
	while (temporal != 0)
	{
		if (temporal->columna == columna) {
			return temporal;
			break;
		}
		temporal = temporal->siguiente;
	}
	return 0;
}

NodoTablero* Tablero::buscarFila(int fila) {
	NodoTablero* temporal = this->raiz;
	while (temporal != 0) {
		if (temporal->fila == fila) {
			return temporal;
			break;
		}
		temporal = temporal->abajo;
	}
	return 0;
}

NodoTablero* Tablero::insertarColumna(NodoTablero* nuevo, NodoTablero* cabezaColumna) {
	NodoTablero* auxiliar = cabezaColumna;

	bool condicion = false;
	while (true) {
		if (auxiliar->columna == nuevo->columna) {
			auxiliar->fila = nuevo->fila;
			auxiliar->columna = nuevo->columna;
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
			auxiliar->fila = nuevo->fila;
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
	return insertarFila(new NodoTablero("", fila, 0), this->raiz);
}

NodoTablero* Tablero::crearColumna(int columna) {
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
	cout << "aaj?" << endl;
	if (this->raiz == 0) {
		cout << "No hay letras en el tablero." << endl;
	}
	else {

		NodoTablero* columna = raiz;

		int numerador = 0;
		while (columna != 0)
		{
			NodoTablero* dato = columna->abajo;
			if (dato == 0) {
				cout << "Que putas?" << endl;
			}
			while (dato != 0) {
				cout << "aa" << endl;
				cout << dato->letra << endl;
				dato = dato->abajo;
			}
			columna = columna->siguiente;
		}
	}
}


void Tablero::graficar() {
	if (this->raiz != 0) {
		ofstream archivo;
		archivo.open("Tablero.dot", ios::out);

		if (!archivo.good()) {
			cout << "Lo siento, no se puede generar." << endl;
		}
		else {
			archivo << "digraph Matriz { " << endl;
			archivo << "node [shape=box]" << endl;
			archivo << endl;

			/*add group 1 for vertical alignment */
			archivo << "Root[label = " << "\"" << "Root\", width=1.5, group = 1];" << endl;
			archivo << endl;

			/*empty nodes, needed to override graphiz' default node placement */
			archivo << "e0[ shape = point, width = 0 ];" << endl;
			archivo << "e1[ shape = point, width = 0 ];" << endl;
			archivo << endl;

			/* groups added for vertical alignment (ROWS) */
			NodoTablero* row = raiz->abajo;
			int index = 0;
			while (row != 0)
			{
				archivo << "U" << index << "[label =" << "\"" << row->fila << "\" width = 1.5, group = 1 ];" << endl;
				index++;
				row = row->abajo;
			}
			archivo << endl;

			/*Links Row*/
			row = raiz->abajo;
			index = 0;

			while (row->abajo != 0)
			{
				archivo << "U" << index << "->" << "U" << index + 1 << ";" << endl;
				archivo << "U" << index + 1 << "->" << "U" << index << ";" << endl;

				index++;
				row = row->abajo;
			}

			archivo << endl;
			/* groups 2 to 6 added for vertical alignment (COLUMN) */
			NodoTablero* col = raiz->siguiente;
			index = 0;
			int group = 2;

			while (col != 0)
			{

				archivo << "A" << index << "[label =" << "\"" << col->columna << "\" width = 1.5, group = " << group << "];" << endl;
				index++;
				group++;
				col = col->siguiente;
			}

			archivo << endl;
			/*------- links Column --------*/
			col = raiz->siguiente;
			index = 0;

			while (col->siguiente != 0)
			{
				archivo << "A" << index << "->" << "A" << index + 1 << ";" << endl;
				archivo << "A" << index + 1 << "->" << "A" << index << ";" << endl;
				index++;
				col = col->siguiente;
			}

			archivo << endl;

			/*------ link  root -----*/
			archivo << "Root -> U0;" << endl;
			archivo << "U0 -> Root;" << endl;
			archivo << "Root -> A0;" << endl;
			archivo << "A0 -> Root;" << endl;

			archivo << endl;
			/*----- Write same ----*/
			archivo << "{";
			archivo << "rank = same;Root;";
			col = raiz->siguiente;
			index = 0;

			while (col != 0)
			{
				archivo << "A" << index << ";";
				index++;
				col = col->siguiente;
			}
			archivo << "}" << endl;

			archivo << endl;
			/*---- 1. Declare Node, 2. Link Node, 3. define rank -----*/
			/*By Row*/

			/*--- 1. Declare Node by row ----*/
			row = raiz->abajo;
			int node_id = 0;

			while (row != 0)
			{
				NodoTablero* node = row->siguiente;

				archivo << "N" << node_id << "[label =" << "\"" << row->letra << "\" width = 1.5, group =" << group_columnGraph(row) << "];" << endl;



				node_id++;


				row = row->abajo;
			}

			archivo << endl;
			/*------ 2. Link node ---------*/
			row = raiz->abajo;
			node_id = 0;
			int u = 0;

			while (row != 0)
			{
				NodoTablero* node = row->siguiente;
				if (node == 0) {
					cout << "Vacio" << endl;
				}
				while (node != 0)
				{
					if (atoi(node->anterior->letra.c_str()) == 0) //-------------LINK IZUIERDA
					{
						cout << "Si entra" << endl;
						archivo << "U" << u << "->" << "N" << node_id << ";" << endl;
						archivo << "N" << node_id << "->" << "U" << u << ";" << endl;

					}

					const char* mes = "0";
					const char* node_month = node->arriba->letra.c_str();
					if (strcmp(node_month, mes) == 0) //---------------LINK ARRIBA
					{
						archivo << "A" << id_columnGraph(node->arriba) << "->" << "N" << node_id << ";" << endl;
						archivo << "N" << node_id << "->" << "A" << id_columnGraph(node->arriba) << ";" << endl;
					}
					else
					{
						archivo << "N" << node_id << "->" << "N" << node_idgraph(node->arriba) << ";" << endl;
						archivo << "N" << node_idgraph(node->arriba) << "->" << "N" << node_id << ";" << endl;
					}

					node_id++;
					node = node->siguiente;

				}
				u++;
				row = row->abajo;
			}

			archivo << endl;

			row = raiz->abajo;
			node_id = 0;
			u = 0;

			while (row != 0) {
				archivo << "{rank = same;U" << u << ";";
				NodoTablero* node = row->siguiente;
				archivo << "N" << node_id << ";";



				node_id++;

				archivo << "}" << endl;
				u++;
				row = row->abajo;
			}

			archivo << endl;
			/*------ 3. define rank ---------*/
			archivo << "/*Same define rank Node */" << endl;
			row = raiz->abajo;
			node_id = 0;
			u = 0;

			while (row != 0)
			{
				archivo << "{rank = same;U" << u << ";";
				NodoTablero* node = row->siguiente;

				while (node != 0)
				{
					archivo << "N" << node_id << ";";
					archivo << "/*No se */" << endl;

					node_id++;
					node = node->siguiente;
				}

				archivo << "}" << endl;
				u++;
				row = row->abajo;
			}
			/*close file*/
			archivo << "}" << endl;
			archivo.close();

			system("dot -Tpng Tablero.dot -o Tablero.png"); //Create image
			system("Tablero.png"); //Open image
		}
	}
}

int Tablero::group_columnGraph(NodoTablero* temp)
{
	NodoTablero* col = this->raiz->siguiente;
	int group = 2;
	while (col != 0)
	{
		if (col->columna == temp->columna)
		{
			return group;
			break;

		}
		group++;
		col = col->siguiente;
	}
	return -1;
}

//return id column in Graphviz
int Tablero::id_columnGraph(NodoTablero* temp)
{
	NodoTablero* col = raiz->siguiente;
	int id = 0;
	while (col != 0)
	{
		if (col->columna == temp->columna)
		{
			return id;
			break;

		}
		id++;
		col = col->siguiente;
	}
	return -1;

}


//return id node in graphviz
int Tablero::node_idgraph(NodoTablero* temp)
{
	NodoTablero* row = raiz->abajo;
	int node_id = 0;
	const char* temp_dato = temp->letra.c_str();

	while (row != 0)
	{
		NodoTablero* node = row->siguiente;
		while (node != 0)
		{
			const char* node_dat = node->getLetra().c_str();
			if (strcmp(node_dat, temp_dato) == 0)
			{
				return node_id;
				break;
			}
			NodoTablero* node3D = node->siguiente;
			while (node3D != 0) //----- VERIFICAR 3D ----
			{
				node_id++;
				node3D = node3D->siguiente;
			}

			node_id++;
			node = node->siguiente;
		}

		row = row->abajo;
	}
	return -1;
}