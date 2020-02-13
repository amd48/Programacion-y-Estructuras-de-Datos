
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include "tavlcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

// ------------------------------------------ TNodoAVL --------------------------------------------

//Constructor por defecto
TNodoAVL::TNodoAVL(){
    item = TComplejo();
    iz = TAVLCom();
    de = TAVLCom();
    fe = 0;	
}

// Constructor de copia
TNodoAVL::TNodoAVL (const TNodoAVL &a){
    item = a.item;
    iz = a.iz;
    de = a.de;
    fe = a.fe;
}

// Destructor
TNodoAVL::~TNodoAVL (){
    item = TComplejo();
    iz.~TAVLCom();
    de.~TAVLCom();
}

// Sobrecarga del operador asignación
TNodoAVL &TNodoAVL::operator=(const TNodoAVL &a){
    if(this != &a){
	(*this).~TNodoAVL();
    	item = a.item;
    	iz = a.iz;
    	de = a.de;
	fe = a.fe;
	}
    return(*this);
}

// ------------------------------------------ TAVL ---------------------------------------------

//Constructor por defecto
TAVLCom::TAVLCom(){
    raiz = NULL;
}

// Constructor de copia
TAVLCom::TAVLCom(const TAVLCom &a){
        if(a.raiz != NULL)
                raiz = new TNodoAVL(*a.raiz);
	else
                raiz = NULL;
}
//Destructor
TAVLCom::~TAVLCom(){
        if(raiz != NULL){
                delete raiz;
                raiz = NULL;
	}
}

// Sobrecarga del operador asignacion
TAVLCom &TAVLCom::operator=(const TAVLCom &a){
   	if(this != &a){
                raiz = NULL;
                if(a.raiz)
                        raiz = new TNodoAVL(*a.raiz);
	}
	return(*this);
}

// Sobrecarga del operador igualdad
bool TAVLCom::operator==(const TAVLCom &a) const{
    bool b = false;
    if(Inorden() == a.Inorden())
        b = true;
    return(b);
}

// Sobrecarga del operador desigualdad
bool TAVLCom::operator!=(const TAVLCom &a) const{
    bool b = false;
    if(Inorden() != a.Inorden())
        b = true;
    return(b);
}

//Devuelve TRUE si el arbol esta vacio
bool TAVLCom::EsVacio() const{
    bool b = false;
    if(raiz == NULL)
        b = true;
    return(b);
}

//Insertar el elemento en el arbol
bool TAVLCom::Insertar(const TComplejo &co){
	bool b;
        if(raiz == NULL){
                raiz = new TNodoAVL();
                raiz->item = co;
		b = true;}
	else{
		if(co != Raiz())
			if(co > Raiz())
                                b = raiz->de.Insertar(co);
			else
                                b = raiz->iz.Insertar(co);
		else{
			b = false;

		}
	}
	Equilibrado();
	return(b);
}

