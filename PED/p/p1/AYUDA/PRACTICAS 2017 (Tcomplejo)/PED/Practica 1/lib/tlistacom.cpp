#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "tlistacom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

//-----------------TListaNodo--------------------

TListaNodo::TListaNodo(){
	anterior = NULL;
   	siguiente = NULL;
}

TListaNodo::TListaNodo(const TListaNodo &nodo){
    	anterior = nodo.anterior;
    	siguiente = nodo.siguiente;
    	e = nodo.e;
}

TListaNodo::~TListaNodo(){
    	anterior = NULL;
    	siguiente = NULL;
}

TListaNodo &TListaNodo::operator=(const TListaNodo &nodo){
    	anterior = nodo.anterior;
    	siguiente = nodo.siguiente;
    	e = nodo.e;
    	return(*this);
}

//-------------------TListaCom---------------------

TListaCom::TListaCom(){
    	primero = NULL;
    	ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &lis){
    	primero = NULL;
    	ultimo = NULL;
    	*this = lis;
}

TListaCom::~TListaCom(){
    	TListaNodo *aux;
    	aux = primero;
    	while(primero != NULL){
        	primero = primero->siguiente;
        	delete(aux);
        	aux = primero;
    	}	
    	primero = NULL;
    	ultimo = NULL;
}

TListaCom &TListaCom::operator=(const TListaCom &lis){
    	TListaNodo *res;
    	if(EsVacia() == false)
        	this->~TListaCom();
	res = lis.ultimo;
    	while(res != NULL){
        	InsCabeza(res->e);
        	res = res->anterior;
	}
   	return(*this);
}

bool TListaCom::operator==(const TListaCom &lis)const{
	bool b = true;
	TListaNodo *nod1; 
	TListaNodo *nod2;
	nod1 = primero;
	nod2 = lis.primero;
	while((nod1 != NULL) && (nod2 != NULL) && (b == true))
		if(nod1->e != nod2->e)
			b = false;
		else{
			nod1 = nod1->siguiente;
			nod2 = nod2->siguiente;}
	return(b);
}

bool TListaCom::operator!=(const TListaCom &lis)const{
	bool b = true;
	if(*this == lis)
		b = false;
	return(b);
}

TListaCom TListaCom::operator+(const TListaCom &lis)const{
	TListaCom sum;
        TListaNodo *nod;
 	sum = lis;
	nod = ultimo;
	while(nod != NULL){
		sum.InsCabeza(nod->e);
		nod = nod->anterior;
	}
	return(sum);
}

TListaCom TListaCom::operator-(const TListaCom &lis)const{
	TListaCom res;
	TListaNodo *nod;
	nod = ultimo;
	while(nod != NULL){
		if(lis.Buscar(nod->e) == false)
			res.InsCabeza(nod->e);
			nod = nod->anterior;
	}
	return(res);
}

bool TListaCom::EsVacia()const{
    	bool b;
    	if((primero == ultimo) && (primero == NULL))
        	b = true;
    	else
    		b = false;
    	return(b);
}

bool TListaCom::InsCabeza(const TComplejo &com){
    	bool b = false;
    	TListaNodo *nodo;
    	nodo = new TListaNodo;
    	if(nodo != NULL){
        	b = true;
        	nodo->siguiente = primero;
        	if(primero != NULL)
           		primero->anterior = nodo;
        	else
            		ultimo = nodo;
		nodo->e = com;
        	primero = nodo;
    }
    return(b);
}

bool TListaCom::InsertarI(const TComplejo &com,const TListaPos &pos){
	bool b = false;
    	TListaNodo *nodo;
    	if(pos.pos != NULL){
        	if(pos.pos == primero)
            		b = InsCabeza(com);
        	else{
            		nodo = new TListaNodo;
            		if(nodo != NULL){
                		b = true;
                		nodo->e = com;
               			nodo->siguiente = pos.pos;
                		nodo->anterior = pos.pos->anterior;
                		pos.pos->anterior->siguiente = nodo;
                		pos.pos->anterior = nodo;
            }
        }
    }
    return(b);
}

bool TListaCom::InsertarD(const TComplejo &c,const TListaPos &p){
	bool b = false;
        TListaNodo *nod;
	if(p.EsVacia() == false){
		nod = new TListaNodo;
		if(nod != NULL){
			b = true;
			nod->e = c;
			nod->siguiente = p.pos->siguiente;
			nod->anterior = p.pos;
			if(p.pos->siguiente == NULL)
				ultimo = nod;
			else
				p.pos->siguiente->anterior = nod;
			p.pos->siguiente = nod;
		}
	}
	return(b);
}

