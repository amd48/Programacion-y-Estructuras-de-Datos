//48666767D  Mas Devesa, Alejandro

#ifndef _TListaPoro
#define _TListaPoro

#include <iostream>

using namespace std;

#include "tporo.h"
class TListaNodo;

class TListaPosicion;	

class TListaPoro
{
	friend class TListaNodo;
	friend ostream & operator<<(ostream &os,const TListaPoro &lista);
	// Sobrecarga del operador salida
	private:
			
		// Primer elemento de la lista
		TListaNodo *primero;
		// Ultimo elemento de la lista
		TListaNodo *ultimo;
		bool derechaPrimero(TPoro &poro, TListaNodo *nodo, TListaNodo *nodoAux);
		bool enMedio(TPoro &poro, TListaNodo *nodo);
		bool AlInicio(TPoro &poro, TListaNodo *nodo);
		bool AlInicioListaLlena(TPoro &poro, TListaNodo *nodo, TListaNodo *nodoAux);
		bool inicioIzquierda(TPoro &poro, TListaNodo *nodo);
		bool inicioDerecha(TPoro &poro, TListaNodo *nodo);
		bool EnMedioIzquierda(TPoro &poro, TListaNodo *,TListaNodo*);//El poro que introducimos tiene un volumen menor que alguno de la lista
		bool AlFinal(TPoro &poro, TListaNodo *nodo);

	public:

		// Constructor por defecto
		TListaPoro();
		// Constructor de copia
		TListaPoro (const TListaPoro &);
		// Destructor
		~TListaPoro ();
		// Sobrecarga del operador asignación
		TListaPoro & operator=(const TListaPoro &);	


		// Sobrecarga del operador igualdad
		bool operator==(TListaPoro &);
		// Sobrecarga del operador suma
		TListaPoro operator+(TListaPoro &);
		// Sobrecarga del operador resta
		TListaPoro operator-(TListaPoro &);
		// Devuelve true si la lista está vacía, false en caso contrario
		bool EsVacia();
		/////////////////////////////////////////
		//Auxiliares de insertar
		
		// Inserta el elemento en la lista
		bool Insertar(TPoro &);
		// Busca y borra el elemento
		bool Borrar(TPoro &);
		// Borra el elemento que ocupa la posición indicada
		bool Borrar(TListaPosicion &);
		// Obtiene el elemento que ocupa la posición indicada
		TPoro Obtener(TListaPosicion &);
		// Devuelve true si el elemento está en la lista, false en caso contrario
		bool Buscar(TPoro &);
		// Devuelve la longitud de la lista
		int Longitud();

		// Devuelve la primera posición en la lista
		TListaPosicion Primera();
		// Devuelve la última posición en la lista
		TListaPosicion Ultima();
		// Extraer un rango de nodos de la lista
		TListaPoro ExtraerRango (int n1, int n2);



};

class TListaPosicion
{
	friend class TListaPoro;
	friend class TListaNodo;
	//friend class TListaNodo;

	private:
			
		// Para implementar la POSICIÓN a NODO de la LISTA de TPoro	
		TListaNodo *pos;

	public:

		// Constructor por defecto
		TListaPosicion ();
		
		// Constructor de copia
		TListaPosicion (const TListaPosicion &);
		// Destructor
		~TListaPosicion ();
		// Sobrecarga del operador asignación
		TListaPosicion& operator=(const TListaPosicion &);		


		// Sobrecarga del operador igualdad
		bool operator==( TListaPosicion &);
		// Devuelve la posición anterior
		TListaPosicion Anterior();
		// Devuelve la posición siguiente
		TListaPosicion Siguiente();
		// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
		bool EsVacia();
};

class TListaNodo
{
	friend class TListaPosicion;
	friend class TListaPoro;
	friend ostream & operator<<(ostream &os,const TListaPoro &lista);
	
	private:
		// El elemento del nodo
		TPoro e;
		// El nodo anterior
		TListaNodo *anterior;
		// El nodo siguiente
		TListaNodo *siguiente;

	public:

		// Constructor por defecto
		TListaNodo ();
		// Constructor de copia
		TListaNodo (const TListaNodo &);
		// Destructor
		~TListaNodo ();

		TPoro E(){return e;}
		TListaNodo* Siguiente(){return siguiente;}

		// Sobrecarga del operador asignación
		TListaNodo & operator=( TListaNodo &);		
};
#endif
