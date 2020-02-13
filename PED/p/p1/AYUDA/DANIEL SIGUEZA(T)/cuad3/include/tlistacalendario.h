/*
 * TListaCalendario.h
 *
 *  Created on: 13/03/2015
 *      Author: dsr20
 */

#ifndef TLISTACALENDARIO_H_
#define TLISTACALENDARIO_H_

#include "tcalendario.h"
using namespace std;
class TNodoCalendario;
class TListaPos;

class TListaCalendario 
{
  friend class TNodoCalendario;
  friend class TListaPos;
  
  private:
	TNodoCalendario *primero;
  public:
	// Constructor por defecto
	TListaCalendario();
	// Constructor de copia
	TListaCalendario(const TListaCalendario &);
	//Destructor
	~TListaCalendario();
	// Sobrecarga del operador asignación
	TListaCalendario & operator=(const TListaCalendario &);
	// Sobrecarga del operador igualdad
	bool operator==(const TListaCalendario &);
	//Sobrecarga del operador suma
	TListaCalendario operator+ (const TListaCalendario &);
	//Sobrecarga del operador resta
	TListaCalendario operator- (const TListaCalendario &);
	// Inserta el elemento en la posición que le corresponda dentro de la lista
	bool Insertar(const TCalendario &);
	// Busca y borra el elemento
	bool Borrar(const TCalendario &);
	// Borra el elemento que ocupa la posición indicada
	bool Borrar (const TListaPos &);
	//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
	bool Borrar(int,int,int);
	// Devuelve true si la lista está vacía, false en caso contrario
	bool EsVacia() const;
	// Obtiene el elemento que ocupa la posición indicada
	TCalendario Obtener(const TListaPos &) const;
	// Devuelve true si el Calendario está en la lista.
	bool Buscar(const TCalendario &);
	// Devuelve la longitud de la lista
	int Longitud();
	// Devuelve la primera posición en la lista
	TListaPos Primera() const;
	// Devuelve la última posición en la lista
	TListaPos Ultima()const;
	// Suma de dos sublistas en una nueva lista
	TListaCalendario SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
	// Extraer un rango de nodos de la lista
	TListaCalendario ExtraerRango (int n1, int n2);
	//Sobrecarga del operador salida
	friend ostream & operator<<(ostream &, const TListaCalendario &);
	
};

class TNodoCalendario
{
	friend class TListaCalendario; 
	friend class TListaPos;
  private:
	TCalendario c; // Uso de LAYERING sobre la clase
	TNodoCalendario *siguiente;

  public:
	// Constructor por defecto
	TNodoCalendario ();
	// Constructor de copia
	TNodoCalendario (const TNodoCalendario &);
	// Destructor
	~ TNodoCalendario ();
	// Sobrecarga del operador asignación
	TNodoCalendario & operator=(const TNodoCalendario &);
	

};

class TListaPos
{
	friend class TNodoCalendario;
	friend class TListaCalendario;
	private:
		// Para implementar la POSICIÓN a NODO de la LISTA de TCalendario
		TNodoCalendario *pos;
	public:
		// Constructor por defecto
		TListaPos();
		// Constructor de copia
		TListaPos(const TListaPos &);
		// Destructor
		~TListaPos();
		// Sobrecarga del operador asignación
		TListaPos & operator=(const TListaPos &);
		// Sobrecarga del operador igualdad
		bool operator==(const TListaPos &);
		// Sobrecarga del operador desigualdad
		bool operator!=(const TListaPos &);
		// Devuelve la posición siguiente
		TListaPos Siguiente() const;
		// Posición vacía
		bool EsVacia() const;
		
		

};
#endif
