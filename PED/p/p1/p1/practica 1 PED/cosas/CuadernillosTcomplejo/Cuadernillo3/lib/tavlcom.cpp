#include "tavlcom.h"

TAVLCom::TAVLCom()
{
	raiz = NULL;
}

TAVLCom::TAVLCom(const TAVLCom &a)
{
	if(a.raiz != NULL)
		raiz = new TNodoAVL(*a.raiz);
	else
		raiz = NULL;
}

TAVLCom::~TAVLCom()
{
	if(raiz!=NULL)
	{
		delete raiz;
		raiz=NULL;
	}
}

TAVLCom &TAVLCom::operator=(const TAVLCom &a)
{
	if(this!=&a)
	{
		raiz = NULL;
		if(a.raiz)
			raiz = new TNodoAVL(*a.raiz);
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
	if(raiz == NULL)
	{
		es = true;
	}
	return es;
}

bool TAVLCom::Insertar(const TComplejo &c)
{
	bool ok;
	if(raiz == NULL){
		raiz = new TNodoAVL();
		raiz->item = c;		
		ok = true;
	}
	else
		if(c == Raiz())
			ok = false;
		else
			if(c > Raiz())
				ok = raiz->de.Insertar(c);
			else
				ok = raiz->iz.Insertar(c);
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
				es = raiz->iz.Borrar(c);
				raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else if(c > Raiz())
			{
				es = raiz->de.Borrar(c);
				raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else if(Raiz() == c)
			{
				if(raiz->iz.EsVacio() && raiz->de.EsVacio())
				{
					delete raiz;
					raiz = NULL;
				}
				else if(raiz->de.EsVacio())
				{
					aux = raiz;
					raiz = aux->iz.raiz;
					aux->iz.raiz = NULL;
					delete aux;
					aux = NULL;
				}
				else if(raiz->iz.EsVacio())
				{
					aux = raiz;
					raiz = aux->de.raiz;
					aux->de.raiz = NULL;
					delete aux;
					aux = NULL;
				}
				else
				{
					TComplejo mayor;
					TNodoAVL *aux2;
					aux = raiz->iz.raiz;
					while(aux != NULL)
					{
						aux2 = aux;
						aux = aux->de.raiz;
					}
					mayor = aux2->item;
					raiz->iz.Borrar(mayor);
					raiz->item = mayor;
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
	if(raiz == NULL)
		ok = false;
	else{
		if(c == raiz->item)
			ok = true;
		else
			ok = raiz->iz.Buscar(c) || raiz->de.Buscar(c);
	}
	return ok;
}

void TAVLCom::Equilibrio()
{
	if(!EsVacio())
	{
		raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
		if(raiz->fe < -1)
		{
			if(raiz->iz.raiz->fe <= 0)
			{
				EquilibrioII();
			}
			else
			{
				EquilibrioID();
			}
			ActualizarFE();
		}
		else if(raiz->fe > 1)
		{
			if(raiz->de.raiz->fe >= 0)
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
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz;
	aux->de.raiz = raiz;
	raiz = aux;
}

void TAVLCom::EquilibrioID()
{
	TNodoAVL *aux;
	aux = raiz->iz.raiz;
	raiz->iz.raiz = aux->de.raiz->de.raiz;
	aux->de.raiz->de.raiz = raiz;
	raiz = aux->de.raiz;
	aux->de.raiz = raiz->iz.raiz;
	raiz->iz.raiz = aux;
}

void TAVLCom::EquilibrioDD()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz;
	aux->iz.raiz = raiz;
	raiz = aux;
}

void TAVLCom::EquilibrioDI()
{
	TNodoAVL *aux;
	aux = raiz->de.raiz;
	raiz->de.raiz = aux->iz.raiz->iz.raiz;
	aux->iz.raiz->iz.raiz = raiz;
	raiz = aux->iz.raiz;
	aux->iz.raiz = raiz->de.raiz;
	raiz->de.raiz = aux;
}

void TAVLCom::ActualizarFE()
{
	raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
	if(raiz->iz.raiz != NULL)
	{
		raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
	}
	if(raiz->de.raiz != NULL)
	{
		raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
	}
}

TComplejo TAVLCom::Raiz()const
{
	if(raiz == NULL) 
	{
		TComplejo c;
		return c;
	}
	else 
		return raiz->item;
}

int TAVLCom::Altura()const
{
	int altura;
	if(!EsVacio())
	{
		if(raiz->iz.Altura() > raiz->de.Altura())
		{
			altura = 1 + raiz->iz.Altura();
		}
		else
		{
			altura = 1 + raiz->de.Altura();
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
		nodos = 1 + raiz->iz.Nodos() + raiz->de.Nodos();
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
		if(raiz->iz.EsVacio() && raiz->de.EsVacio())
		{
			nodoshoja = 1;
		}
		else
		{
			nodoshoja = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
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
	if(raiz != NULL)
	{
		raiz->iz.InordenAux(v, posicion);
		v[posicion++] = raiz->item;
		raiz->de.InordenAux(v, posicion);
	}
}

void TAVLCom::PreordenAux(TVectorCom &v,int &posicion) const
{
	if(raiz != NULL)
	{
		v[posicion++] = raiz->item;
		raiz->iz.PreordenAux(v, posicion);
		raiz->de.PreordenAux(v, posicion);
	}
}

void TAVLCom::PostordenAux(TVectorCom &v,int &posicion) const
{
	if(raiz != NULL)
	{
		raiz->iz.PostordenAux(v, posicion);
		raiz->de.PostordenAux(v, posicion);
		v[posicion++] = raiz->item;
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


