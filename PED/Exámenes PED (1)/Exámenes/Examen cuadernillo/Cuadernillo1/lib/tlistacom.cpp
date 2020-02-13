#include "tlistacom.h"
#include "tcomplejo.h"


		
TListaNodo::TListaNodo()
{
	anterior = NULL;
	siguiente = NULL;
}
		
TListaNodo::TListaNodo(const TListaNodo &nodo)
{
	anterior = nodo.anterior;
	siguiente = nodo.siguiente;
	e = nodo.e;

}
		
TListaNodo::~TListaNodo()
{
	anterior = NULL;
	siguiente = NULL;
}
		
TListaNodo &TListaNodo::operator=(const TListaNodo &nodo)
{
	if(this != &nodo)
	{
		anterior = nodo.anterior;
		siguiente = nodo.siguiente;
		e = nodo.e;
	}
	return *this;
}
		
TListaPos::TListaPos()
{
	pos = NULL;
}
		
TListaPos::TListaPos(const TListaPos &p)
{
	pos = p.pos;
}
		
TListaPos::~TListaPos()
{
	pos = NULL;
}
	
TListaPos &TListaPos::operator=(const TListaPos &p)
{
	pos = p.pos;
	return *this;
}
		

bool TListaPos::operator==(const TListaPos &p) const
{
	bool igual = false;
	if(pos == p.pos)
	{
		igual = true;
	}
	return igual;
}
		
bool TListaPos::operator!=(const TListaPos &p) const
{
	bool igual = false;
	if(pos != p.pos)
	{
		igual = true;
	}
	return igual;
}
		
TListaPos TListaPos::Anterior() const
{
	TListaPos p;

	if(pos)
	{
		p.pos = pos->anterior;
	}
	return p;
}
		
TListaPos TListaPos::Siguiente() const
{
	TListaPos p;

	if(pos)
	{
		p.pos = pos->siguiente;
	}
	return p;
}
		
bool TListaPos::EsVacia() const
{
	return pos == NULL;
}

		
TListaCom::TListaCom()
{
	primero = NULL;
	ultimo = NULL;
}
		
TListaCom::TListaCom(const TListaCom &lista)
{
	primero = NULL;
	ultimo = NULL;
	*this = lista;
}
	
TListaCom::~TListaCom()
{
	TListaNodo *l = primero;
	do
	{
		if(primero)
		{
			primero = primero->siguiente;
			delete l;
			l = primero;
		}
	}while(primero);
	primero = NULL;
	ultimo = NULL;
}
		
TListaCom &TListaCom::operator=(const TListaCom &lista)
{
	TListaNodo *p;
	if(this != &lista)
	{
		this->~TListaCom();
		p = lista.ultimo;
		do
		{
			if(p)
			{
				InsCabeza(p->e);
				p = p->anterior;
			}
		}while(p);
	}
	return *this;
}		

bool TListaCom::operator==(const TListaCom &lista) const
{
	TListaNodo *p1 = primero;
	TListaNodo *p2 = lista.primero;
	bool igual = true;

	do
	{
		if(p1 != NULL && p2 != NULL && igual == true)
		{
			if(p1->e == p2->e)
			{
				p1 = p1->siguiente;
				p2 = p2->siguiente;
			}
			else
			{
				igual = false;
			}
		}
	}while(p1 != NULL && p2 != NULL && igual == true);
	if(p1 != NULL || p2 != NULL)
	{
		igual = false;
	}
	return igual;
}
		
bool TListaCom::operator!=(const TListaCom &lista) const
{
	return !(*this == lista);
}
		
TListaCom TListaCom::operator+(const TListaCom &lista) const
{
	TListaCom l(*this);
	TListaNodo *p = lista.primero;

	do
	{
		if(p != NULL)
		{
			if(l.EsVacia() == true)
				l.InsCabeza(p->e);
			else
				l.InsertarD(p->e, l.Ultima());		
			p = p->siguiente;
		}
	}while(p != NULL);
	return l;
}
		
TListaCom TListaCom::operator-(const TListaCom &de) const
{
	TListaCom aux;
	TListaNodo *ptL;
	
	ptL = ultimo;
	while(ptL)
	{
		if(!de.Buscar(ptL->e))
			aux.InsCabeza(ptL->e);
		ptL = ptL->anterior;
	}
	return aux;
}
		
bool TListaCom::EsVacia() const
{
	bool vacia = false;

	if(primero == NULL)
	{
		vacia = true;
	}
	return vacia;
}
		
bool TListaCom::InsCabeza(const TComplejo &c)
{
	bool entra = false;
	TListaNodo *p = new TListaNodo;

	if(p)
	{
		entra = true;
		p->siguiente = primero;
		if(primero != NULL)
		{
			primero->anterior = p;
		}
		else
		{
			ultimo = p;
		}
		p->e = c;
		primero = p;
	}
	return entra;
}
		
