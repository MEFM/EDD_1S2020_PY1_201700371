// Proyecto1EDD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Tablero.h"
#include "json.hpp"
#include "Diccionario.h"
#include "ScoreBoard.h"
#include "Ficha.h"
#include "Jugador.h"

using json = nlohmann::json;
using namespace std;

//Objetos que se utilizaran
Tablero* tablero = new Tablero();
Usuarios* usuarios = new Usuarios();
Diccionario* diccionario = new Diccionario();
ScoreBoard* clasificacion = new ScoreBoard();
Ficha* fichas = new Ficha();

//Variables globales
int cuadrado = 0;

//Metodos utilizados para los menus

void archivo();
void menuJuego();
void menuReportes();
void menuPrevia();
void juego(Jugador* j1, Jugador* j2);
void menuJugador(Jugador jugador);

void menu() {
	bool validador = true;
	int opcion = 0;
	while (validador) {
		cout << "1. Leer archivo\n2. Juego\n3. Reportes\n4. Cerrar\n" << endl;
		cout << "Ingrese la opcion a elegir" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			archivo();
			break;
		case 2:
			menuJuego();
			break;
		case 3:
			menuReportes();
			break;
		case 4:
			validador = false;
			break;
		default:
			break;
		}
	}
}

void archivo() {
	string nombre = "";

	cout << "Ingrese nombre del archivo" << endl;
	cin.ignore();
	getline(cin, nombre);
	ifstream(nombre + ".json");
	json j;


	int x, y;
	string palabra;

	for (const auto& el : j["dimension"]) {
		int dimensiones = j["dimension"];
		cuadrado = dimensiones;
	}
	for (const auto& el : j["casillas"]) {
		for (const auto& ell : el["dobles"]) {
			int x = ell["x"];
			int y = ell["y"];
			int valor = 2;
			tablero->insertar("", x, y, valor);
		}
		for (const auto& ell : el["triples"]) {
			x = ell["x"];
			y = ell["y"];
			int valor = 3;
			tablero->insertar("", x, y, valor);
		}

	}
	for (const auto& el : j["diccionario"]) {
		string palabra = j["palabra"];
		diccionario->insertar(palabra);
	}

}

void menuJuego() {
	bool validador = true;
	int seleccion = 0;

	while (validador) {
		system("cls");
		cout << "1. Ver ScoreBoard\n2. Buscar Jugador\n3. Ingresar Jugador\n4. Jugar" << endl;
		cout << "Ingrese la opcion que desea selccionar." << endl;
		cin >> seleccion;
		string nombre;
		switch (seleccion)
		{
		case 1:
			system("cls");
			clasificacion->imprimirSB();
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Ingrese el jugador a buscar" << endl;
			cin.ignore();
			getline(cin, nombre);
			usuarios->buscar(nombre);
			break;
		case 3:
			system("cls");
			cout << "----Ingreso de jugadores para jugar----" << endl;
			cout << "Ingresa nombre del nuevo Jugador" << endl;
			cin.ignore();
			getline(cin, nombre);
			usuarios->insertar(nombre, diccionario, clasificacion);
			break;
		case 4:
			menuPrevia();
			break;
		default:
			break;
		}
	}
}

void menuPrevia() {

	string nombre1, nombre2;
	cout << "Ingrese nombre1 " << endl;
	cin.ignore();
	getline(cin, nombre1);
	cout << "Ingreso nombre2 " << endl;
	getline(cin, nombre2);
	juego(usuarios->caracteristicas(nombre1), usuarios->caracteristicas(nombre2));


}

