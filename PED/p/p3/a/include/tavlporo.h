//ALEJANDRO MAS DEVESA
#ifndef _TAVLPoro_
#define _TAVLPoro_ 

#include <iostream>

#include "tvectorporo.h"
#include "tporo.h"
using namespace std;

class TNodoAVL;
class TAVLPoro
{
	friend class TNodoAVL;
	friend ostream & operator<<(ostream &, const TAVLPoro &);

	private:
				// Puntero al nodo raíz
		TNodoAVL *raiz;
		// AUXILIAR : Devuelve el recorrido en inorden
		void InordenAux(TVectorPoro &, int &)const;
		// AUXILIAR : Devuelve el recorrido en preorden
		void PreordenAux(TVectorPoro &, int &)const;
		// AUXILIAR : Devuelve el recorrido en postorden
		void PostordenAux(TVectorPoro &, int &);

		void auxCopia(const TAVLPoro &);
		bool esHoja();
		
		void equilibrarArbol();
		void factorEquilibrio();
		
		void balanceoDerIzq();
		void balanceoDer();

		void balanceoIzq();
		void balanceoIzqDer();

		void dosHijos(TNodoAVL *elementoaBorrar, TAVLPoro &avl);

	public:
		//Constructor por defecto
		TAVLPoro ();
		//Constructor de copia
		TAVLPoro (const TAVLPoro &);
		//Destructor
		~ TAVLPoro ();
		// Sobrecarga del operador asignación
		TAVLPoro & operator=(const  TAVLPoro &);
		// Sobrecarga del operador igualdad
		bool operator==(const TAVLPoro &);
		// Sobrecarga del operador desigualdad
		bool operator!=(const TAVLPoro &);
		// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
		bool EsVacio()const;
		// Inserta el elemento TPoro en el árbol
		bool Insertar(TPoro &);
		// Devuelve true si el elemento TPoro está en el árbol, false en caso contrario
		bool Buscar(const TPoro &);
		// Borra un elemento TPoro del árbol AVL
		bool Borrar(TPoro &);
		// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
		int Altura();
		// Devuelve el elemento TPoro raíz del árbol AVL
		TPoro Raiz();
		// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
		int Nodos()const;
		// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
		int NodosHoja();
		// Devuelve el recorrido en Inorden sobre un vector
		TVectorPoro Inorden()const;
		// Devuelve el recorrido en Preorden sobre un vector
		TVectorPoro Preorden()const;
		// Devuelve el recorrido en Postorden sobre un vector
		TVectorPoro Postorden();
		// Sobrecarga del operador salida

};

class TNodoAVL
{
	friend class TAVLPoro;
	private:
		// El elemento del nodo
		TPoro item;
		// Subárbol izquierdo y derecho
		TAVLPoro iz, de;
		// Factor de equilibrio
		int fe;

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