bool TListaCom::Borrar(const TComplejo &co){
	bool b = false;
	TListaNodo *nod;	
	TListaNodo *nodpre;	
	TListaNodo *nodpost;	
	nod = primero;
	while((nod != NULL) && (b == false)){
		if(nod->e == co){
			b = true;
			nodpre = nod->anterior;
			nodpost = nod->siguiente;
			if(nodpre != NULL)
				nodpre->siguiente = nodpost;
			else
				primero = nodpost;

			if(nodpost != NULL)
				nodpost->anterior = nodpre;
			else
				ultimo = nodpre;
			delete nod;
		}
		else
			nod = nod->siguiente;
	}
	return(b);	
}

bool TListaCom::BorrarTodos(const TComplejo &co){
	bool b = false;
	TListaNodo *nod;
	TListaNodo *nod2;	
	TListaNodo *nodpre;	
	TListaNodo *nodpost;
	nod = primero;
	while(nod != NULL){
		if(nod->e == co){
			b = true;
			nod2 = nod;
			nodpre = nod->anterior;
			nodpost = nod->siguiente;
			if(nodpre != NULL){
				nodpre->siguiente = nodpost;
				nod = nodpost;}
			else{
				primero = nodpost;
				nod = primero;}
			if(nodpost != NULL)
				nodpost->anterior = nodpre;
			else
				ultimo = nodpre;

			delete nod2;
		}
		else
			nod = nod->siguiente;			
	}
	return(b);
}


bool TListaCom::Borrar(TListaPos &pos){
	bool b = false;
	TListaNodo *nod = primero;	
	TListaNodo *nodpre;	
	TListaNodo *nodpost;	
	if(pos.EsVacia() == false){
		while((nod != NULL) && (b == false)){
			if(nod == pos.pos){
				b = true;
				nodpre = nod->anterior;
				nodpost = nod->siguiente;
				if(nodpre != NULL)
					nodpre->siguiente = nodpost;
				else
					primero = nodpost;

				if(nodpost != NULL)
					nodpost->anterior = nodpre;
				else
					ultimo = nodpre;

				delete nod;
				pos.pos = NULL;	
			}			
			else
			nod = nod->siguiente;
		}
	}
	return(b);
}

TComplejo TListaCom::Obtener(const TListaPos &po)const{
	bool b = false;
	TComplejo co;
	TListaNodo *nod;
	nod = primero;
	while((nod != NULL) && (b == false)){
		if(nod == po.pos){
			co = nod->e;
			b = true;
		}
		else
			nod = nod->siguiente;	
	}		
	return(co);
}

bool TListaCom::Buscar(const TComplejo &co)const{
	bool b = false;
	TListaNodo *nod = NULL;
	nod = primero;
	while((nod != NULL) && (b == false))
		if(nod->e == co)
			b = true;
		else
			nod = nod->siguiente;
	return(b);
}

int TListaCom::Longitud()const{
	int lon;
	TListaNodo *nod = primero;
	lon = 0;
	while(nod != NULL){
                lon++;
		nod = nod->siguiente;
	}
        return(lon);
}

TListaPos TListaCom::Primera()const{
        TListaPos p;
	p.pos = primero;
	return(p);
}

TListaPos TListaCom::Ultima()const{
	TListaPos u;
	u.pos = ultimo;
	return(u);
}

ostream & operator<<(ostream &salida,const TListaCom &lis){
	TListaNodo *nod = lis.primero;
	if(lis.primero == NULL)
		salida << "{}";
	else{
		salida << "{";
		while(nod != NULL){
			salida << nod->e;
			if(nod->siguiente != NULL){ 
				salida << ' ';}
			nod = nod->siguiente;
		}
		salida << "}";
	}
	return(salida);
}

//------------------TListaPos-----------------

TListaPos::TListaPos(){
	pos = NULL;
}

TListaPos::~TListaPos(){
	pos = NULL;
}

TListaPos::TListaPos(const TListaPos &x){
	pos = x.pos;
}

TListaPos TListaPos::operator=(const TListaPos &x){
	pos = x.pos;
	return(*this);
}

bool TListaPos::operator==(const TListaPos &x)const{
	bool b = false;
	if(pos == x.pos)
		b = true;
	return(b);
}

bool TListaPos::operator!=(const TListaPos &x)const{
	bool b = false;
	if(pos != x.pos)
		b = true;
	return(b);
}

TListaPos TListaPos::Anterior()const{
	TListaPos x;
	if(pos != NULL)
		x.pos = pos->anterior;
	return(x);
}

TListaPos TListaPos::Siguiente()const{
	TListaPos x;
	if(pos != NULL)
		x.pos = pos->siguiente;
	return(x);
}

bool TListaPos::EsVacia()const{
	bool b = false;
	if(pos == NULL)
		b = true;
	return(b);
}