//Devuelve TRUE si en cuentra el elemento en el arbol
bool TAVLCom::Buscar(const TComplejo &co)const{
    bool b;
    if(raiz == NULL)
        b = false;
    else{
        if(co == raiz->item)
            b = true;
        else
            b = (raiz->iz.Buscar(co) || raiz->de.Buscar(co));
    }
    return(b);
}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TAVLCom::Altura()const{
    int al;
    int iz;
    int de;

    if(raiz == NULL)
        al = 0;
    else{
        iz = raiz->iz.Altura();
        de = raiz->de.Altura();
        if(iz <= de)
            al = de + 1;
        else
            al = iz + 1;
    }
    return(al);
}

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TAVLCom::Nodos()const{
    int n = 0;
    if(raiz == NULL)
        n = 0;
    else
        n = (raiz->iz.Nodos() + raiz->de.Nodos()) + 1;
    return(n);
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TAVLCom::NodosHoja()const{
    int n;
    if(raiz == NULL)
        n = 0;
    else
        if((raiz->iz.EsVacio()) && (raiz->de.EsVacio()))
            n = 1;
        else
            n = raiz->iz.NodosHoja() + raiz->de.NodosHoja();
    return(n);
}

// Devuelve el recorrido en inorden
TVectorCom TAVLCom::Inorden()const{
    int pos;
    TVectorCom vec(Nodos());
    pos = 1;
    InordenAux(vec, pos);
    return(vec);
}

//Auxiliar inorden
void TAVLCom::InordenAux(TVectorCom &vec, int &pos)const{
    if(raiz != NULL){
        raiz->iz.InordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
        raiz->de.InordenAux(vec, pos);
    }
}

// Devuelve el recorrido en preorden
TVectorCom TAVLCom::Preorden()const{
    int pos;
    TVectorCom vec( Nodos() );
    pos = 1;
    PreordenAux(vec, pos);
    return(vec);
}

//Auxiliar preorden
void TAVLCom::PreordenAux(TVectorCom &vec, int &pos)const{
    if(raiz != NULL){
        vec[pos] = raiz->item;
        pos++;
        raiz->iz.PreordenAux(vec, pos);
        raiz->de.PreordenAux(vec, pos);
    }
}

// Devuelve el recorrido en postorden
TVectorCom TAVLCom::Postorden()const{
    int pos;
    TVectorCom vec( Nodos());
    pos = 1;
    PostordenAux(vec, pos);
    return(vec);
}

//Auxiliar postorden
void TAVLCom::PostordenAux(TVectorCom &vec, int &pos)const{
    if(raiz != NULL){
        raiz->iz.PostordenAux(vec, pos);
        raiz->de.PostordenAux(vec, pos);
        vec[pos] = raiz->item;
        pos++;
    }
}

// Devuelve el recorrido en niveles
TVectorCom TAVLCom::Niveles() const{
    TVectorCom vec(Nodos());
    queue<TNodoAVL *> cola;
    TNodoAVL *a;
    int n;
    n = 1;
    if(raiz != NULL)
        cola.push(raiz);
    while(!cola.empty()){
        a = cola.front();
        cola.pop();
        vec[n] = a->item;
        n++;
        if(a->iz.raiz != NULL)
            cola.push(a->iz.raiz);
        if(a->de.raiz != NULL)
            cola.push(a->de.raiz);
    }
    return(vec);
}

// Devuelve el elemento en la raíz del árbol
TComplejo TAVLCom::Raiz()const{
    TComplejo co;
    if(raiz != NULL)
        co = raiz->item;
    return(co);
}

//Borra el elemento de un arbol si lo encuentra
bool TAVLCom::Borrar(const TComplejo &co){
	bool b = false;
	TNodoAVL *n;
	TNodoAVL *n2;
	TComplejo mayor;
					
	if(EsVacio() == false){
                if(Buscar(co) == true){
			if(co > Raiz()){
                                b = raiz->de.Borrar(co);
                                raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else
			if(co < Raiz()){
                                b = raiz->iz.Borrar(co);
                                raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
			}
			else 
			if(Raiz() == co){
                                if((raiz->iz.EsVacio()) && (raiz->de.EsVacio())){
                                        delete raiz;
                                        raiz = NULL;
				}
				else 
                                if(raiz->de.EsVacio()){
                                        n = raiz;
                                        raiz = n->iz.raiz;
                                        n->iz.raiz = NULL;
					delete n;
					n = NULL;
				}
				else 
                                if(raiz->iz.EsVacio()){
                                        n = raiz;
                                        raiz = n->de.raiz;
                                        n->de.raiz = NULL;
					delete n;
					n = NULL;
				}
				else{
                                        n = raiz->iz.raiz;
					while(n != NULL){
						n2 = n;
                                                n = n->de.raiz;}
					mayor = n2->item;
                                        raiz->iz.Borrar(mayor);
                                        raiz->item = mayor;
				}
				b = true;
			}
		}
	}
	Equilibrado();
	return(b);
}

// Sobrecarga del operador salida
ostream &operator<<(ostream &os, const TAVLCom &a){
    os << a.Inorden();
    return(os);
}

//Auxiliar equilibradora jefa
void TAVLCom::Equilibrado(){
	if(EsVacio() == false){
                raiz->fe = (raiz->de.Altura() - raiz->iz.Altura());
                if(raiz->fe < -1){
                        if(raiz->iz.raiz->fe > 0){
				EquilibradoID();
			}
			else{
				EquilibradoI();
			}
			Actualizar();
		}
		else 
                if(raiz->fe > 1){
                        if(raiz->de.raiz->fe < 0)
				EquilibradoDI();
			else
				EquilibradoD();

			Actualizar();
		}
	}
}

//Auxiliar equilibradora derecha derecha
void TAVLCom::EquilibradoD(){
        TNodoAVL *nod;
        nod = raiz->de.raiz;
        raiz->de.raiz = nod->iz.raiz;
        nod->iz.raiz = raiz;
        raiz = nod;
}

//Auxiliar equilibradora izquierda izquierda
void TAVLCom::EquilibradoI(){
	TNodoAVL *nod;
        nod = raiz->iz.raiz;
        raiz->iz.raiz = nod->de.raiz;
        nod->de.raiz = raiz;
        raiz = nod;
}

//Auxiliar equilibradora derecha izquierda
void TAVLCom::EquilibradoDI(){
        TNodoAVL *nod;
        nod = raiz->de.raiz;
        raiz->de.raiz = nod->iz.raiz->iz.raiz;
        nod->iz.raiz->iz.raiz = raiz;
        raiz = nod->iz.raiz;
        nod->iz.raiz = raiz->de.raiz;
        raiz->de.raiz = nod;
}

//Auxiliar equilibradora izquierda derecha
void TAVLCom::EquilibradoID(){
	TNodoAVL *nod;
        nod = raiz->iz.raiz;
        raiz->iz.raiz = nod->de.raiz->de.raiz;
        nod->de.raiz->de.raiz = raiz;
        raiz = nod->de.raiz;
        nod->de.raiz= raiz->iz.raiz;
        raiz->iz.raiz = nod;
}

//Acualiza el árbol AVL
void TAVLCom::Actualizar(){
        raiz->fe = (raiz->de.Altura()) - (raiz->iz.Altura());
        if(raiz->iz.raiz != NULL)
                raiz->iz.raiz->fe = (raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura());
        if(raiz->de.raiz != NULL)
                raiz->de.raiz->fe = (raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura());
}


