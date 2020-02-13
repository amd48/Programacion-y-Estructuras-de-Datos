//============================================================================
// Name        : TABBCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tabbcalendario.h"


// Constructor por defecto
TABBCalendario::TABBCalendario ()
{
	raiz = NULL;
}

// METODO AUXILIAR PARA COPIAR
void TABBCalendario:: Copiar(const TABBCalendario & t)
{
	if (t.raiz != NULL){
		TNodoABB *aux = new TNodoABB();
		aux->item = t.raiz->item;
		raiz = aux;
		(raiz->iz).Copiar(t.raiz->iz);
		(raiz->de).Copiar(t.raiz->de);
	}
	else 
		raiz = NULL;
}
// Constructor de copia
TABBCalendario:: TABBCalendario (const TABBCalendario &t)
{
	Copiar(t);
}

// Destructor
TABBCalendario:: ~TABBCalendario ()
{
	if (raiz != NULL)
	{
		delete raiz;
		raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TABBCalendario &  TABBCalendario:: operator=(const TABBCalendario &t)
{
	this->~TABBCalendario();
	Copiar(t);
	return *this;
}
// Sobrecarga del operador igualdad
bool TABBCalendario:: operator==(TABBCalendario &t)
{
	return true;
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBCalendario:: EsVacio()
{
	return (raiz==NULL);
}

/*void TABBCalendario:: Enraizar(TABBCalendario &iz, TCalendario c,TABBCalendario &de)
{
	TNodoABB *aux = new TNodoABB();
	aux->item = c;
	(aux->de).raiz = de.raiz;
	(aux->iz).raiz = iz.raiz;
	iz.raiz = de.raiz = NULL;
	this-> ~TABBCalendario();
	raiz = aux;
}*/
// Inserta el elemento en el árbol
bool TABBCalendario:: Insertar(TCalendario &t)
{
	if(this->Buscar(t)) // COMPROBAMOS SI EXISTE O NO
	{
		cout << cerr << "ERROR: El elemento ya existe"  <<endl;
		return false;
	}
	else
	{
		this->InsertarAux(t);
		return true;
	}
}

bool TABBCalendario:: InsertarAux(TCalendario &t)
{
	
	if(raiz==NULL)
	{
		TNodoABB *aux = new TNodoABB();
		aux->item = t;
		raiz = aux;
		
		return true;
	}
    else if(t < raiz->item)
		(raiz->iz).InsertarAux(t);
    else if(t > raiz->item)
		(raiz->de).InsertarAux(t);
	else
		return false;
}
// Borra el elemento en el árbol
bool TABBCalendario:: Borrar(TCalendario &t)
{
	if(raiz==NULL)
		return false;
	else if(raiz->item == t)
	{
		if(raiz->de.EsVacio() || raiz->iz.EsVacio()) // EL NODO TIENE UN HIJO O NINGUNO
		{
			if(raiz->de.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux = raiz->iz.raiz;
				raiz = aux;
			}
			else if(raiz->iz.EsVacio())
			{
				TNodoABB *aux = new TNodoABB();
				aux = raiz->de.raiz;
				raiz = aux;
			}
			else // NO TIENE HIJOS
				raiz == NULL;
		}	
		else // TIENE 2 HIJOS 
		{ 
			TNodoABB *aux = new TNodoABB(raiz->iz.Maximo()); // MAXIMO DEL ARBOL IZQUIERDO
			
			aux->de = raiz->de; // COPIAMOS DERECHA
			aux->iz = raiz->iz; // COPIAMOS IZQUIERDA
			raiz = aux; // CAMBIAMOS POR LA RAIZ A BORRAR
			aux == NULL; // ELIMINAMOS PUNTERO
		}
		
		return true;
	}		
	else if(t<raiz->item)
		return (raiz->iz).Borrar(t);
	else if(t>raiz->item)
		return (raiz->de).Borrar(t);
}

TNodoABB TABBCalendario:: Maximo()
{
	TNodoABB *aux = new TNodoABB();
	if(EsVacio())
	{
		return *aux;
	}
	if(raiz->de.EsVacio())
	{
		aux=raiz;
		Borrar(aux->item); // VOLVEMOS A LLAMAR  BORRAR PARA ELIMINAR EL NODO 
		return *aux;
	}
	else
	{
		aux=new TNodoABB(raiz->de.Maximo());
		
		return *aux;
	}

}
// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TABBCalendario::Buscar(TCalendario &c)
{
	if(raiz==NULL)
		return false;
	else if(c<raiz->item)
		return (raiz->iz).Buscar(c);
	else if(c>raiz->item)
		return (raiz->de).Buscar(c);
	else
		return true;
	
}
// Devuelve el elemento en la raíz del árbol
TCalendario TABBCalendario:: Raiz()
{
	if(raiz != NULL)
		return raiz->item;
	else
	{
		cout << cerr << "ERROR: No existe ninǵun dato en el árbol" <<endl;
		return TCalendario(); // DEVOLVER EEEEERRRRROOOOORRR
	}
}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBCalendario:: Altura() const
{
	int a1, a2;
	
	if(raiz != NULL)
	{
		a1=(raiz->iz).Altura();
		a2=(raiz->de).Altura();
		return (1+ (a1<a2 ? a2 : a1)); // MAX
	}
	else
		return 0;
}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBCalendario:: Nodos() const
{
	if(raiz!=NULL)
	{
		return (1 + (raiz->iz).Nodos() + (raiz->de).Nodos());
	}
	else
		return 0;
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBCalendario:: NodosHoja() const 
{
	if(raiz == NULL)
		return 0;
	else if((raiz->iz).EsVacio() && raiz->de.EsVacio())
		return 1;
	else
		return ((raiz->iz).NodosHoja() + (raiz->de).NodosHoja());
		
}

// Devuelve el recorrido en inorden
TVectorCalendario TABBCalendario::Inorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	InordenAux(v, posicion);

	return v;
}
// Devuelve el recorrido en inorden sobre un vector
void TABBCalendario:: InordenAux( TVectorCalendario& v,int& posicion) const
{
	if(raiz != NULL)
	{
		(raiz->iz).InordenAux(v,posicion);
		v[posicion] = raiz->item;
		posicion++;
		(raiz->de).InordenAux(v,posicion);
		
	}
}
// Devuelve el recorrido en preorden sobre un vector
TVectorCalendario TABBCalendario:: Preorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

void TABBCalendario:: PreordenAux(TVectorCalendario& v,int& posicion) const
{
	if(raiz != NULL)
	{
		int nuevaPos = posicion;
		v[posicion] = raiz->item;
		posicion++;
		(raiz->iz).PreordenAux(v,posicion);
		(raiz->de).PreordenAux(v,posicion);
	}
}
// Devuelve el recorrido en postorden sobre un vector
TVectorCalendario TABBCalendario:: Postorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

void TABBCalendario:: PostordenAux(TVectorCalendario& v,int& posicion)const
{
	if(raiz != NULL)
	{
		int nuevaPos = posicion;
		(raiz->iz).PostordenAux(v,posicion);
		(raiz->de).PostordenAux(v,posicion);
		v[posicion] = raiz->item;
		posicion++;
	}
}
// Devuelve el recorrido en niveles
TVectorCalendario TABBCalendario::  Niveles()
{
	queue<TABBCalendario> c; // CREAMOS LA COLA
	TABBCalendario aux;
	TVectorCalendario v(Nodos()); // CREAMOS EL VECTOR
	int iterador = 1;
	aux=*this;
	c.push(aux);
	while(!c.empty())
	{
		aux = c.front();
		v[iterador] = aux.raiz->item; 	// ESCRIBE
		iterador++; 				// INCREMENTAMOS ITERADOR
		c.pop(); 					// DESENCOLAMOS
		if(!aux.raiz->iz.EsVacio())
			c.push(aux.raiz->iz);
		if(!aux.raiz->de.EsVacio())
			c.push(aux.raiz->de);
	}
	
	return v;
}

// Sobrecarga del operador salida
ostream & operator<<(ostream &s,TABBCalendario & tabb)
{
	TVectorCalendario v(tabb.Nodos());
	v = tabb.Niveles();
	s << v;
	return s;
}

// Suma de dos ABB
TABBCalendario TABBCalendario:: operator+( TABBCalendario &t)
{
	TABBCalendario aux(*this);

	TVectorCalendario v(t.Nodos());
	v = t.Inorden();
	for(int i=1;i<=t.Nodos();i++)
	{
		aux.Insertar(v[i]);
	}
	
	return aux;
}
// Resta de dos ABB
TABBCalendario TABBCalendario:: operator-( TABBCalendario &t)
{
	TABBCalendario aux;

	TVectorCalendario v(this->Nodos());
	v = this->Inorden();
	for(int i=1;i<=this->Nodos();i++)
	{
		if(!t.Buscar(v[i]))
			aux.Insertar(v[i]);
	}
	
	return aux;
}


////////////////////////// TNODOABB //////////////////////////////////////////////

//Constructor por defecto
TNodoABB::TNodoABB ()
{
	this->item = TCalendario();

}
//Constructor copia
TNodoABB:: TNodoABB (const TNodoABB &t)
{
	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;
}
//Destructor
TNodoABB:: ~TNodoABB ()
{
	this->item = TCalendario();
}
// Sobrecarga del operador asignación
TNodoABB& TNodoABB:: operator=(const TNodoABB &t)
{
	if (this != &t)
	{
		this->~TNodoABB();
		
		item = t.item;
		iz = t.iz;
		de = t.de;
	}
	
	return (*this);
}