void juego(Jugador* j1, Jugador* j2) {

	srand(time(NULL));
	int num = rand() % 1;
	string turno1 = "";
	string turno2 = "";
	if (num == 0) {
		//Primer turno toca para j1
		turno1 = j1->getNombre();
		turno2 = j2->getNombre();
	}
	else {
		//Primer turno toca para j2
		turno1 = j2->getNombre();
		turno2 = j1->getNombre();
	}
	bool validador = true;
	int xx = 0, yy = 0;
	string palabraIngresada = "";

	while (validador) {

		cout << "Te toca colocar tu palabra jugador " << turno1 << endl;
		cout << "Posicion de inicio de la palabra en x: ";
		//Ingresar posicion en x		
		cin >> xx;
		cout << endl;
		cout << "Posicion de inicio de la palabra en x: ";
		//Ingresar posicion en y
		cin >> yy;
		cout << endl;
		cout << "Ingresar palabra" << endl;
		cin.ignore();
		getline(cin, palabraIngresada);
		char* insertada = (char*)palabraIngresada.c_str();
		cout << "Vertical u Horizontal? [V/H]" << endl;
		char validacion1 = _getch();
		if (validacion1 == 'V' || validacion1 == 'v') {
			for (int i = 0; i < palabraIngresada.size(); i++) {
				if ((yy + palabraIngresada.size()) > cuadrado) {
					cout << "Te pasaste de las dimensiones del tablero, perdiste tu oportunidad." << endl;
				}
				else {
					tablero->insertar(insertada[i] + "", xx, yy + i);
				}
			}
		}
		else if (validacion1 == 'N' || validacion1 == 'n') {
			for (int i = 0; i < palabraIngresada.size(); i++) {
				if ((xx + palabraIngresada.size()) > cuadrado) {
					cout << "Te pasaste de las dimensiones del tablero, perdiste tu oportunidad." << endl;
				}
				else {
					tablero->insertar(insertada[i] + "", xx + i, yy);
				}
			}
		}


		cout << "Te toca colocar tu palabra jugador " << turno2 << endl;
		cout << "Posicion de inicio de la palabra en x: ";
		//Ingresar posicion en x
		cin >> xx;
		cout << endl;
		cout << "Posicion de inicio de la palabra en x: ";
		//Ingresar posicion en y
		cin >> yy;
		cout << endl;
		cout << "Ingresar palabra" << endl;
		cin.ignore();
		getline(cin, palabraIngresada);
		char* insertadaa = (char*)palabraIngresada.c_str();
		cout << "Vertical u Horizontal? [V/H]" << endl;
		char validacion2 = _getch();
		if (validacion2 == 'V' || validacion2 == 'v') {
			for (int i = 0; i < palabraIngresada.size(); i++) {
				if ((yy + palabraIngresada.size()) > cuadrado) {
					cout << "Te pasaste de las dimensiones del tablero, perdiste tu oportunidad." << endl;
				}
				else {
					tablero->insertar(insertadaa[i] + "", xx, yy + i);
				}
			}
		}
		else if (validacion2 == 'N' || validacion2 == 'n') {
			for (int i = 0; i < palabraIngresada.size(); i++) {
				if ((xx + palabraIngresada.size()) > cuadrado) {
					cout << "Te pasaste de las dimensiones del tablero, perdiste tu oportunidad." << endl;
				}
				else {
					tablero->insertar(insertadaa[i] + "", xx + i, yy);
				}
			}
		}




		cout << "Ya pasaron sus turnos, desean seguir jugando? [S/N]" << endl;
		char caracter = _getch();
		if (caracter == 'S' || caracter == 's') {
			validador = false;
		}
		else if (caracter == 'n' || caracter == 'N') {
			validador = true;
		}
	}

}

void menuReportes() {
	bool validador = true;
	int opcion = 0;

	while (validador)
	{
		string nombreJugador = "";
		system("cls");
		cout << "-----------MENU DE REPORTES-----------" << endl;
		cout << "1. Diccionario\n2. Fichas\n3. Pre-Orden Jugadores\n4. In-Orden Jugadores" << endl;
		cout << "5. Post-Orden Jugadores\n6. Puntajes por Jugador\n7. Scoreboard\n8. Tablero\n9. Fichas del game" << endl;
		cout << endl;
		cout << "Ingrese su opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			diccionario->graficar();
			break;
		case 2:
			fichas->graficar();
			break;
		case 3:
			usuarios->preorden();
			break;
		case 4:
			usuarios->innorden();
			break;
		case 5:
			usuarios->postorden();
			break;
		case 6:
			cout << "-Ingrese nombre del jugador a buscar, porfavor." << endl;
			cin.ignore();
			getline(cin, nombreJugador);
			usuarios->buscar(nombreJugador);
			break;
		case 7:
			clasificacion->graficar();
			break;
		case 8:
			tablero->graficar();
			break;
		case 9:
			fichas->graficar();//RECORDATE DE HACER EL REPORTE DE LAS FICHAS DE JUGADOR
			break;
		}
	}
}

int main()
{

	menu();
	//tab.graficar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
