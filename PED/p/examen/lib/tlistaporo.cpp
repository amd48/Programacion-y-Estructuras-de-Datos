//48666767D  Mas Devesa, Alejandro

#include <iostream>

#include "tlistaporo.h"
#include "tporo.h"
	
using namespace std;

// Constructor por defecto
TListaPoro::TListaPoro()
{
	primero = NULL;
	ultimo = NULL;
}


// Constructor de copia 
TListaPoro::TListaPoro (const TListaPoro &lista)
{
	//(*this).~TListaPoro();
	*this = lista;
}

// Destructor
TListaPoro::~TListaPoro ()
{/*
	TListaNodo *nodo = NULL;
	TListaPosicion p;
	p.pos = primero;
	nodo = primero;

	while(p.pos)
	{ 
		p.pos = p.pos->siguiente;
		delete nodo;
		nodo = p.pos;
	}*/

	primero = NULL;
	ultimo = NULL; 
}

// Sobrecarga del operador asignación
TListaPoro& TListaPoro::operator=(const TListaPoro &lista)
{
	(*this).~TListaPoro();
	
	TListaNodo *nodo;
	nodo = lista.ultimo;
 
	while(nodo != NULL)
	{
		Insertar(nodo->e);
		nodo = nodo->anterior;
	}
	return *this;
}	


//Sobrecarga del operador igualdad
bool TListaPoro::operator==(TListaPoro &lista)
{
	TListaNodo *nodoA, *nodoB;
	TListaPosicion iteradorLista;

	nodoA = primero;
	nodoB = lista.primero;
	iteradorLista.pos = primero;

	if(primero == lista.primero && ultimo == lista.ultimo)
	{
		while(!iteradorLista.EsVacia())
		{
			if(nodoA->e == nodoB->e)
			{
				nodoA = nodoA->siguiente;
				nodoB = nodoB->siguiente;

				iteradorLista.pos = iteradorLista.pos->siguiente;
			}
			else
				return false;
		}
	}
	else
		return false;
	
	return true;
}


// Sobrecarga del operador suma
TListaPoro TListaPoro::operator+(TListaPoro &lista)
{
	TListaNodo *nodo = lista.primero;	

    while(nodo)
	{
		Insertar(nodo->e);
		nodo = nodo->siguiente;
	}
	return *this;  
}
// Sobrecarga del operador resta
TListaPoro TListaPoro::operator-(TListaPoro &lista)
{
	TListaNodo *nodo = primero;
	while(nodo != NULL) 
	{
		if(lista.Buscar(nodo->e))
			Borrar(nodo->e);
		nodo = nodo->siguiente;
	}
	return *this;
}

// Devuelve true si la lista está vacía, false en caso contrario
bool TListaPoro::EsVacia()
{
	return (ultimo == NULL || primero == NULL);
}

bool TListaPoro::AlInicio(TPoro &poro, TListaNodo *nodo)//INSERTAR EN VACIA
{
	nodo->e = poro;
	ultimo = nodo;
	primero = nodo;
	return true;
}

bool TListaPoro::AlInicioListaLlena(TPoro &poro, TListaNodo *nodo, TListaNodo *nodoAux)//CAMBIO PRIMERO
{
	nodo->e = poro;
	nodo->siguiente = primero;
	primero = nodo;
	return true;
}

bool TListaPoro::inicioIzquierda(TPoro &poro, TListaNodo *nodo)//INSERTAMOS PRIMERO
{
	ultimo = primero;
	ultimo->anterior = primero;

	nodo->e = poro;
	nodo->siguiente = primero;
	primero = nodo;

	return true;
}

bool TListaPoro::inicioDerecha(TPoro &poro, TListaNodo *nodo)
{
	nodo->e = poro;
	nodo->anterior = primero;

	primero->siguiente = nodo;
	ultimo = nodo; 
	return true;
}

bool TListaPoro::enMedio(TPoro &poro, TListaNodo *nodo)
{
	nodo->e = poro;
	nodo->anterior = primero;
	nodo->siguiente = ultimo;

	primero->siguiente = nodo;
	ultimo->anterior = nodo;

	return true;
}

