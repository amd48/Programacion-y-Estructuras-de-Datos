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


void TListaCalendario:: copiar(const TListaCalendario &t)
{
	
	TListaPos tPos,tAnt;
	tPos=t.Primera();

	TNodoCalendario *aux = new TNodoCalendario();  
	aux->c = tPos.pos->c;							
	primero = aux;
	tAnt.pos = primero;
	tPos = tPos.Siguiente();									


	while(!tPos.EsVacia())
	{
		TNodoCalendario *aux = new TNodoCalendario();
		aux->c = tPos.pos->c;
		tAnt.pos->siguiente = aux;
		tPos=tPos.Siguiente();
		tAnt=tAnt.Siguiente();
	}
}

// Constructor de copia
TListaCalendario::TListaCalendario(const TListaCalendario &l)
{
	copiar(l);
	
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
	if (this != &t)
	{
		this->~TListaCalendario();
		copiar(t);
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
TListaCalendario TListaCalendario::operator+ (const TListaCalendario &l)
{
	TListaCalendario temp(*this);
	
	temp = SumarSubl(1,this->Longitud(),l,1,l.Longitud());
	
	return temp;
}

//Sobrecarga del operador resta
TListaCalendario TListaCalendario::operator- (const TListaCalendario &l)
{
	TListaCalendario temp;
	TListaPos tPos;
	tPos = this->Primera();
	
	while(!tPos.EsVacia())
	{
		if(!(l.Buscar(Obtener(tPos))))
		
			temp.Insertar(this->Obtener(tPos));
			
		tPos = tPos.Siguiente();
	}
	
	return temp;
}
// Inserta el elemento en la posición que le corresponda dentro de la lista
bool TListaCalendario:: Insertar(const TCalendario &calendario)
{
	//TCalendario *tcal;
	//tcal = &primero->c;
	
	bool insertado = false; // NO EXISTE EL ELEMENTO
		
	if(this->Primera().EsVacia()) // INSERTAMOS EL PRIMER NODO EN LA LISTA
	{
		TNodoCalendario *tn = new TNodoCalendario();
		tn->c = calendario;
		tn->siguiente = NULL;
		
		this->primero = tn;
		
		return true;

	}
	else if(this->Buscar(calendario)) // SI EXISTE EL CALENDARIO  NO LO INSERTAMOS
		return false;
	else
	{	
		TListaPos tPos,tAnt;
		
		tPos = this->Primera(); // INTRODUCIMOS PRIMER NODO	
		
		while(!tPos.EsVacia())
		{	
			if(Obtener(tPos) > calendario) // SI EL CALENDARIO ES MAYOR INSERTAMOS
			{
				TNodoCalendario * aux = new TNodoCalendario();
				
				aux->siguiente = tPos.pos; // APUNTAMOS EN NUEVO AL SIGUIENTE
				aux->c = calendario;	// COPIAMOS EL DATO
				tAnt.pos->siguiente = aux; // APUNTAMOS ANTERIOR AL NUEVO
				
				return true;
			}
			else if(tPos.Siguiente().EsVacia()) // CUANDO LLEGA AL FINAL
			{
				TNodoCalendario * aux = new TNodoCalendario();
				aux->siguiente = NULL;
				aux->c = calendario;
				tPos.pos->siguiente = aux;
				return true;
			}
			else // SEGUIMOS RECORRIENDO
			{
				tAnt = tPos;
				tPos = tPos.Siguiente();
			}
		}
	}
		
	return false;
}

// Busca y borra el elemento
bool TListaCalendario:: Borrar(const TCalendario &calendario)
{
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	
	if(Obtener(tPos)==calendario) // PRIMERA POSICION
	{
		this->primero = tPos.Siguiente().pos;
		return true;
	}
	
	while(!tPos.EsVacia())
	{
		if(Obtener(tPos) == calendario)
		{
			if(tPos.Siguiente().EsVacia()) // ULTIMA POSICION
			{
				tAnt.pos->siguiente = NULL;
				
				return true;
			}
			else
			{
				tAnt.pos->siguiente = tPos.pos->siguiente;
				
				return true;
			}  
		}
		
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return false;
}

// Borra el elemento que ocupa la posición indicada
bool TListaCalendario:: Borrar (const TListaPos &tListaPos)
{
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	
	while(!tPos.EsVacia())
	{
		if(tPos == tListaPos)
		{
			if(tPos.Siguiente().EsVacia()) // ULTIMA POSICION
			{
				tAnt.pos->siguiente = NULL;
				
				
				return true;
			}
			else
			{
				tAnt.pos->siguiente = tPos.pos->siguiente;

				
				return true;
			}  
		}
		
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return false;
}
//Borra todos los Calendarios con fecha ANTERIOR a la pasada.
bool TListaCalendario:: Borrar(int dia,int mes,int anyo)
{
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	
	TCalendario aux(dia,mes,anyo,NULL);
	if(this->EsVacia()) // NO HAY CALENDARIOS
		return false;
	if(Obtener(tPos) > aux) // NO EXISTEN FECHAS ANTERIORES
		return false;
	
	while(!tPos.EsVacia())
	{
		if(Obtener(tPos) > aux || Obtener(tPos) == aux )
		{
			if(tPos.Siguiente().EsVacia()) // ULTIMA POSICION
			{
				primero = NULL;
				
				return true;
			}
			else
			{
				primero = tPos.pos->siguiente;
				
				return true;
			}  
		}
		
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return false;
}
// Devuelve true si la lista está vacía, false en caso contrario
bool TListaCalendario:: EsVacia() const
{
	return primero == NULL;
}
// Obtiene el elemento que ocupa la posición indicada
TCalendario TListaCalendario:: Obtener(const TListaPos &tlp) const
{
	return tlp.pos->c;
}
// Devuelve true si el Calendario está en la lista.
bool TListaCalendario:: Buscar(const TCalendario &t)const
{
	TListaPos tPos = this->Primera();
	
	while(!tPos.EsVacia())
	{
		if(tPos.pos->c==t)
			return true;
			
		tPos = tPos.Siguiente();
	}
	
	return false;
}
// Devuelve la longitud de la lista
int TListaCalendario:: Longitud() const 
{
	int n = 0;
	
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	
	while(!tPos.EsVacia())
	{
		n++;
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return n;
}
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
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	
	while(!tPos.EsVacia())
	{
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return tAnt;
}
// Suma de dos sublistas en una nueva lista
TListaCalendario TListaCalendario:: SumarSubl (int I_L1, int F_L1,const TListaCalendario & L2, int I_L2, int F_L2)
{
	TListaCalendario lst1,lst2,lista;
	TListaPos tPos,tPos2;
	
	lst1 = this->ExtraerRango(I_L1,F_L1);
	lst2 = L2.ExtraerRango(I_L2,F_L2);
	
	int longitud;

	longitud = lst1.Longitud()+lst2.Longitud();
	
	tPos =  lst1.Primera();
	tPos2 =  lst2.Primera();
	
	for(int i=0;i<longitud;i++)
	{
		
		if(tPos.EsVacia() || tPos2.EsVacia()) // EN CASO DE QUE ALGUN PUNTERO SE QUEDARA VACIO
		{
			if(!tPos.EsVacia())
			{			
				lista.Insertar(Obtener(tPos));
				tPos = tPos.Siguiente();
			}
			if(!tPos2.EsVacia())
			{
				lista.Insertar(Obtener(tPos2));
				tPos2 = tPos2.Siguiente();
			}
		}
		else
		{
			if(Obtener(tPos) > Obtener(tPos2))
			{
				lista.Insertar(Obtener(tPos2));
				tPos2 = tPos2.Siguiente();
			}
			else if(Obtener(tPos) < Obtener(tPos2))
			{
				lista.Insertar(Obtener(tPos));
				tPos = tPos.Siguiente();
			}
			else 
			{
				lista.Insertar(Obtener(tPos));
				tPos = tPos.Siguiente();
				tPos2 = tPos2.Siguiente();
			}
		}	
	}
	
	return lista;	
}


// Extraer un rango de nodos de la lista
TListaCalendario TListaCalendario:: ExtraerRango (int n1, int n2)const
{
	
	TListaCalendario aux;
	
	if(n1>n2)
		return aux;
	if(n1==n2)
		return aux;
	if(n1<=0)
		n1 = 1;
		
	TListaPos tPos,tAnt;
	tPos = this->Primera();
	tAnt = this->Primera();
	int n = 1;
	
	while(!tPos.EsVacia())
	{
		if(n>=n1 && n<=n2)
		{
			aux.Insertar(Obtener(tPos));
		}
		n++;
		tAnt = tPos;
		tPos = tPos.Siguiente(); 
	}
	
	return aux;
}
//Sobrecarga del operador salida
ostream & operator<<(ostream &os, const TListaCalendario &tLista)
{
	TListaPos tPos;
	
	tPos = tLista.Primera();
	os << '<';
	while(!tPos.EsVacia())
	{
		os << tLista.Obtener(tPos);
		
		if(!tPos.Siguiente().EsVacia())
			os << " ";
			
		tPos = tPos.Siguiente();
	}
	


	os << '>';
	return os;
}


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
TListaPos TListaPos::Siguiente() const
{
	TListaPos aux;
	aux.pos = this->pos->siguiente;
	return aux;
}
// Posición vacía
bool TListaPos::EsVacia() const
{
	if(pos==NULL)
		return true;
	else
		return false;
}


