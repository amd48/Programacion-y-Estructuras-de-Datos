 //48666767D  Mas Devesa, Alejandro

#ifndef _TABBPoro_
#define _TABBPoro_

#include <iostream>
#include <limits>
#include <vector>

#include "tvectorporo.h"
#include "tporo.h"
#include "tlistaporo.h"

using namespace std;

class TNodoABB;
class TABBPoro
{
	friend class TNodoABB;
	// Sobrecarga del operador salida
	friend ostream & operator<<(ostream &,const TABBPoro &);

	private:

		friend class TNodoABB;

		// Puntero al nodo
		TNodoABB *nodo;
		// AUXILIAR : Devuelve el recorrido en inorden
		void InordenAux(TVectorPoro&, int &);
		// AUXILIAR : Devuelve el recorrido en preorden
		void PreordenAux(TVectorPoro&, int &);
		// AUXILIAR : Devuelve el recorrido en postorden
		void PostordenAux(TVectorPoro&, int &);

		bool esHoja(TABBPoro &abb);
		void copiaExacta(const TABBPoro &abb);
		void dosHijosBorrado(TNodoABB *, TABBPoro &);
		vector<TNodoABB> listaHijos(vector<TNodoABB> &raicesNivel);
		bool esPadreDe1(TABBPoro &abb);
		bool esPadreDe2(TABBPoro &abb);
		TNodoABB* ObtenerNodo(TPoro &);
		void recorrido(TPoro &, vector<TPoro>&);


	public:

		int* examen(TListaPoro &);
		TVectorPoro* examen2(TListaPoro &);
		//CANONICA
		// Constructor por defecto
		TABBPoro();
		// Constructor de copia
		TABBPoro(TABBPoro &);
		// Destructor
		~TABBPoro();
		// Sobrecarga del operador asignación
		TABBPoro & operator=(const TABBPoro &);

		//METODOS

		// Sobrecarga del operador igualdad
		bool operator==(TABBPoro &);
		// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
		bool EsVacio();
		// Inserta el elemento en el árbol
		bool Insertar(TPoro &);
		// Borra el elemento en el árbol
		bool Borrar(TPoro &);
		// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
		bool Buscar(TPoro &);
		// Devuelve el elemento en la raíz del árbol
		TPoro Raiz();
		// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
		int Altura();
		// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
		int Nodos();
		// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
		int NodosHoja();
		// Devuelve el recorrido en inorden
		TVectorPoro Inorden();
		// Devuelve el recorrido en preorden
		TVectorPoro Preorden();
		// Devuelve el recorrido en postorden
		TVectorPoro Postorden();
		// Devuelve el recorrido en niveles
		TVectorPoro Niveles();
		// Suma de dos ABB
		TABBPoro operator+( TABBPoro &);
		// Resta de dos ABB
		TABBPoro operator-( TABBPoro &);


};

class TNodoABB
{
	friend class TABBPoro;

	private:
 
		// El elemento del nodo
		TPoro item;
		// Subárbol izquierdo y derecho
		TABBPoro iz, de;
	
	public:

		// Constructor por defecto
		TNodoABB ();
		
		// Constructor de copia
		TNodoABB (const TNodoABB &);
		
		// Destructor
		~TNodoABB ();
		
		// Sobrecarga del operador asignación
		TNodoABB & operator=(const TNodoABB &);
		
};

#endif