//
bool TListaPoro::EnMedioIzquierda(TPoro &poro, TListaNodo *nodo, TListaNodo *nodoAux)
{
	nodo->e = poro;
	nodo->siguiente = nodoAux;
	nodo->anterior = nodoAux->anterior;

	nodoAux->anterior->siguiente= nodo;
	nodoAux->anterior= nodo;
	return true;
}
bool TListaPoro::derechaPrimero(TPoro &poro, TListaNodo *nodo, TListaNodo *nodoAux)
{
	//p n ps
	nodo->e = poro;
	nodo->siguiente = primero->siguiente;
	nodo->anterior = primero;

	primero->siguiente->anterior = nodo;
	primero->siguiente = nodo;
	return true;
}

bool TListaPoro::AlFinal(TPoro &poro, TListaNodo *nodo)
{
	nodo->e = poro;
	nodo->anterior = ultimo;

	ultimo->siguiente = nodo;
	ultimo = nodo;
	return true;
}


// Inserta el elemento en la lista
bool TListaPoro::Insertar(TPoro &poro)
{
	if(Buscar(poro))
		return false;

	TListaNodo *nodo = new TListaNodo;
	TListaNodo *nodoAux;
	nodoAux = primero;

	//cout << "PORO" << poro << endl;
	if(primero == NULL)//LA LISTA ESTA VACIA, ESTE NODO SE CONVIERTE EN PRIMERO
		return AlInicio(poro, nodo);
	else
	{
		if(primero == ultimo && poro.Volumen() < nodoAux->e.Volumen())
			return inicioIzquierda(poro, nodo);

		else if(primero == ultimo && poro.Volumen() >= nodoAux->e.Volumen())
			return inicioDerecha(poro, nodo);
		
		while(nodoAux != NULL)
		{
			if(poro.Volumen() < primero->e.Volumen())
				return AlInicioListaLlena(poro, nodo, nodoAux);

			else if(nodoAux == primero && nodoAux->siguiente == ultimo && poro.Volumen() < nodoAux->siguiente->e.Volumen())
				return enMedio(poro, nodo);

			else if(poro.Volumen() < nodoAux->e.Volumen() && nodoAux->anterior == primero)
				return derechaPrimero(poro, nodo, nodoAux);

			else if(poro.Volumen() < nodoAux->e.Volumen())
				return EnMedioIzquierda(poro, nodo, nodoAux);

			
			else if(poro.Volumen() >= nodoAux->e.Volumen() && nodoAux == ultimo)	
				return AlFinal(poro, nodo);

			nodoAux = nodoAux->siguiente;
		}	
	}
	return false;
}


// Busca y borra el elemento
bool TListaPoro::Borrar(TPoro &poro)
{
	if(&poro == NULL)
		return false;
 
	TListaNodo *nodo;
	nodo = primero;

	while(nodo != NULL)
	{
		if(nodo->e == poro)
		{
			if(nodo == primero && nodo == ultimo)
			{
				ultimo = NULL;
				primero = NULL;
				return true;
			}
			else if(nodo == primero)
			{
				primero = primero->siguiente;
				return true;
			}
			else if(nodo == ultimo)
			{
				//ultimo->siguiente = ultimo;
				ultimo = ultimo->anterior;
				return true;
			}
			else
			{
				nodo->anterior = nodo->siguiente;
				return true;
			}
		}
		nodo = nodo->siguiente;
	}
	return false;
}

// Borra el elemento que ocupa la posición indicada
bool TListaPoro::Borrar(TListaPosicion &pos)
{
	// a pos b
	if(pos.EsVacia())
		return false;

	return Borrar(pos.pos->e);
}

// Obtiene el elemento que ocupa la posición indicada
TPoro TListaPoro::Obtener(TListaPosicion &pos)
{
	TPoro poro;
	TListaNodo *posnodo = primero;

	if(pos.pos == NULL)
		return poro;

	while(posnodo != NULL)
	{
		if(posnodo == pos.pos)
		{
			poro = pos.pos->e;
			return poro; 
		}

		posnodo = posnodo->siguiente;
	}

	return poro;
}

// Devuelve true si el elemento está en la lista, false en caso contrario
bool TListaPoro::Buscar(TPoro &poro)
{
	TListaNodo *nodo = primero;

	while(nodo != NULL)
	{
		if(nodo->e == poro)
			return true;

		nodo = nodo->siguiente;
	}
	return false;
}

// Devuelve la longitud de la lista
int TListaPoro::Longitud()
{
	int size = 0;
	TListaPosicion nodos;
	nodos.pos = primero;
	while(nodos.pos != NULL)
	{
		nodos.pos = nodos.pos->siguiente;
		size++;
	}
	return size;
}


