#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"

using namespace std;

//Constructor por defecto
TNodoABB::TNodoABB(){
    item = TComplejo();
    iz = TABBCom();
    de = TABBCom();
}

// Constructor de copia
TNodoABB::TNodoABB (const TNodoABB &a){
    item = a.item;
    iz = a.iz;
    de = a.de;
}

// Destructor
TNodoABB::~TNodoABB (){
    item = TComplejo();
    iz.~TABBCom();
    de.~TABBCom();
}

// Sobrecarga del operador asignación
TNodoABB &TNodoABB::operator=(const TNodoABB &a){
    item = a.item;
    iz = a.iz;
    de = a.de;
    return(*this);
}

TNodoABB::TNodoABB(const TComplejo &e){
    item = e;
}


TABBCom::TABBCom(){
    nodo = NULL;
}

TABBCom::TABBCom (const TABBCom &a){
    if(a.nodo != NULL)
        nodo = new TNodoABB(*a.nodo);
    else
        nodo = NULL;
}

TABBCom::~TABBCom (){
    delete nodo;
    nodo = NULL;
}

// Sobrecarga del operador asignacion
TABBCom &TABBCom::operator=(const TABBCom &a){
    this->~TABBCom();
    nodo = NULL;

    nodo = new TNodoABB(a.nodo->item);
    nodo->de = a.nodo->de;
    nodo->iz = a.nodo->iz;
    if(a.nodo != NULL)
        nodo = new TNodoABB(*a.nodo);
    return(*this);
}

// Sobrecarga del operador igualdad
bool TABBCom::operator==(const TABBCom &a) const{
    bool b = false;
    if(Inorden() == a.Inorden())
        b = true;
    return(b);
}

//Devuelve TRUE si el arbol esta vacio
bool TABBCom::EsVacio() const{
    bool b = false;
    if(nodo == NULL)
        b = true;
    return(b);
}

//Insertar el elemento en el arbol
bool TABBCom::Insertar(const TComplejo &co){
    bool b;
    //caso base
    if(nodo == NULL){
        nodo = new TNodoABB();
        nodo->item = co;
        b = true;
    }
    else
        if(co == nodo->item)
            b = false;
        else
            if((co.Mod() > nodo->item.Mod()) || ((co.Mod() == nodo->item.Mod()) && (co.Re() > nodo->item.Re())) || ((co.Mod() == nodo->item.Mod()) && (co.Re() == nodo->item.Re())) || (co.Im() > nodo->item.Im()))
                b = nodo->de.Insertar(co);
            else
                b = nodo->iz.Insertar(co);
    return(b);
}

//Borra el elemento de un arbol si lo encuentra
bool TABBCom::Borrar(const TComplejo &co){
    bool b = false;
    /*TNodoABB *nod;
    TComplejo co;

    if(nodo == NULL){
        b = false;
    }
    else{*/

    return(b);
}

//Devuelve TRUE si en cuentra el elemento en el arbol
bool TABBCom::Buscar(const TComplejo &co)const{
    bool b;
    if(nodo == NULL)
        b = false;
    else{
        if(co == nodo->item)
            b = true;
        else
            b = (nodo->iz.Buscar(co) || nodo->de.Buscar(co));
    }
    return(b);
}

// Devuelve el elemento en la raíz del árbol
TComplejo TABBCom::Raiz()const{
    TComplejo co;
    if(nodo != NULL)
        co = nodo->item;
    return(co);
}

// Devuelve la altura del árbol (la altura de un árbol vacío es 0)
int TABBCom::Altura()const{
    int al;
    int iz;
    int de;

    if(nodo == NULL)
        al = 0;
    else{
        iz = nodo->iz.Altura();
        de = nodo->de.Altura();
        if(iz <= de)
            al = de + 1;
        else
            al = iz + 1;
    }
    return(al);
}

// Devuelve el número de nodos del árbol (un árbol vacío posee 0 nodos)
int TABBCom::Nodos()const{
    int n=0;
    if(nodo == NULL)
        n=0;
    else
        n = (nodo->iz.Nodos() + nodo->de.Nodos()) + 1;
    return(n);
}

// Devuelve el número de nodos hoja en el árbol (la raíz puede ser nodo hoja)
int TABBCom::NodosHoja()const{
    int n;
    if(nodo == NULL)
        n = 0;
    else
        if((nodo->iz.EsVacio()) && (nodo->de.EsVacio()))
            n = 1;
        else
            n = nodo->iz.NodosHoja() + nodo->de.NodosHoja();
    return(n);
}

// Devuelve el recorrido en inorden
TVectorCom TABBCom::Inorden()const{
    int pos;
    TVectorCom vec(Nodos());
    pos = 1;
    auxin(vec, pos);
    return(vec);
}

//Auxiliar inorden
void TABBCom::auxin(TVectorCom &vec, int &pos)const{
    if(nodo != NULL){
        nodo->iz.auxin(vec, pos);
        vec[pos] = nodo->item;
        pos++;
        nodo->de.auxin(vec, pos);
    }
}

// Devuelve el recorrido en preorden
TVectorCom TABBCom::Preorden()const{
    int pos;
    TVectorCom vec( Nodos() );
    pos = 1;
    auxpre(vec, pos);
    return(vec);
}

//Auxiliar preorden
void TABBCom::auxpre(TVectorCom &vec, int &pos)const{
    if(nodo != NULL){
        vec[pos] = nodo->item;
        pos++;
        nodo->iz.auxpre(vec, pos);
        nodo->de.auxpre(vec, pos);
    }
}

// Devuelve el recorrido en postorden
TVectorCom TABBCom::Postorden()const{
    int pos;
    TVectorCom vec( Nodos());
    pos = 1;
    auxpost(vec, pos);
    return(vec);
}

//Auxiliar postorden
void TABBCom::auxpost(TVectorCom &vec, int &pos)const{
    if(nodo != NULL){
        nodo->iz.auxpost(vec, pos);
        nodo->de.auxpost(vec, pos);
        vec[pos] = nodo->item;
        pos++;
    }
}

// Devuelve el recorrido en niveles
TVectorCom TABBCom::Niveles() const{
    TVectorCom vec(Nodos());
    queue<TNodoABB *> cola;
    TNodoABB *a;
    int n;
    n = 1;
    if(nodo != NULL)
        cola.push(nodo);
    while(!cola.empty()){
        a = cola.front();
        cola.pop();
        vec[n] = a->item;
        n++;
        if(a->iz.nodo != NULL)
            cola.push(a->iz.nodo);
        if(a->de.nodo != NULL)
            cola.push(a->de.nodo);
    }
    return(vec);
}

// Sobrecarga del operador salida
ostream &operator<<(ostream &os, const TABBCom &a){
    os << a.Niveles();
    return(os);
}
