//============================================================================
// Name        : TABBCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef TABBCALENDARIO_H_
#define TABBCALENDARIO_H_

#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <queue>  
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoABB;

class TABBCalendario {
	friend class TNodoABB;
	
	private:
		// Puntero al nodo raíz
		TNodoABB *raiz;
		// Devuelve el recorrido en inorden
		void InordenAux(TVectorCalendario &,int &) const;
		// Devuelve el recorrido en preorden
		void PreordenAux(TVectorCalendario &,int &) const;
		// Devuelve el recorrido en postorden
		void PostordenAux(TVectorCalendario &,int &) const;
		// Metodo auxiliar para la copia
		void Copiar(const TABBCalendario &);
		
		void Enraizar(TABBCalendario &, TCalendario c,TABBCalendario &);
		
		bool InsertarAux(TCalendario &);
		TNodoABB Maximo();

	public:
		// Constructor por defecto
		TABBCalendario ();
		// Constructor de copia
		TABBCalendario (const TABBCalendario &);
		// Destructor
		~TABBCalendario ();
		// Sobrecarga del operador asignación
		TABBCalendario & operator=(const TABBCalendario &);
		// Sobrecarga del operador igualdad
		bool operator==( TABBCalendario &);
		// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
		bool EsVacio();
		// Inserta el elemento en el árbol
		bool Insertar(TCalendario &);
		// Borra el elemento en el árbol
		bool Borrar(TCalendario &);
		// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
		bool Buscar(TCalendario &);
		// Devuelve el elemento en la raíz del árbol
		TCalendario Raiz();
		// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
		int Altura() const;
		// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
		int Nodos() const;
		// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
		int NodosHoja() const;
		// Devuelve el recorrido en inorden sobre un vector
		TVectorCalendario Inorden() const ;
		// Devuelve el recorrido en preorden sobre un vector
		TVectorCalendario Preorden() const ;
		// Devuelve el recorrido en postorden sobre un vector
		TVectorCalendario Postorden() const;
		// Devuelve el recorrido en niveles
		TVectorCalendario Niveles();
		// Sobrecarga del operador salida
		friend ostream & operator<<(ostream &,const TABBCalendario &);
		// Suma de dos ABB
		TABBCalendario operator+( TABBCalendario &);
		// Resta de dos ABB
		TABBCalendario operator-( TABBCalendario &);

};

class TNodoABB {
	friend class TABBCalendario;
	private:
		// Elemento del nodo
		TCalendario item;
		// Subárbol izquierdo y derecho
		TABBCalendario iz, de;
	public:
		//Constructor por defecto
		TNodoABB ();
		//Constructor copia
		TNodoABB (const TNodoABB &);
		//Destructor
		~TNodoABB ();
		// Sobrecarga del operador asignación
		TNodoABB & operator=(const TNodoABB &);

};
#endif
