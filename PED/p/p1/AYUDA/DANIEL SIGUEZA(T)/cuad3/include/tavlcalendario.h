//============================================================================
// Name        : TAVLCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#ifndef TAVLCALENDARIO_H_
#define TAVLCALENDARIO_H_

#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <queue>  
#include "tcalendario.h"
#include "tvectorcalendario.h"

using namespace std;

class TNodoAVL;

class TAVLCalendario {
	friend class TNodoAVL;
	
	private:
		// Puntero al nodo raíz
		TNodoAVL *raiz;
		// Devuelve el recorrido en inorden
		void InordenAux(TVectorCalendario &, int &)const;
		// Devuelve el recorrido en preorden
		void PreordenAux(TVectorCalendario &, int &)const;
		// Devuelve el recorrido en postorden
		void PostordenAux(TVectorCalendario &, int &)const;
		
		void InsertarAux(TCalendario &);
		
		TNodoAVL Maximo();
		
		void Copiar(const TAVLCalendario &);
		
		void rotDD();
		void rotID();
		void rotDI();
		void rotII();
		
		void equilibrado();
		void actualizaFE();

	public:
		// Constructor por defecto
		TAVLCalendario ();
		// Constructor de copia
		TAVLCalendario (const TAVLCalendario &);
		// Destructor
		~ TAVLCalendario ();
		// Sobrecarga del operador asignación
		TAVLCalendario & operator=(const TAVLCalendario &);
		
		// Sobrecarga del operador igualdad
		bool operator==(const TAVLCalendario &);
		// Sobrecarga del operador desigualdad
		bool operator!=(const TAVLCalendario &);
		// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
		bool EsVacio();
		// Inserta el elemento en el árbol
		bool Insertar(TCalendario &);
		
		// Devuelve true si el elemento está en el árbol, false en caso contrario
		bool Buscar(TCalendario &);
		// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
		int Altura()const;
		// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
		int Nodos()const;
		// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
		int NodosHoja()const;
		// Devuelve el recorrido en inorden sobre un vector
		TVectorCalendario Inorden()const;
		// Devuelve el recorrido en preorden sobre un vector
		TVectorCalendario Preorden()const;
		// Devuelve el recorrido en postorden sobre un vector
		TVectorCalendario Postorden()const;
		// Borra un TCalendario del árbol AVL
		bool Borrar(TCalendario &);
		// Devuelve el elemento TCalendario raíz del árbol AVL
		TCalendario Raiz();
		// Sobrecarga del operador salida
		friend ostream & operator<<(ostream &, TAVLCalendario &);

};

class TNodoAVL {
	friend class TAVLCalendario;
	
	private:
		// El elemento (etiqueta) del nodo
		TCalendario item ;
		// Subárbol izquierdo y derecho
		TAVLCalendario iz, de ;
		// Factor de equilibrio
		int fe ;

	public:
		//Constructor por defecto
		TNodoAVL ();
		//Constructor copia
		TNodoAVL (const TNodoAVL &);
		//Destructor
		~TNodoAVL ();
		// Sobrecarga del operador asignación
		TNodoAVL & operator=(const TNodoAVL &);


};
#endif
