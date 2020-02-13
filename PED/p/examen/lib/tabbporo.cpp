//48666767D  Mas Devesa, Alejandro

#include "tvectorporo.h"
#include "tporo.h"
#include "tabbporo.h"
#include "tlistaporo.h"

/////////TABBPORO
// Constructor por defecto
TABBPoro::TABBPoro()
{
	nodo = NULL;
}
//Aux copia
void TABBPoro::copiaExacta(const TABBPoro &abb)
{
	if(abb.nodo != NULL)
	{
		//Tal cual las trasparencias
		TNodoABB *auxNodo = new TNodoABB();
		auxNodo->item = abb.nodo->item;
		nodo = auxNodo;
		nodo->iz.copiaExacta(abb.nodo->iz);
		nodo->de.copiaExacta(abb.nodo->de);
	}
	else
		nodo = NULL;
}
// Constructor de copia
TABBPoro::TABBPoro(TABBPoro &abb)
{
	copiaExacta(abb);
}
// Destructor
TABBPoro:: ~TABBPoro()
{
	if(nodo != NULL)
	{	
		delete nodo;
		nodo = NULL;
	}
}
// Sobrecarga del operador asignación
TABBPoro& TABBPoro::operator=(const TABBPoro &abb)
{
	//Tal cual las trasparencias
	(*this).~TABBPoro();
	copiaExacta(abb);
	return *this;
}

// Sobrecarga del operador igualdad
bool TABBPoro::operator==(TABBPoro &abb)
{
	if(EsVacio() && abb.EsVacio())
		return true;
	if(!EsVacio() && abb.EsVacio())
		return false;
	if(EsVacio() && !abb.EsVacio())
		return false;

	TVectorPoro v1 = Preorden();
	TVectorPoro v2 = abb.Preorden();

	int sizev1 = v1.Longitud();
	int sizev2 = v2.Longitud();
	
	if(sizev1 != sizev2)
		return false;

	bool elementoEncontrado;

	for(int i = 1; i <= sizev1; i++)
	{
		elementoEncontrado = false;
		for(int j = 1; j <= sizev2 && !elementoEncontrado; j++)
			if(v1[i] == v2[j])
				elementoEncontrado = true;// Si encontramos el elemento continuamos byscando el siguiente elemento

		if(!elementoEncontrado)//Si no encontramsos el elemento en el el vector terminamos con false,ya que no son iguales
			return false;
	}
	return true;//Si pasamos todas las comprobaciones estamos seguros de que los arboles son iguales sin contar su estructura interna
}
// Devuelve TRUE si el árbol está vacío, FALSE en caso contrario
bool TABBPoro::EsVacio()
{
	return (nodo == NULL);
}

// Inserta el elemento en el árbol
bool TABBPoro::Insertar(TPoro &poro)
{
	if(Buscar(poro))
		return false;
	
	if(EsVacio())
	{
		TNodoABB *auxNodo = new TNodoABB();
		auxNodo->item = poro;
		nodo = auxNodo;
		return true;
	}
	if(poro.Volumen() < nodo->item.Volumen())
		return nodo->iz.Insertar(poro);
	if(poro.Volumen() > nodo->item.Volumen())
		return nodo->de.Insertar(poro);

	return false;
}

bool TABBPoro::esHoja(TABBPoro &abb)
{
	return (abb.nodo->iz.EsVacio() && abb.nodo->de.EsVacio());
}

bool TABBPoro::esPadreDe1(TABBPoro &abb)
{
	return ((!abb.nodo->iz.EsVacio() && abb.nodo->de.EsVacio()) || (abb.nodo->iz.EsVacio() && !abb.nodo->de.EsVacio()));
}

bool TABBPoro::esPadreDe2(TABBPoro &abb)
{
	return (!abb.nodo->iz.EsVacio() && !abb.nodo->de.EsVacio());
}


void TABBPoro::dosHijosBorrado(TNodoABB *elementoaBorrar, TABBPoro &abb)
{
	if(esHoja(abb))//Es Hoja
	{
		elementoaBorrar->item = abb.nodo->item;
		abb.nodo = NULL;
	}
	else if(abb.nodo->de.EsVacio())// la raiz del arbol que me pasan es el valor mas grande de la parte izquierda
	{
		elementoaBorrar->item = abb.nodo->item;
		abb.nodo = abb.nodo->iz.nodo;
	}
	else
		dosHijosBorrado(elementoaBorrar, abb.nodo->de);//Nos movemos por la derecha, sabemos por la estructura del arbolqu 
}