bool TListaCom::InsertarI(const TComplejo &c, const TListaPos &p)
{
	bool esta = false;
	TListaNodo *p1;

	if(p.pos != NULL)
	{
		if(p.pos == primero)
			esta = InsCabeza(c);
		else
		{
			p1 = new TListaNodo;
			if(p1)
			{
				esta = true;
				p1->e = c;
				p1->siguiente = p.pos;
				p1->anterior = p.pos->anterior;
				p.pos->anterior->siguiente = p1;
				p.pos->anterior = p1;
			}
		}
	}
	return esta;
}
		
bool TListaCom::InsertarD(const TComplejo &c, const TListaPos &p)
{
	bool ok = false;
    TListaNodo *p1, *p2;
	bool esta = false;	
	
	p2 = primero;
	do
	{
		if(p2 && !esta)
		{
			if(p2 == p.pos && !esta && p2 == p.pos )
			esta = true;
		else
			p2 = p2->siguiente;
		}
	}while(p2 && !esta);
	if(esta== true){
		if(!p.EsVacia() && esta)
		{
			p1 = new TListaNodo;
			if(p1)
			{
				ok = true;
				p1->e = c;
				p1->siguiente = p.pos->siguiente;
				p1->anterior = p.pos;
				if(p.pos->siguiente == NULL)
					ultimo = p1;
				else
					p.pos->siguiente->anterior = p1;
				p.pos->siguiente = p1;
			}
		}
	}
	return ok;
}
		
bool TListaCom::Borrar(const TComplejo &c)
{
	bool esta = false;
	TListaNodo *p1, *p2, *p3;
	p1 = primero;

	do
	{
		if(p1 && esta == false)
		{
			if(p1->e == c)
				esta = true;
			else
				p1 = p1->siguiente;
		}
	}while(p1 && esta == false);
	if(esta == true)
	{
		p2 = p1->anterior;
		p3 = p1->siguiente;
		if(!p2)
		{
			primero = p3;
		}
		else
		{
			p2->siguiente = p3;
		}
		if(!p3)
		{
			ultimo = p2;
		}
		else
		{
			p3->anterior = p2;
		}
		delete p1;
	}
	return esta;
}
		
bool TListaCom::BorrarTodos(const TComplejo &c)
{
	bool borra = false;
	TListaNodo *p1, *p2, *p3;
	p1 = primero;

	do
	{
		if(p1)
		{
			if(p1->e == c)
			{
				borra = true;
				p2 = p1->anterior;
				p3 = p1->siguiente;
				if(!p2)
				{
					primero = p3;
					p1 = p3;
				}
				else
				{
					p2->siguiente = p3;
					p1 = p3;
				}
				if(!p3)
				{
					ultimo = p2;
				}
				else
				{
					p3->anterior = p2;
				}
			}
			else
				p1 = p1->siguiente;
		}
	}while(p1);
	return borra;
}
		
bool TListaCom::Borrar(TListaPos &p)
{
	bool esta = false;
	TListaNodo *p1 = primero;

	if(!p.EsVacia()){
		while(p1 && !esta)
		{
			if(p1 == p.pos)
				esta = true;
			else
				p1 = p1->siguiente;
		}
		if(esta){
			if(p1 == primero){
				primero = primero->siguiente;
				if(primero != NULL){
					primero->anterior = NULL;
				}									
			}
			else{
				if(p1 == ultimo){
					ultimo = ultimo->anterior;
					if(ultimo != NULL){
						ultimo->siguiente = NULL;
					}
				}
				else{
					p1->anterior->siguiente = p1->siguiente;
					p1->siguiente->anterior = p1->anterior;
				}
			}
			delete p1;
			p.pos = NULL;
		}
	}
	return esta;
}
		
TComplejo TListaCom::Obtener(const TListaPos &lista) const
{
	TComplejo c;
	TListaNodo *p = primero;
	bool obtenido = false;

	do
	{
		if(p && obtenido == false)
		{
			if(p == lista.pos)
			{
				obtenido = true;
			}
			else
			{
				p = p->siguiente;
			}
		}
	}while(p && obtenido == false);
	if(obtenido)
	{
		c = p->e;
	}
	return c;
}
		
bool TListaCom::Buscar(const TComplejo &c) const
{
	TListaNodo *p = primero;
	bool esta = false;
	do
	{
		if(p != NULL && !esta)
		{
			if(p->e == c)
			{
				esta = true;
			}
			else
				p = p->siguiente;
		}
	}while(p != NULL && !esta);
	return esta;
}
		
int TListaCom::Longitud() const
{
	int n = 0;
	TListaNodo *p = primero;
	do
	{
		if(p)
		{
			p = p->siguiente;
			n++;
		}
	}while(p);
	return n;
}
		
TListaPos TListaCom::Primera() const
{
	TListaPos lista;

	lista.pos = primero;
	return lista;
}
		
TListaPos TListaCom::Ultima() const
{
	TListaPos lista;

	lista.pos = ultimo;
	return lista;
}
		
ostream &operator<<(ostream &os, const TListaCom &lista)
{
	TListaNodo *p;

	if(lista.primero != NULL)
	{
		os << "{";
		p = lista.primero;
		do
		{
			if(p)
			{
				os << p->e;
				if(p->siguiente)
				{
					os << ' ';
				}
				p = p->siguiente;
			}
		}while(p);
		os << "}";
	}
	else
	{
		os << "{}";
	}
	return os;
}
