//============================================================================
// Name        : TCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tlistacalendario.h"
using namespace std;
// Constructor por defecto
TListaCalendario::TListaCalendario()
{
	this->primero = NULL;
}
// Constructor de copia
TListaCalendario::TListaCalendario(const TListaCalendario &l)
{
	TNodoCalendario * aux = l.primero;
	
	while(primero != NULL)  
	{
		this->primero = aux; // COPIAMOS EN EL TEMPORAL EL ELEMENTO
		aux = l.primero->siguiente; // APUNTAMOS AL SIGUIENTE ELEMENTO
	}
	aux = NULL;
}
//Destructor
TListaCalendario::~TListaCalendario()
{
	TNodoCalendario* aux;
	
	while(primero != NULL)
	{
		aux = primero;
		primero=primero->siguiente; // APUNTAMOS AL SIGUIENTE ELEMENTO
		delete aux; 				// ELIMINAMOS DE MEMORIA
	}
	aux = NULL;
}

// Sobrecarga del operador asignación
TListaCalendario& TListaCalendario:: operator=(const TListaCalendario &t)
{
	if(this!=&t)
	{
		this->~TListaCalendario();	// LLAMADA AL DESTRUCTOR
		
		TNodoCalendario * aux = t.primero;
		
		while(primero != NULL)  
		{
			this->primero = aux; // COPIAMOS EN EL TEMPORAL EL ELEMENTO
			aux = t.primero->siguiente; // APUNTAMOS AL SIGUIENTE ELEMENTO
		}
		
		aux = NULL; // ELIMINAMOS EL PUNTERO
	}
	return *this;
}

// Sobrecarga del operador igualdad
bool TListaCalendario::operator==(const TListaCalendario &l) 
{
	bool distintos = true;
	
	TNodoCalendario* aux = this->primero;
	TNodoCalendario* auxL = l.primero;
	
	while((aux != NULL && l.primero != NULL) || distintos == true) // RECORREMOS HASTA QUE LOS DOS DEJEN DE APUNTAR AL SIGUIENTE
	{
		
		if(aux->c != auxL->c)
		{
			distintos =  false;
		}
		else 														// APUNTAMOS AL SIGUIENTE NODO
		{
			aux =  aux->siguiente;
			auxL = auxL->siguiente;
				
		}
	}
	
	return distintos;
}

//Sobrecarga del operador suma
//TListaCalendario TListaCalendario::operator+ (const TListaCalendario &)
//{
//}
//Sobrecarga del operador resta
//TListaCalendario TListaCalendario::operator- (const TListaCalendario &);
// Inserta el elemento en la posición que le corresponda dentro de la lista
bool TListaCalendario:: Insertar(const TCalendario &calendario)
{
	//TCalendario *tcal;
	//tcal = &primero->c;
	
	bool insertado = false; // NO EXISTE EL ELEMENTO
	
	TListaPos tPos,tAnt;
	
	tPos = this->Primera(); // INTRODUCIMOS PRIMER NODO	

	if(tPos.pos->c == calendario)
		return true;
	
	while(tPos.EsVacia() && !insertado)
	{		
		if(Obtener(tPos) > calendario && !(Obtener(tPos) == calendario))
		{
			
			TNodoCalendario *tn = new TNodoCalendario();
			
			tn->c = calendario; 
			
			tn->siguiente = tPos.Siguiente().pos; // NUEVO APUNTA A SIGUIENTE
			
			tAnt.pos = tn; 			// ANTERIOR APUNTA A NUEVO
			
			insertado = true;
		}
		else
		{
			tAnt = tPos;
			tPos = tPos.Siguiente();
		}
	}
	
	return insertado;
}
// Busca y borra el elemento
//bool TListaCalendario:: Borrar(const TCalendario &);
// Borra el elemento que ocupa la posición indicada
//bool Borrar (TListaPos &);
//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
//bool TListaCalendario:: Borrar(int,int,int);
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCalendario:: EsVacia() const
{
	return primero == NULL;
}
// Obtiene el elemento que ocupa la posición indicada
TCalendario TListaCalendario:: Obtener(const TListaPos &tlp)
{
	return tlp.pos->c;
}
// Devuelve true si el Calendario está en la lista.
//bool TListaCalendario:: Buscar(TCalendario &);
// Devuelve la longitud de la lista
//int TListaCalenadio:: Longitud();
// Devuelve la primera posición en la lista
TListaPos TListaCalendario:: Primera() const
{
	TListaPos aux;
	
	if(!this->EsVacia())
		aux.pos = primero;
	
	return aux;
	
}
// Devuelve la última posición en la lista
TListaPos TListaCalendario:: Ultima() const
{
	TListaPos aux;
	return aux;
}
// Suma de dos sublistas en una nueva lista
//TListaCalendario TListaCalendario:: SumarSubl (int I_L1, int F_L1, TListaCalendario & L2, int I_L2, int F_L2);
// Extraer un rango de nodos de la lista
//TListaCalendario TListaCalendario:: ExtraerRango (int n1, int n2);
//Sobrecarga del operador salida
//friend ostream & operator<<(ostream &, TListaCalendario &);


/////////////////////////////// TNODOCALENDARIO  //////////////////////////////////////////

// Constructor por defecto
TNodoCalendario::TNodoCalendario ()
{
	this->c = TCalendario();
	this->siguiente = NULL;
}

// Constructor de copia
TNodoCalendario::TNodoCalendario (const TNodoCalendario &t)
{
	if(siguiente!=NULL)
	{
		delete siguiente;
	}	
	
	c=t.c;
	
	siguiente = t.siguiente;
}
// Destructor
TNodoCalendario::~TNodoCalendario ()
{
	this->c = TCalendario();
	this->siguiente = NULL;
}
// Sobrecarga del operador asignación
TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &t)
{
	if (siguiente!=NULL)
    {
		delete siguiente;
    }
       
    if (this!=NULL)
    {
		c=t.c;
        siguiente=t.siguiente;
    }

	return *this;
}



/////////////////////////////// TLISTACALENDARIO  /////////////////////////////////////////
// Constructor por defecto
TListaPos::TListaPos()
{
	pos = NULL;
}
// Constructor de copia
TListaPos::TListaPos(const TListaPos &tlp)
{
	if(pos!=NULL)
	{
		delete pos;
	}
	else
	{
		this->pos = tlp.pos;
	}
	
}
// Destructor
TListaPos::~TListaPos()
{
	this->pos = NULL;
}
// Sobrecarga del operador asignación
TListaPos & TListaPos:: operator=(const TListaPos &tlp)
{
	if(this != &tlp)
	{

		this->pos = tlp.pos;
	}
	
	return *this;
}
// Sobrecarga del operador igualdad
bool TListaPos::operator==(const TListaPos &tlp)
{
	if(&tlp.pos == &this->pos)
		return true;
	else 
		return false;
}
// Sobrecarga del operador desigualdad
bool TListaPos::operator!=(const TListaPos &tlp)
{
	return !(tlp.pos==this->pos);
}
// Devuelve la posición siguiente
TListaPos TListaPos::Siguiente()
{
	TListaPos aux;
	aux.pos = this->pos->siguiente;
	return aux;
}
// Posición vacía
bool TListaPos::EsVacia()
{
	if(pos==NULL)
		return true;
	else
		return false;
}