// Borra el elemento en el árbol
bool TABBPoro::Borrar(TPoro &poro)
{
	if(EsVacio())
		return false;
	if(nodo->item == poro)
	{
		TNodoABB *nodoAux = new TNodoABB();

		if(esHoja(*this))//Nodo Hoja
			nodo = NULL;
		
		else if(nodo->iz.EsVacio()) //El hijo derecho pasa a ser la raiz
		{
			nodoAux = nodo->de.nodo;
			nodo = nodoAux;
		}
		else if(nodo->de.EsVacio()) //El hijo izquierdo pasa a ser la raiz
		{
			nodoAux = nodo->iz.nodo;
			nodo = nodoAux;
		}
		else 
			dosHijosBorrado(nodo, nodo->iz);//Reestructura y elimina el elemento

		return true;
	}
	if(poro.Volumen() < nodo->item.Volumen())
		return nodo->iz.Borrar(poro);

	return nodo->de.Borrar(poro); 
}


// Devuelve TRUE si el elemento está en el árbol, FALSE en caso contrario
bool TABBPoro::Buscar(TPoro &poro)
{
	if(EsVacio())
		return false;
	if(nodo->item == poro)
		return true;
	else
		return (nodo->iz.Buscar(poro) || nodo->de.Buscar(poro));
}

TNodoABB* TABBPoro::ObtenerNodo(TPoro &poro)
{
	TNodoABB *a;

	if(EsVacio()) return a;
	
	if(nodo->item == poro) return nodo;

	if(poro.Volumen() < nodo->item.Volumen()) nodo->iz.ObtenerNodo(poro);
	
	else nodo->de.ObtenerNodo(poro);
}
/*
void TABBPoro::recorrido(TPoro &poro, vector<TPoro> &camino)
{
	if(EsVacio()) return;

	camino.push_back(nodo->item);
	
	if(nodo->item == poro) return;

	else if(poro.Volumen() < nodo->item.Volumen()) nodo->iz.recorrido(poro, camino);
	
	else nodo->de.recorrido(poro, camino);

}

TVectorPoro* TABBPoro::examen2(TListaPoro &lista)
{
	TVectorPoro vacio;
	
	TVectorPoro *v = new TVectorPoro(lista.Longitud());
	
	if(EsVacio()) return v;
	
	if(lista.EsVacia()) return v = NULL;	

	TListaPosicion laux = lista.Primera(); int i = 0; TPoro raiz = nodo->item; 
	while(!laux.EsVacia())
	{
		vector<TPoro> camino;
		TPoro poro = lista.Obtener(laux);

		if(Buscar(poro))
		{
			recorrido(poro, camino);
			
			TVectorPoro vRecorrido(camino.size());

			for(int j = 1; j <= camino.size(); j++) vRecorrido[j] = camino[j-1];

			v[i] = vRecorrido;
		}
		else v[i] = vacio;
		
		i++;
		laux = laux.Siguiente();
	}
		return v;
}

int* TABBPoro::examen(TListaPoro &lista)
{
	int* v = NULL; int* vv = new int[lista.Longitud(), 0];

	if(lista.EsVacia()) return v;
	
	if(EsVacio()) return vv;
	
	TABBPoro abbaux;   TListaPosicion laux = lista.Primera();  int i = 0;

	while(!laux.EsVacia())
	{
		TPoro poro = lista.Obtener(laux);//Obtener poro de la lista a partir de una posicion
		
		if(Buscar(poro))
		{
			abbaux.nodo = ObtenerNodo(poro);//ObtenerNodo el nodo del arbol , a partir de un poro 
			
			if(esHoja(abbaux)) vv[i] = 0;
			
			else if(esPadreDe2(abbaux)) vv[i] = 2;
			
			else vv[i] = 1;
		}
		else vv[i] = 0;
		
		i++;
		laux = laux.Siguiente();
	}
	return vv;
}*/


TPoro TABBPoro::Raiz()
{
	TPoro nodoVacio;
	if(nodo != NULL)
		return nodo->item;
	else
		return nodoVacio;
}
// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBPoro::Altura()
{
	int a1, a2;
	if(nodo != NULL)
	{
		a1 = nodo->iz.Altura();
		a2 = nodo->de.Altura();
		return (1 + (a1 < a2 ? a2: a1));// se le suma 1 para contar la raiz
	}
	return 0;
}
// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBPoro::Nodos()
{
	if(nodo != NULL)
		return (nodo->iz.Nodos() + nodo->de.Nodos()) + 1;
	
	return 0;
}
// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBPoro::NodosHoja()
{
	if(EsVacio())
		return 0;
	if(esHoja(*this))
		return 1;
	else
		return nodo->iz.NodosHoja() + nodo->de.NodosHoja();

}

void TABBPoro::InordenAux(TVectorPoro &v, int &indice)
{
	if(!EsVacio())
	{
		nodo->iz.InordenAux(v, indice);
		v[indice] = nodo->item;
		indice++;
		nodo->de.InordenAux(v, indice);
	}
}

