#include "tavlcom.h"

TAVLCom::TAVLCom()
{
	nodo = NULL;
}

TAVLCom::TAVLCom(const TAVLCom &a)
{
	if(a.nodo != NULL)
		nodo = new TNodoAVL(*a.nodo);
	else
		nodo = NULL;
}

TAVLCom::~TAVLCom()
{
	if(nodo!=NULL)
	{
		delete nodo;
		nodo=NULL;
	}
}

TAVLCom &TAVLCom::operator=(const TAVLCom &a)
{
	if(this!=&a)
	{
		nodo = NULL;
		if(a.nodo)
			nodo = new TNodoAVL(*a.nodo);
	}
	return *this;
}
		
bool TAVLCom::operator==(const TAVLCom &a)const
{
	bool ok = false;
	TVectorCom v1(Nodos());
	TVectorCom v2(a.Nodos());
	v1 = Inorden();
	v2 = a.Inorden();
	
	if(v1 == v2){
		ok = true;
	}
	return ok;
}

bool TAVLCom::operator!=(const TAVLCom &a)const
{
	return !(*this == a);
}

bool TAVLCom::EsVacio() const
{
	bool es = false;
	if(nodo == NULL)
	{
		es = true;
	}
	return es;
}

bool TAVLCom::Insertar(const TComplejo &c)
{
	bool ok;
	if(nodo == NULL){
		nodo = new TNodoAVL();
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
	Equilibrio();
	return ok;
}

bool TAVLCom::Borrar (const TComplejo &c)
{
	bool es = false;
	TNodoAVL *aux;
    if(!EsVacio())
    {
    	if(Buscar(c))
    	{
			if(c < Raiz())
			{
				es = nodo->iz.Borrar(c);
				nodo->fe = (nodo->de.Altura()) - (nodo->iz.Altura());
			}
			else if(c > Raiz())
			{
				es = nodo->de.Borrar(c);
				nodo->fe = (nodo->de.Altura()) - (nodo->iz.Altura());
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
					TNodoAVL *aux2;
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
	Equilibrio();
	return es;
}

bool TAVLCom::Buscar(const TComplejo &c)
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

void TAVLCom::Equilibrio()
{
	if(!EsVacio())
	{
		nodo->fe = nodo->de.Altura() - nodo->iz.Altura();
		if(nodo->fe < -1)
		{
			if(nodo->iz.nodo->fe <= 0)
			{
				EquilibrioII();
			}
			else
			{
				EquilibrioID();
			}
			ActualizarFE();
		}
		else if(nodo->fe > 1)
		{
			if(nodo->de.nodo->fe >= 0)
			{
				EquilibrioDD();
			}
			else
			{
				EquilibrioDI();
			}
			ActualizarFE();
		}
	}
}

void TAVLCom::EquilibrioII()
{
	TNodoAVL *aux;
	aux = nodo->iz.nodo;
	nodo->iz.nodo = aux->de.nodo;
	aux->de.nodo = nodo;
	nodo = aux;
}

void TAVLCom::EquilibrioID()
{
	TNodoAVL *aux;
	aux = nodo->iz.nodo;
	nodo->iz.nodo = aux->de.nodo->de.nodo;
	aux->de.nodo->de.nodo = nodo;
	nodo = aux->de.nodo;
	aux->de.nodo= nodo->iz.nodo;
	nodo->iz.nodo = aux;
}

void TAVLCom::EquilibrioDD()
{
	TNodoAVL *aux;
	aux = nodo->de.nodo;
	nodo->de.nodo = aux->iz.nodo;
	aux->iz.nodo = nodo;
	nodo = aux;
}

void TAVLCom::EquilibrioDI()
{
	TNodoAVL *aux;
	aux = nodo->de.nodo;
	nodo->de.nodo = aux->iz.nodo->iz.nodo;
	aux->iz.nodo->iz.nodo = nodo;
	nodo = aux->iz.nodo;
	aux->iz.nodo = nodo->de.nodo;
	nodo->de.nodo = aux;
}

void TAVLCom::ActualizarFE()
{
	nodo->fe = (nodo->de.Altura()) - (nodo->iz.Altura());
	if(nodo->iz.nodo != NULL)
	{
		nodo->iz.nodo->fe = nodo->iz.nodo->de.Altura() - nodo->iz.nodo->iz.Altura();
	}
	if(nodo->de.nodo != NULL)
	{
		nodo->de.nodo->fe = nodo->de.nodo->de.Altura() - nodo->de.nodo->iz.Altura();
	}
}

TComplejo TAVLCom::Raiz()const
{
	if(nodo == NULL) 
	{
		TComplejo c;
		return c;
	}
	else 
		return nodo->item;
}

int TAVLCom::Altura()const
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

int TAVLCom::Nodos()const
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

int TAVLCom::NodosHoja()const
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

void TAVLCom::InordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		nodo->iz.InordenAux(v, posicion);
		v[posicion++] = nodo->item;
		nodo->de.InordenAux(v, posicion);
	}
}

void TAVLCom::PreordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		v[posicion++] = nodo->item;
		nodo->iz.PreordenAux(v, posicion);
		nodo->de.PreordenAux(v, posicion);
	}
}

void TAVLCom::PostordenAux(TVectorCom &v,int &posicion) const
{
	if(nodo != NULL)
	{
		nodo->iz.PostordenAux(v, posicion);
		nodo->de.PostordenAux(v, posicion);
		v[posicion++] = nodo->item;
	}
}

TVectorCom TAVLCom::Inorden() const
{
	int posicion=1;

	TVectorCom v(Nodos());
	InordenAux(v, posicion);

	return v;
}

TVectorCom TAVLCom::Preorden() const
{
	int posicion = 1;
	TVectorCom v(Nodos());
	PreordenAux(v, posicion);
	return v;
}

TVectorCom TAVLCom::Postorden() const
{
	int posicion = 1;
	TVectorCom v(Nodos());
	PostordenAux(v, posicion);
	return v;
}

ostream &operator<<(ostream &os, const TAVLCom &a)
{
	os << a.Inorden();
	return os;
}

TNodoAVL::TNodoAVL():item(),iz(),de()
{
	fe = 0;
}

TNodoAVL::TNodoAVL (const TNodoAVL &a):item(a.item),iz(a.iz),de(a.de)
{
	fe = a.fe;
}

TNodoAVL::~TNodoAVL()
{

}

TNodoAVL &TNodoAVL::operator=(const TNodoAVL &a)
{
	if(this != &a)
	{
		(*this).~TNodoAVL();
		item = a.item;
		iz = a.iz;
		de = a.de;
		fe = a.fe;
	}
	return *this;
}


