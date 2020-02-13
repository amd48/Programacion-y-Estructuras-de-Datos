//============================================================================
// Name        : TABBCalendario.cpp
// Author      : Daniel Siguenza Rico
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "tavlcalendario.h"

// Constructor por defecto
TAVLCalendario::TAVLCalendario ()
{
	raiz = NULL;
}

// METODO AUXILIAR PARA COPIAR
void TAVLCalendario:: Copiar(const TAVLCalendario &t)
{
	if (t.raiz != NULL){
		TNodoAVL *aux = new TNodoAVL();
		aux->item = t.raiz->item;
		aux->fe = t.raiz->fe;
		raiz = aux;
		(raiz->iz).Copiar(t.raiz->iz);
		(raiz->de).Copiar(t.raiz->de);
	}
	else 
		raiz = NULL;
}
// Constructor de copia
TAVLCalendario:: TAVLCalendario (const TAVLCalendario &t)
{
	Copiar(t);
}

// Destructor
TAVLCalendario:: ~TAVLCalendario ()
{
	if (raiz != NULL)
	{
		delete raiz;
		raiz = NULL;
	}
}

// Sobrecarga del operador asignación
TAVLCalendario &  TAVLCalendario:: operator=(const TAVLCalendario &t)
{
	this->~TAVLCalendario();
	Copiar(t);
	return *this;
}


// Sobrecarga del operador igualdad
bool TAVLCalendario:: operator==(const TAVLCalendario &t)
{
	if(raiz==NULL && t.raiz==NULL)
		return true;
	if(Nodos() != t.Nodos())
		return false;
	return true;
}

bool TAVLCalendario:: operator!=(const TAVLCalendario &t)
{
	return false;
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLCalendario:: EsVacio()
{
	return (raiz==NULL);
}

void TAVLCalendario::rotII()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = raiz->iz.raiz->de.raiz;
	aux->de.raiz = raiz;
	raiz = aux;
}

void TAVLCalendario::rotDD()
{
	TNodoAVL *aux;
	aux=raiz->de.raiz;
	raiz->de.raiz= raiz->de.raiz->iz.raiz;
	aux->iz.raiz = raiz;
	raiz=aux;
}


void TAVLCalendario::rotID()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz->de.raiz;
	aux->de.raiz->de.raiz = raiz;
	raiz = aux->de.raiz;
	aux->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = aux;
	
}

void TAVLCalendario::rotDI()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz->iz.raiz;
	aux->iz.raiz->iz.raiz = raiz;
	raiz = aux->iz.raiz;
	aux->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = aux;
}


// Inserta el elemento en el árbol
bool TAVLCalendario:: Insertar(TCalendario &t)
{
	if(!this->EsVacio())
	{
		if(this->Buscar(t)) // COMPROBAMOS SI EXISTE O NO
		{
			//cout << cerr << "ERROR: El elemento ya existe"  <<endl;
			return false;
		}
		else
		{ 
			this->InsertarAux(t);
			return true;
		}
	}
	else
	{
		if(!t.EsVacio())
		{
			TNodoAVL *aux = new TNodoAVL();
			aux->item = t;
			aux->fe = 0;
			raiz = aux;
			return true;
		}
	}
}

void TAVLCalendario:: InsertarAux(TCalendario &t)
{
	if(t<raiz->item)
	{
		if(raiz->iz.EsVacio())
		{
			TNodoAVL *aux = new TNodoAVL();
			aux->item = t;
			aux->fe = 0;
			raiz->iz.raiz = aux;
			
		}
		else
			(raiz->iz).InsertarAux(t);
	}
    else if(t>raiz->item)
    {
		if(raiz->de.EsVacio())
		{
			TNodoAVL *aux = new TNodoAVL();
			aux->item = t;
			aux->fe = 0;
			raiz->de.raiz = aux;

		}
		else
			(raiz->de).InsertarAux(t);
	}
	
	equilibrado();
}


// Borra el elemento en el árbol
bool TAVLCalendario:: Borrar(TCalendario &t)
{
	if(raiz==NULL)
		return false;
	else if(raiz->item == t)
	{
		if(raiz->de.EsVacio() || raiz->iz.EsVacio()) // EL NODO TIENE UN HIJO O NINGUNO
		{
			if(raiz->de.EsVacio())
			{
				TNodoAVL *aux = new TNodoAVL();
				aux = raiz->iz.raiz;
				raiz = aux;
			}
			else if(raiz->iz.EsVacio())
			{
				TNodoAVL *aux = new TNodoAVL();
				aux = raiz->de.raiz;
				raiz = aux;
			}
			else // NO TIENE HIJOS
				raiz == NULL;
		}	
		else // TIENE 2 HIJOS 
		{ 
			/*TNodoAVL *aux = new TNodoAVL(raiz->iz.Maximo()); // MAXIMO DEL ARBOL IZQUIERDO
			
			aux->de = raiz->de; // COPIAMOS DERECHA
			aux->iz = raiz->iz; // COPIAMOS IZQUIERDA
			raiz = aux; // CAMBIAMOS POR LA RAIZ A BORRAR
			aux == NULL; // ELIMINAMOS PUNTERO*/
			
			TNodoAVL *aux = new TNodoAVL(raiz->iz.Maximo());
				TNodoAVL *aux2 = new TNodoAVL();
				aux2 = raiz;
				TCalendario *cal = new TCalendario(raiz->iz.Maximo().item);

				aux->de = raiz->de;	//se cuelga la parte derecha del arbol actual, en la derecha del aux
				aux2->iz.Borrar(*cal);
				aux->iz = aux2->iz;

				raiz = aux;
		}
		
		return true;
	}		
	else if(t<raiz->item)
		return (raiz->iz).Borrar(t);
	else if(t>raiz->item)
		return (raiz->de).Borrar(t);
		
	if(raiz != NULL)
		equilibrado();
}