// Devuelve el recorrido en inorden
TVectorPoro TABBPoro::Inorden()
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;
	int posicion = 1;
	TVectorPoro v(Nodos());
	InordenAux(v, posicion);
	return v;
}
// AUXILIAR : Devuelve el recorrido en preorden
void TABBPoro::PreordenAux(TVectorPoro &v, int &indice)
{
	if(!EsVacio())
	{
		v[indice] = nodo->item;
		indice++;
		nodo->iz.PreordenAux(v, indice);
		nodo->de.PreordenAux(v, indice);
	}
}

// Devuelve el recorrido en preorden
TVectorPoro TABBPoro::Preorden()
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;
	int posicion = 1;
	TVectorPoro v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

// AUXILIAR : Devuelve el recorrido en postorden
void TABBPoro::PostordenAux(TVectorPoro &v, int &indice)
{
	if(!EsVacio())
	{
		nodo->iz.PostordenAux(v, indice);
		nodo->de.PostordenAux(v, indice);
		v[indice] = nodo->item;
		indice++;
	}
}

// Devuelve el recorrido en postorden
TVectorPoro TABBPoro::Postorden()
{
	TVectorPoro vv;
	if(EsVacio())
		return vv;
	int posicion = 1;
	TVectorPoro v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

vector<TNodoABB> TABBPoro::listaHijos(vector<TNodoABB> &hijosNivel)
{
	vector<TNodoABB> nodos;
	int size = hijosNivel.size();
	
	for(int i = 0; i < size; i++)
	{
		if(!hijosNivel[i].iz.EsVacio())
			nodos.push_back(*hijosNivel[i].iz.nodo);
		
		if(!hijosNivel[i].de.EsVacio())
			nodos.push_back(*hijosNivel[i].de.nodo);
	}

	return nodos;
}
// Devuelve el recorrido en niveles
TVectorPoro TABBPoro::Niveles()
{
	if(EsVacio())
		return TVectorPoro();
	
	else
	{
		vector<TNodoABB> vHijos;
		vector<TNodoABB> recorrido;
		
		recorrido.push_back(*nodo);
		vHijos = recorrido;
		int size = 0;
		do
		{
			vHijos = listaHijos(vHijos);
			size = vHijos.size();

			if(size > 0)
				for(int i = 0; i < size; i++)
					recorrido.push_back(vHijos[i]);

		}while(size > 0);
		
		size = recorrido.size();
		TVectorPoro v(size);
		for(int i = 0; i < size; i++)
			v[i+1] = recorrido[i].item;

		return v;
	}	
	
}
// Suma de dos ABB
TABBPoro TABBPoro::operator+( TABBPoro &abb)
{
	if(abb.EsVacio())
		return *this;

	if(EsVacio())
		return abb;

	TABBPoro arbolIZQ(*this);
	TVectorPoro v = abb.Inorden();
	int size = v.Longitud();
	
	for(int i = 1; i <= size; i++)
		arbolIZQ.Insertar(v[i]);

	return arbolIZQ;
}
// Resta de dos ABB
TABBPoro TABBPoro::operator-(TABBPoro &abb)
{
	TABBPoro arbolResultante;
	
	if(EsVacio())
		return arbolResultante;

	if(abb.EsVacio())
		return *this;

	TVectorPoro vI = Inorden();//Operando de la izquierda
	TVectorPoro vD = abb.Inorden();//Operando de la derecha
	int sizevI = vI.Longitud();
	int sizevD = vD.Longitud();
		
	bool insertar = true;
	for(int i = 1; i <= sizevI; i++)
	{
		for(int j = 1; j <= sizevD; j++)
			if(vI[i] == vD[j])
				insertar = false;

		if(insertar)
			arbolResultante.Insertar(vI[i]);

		insertar = true;
	}
	return arbolResultante;
}

ostream& operator<<(ostream &os, const TABBPoro &abb)
{
	if(abb.nodo == NULL)
		os << "[]";
	else
	{
		TVectorPoro recorridoNiveles;
		TABBPoro ab;
		
		ab = abb;
		recorridoNiveles = ab.Niveles();
		os << recorridoNiveles;
	}

	return os;
}












//Abajo implementacion de la clase nodo;


/////////TABBNODO
// Constructor por defecto
TNodoABB::TNodoABB ()
{
	item = TPoro();
	iz = TABBPoro();
	de = TABBPoro();
}

// Constructor de copia
TNodoABB::TNodoABB (const TNodoABB &abb)
{
	item = abb.item;
	iz = abb.iz;
	de = abb.de;
}

// Destructor
TNodoABB:: ~TNodoABB ()
{
	item.~TPoro();
	iz.~TABBPoro();
	de.~TABBPoro();
}

// Sobrecarga del operador asignación
TNodoABB& TNodoABB::operator=(const TNodoABB &abb)
{
	(*this).~TNodoABB();
	item = abb.item;
	iz = abb.iz;
	de = abb.de;

	return *this;
}