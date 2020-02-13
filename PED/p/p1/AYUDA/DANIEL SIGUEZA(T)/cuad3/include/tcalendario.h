//============================================================================
// Name        : TCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef TCALENDARIO_H_
#define TCALENDARIO_H_

#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
class TCalendario {

	private:
		int dia;
		int mes;
		int anyo;
		char* mensaje;
		int compruebaFecha(int mes, int anyo);
		bool compara(const TCalendario &t) const;
		bool esMayor(const TCalendario &t);
		bool esMayorCadena(const TCalendario &t2);

	public:
		//Constructor por defecto: inicializa dia, mes y anyo a 1 de 1 del 1900 y mensaje a NULL
		TCalendario ();
		//Constructor que inicializa calendario con parámetros pasados
		TCalendario(int dia, int mes, int anyo, char * mens);
		//Constructor copia
		TCalendario (const TCalendario &);
		//Destructor
		~TCalendario();
		// Sobrecarga del operador asignación
		TCalendario & operator=(const TCalendario &);

		// Sobrecarga del operador SUMA de fecha + un número de dias;
		TCalendario operator +(int);
		// Sobrecarga del operador RESTA de fecha - un número de dias;
		TCalendario operator-(int);
		// Modifica la fecha incrementandola en un dia (con postincremento);
		TCalendario operator++(int);
		// Modifica la fecha incrementandola en un dia (con preincremento);
		TCalendario & operator++();
		// Modifica la fecha decrementándola en un dia (con postdecremento);
		TCalendario operator--(int);
		// Modifica la fecha decrementándola en un día (con predecremento);
		TCalendario & operator--();
		// Modifica la fecha
		bool ModFecha (int, int, int);
		// Modifica el mensaje
		bool ModMensaje(char *);
		// Sobrecarga del operador igualdad;
		bool operator ==(TCalendario const&);
		// Sobrecarga del operador desigualdad;
		bool operator !=(TCalendario const&);
		// Sobrecarga del operador >; (ver ACLARACIÓN sobre ORDENACIÓN)
		bool operator>(const TCalendario &);
		// Sobrecarga del operador <; (ver ACLARACIÓN sobre ORDENACIÓN)
		bool operator<(const TCalendario &);
		//TCalendario vacío
		bool EsVacio();
		// Devuelve el día del calendario;
		int Dia();
		// Devuelve el mes del calendario;
		int Mes();
		// Devuelve el año del calendario;
		int Anyo();
		// Devuelve el mensaje del calendario;
		char *Mensaje();

		friend ostream & operator<<(ostream &, const TCalendario &);

};
#endif
