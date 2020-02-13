#ifndef TAVLCOM_H
#define TAVLCOM_H

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;
class TNodoAVL;

class TAVLCom{
	friend class TNodoAVL;
	private:
                TNodoAVL *raiz;
		// AUXILIAR : Devuelve el recorrido en inorden
		void InordenAux(TVectorCom &,int &) const;
		// AUXILIAR : Devuelve el recorrido en preorden
		void PreordenAux(TVectorCom &,int &) const;
		// AUXILIAR : Devuelve el recorrido en postorden
		void PostordenAux(TVectorCom &,int &) const;
		// AUXILIARES : Funciones de equilibrado
		void Equilibrado();
		void EquilibradoD();
		void EquilibradoI();
		void EquilibradoDI();
		void EquilibradoID();
		void Actualizar();
	public:
	// FORMA CANÓNICA
		// Constructor por defecto
		TAVLCom();
		// Constructor de copia
		TAVLCom(const TAVLCom &);
		// Destructor
		~TAVLCom();
		// Sobrecarga del operador asignación
		TAVLCom &operator=(const TAVLCom &);
	// MÉTODOS
		// Sobrecarga del operador igualdad		
		bool operator==(const TAVLCom &)const;
		// Sobrecarga del operador desigualdad
		bool operator!=(const TAVLCom &)const;
		// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
		bool EsVacio() const;
		// Inserta el elemento en el árbol
		bool Insertar(const TComplejo &);
		// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
		bool Buscar(const TComplejo &)const;
		// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
		int Altura()const;
		// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
		int Nodos()const;	
		// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
		int NodosHoja()const;	
    		// Devuelve el recorrido en inorden
   		TVectorCom Inorden()const;
    		// Devuelve el recorrido en preorden
    		TVectorCom Preorden()const;
    		// Devuelve el recorrido en postorden
    		TVectorCom Postorden()const;
    		// Devuelve el recorrido por niveles
    		TVectorCom Niveles()const;
		// Devuelve el elemento TComplejo raíz del árbol AVL
		TComplejo Raiz()const;
		// Borra un TComplejo del árbol AVL
		bool Borrar (const TComplejo &);
		// Sobrecarga del operador salida
		friend ostream &operator<<(ostream &, const TAVLCom &);

};

class TNodoAVL{
	friend class TAVLCom;
	private:
		TComplejo item;
		TAVLCom iz, de;
		int fe;
	public:
		// Constructor por defecto
		TNodoAVL();
		// Constructor de copia
		TNodoAVL(const TNodoAVL &);
		// Destructor
		~TNodoAVL();
		// Sobrecarga del operador asignación
		TNodoAVL &operator=(const TNodoAVL &);
};

#endif // TAVLCOM_H
