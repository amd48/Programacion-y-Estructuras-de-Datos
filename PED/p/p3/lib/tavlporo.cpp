//MAS DEVESA, ALEJANDRO 48666767d
#include "tavlporo.h"

// AUXILIAR : Devuelve el recorrido en inorden
void TAVLPoro::InordenAux(TVectorPoro &v, int &indice)const
{
	if(!EsVacio())
	{
		raiz->iz.InordenAux(v, indice);
		v[indice] = raiz->item;
		indice++;
		raiz->de.InordenAux(v, indice);
	}
}
// AUXILIAR : Devuelve el recorrido en PreordenAux
void TAVLPoro::PreordenAux(TVectorPoro &v, int &indice) const
{
	if(!EsVacio())
	{
		v[indice] = raiz->item;
		indice++;
		raiz->iz.PreordenAux(v, indice);
		raiz->de.PreordenAux(v, indice);
	}
}
// AUXILIAR : Devuelve el recorrido en postorden
void TAVLPoro::PostordenAux(TVectorPoro &v, int &indice)
{
	if(!EsVacio())
	{
		raiz->iz.PostordenAux(v, indice);
		raiz->de.PostordenAux(v, indice);
		v[indice] = raiz->item;
		indice++;
	}
}
//Constructor por defecto
TAVLPoro::TAVLPoro ()
{
	raiz = NULL;
}

void TAVLPoro::auxCopia(const TAVLPoro &avl)
{
	if(avl.raiz != NULL)
	{
		//Tal cual las trasparencias
		TNodoAVL *auxNodo = new TNodoAVL();
		auxNodo->item = avl.raiz->item;
		raiz = auxNodo;
		raiz->iz.auxCopia(avl.raiz->iz);
		raiz->de.auxCopia(avl.raiz->de);
	}
	else
		raiz = NULL;
}