TNodoAVL TAVLCalendario:: Maximo()
{
	TNodoAVL *aux = new TNodoAVL();
	if(EsVacio())
	{
		return *aux;
	}
	if(raiz->de.EsVacio())
	{
		aux=raiz;
		//Borrar(aux->item); // VOLVEMOS A LLAMAR  BORRAR PARA ELIMINAR EL NODO 
		return *aux;
	}
	else
	{
		aux=new TNodoAVL(raiz->de.Maximo());
		
		return *aux;
	}
}

void TAVLCalendario :: equilibrado()
{
	
	 raiz->fe = raiz->de.Altura() - raiz->iz.Altura(); // CALCULAMOS FACTOR EQUILIBRIO RAIZ
	 
	 if(raiz->fe > 1) // ROTACION DERECHA  
	 {
		if(raiz->de.raiz->fe >= 0) 
			rotDD();
		else
			rotDI();
			
		// RECALCULAMOS FE
		actualizaFE();

	 }
	 
	 if(raiz->fe < -1) // ROTACION IZQUIERDA
	 {
		 if(raiz->iz.raiz->fe <= 0) 
			rotII();
		 else
			rotID();
			
		// RECALCULAMOS FE
		actualizaFE();
	}

	actualizaFE();
}

void TAVLCalendario:: actualizaFE()
{
	raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
	if (raiz->iz.raiz != NULL)
	{
		raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();                    
	}
	if (raiz->de.raiz != NULL)
	{
	raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
	}
}

// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TAVLCalendario::Buscar(TCalendario &c)
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

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLCalendario:: Altura() const
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
int TAVLCalendario:: Nodos() const
{
	if(raiz!=NULL)
	{
		return (1 + (raiz->iz).Nodos() + (raiz->de).Nodos());
	}
	else
		return 0;
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCalendario:: NodosHoja() const 
{
	if(raiz == NULL)
		return 0;
	else if((raiz->iz).EsVacio() && raiz->de.EsVacio())
		return 1;
	else
		return ((raiz->iz).NodosHoja() + (raiz->de).NodosHoja());
		
}

// Devuelve el recorrido en inorden
TVectorCalendario TAVLCalendario::Inorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	InordenAux(v, posicion);

	return v;
}
// Devuelve el recorrido en inorden sobre un vector
void TAVLCalendario:: InordenAux(TVectorCalendario& v,int& posicion) const
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
TVectorCalendario TAVLCalendario:: Preorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PreordenAux(v, posicion);
	
	return v;
}

void TAVLCalendario:: PreordenAux(TVectorCalendario& v,int& posicion) const
{
	if(raiz != NULL)
	{
		v[posicion] = raiz->item;
		posicion++;
		(raiz->iz).PreordenAux(v,posicion);
		(raiz->de).PreordenAux(v,posicion);
	}
}

// Devuelve el recorrido en postorden sobre un vector
TVectorCalendario TAVLCalendario:: Postorden() const
{
	int posicion = 1;
	
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorCalendario v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

void TAVLCalendario:: PostordenAux(TVectorCalendario& v, int& posicion)const
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

// Devuelve el elemento en la raíz del árbol
TCalendario TAVLCalendario:: Raiz()
{
	if(raiz != NULL)
		return raiz->item;
	else
	{
		// cout << cerr << "ERROR: No existe ninǵun dato en el árbol" <<endl;
		return TCalendario(); 
	}
}


// Sobrecarga del operador salida
ostream & operator<<(ostream &s,TAVLCalendario & tavl)
{
	TVectorCalendario v(tavl.Nodos());
	v = tavl.Inorden();
	s << v;
	return s;
}



////////////////////////// TNODOABB //////////////////////////////////////////////

//Constructor por defecto
TNodoAVL::TNodoAVL ()
{
	this->item = TCalendario();

}
//Constructor copia
TNodoAVL:: TNodoAVL (const TNodoAVL &t)
{
	this->item = t.item;
	this->iz = t.iz;
	this->de = t.de;
	this->fe = t.fe;
}
//Destructor
TNodoAVL:: ~TNodoAVL ()
{
	this->item = TCalendario();
}
// Sobrecarga del operador asignación
TNodoAVL& TNodoAVL:: operator=(const TNodoAVL &t)
{
	if (this != &t)
	{
		this->~TNodoAVL();
		
		item = t.item;
		iz = t.iz;
		de = t.de;
		fe = t.fe;
	}
	
	return (*this);
}



