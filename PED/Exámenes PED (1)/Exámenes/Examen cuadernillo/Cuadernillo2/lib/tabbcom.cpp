#include "tabbcom.h"
#include <queue>

TABBCom::TABBCom()
{
	nodo = NULL;
}

TABBCom::TABBCom(const TABBCom &c)
{
	if(c.nodo != NULL)
		nodo = new TNodoABB(*c.nodo);
	else
		nodo = NULL;
}

TABBCom::~TABBCom()
{
	if(nodo!=NULL)
	{
		delete nodo;
		nodo=NULL;
	}
}

TABBCom &TABBCom::operator=(const TABBCom &c)
{
	if(this!=&c)
	{
		nodo = NULL;
		if(c.nodo)
			nodo = new TNodoABB(*c.nodo);
	}
	return *this;
}

bool TABBCom::operator==(const TABBCom &t)const
{
	bool ok = false;
	TVectorCom v1(Nodos());
	TVectorCom v2(t.Nodos());
	v1 = Inorden();
	v2 = t.Inorden();
	
	if(v1 == v2){
		ok = true;
	}
	return ok;
}

bool TABBCom::EsVacio() const
{
	bool ok = false;
	if(nodo == NULL)
	{
		ok = true;
	}
	return ok;
}

bool TABBCom::Insertar(const TComplejo &c){
	bool ok;
	if(nodo == NULL){
		nodo = new TNodoABB();
		nodo->item = c;		
		ok = true;
	}
	else
		if(c == Raiz())
			ok = false;
		else
			if(c > Raiz())
				ok = nodo->de.Insertar(c);
			else
				ok = nodo->iz.Insertar(c);
	return ok;
}

bool TABBCom::Borrar (const TComplejo &c)
{
	bool es = false;
	TNodoABB *aux;
    if(!EsVacio())
    {
    	if(Buscar(c))
    	{
			if(c < Raiz())
			{
				es = nodo->iz.Borrar(c);
			}
			else if(c > Raiz())
			{
				es = nodo->de.Borrar(c);
			}
			else if(Raiz() == c)
			{
				if(nodo->iz.EsVacio() && nodo->de.EsVacio())
				{
					delete nodo;
					nodo = NULL;
				}
				else if(nodo->de.EsVacio())
				{
					aux = nodo;
					nodo = aux->iz.nodo;
					aux->iz.nodo = NULL;
					delete aux;
					aux = NULL;
				}
				else if(nodo->iz.EsVacio())
				{
					aux = nodo;
					nodo = aux->de.nodo;
					aux->de.nodo = NULL;
					delete aux;
					aux = NULL;
				}
				else
				{
					TComplejo mayor;
					TNodoABB *aux2;
					aux = nodo->iz.nodo;
					while(aux != NULL)
					{
						aux2 = aux;
						aux = aux->de.nodo;
					}
					mayor = aux2->item;
					nodo->iz.Borrar(mayor);
					nodo->item = mayor;
				}
				es = true;
			}
		}
	}
	return es;
}

bool TABBCom::Buscar(const TComplejo &c)
{
	bool ok;
	if(nodo == NULL)
		ok = false;
	else{
		if(c == nodo->item)
			ok = true;
		else
			ok = nodo->iz.Buscar(c) || nodo->de.Buscar(c);
	}
	return ok;
}

TComplejo TABBCom::Raiz()const
{
	if(nodo == NULL) 
	{
		TComplejo c;
		return c;
	}
	else 
		return nodo->item;
}

int TABBCom::Altura()const
{
	int altura;
	if(!EsVacio())
	{
		if(nodo->iz.Altura() > nodo->de.Altura())
		{
			altura = 1 + nodo->iz.Altura();
		}
		else
		{
			altura = 1 + nodo->de.Altura();
		}
	}
	else
	{
		altura = 0;
	}
	return altura;
}

int TABBCom::Nodos()const
{
	int nodos;
	if(!EsVacio())
	{
		nodos = 1 + nodo->iz.Nodos() + nodo->de.Nodos();
	}
	else
	{
		nodos = 0;
	}
	return nodos;
}

int TABBCom::NodosHoja()const
{
	int nodoshoja;
	if(!EsVacio())
	{
		if(nodo->iz.EsVacio() && nodo->de.EsVacio())
		{
			nodoshoja = 1;
		}
		else
		{
			nodoshoja = nodo->iz.NodosHoja() + nodo->de.NodosHoja();
		}
	}
	else
	{
		nodoshoja = 0;
	}
	return nodoshoja;
}

ostream &operator<<(ostream &os, const TABBCom &t)
{
	os << t.Niveles();
	return os;
}

void TABBCom::InordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		nodo->iz.InordenAux(v, posicion);
		v[posicion++] = nodo->item;
		nodo->de.InordenAux(v, posicion);
	}
}

void TABBCom::PreordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		v[posicion++] = nodo->item;
		nodo->iz.PreordenAux(v, posicion);
		nodo->de.PreordenAux(v, posicion);
	}
}

void TABBCom::PostordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		nodo->iz.PostordenAux(v, posicion);
		nodo->de.PostordenAux(v, posicion);
		v[posicion++] = nodo->item;
	}
}

TVectorCom TABBCom::Inorden() const
{
	int posicion=1;

	TVectorCom v(Nodos());
	InordenAux(v, posicion);

	return v;
}

TVectorCom TABBCom::Preorden() const
{
	int posicion = 1;

	TVectorCom v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

TVectorCom TABBCom::Postorden() const
{
	int posicion = 1;

	TVectorCom v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

TVectorCom TABBCom::Niveles() const
{
	TVectorCom vp(Nodos());
	if(!EsVacio())
	{
		TNodoABB *aux;
		queue<TNodoABB*> myqueue;
		myqueue.push(nodo);
		for (int i = 1; i <= vp.Tamano(); ++i)
		{
			aux = myqueue.front();
			myqueue.pop();
			vp[i] = aux->item;
			if(!aux->iz.EsVacio() && !aux->de.EsVacio())
			{
				myqueue.push(aux->iz.nodo);
				myqueue.push(aux->de.nodo);
			}
			if(!aux->iz.EsVacio() && aux->de.EsVacio())
			{
				myqueue.push(aux->iz.nodo);
			}
			if(!aux->de.EsVacio() && aux->iz.EsVacio())
			{
				myqueue.push(aux->de.nodo);
			}
		}
	}
	return vp;
}


TNodoABB::TNodoABB() :item(), iz(), de()
{

}

TNodoABB::TNodoABB (const TNodoABB &n) :item(n.item), iz(n.iz), de(n.de)
{
	
}

TNodoABB::~TNodoABB()
{
	
}

TNodoABB &TNodoABB::operator=(const TNodoABB &n)
{
	if(this!=&n)
	{
		
		item = n.item;
		iz=n.iz;
		de = n.de;
	}
	return *this;
}