//Constructor de copia
TAVLPoro::TAVLPoro (const TAVLPoro &avl)
{
	auxCopia(avl);
}
//Destructor
TAVLPoro:: ~TAVLPoro ()
{
	if(raiz != NULL)
	{	
		delete raiz;
		raiz = NULL;
	}
}
// Sobrecarga del operador asignación
TAVLPoro & TAVLPoro::operator=(const TAVLPoro &avl)
{
	(*this).~TAVLPoro();
	auxCopia(avl);
	return *this;
}
// Sobrecarga del operador igualdad
bool TAVLPoro::operator==(const TAVLPoro &avl)
{
	if(EsVacio() && avl.EsVacio())
		return true;
	if(!EsVacio() && avl.EsVacio())
		return false;
	if(EsVacio() && !avl.EsVacio())
		return false;

	TVectorPoro v1 = Inorden();
	TVectorPoro v2 = avl.Inorden();

	int sizev1 = v1.Longitud();
	int sizev2 = v2.Longitud();

	bool elementoEncontrado;

	for(int i = 1; i <= sizev1; i++)
	{
		elementoEncontrado = false;
		for(int j = 1; j <= sizev2 && !elementoEncontrado; j++)
			if(v1[i] == v2[j])
				elementoEncontrado = true;

		if(!elementoEncontrado)
			return false;
	}
	return true;
}
// Sobrecarga del operador desigualdad
bool TAVLPoro::operator!=(const TAVLPoro &avl)
{
	return !(*this == avl);
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TAVLPoro::EsVacio()const
{
	return (raiz == NULL);
}


void TAVLPoro::balanceoIzq()
{
	TNodoAVL *auxNodo;
    
    auxNodo = raiz->iz.raiz;
    raiz->iz.raiz = auxNodo->de.raiz;
    
    auxNodo->de.raiz = raiz;
    raiz = auxNodo;
}
void TAVLPoro::balanceoDer()
{
	TNodoAVL *auxNodo;
    
    auxNodo = raiz->de.raiz;
    raiz->de.raiz = auxNodo->iz.raiz;
    
    auxNodo->iz.raiz = raiz;
    raiz = auxNodo;
}
void TAVLPoro::balanceoIzqDer()
{
	TNodoAVL *auxNodo;
	
	auxNodo = raiz->iz.raiz;
	raiz->iz.raiz = auxNodo->de.raiz->de.raiz;
	
	auxNodo->de.raiz->de.raiz = raiz;
	raiz = auxNodo->de.raiz;
	
	auxNodo->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = auxNodo;
}

void TAVLPoro::balanceoDerIzq()
{
	TNodoAVL *auxNodo;

	auxNodo = raiz->de.raiz;
	raiz->de.raiz = auxNodo->iz.raiz->iz.raiz;
	
	auxNodo->iz.raiz->iz.raiz = raiz;
	raiz = auxNodo->iz.raiz;
	
	auxNodo->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = auxNodo;

}

void TAVLPoro::factorEquilibrio()
{
	raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
	
	if(raiz->iz.raiz != NULL)
		raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
	
	if(raiz->de.raiz != NULL)
		raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
}

void TAVLPoro::equilibrarArbol()
{
    if(EsVacio())
		return;
	
	raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
	
	if(raiz->fe < -1)
	{
		if(raiz->iz.raiz->fe > 0)
			balanceoIzqDer();
		else
			balanceoIzq();
		
		factorEquilibrio();
	}
	else if(raiz->fe > 1)
	{
		if(raiz->de.raiz->fe < 0)
			balanceoDerIzq();
		else
			balanceoDer();
		
		factorEquilibrio();
	}
}


// Inserta el elemento TPoro en el árbol
bool TAVLPoro::Insertar(TPoro &poro)
{
	if(Buscar(poro))
		return false;
	if(EsVacio())
	{
		raiz = new TNodoAVL();
		raiz->item = poro;
		equilibrarArbol();
		return true;		
	}
	else
	{
		if(poro.Volumen() == raiz->item.Volumen())
			return false;

		if(poro.Volumen() < raiz->item.Volumen())
			raiz->iz.Insertar(poro);
		else
			raiz->de.Insertar(poro);
	}
	equilibrarArbol();
}

// Devuelve true si el elemento TPoro está en el árbol, false en caso contrario
bool TAVLPoro::Buscar(const TPoro &poro)
{
	if(EsVacio())
		return false;
	if(raiz->item == poro)
		return true;
	else
		return raiz->iz.Buscar(poro) || raiz->de.Buscar(poro);
}

void TAVLPoro::dosHijos(TNodoAVL *elementoaBorrar, TAVLPoro &avl)
{
	if(avl.esHoja())//Es Hoja
	{
		elementoaBorrar->item = avl.raiz->item;
		avl.raiz = NULL;
		
	}
	else if(avl.raiz->de.EsVacio())// la raiz del arbol que me pasan es el valor mas grande de la parte izquierda
	{
		elementoaBorrar->item = avl.raiz->item;
		avl.raiz = avl.raiz->iz.raiz;
	}
	else
		dosHijos(elementoaBorrar, avl.raiz->de);//Nos movemos por la derecha, sabemos por la estructura del arbolqu 
	
	//equilibrarArbol();
}

// Borra un elemento TPoro del árbol AVL
bool TAVLPoro::Borrar(TPoro &poro)
{
	if(EsVacio())
		return false;
	if(!Buscar(poro))
		return false;

	if(raiz->item == poro)
	{
		TNodoAVL *nodoAux = new TNodoAVL();

		if(esHoja())//Nodo Hoja
			raiz = NULL;
		
		else if(raiz->iz.EsVacio()) //El hijo derecho pasa a ser la raiz
		{
			nodoAux = raiz->de.raiz;
			raiz = nodoAux;

		}
		else if(raiz->de.EsVacio()) //El hijo izquierdo pasa a ser la raiz
		{
			nodoAux = raiz->iz.raiz;
			raiz = nodoAux;
		}
		else 
			dosHijos(raiz, raiz->iz);//Reestructura y elimina el elemento

		//equilibrarArbol();
	}
	else if(poro.Volumen() < raiz->item.Volumen())
		raiz->iz.Borrar(poro);
	else
		raiz->de.Borrar(poro);
	
	equilibrarArbol();
	
	return true;

		
}
// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLPoro::Altura()
{
	int a1, a2;
	if(!EsVacio())
	{
		a1 = raiz->iz.Altura();
		a2 = raiz->de.Altura();
		return (1 + (a1 < a2 ? a2: a1));// se le suma 1 para contar la raiz
	}
	return 0;
}
// Devuelve el elemento TPoro raíz del árbol AVL
TPoro TAVLPoro::Raiz()
{
	TPoro p;
	if(EsVacio())
		return p;
	return raiz->item;
}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TAVLPoro::Nodos()const
{
	if(EsVacio())
		return 0;
	return raiz->iz.Nodos() + raiz->de.Nodos() + 1;
}
// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)

bool TAVLPoro::esHoja()
{
	return (raiz->iz.EsVacio() && raiz->de.EsVacio());
}
int TAVLPoro::NodosHoja()
{
	if(EsVacio())
		return 0;
	if(esHoja())
		return 1;
	else
		return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}
// Devuelve el recorrido en Inorden sobre un vector
TVectorPoro TAVLPoro::Inorden() const
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;

	int posicion = 1;
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}
// Devuelve el recorrido en Preorden sobre un vector
TVectorPoro TAVLPoro::Preorden()const
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;

	int posicion = 1;
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}
// Devuelve el recorrido en Postorden sobre un vector
TVectorPoro TAVLPoro::Postorden()
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;

	int posicion = 1;
	// Vector del tamaño adecuado para almacenar todos los nodos
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}
// Sobrecarga del operador salida
ostream & operator<<(ostream &os, const TAVLPoro &avl)
{
	TVectorPoro v;
	if(avl.EsVacio())
		os << "[]";
	else
	{
		os << avl.Inorden();
	}
	return os;
}



	



TNodoAVL::TNodoAVL ()
{

	item = TPoro();
	iz = TAVLPoro();
	de = TAVLPoro();
	fe = 0;
}
//Constructor copia
TNodoAVL::TNodoAVL (const TNodoAVL &nodo)
{
	*this = nodo;
}
//Destructor
TNodoAVL:: ~TNodoAVL ()
{
	item.~TPoro();
	iz.~TAVLPoro();
	de.~TAVLPoro();
	fe = 0;
}
// Sobrecarga del operador asignación
TNodoAVL& TNodoAVL::operator=(const TNodoAVL &nodo)
{
	(*this).~TNodoAVL();

	*this = nodo;

	return *this;
}