// Devuelve la primera posición en la lista
TListaPosicion TListaPoro::Primera()
{
	TListaPosicion pos;
	pos.pos = primero;
	return pos;
}
// Devuelve la última posición en la lista
TListaPosicion TListaPoro::Ultima()
{
	TListaPosicion pos;
	pos.pos = ultimo;
	return pos;
}

// Extraer un rango de nodos de la lista
TListaPoro TListaPoro::ExtraerRango (int n1, int n2)
{
	int cont = 1;
	TListaNodo *nodo;
	TListaPoro lista;
	TListaPoro listaNueva;

	if(n1 > n2)
		return listaNueva;

	if(n2 > Longitud()) {n2 = Longitud();}
	if(n1 < 1)			{ n1 = 1; }

	nodo = primero;
	if(n1 == n2)
	{
		while(nodo != NULL)
		{
			if(cont >= n1)
			{
				listaNueva.Insertar(nodo->e);
				Borrar(nodo->e);
				return listaNueva;
			}
			cont++;
			nodo = nodo->siguiente;
		}
	}

	while(nodo != NULL)
	{
		if(cont < n1 || cont > n2)
			lista.Insertar(nodo->e);
		else
			listaNueva.Insertar(nodo->e);
		 
		cont++;
		nodo = nodo->siguiente;
	}
	*this=lista;
	return listaNueva;
}

// Sobrecarga del operador salida
ostream& operator<<(ostream &os, const TListaPoro &lista)
{
	//int size = lista.Longitud();
	TListaNodo *nodo = lista.primero;
	TPoro p;
	if(nodo == NULL)
		return os << "()";

	os << "(";
	while(nodo != NULL)
	{
		if(nodo == lista.ultimo)
		{
			os <<  nodo->e;
			nodo = nodo->Siguiente();
		}
		else
		{
			os <<  nodo->e << " ";
			nodo = nodo->Siguiente();
		}
	}
	os << ")";
	return os;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// TLISTA NODO ////////////////////////////////////////////////
// Constructor por defecto
TListaNodo::TListaNodo ()
{
	anterior = NULL;
	siguiente = NULL;
}

// Constructor de copia
TListaNodo::TListaNodo (const TListaNodo &nodo)
{
	anterior = nodo.anterior;
	siguiente = nodo.siguiente;
	e = nodo.e;
}

// Destructor
TListaNodo::~TListaNodo ()
{
	//delete anterior;
	//delete siguiente;
	anterior =	NULL;
	siguiente = NULL;
}

// Sobrecarga del operador asignación
TListaNodo& TListaNodo::operator=(TListaNodo &nodo)
{
	(*this).~TListaNodo();

	anterior = nodo.anterior;
	siguiente = nodo.siguiente;
	e = nodo.e;

	return *this;
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////// TLISTA POSICION ////////////////////////////////////////////////

TListaPosicion::TListaPosicion ()
{
	pos = NULL;
}
// Constructor de copia
TListaPosicion::TListaPosicion (const TListaPosicion &posicion)
{
	pos = posicion.pos;
}
// Destructor
TListaPosicion::~TListaPosicion ()
{
	//delete pos;
	pos = NULL;
}
// Sobrecarga del operador asignación
TListaPosicion& TListaPosicion::operator=(const TListaPosicion &posicion)
{
	(*this).~TListaPosicion();

	pos = posicion.pos;

	return *this;
}


// Sobrecarga del operador igualdad
bool TListaPosicion::operator==( TListaPosicion &posicion)
{
	if(pos == posicion.pos)
		return true;
	return false;
}
// Devuelve la posición anterior
TListaPosicion TListaPosicion::Anterior()
{
	if(pos->anterior == NULL)
	{
		TListaPosicion p;
		return p;
	}

	TListaPosicion lp;
	lp.pos = pos->anterior;

	return lp;
}
// Devuelve la posición siguiente
TListaPosicion TListaPosicion::Siguiente()
{
	if(pos->siguiente == NULL)
	{
		TListaPosicion p;
		return p;
	}
	
	TListaPosicion lp;
	lp.pos = pos->siguiente;

	return lp;
}
// Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPosicion:: EsVacia()
{
	if(pos == NULL)
		return true;
	return false;
}