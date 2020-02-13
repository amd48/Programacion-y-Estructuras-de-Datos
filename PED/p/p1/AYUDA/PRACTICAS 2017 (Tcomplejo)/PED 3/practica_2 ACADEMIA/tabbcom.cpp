#include "tabbcom.h"
#include "tcomplejo.h"
#include "tvectorcom.h"
#include <queue>

TABBCom::TABBCom(){
	nodo = NULL;
}

TNodoABB::TNodoABB(const TNodoABB &o)
:item(o.item), iz(o.iz), de(o.de){
}

TNodoABB::TNodoABB(){
	// Invoca al constructor por defecto del arbol iz, de y del
	// TComplejo.
}

TNodoABB::TNodoABB(const TComplejo &e){
	item = e;
}

TNodoABB::~TNodoABB(){
	// automaticamente invoca a los destructores de los
	// arboles que contiene.
}

TABBCom::~TABBCom(){
	if(nodo != NULL){
		delete nodo;
		nodo = NULL;
	}
}

TABBCom::TABBCom(const TABBCom &o)
{
	if(o.nodo != NULL)
		nodo = new TNodoABB(*o.nodo);
	else
		nodo = NULL;
}

TABBCom &TABBCom::operator=(const TABBCom &de){
	if(this != &de)
	{
		// this->~TABBCom();
		nodo = NULL;
		/* nodo = new TNodoABB(de.nodo->item);
		nodo->de = de.nodo->de;
		nodo->iz = de.nodo->iz;*/
		if(de.nodo)
			nodo = new TNodoABB(*de.nodo);
	}
	return *this;
}

bool TABBCom::operator==(const TABBCom &de) const{	
	return Inorden() == de.Inorden();
}

bool TABBCom::Insertar(const TComplejo &e){
	bool exito;
	if(nodo == NULL){
		//nodo = new TNodoABB(e);
		nodo = new TNodoABB();
		nodo->item = e;		
		exito = true;
	}
	else
		if(e == nodo->item)
			exito = false;
		else
			if(e.Mod() > nodo->item.Mod() || 
				e.Mod() == nodo->item.Mod() && e.Re() > nodo->item.Re() || 
				e.Mod() == nodo->item.Mod() && e.Re() == nodo->item.Re() || e.Im() > nodo->item.Im())
				exito = nodo->de.Insertar(e);
			else
				exito = nodo->iz.Insertar(e);
	return exito;
}

TVectorCom TABBCom::Inorden() const{
	int posicion;
	TVectorCom v( Nodos() );

	posicion = 1;
	InordenAux(v, posicion);

	return v;
}

void TABBCom::InordenAux(TVectorCom &v, int &posicion) const{
	if(nodo != NULL)
	{
		nodo->iz.InordenAux(v, posicion);
		v[posicion] = nodo->item;
		posicion++;
		nodo->de.InordenAux(v, posicion);
	}
}

TVectorCom TABBCom::Preorden() const{
	int posicion;
	TVectorCom v( Nodos() );

	posicion = 1;
	PreordenAux(v, posicion);

	return v;
}

void TABBCom::PreordenAux(TVectorCom &v, int &posicion) const{
	if(nodo != NULL)
	{
		v[posicion] = nodo->item;
		posicion++;
		nodo->iz.PreordenAux(v, posicion);
		nodo->de.PreordenAux(v, posicion);
	}
}

TVectorCom TABBCom::Niveles() const{
	TVectorCom v(Nodos());
	queue<TNodoABB *> cola;
	TNodoABB *aux;
	int i;

	i = 1;
	if(nodo != NULL)
		cola.push(nodo);
	while(!cola.empty()){
		aux = cola.front();
		cola.pop();		
		v[i] = aux->item;
		i++;
		if(aux->iz.nodo != NULL)
			cola.push(aux->iz.nodo);
		if(aux->de.nodo != NULL)
			cola.push(aux->de.nodo);
	}
	return v;
}

TVectorCom TABBCom::Postorden() const{
	int posicion;
	TVectorCom v( Nodos() );

	posicion = 1;
	PostordenAux(v, posicion);

	return v;
}

void TABBCom::PostordenAux(TVectorCom &v, int &posicion) const{
	if(nodo != NULL){
		nodo->iz.PostordenAux(v, posicion);
		nodo->de.PostordenAux(v, posicion);
		v[posicion] = nodo->item;
		posicion++;
	}
}

int TABBCom::Nodos() const{
	if(nodo == NULL)
		return 0;
	else
		return nodo->iz.Nodos() + nodo->de.Nodos() + 1;
}

bool TABBCom::Borrar(const TComplejo &e){
	bool exito;
	TNodoABB *aux;
	TComplejo mayorIzq;

	if(nodo == NULL){
		exito = false;
	}
	else{
		if(e == nodo->item){	
			exito = true;
			if(nodo->iz.EsVacio() && nodo->de.EsVacio()){
				delete nodo;
				nodo = NULL;
			}
			else{
				if(nodo->iz.EsVacio())
				{
					aux = nodo;
					nodo = nodo->de.nodo;
					aux->de.nodo = NULL;						
					delete aux;
					aux = NULL;

				}
				else{
					if(nodo->de.EsVacio())
					{
						aux = nodo;
						nodo = nodo->iz.nodo;
						aux->iz.nodo =NULL;							
						delete aux;
						aux = NULL;
					}
					else
					{
						// arbol con dos hijos.
						// mayor en la izquierda.
						mayorIzq = nodo->iz.BuscarMayor();
						nodo->iz.Borrar(mayorIzq);
						nodo->item = mayorIzq;
					}
				}
			}
		}
		else{		
			if(e.Mod() > nodo->item.Mod() || 
				e.Mod() == nodo->item.Mod() && e.Re() > nodo->item.Re() || 
				e.Mod() == nodo->item.Mod() && e.Re() == nodo->item.Re() && e.Im() > nodo->item.Im())
					exito = nodo->de.Borrar(e);
			else
				exito = nodo->iz.Borrar(e);
		}
	}
	return exito;
}


TComplejo TABBCom::BuscarMayor() const
{
	TComplejo aux;
	if(nodo->de.EsVacio())
		aux = nodo->item;
	else
		aux = nodo->de.BuscarMayor();
	return aux;
}

bool TABBCom::Buscar(const TComplejo &p) const
{
	bool encontrado;
	if(nodo == NULL)
		encontrado = false;
	else{
		if(p == nodo->item)
			encontrado = true;
		else
			encontrado = nodo->iz.Buscar(p) || nodo->de.Buscar(p);
	}
	return encontrado;
}

int TABBCom::Altura() const{
	int altura, altIzq, altDer;

	if(nodo == NULL)
		altura = 0;
	else
	{
		altIzq = nodo->iz.Altura();
		altDer = nodo->de.Altura();
		if(altIzq > altDer)
			altura = altIzq + 1;
		else
			altura = altDer + 1;
	}
	return altura;
}

bool TABBCom::EsVacio() const{
	bool vacio;
	if(nodo == NULL)
		vacio = true;
	else
		vacio = false;
	return vacio;
}

int TABBCom::NodosHoja() const{
	int nh;
	if(nodo == NULL)
		nh = 0;
	else
		if(nodo->iz.EsVacio() && nodo->de.EsVacio())
			nh = 1;
		else
			nh = nodo->iz.NodosHoja() + nodo->de.NodosHoja();
	return nh;
}

TComplejo TABBCom::Raiz() const{
	TComplejo aux;
	if(nodo != NULL)
		aux = nodo->item;
	return aux;
}

ostream &operator<<(ostream &os, const TABBCom &a){
	os << a.Niveles();
	return os;
}


/*
// devuelve una lista con los nodos que son hojas en el arbol
// de los nodos del vector pasado como parametro.
TListaCom TABBCom::listaHojas(const TVectorCom &up)const{
	TListaCom aux;
	int i;
	
	for(i = 1; i <= up.Tamano(); i++)
	    if(esHoja(up[i])){
			if(aux.EsVacia())
				aux.InsCabeza(up[i]);
			else
				aux.InsertarD(up[i], aux.Ultima()); 	
			// aux.Insertar(up[i]);
		}
	return aux;
}


// auxiliar para la anterior, comprueba si el Com esta en un nodo
// que es hoja en el arbol.
bool TABBCom::esHoja(const TComplejo &p)const
{
	bool es;
	if(nodo == NULL)
	   es = false;
	else if(p < nodo->item)
	   es = nodo->iz.esHoja(p);
	else if(p > nodo->item)
	   es = nodo->de.esHoja(p);
	else if(nodo->iz.nodo == NULL && nodo->de.nodo == NULL)
	   es = true;
	else
	   es = false;

	return es;
	   
}


// Se le pasa una lista y si los nodos estan en el arbol 
// devuelve una lista con las posiciones que si esta pone 1 sino pone 0
int *TABBCom::marcar(const TListaCom &li) const
{
	int *v;
	int i;
	TListaPos po;

	if(li.Longitud() == 0){
		v = NULL;
	}
	else
	{
		v = new int [li.Longitud()];
		po = li.Primera();
		i = 0;
		while(!po.EsVacia()){
			if(Buscar(li.Obtener(po)))
				v[i] = 1;
			else
				v[i] = 0;
			po = po.Siguiente();
			i++;
		}
	}
	return v;
}



//metodo de arbol que recibe una lista de Coms y 
// devuelve otra lista con los hijos de los nodos pasados como parametros
TListaCom TABBCom::recogeHijos(const TListaCom &lp) const
{
	TListaCom laux;
	TListaPos po;
	
	po = lp.Primera();
	while(!po.EsVacia()){
		laux = laux + hijos(lp.Obtener(po));////
		po = po.Siguiente();
	}
	return laux;
}

TListaCom TABBCom::hijos(const TComplejo &p)const
{
	TListaCom l;
	if(nodo != NULL){
		if(p < nodo->item)
			l = nodo->iz.hijos(p);
		else 
			if(p > nodo->item)
				l = nodo->de.hijos(p);
			else{
				if(nodo->iz.nodo != NULL)
					if(l.EsVacia())
						l.InsCabeza(nodo->iz.nodo->item);
					else
						l.InsertarD(nodo->iz.nodo->item, l.Ultima());
				if(nodo->de.nodo != NULL)
					if(l.EsVacia())
						l.InsCabeza(nodo->de.nodo->item);
					else					
						l.InsertarD(nodo->de.nodo->item, l.Ultima());
			}
	}
	return l;
}



//devuelve verdadero si el Com esta en el nivel i del arbol
bool TABBCom::estaEnNivel(const TComplejo &lp, int niv)const
{
	bool esta;

	if(nodo == NULL)
		esta = false;
	else
		if(niv == 1){
			if(lp == nodo->item)
				esta = true;
			else 
				esta = false;
		}
		else{
			if(lp < nodo->item)
				esta = nodo->iz.estaEnNivel(lp, niv-1);
			else
				esta = nodo->de.estaEnNivel(lp, niv-1);
		}
		return esta;
}


TComplejo TABBCom::soyTuPadre(const TComplejo &p) const
{
	TComplejo vacio;

	if(nodo != NULL){
		if(nodo->iz.nodo != NULL && nodo->iz.nodo->item == p || 
			nodo->de.nodo != NULL && nodo->de.nodo->item == p)
				vacio = nodo->item;
		else{
			if(p < nodo->item)
				vacio = nodo->iz.soyTuPadre(p);
			else
				vacio = nodo->de.soyTuPadre(p);
		}
	}	
	return vacio;
}

TVectorCom TABBCom::padresDe(const TListaCom &lp)const
{
	TVectorCom v(lp.Longitud());
	TListaPos pos;
	int i;

	i = 1;
	pos = lp.Primera();	
	while(!pos.EsVacia()) {
		v[i] = soyTuPadre( lp.Obtener(pos) );
		i++;
		pos = pos.Siguiente();
	}
	return v;
}

// implementar un metodo en el arbol que reciba una lista y para cada nodode 
// la lista almacene un vector de enteros, el numero de nodos del subarbol
// que lo tienen como raiz.
int TABBCom::contarHijosCom(const TComplejo &p) const
{
	int numHijos = 0;
	if(nodo != NULL){
		if(p == nodo->item)
		    numHijos = Nodos(); // nodos del subarbol que lo tienen como raiz.
		else
		    if(p < nodo->item)
				numHijos = nodo->iz.contarHijosCom(p);
		    else
				numHijos = nodo->de.contarHijosCom(p);
	}
	return numHijos;
}

int *TABBCom::contarNodosSubarbol(const TListaCom &lp)const {
	int *ve;
	TListaPos p;
	int i;

	if(lp.Longitud() == 0)
		ve = NULL;
	else{
		ve = new int [lp.Longitud()];
		p = lp.Primera();
		i = 0;
		while(!p.EsVacia()){
			ve[i] = contarHijosCom(lp.Obtener(p));
			i++;
			p = p.Siguiente();
		}
	}
	return ve;
}


// devuelve un vector con un entero para cada nodo de la lista,
// con el numero de los hijos que tiene 0, 1 o 2.

int *TABBCom::examen(const TListaCom &lp)const {
	int *ve;
	TListaPos p;
	int i;

	if(lp.Longitud() == 0)
		ve = NULL;
	else{
		ve = new int [lp.Longitud()];
		p = lp.Primera();
		i = 0;
		while(!p.EsVacia()){
			ve[i] = encontrarCaso(lp.Obtener(p));
			i++;
			p = p.Siguiente();
		}
	}
	return ve;
}
int TABBCom::encontrarCaso(const TComplejo &p) const
{
	int numHijos = 0;
	if(nodo != NULL){
		if(p == nodo->item){
			if(nodo->iz.nodo != NULL)	
		    	numHijos++;
			if(nodo->de.nodo != NULL)
				numHijos++;		
		}
		else
		    if(p < nodo->item)
				numHijos = nodo->iz.encontrarCaso(p);
		    else
				numHijos = nodo->de.encontrarCaso(p);
	  }
	return numHijos;
}



bool TABBCom::existeCamino(const TListaCom &lista) const{
	bool existe = false;

	if(lista.Longitud() == 1)
		existe = true;
	else{
		if(lista.Longitud() > 1){
			TComplejo min, max;
			TListaPos p = lista.Primera();
			min = lista.Obtener(p);
			max = lista.Obtener(p);
			while(!p.EsVacia()){
				if(lista.Obtener(p) > max)
					max = lista.Obtener(p);
				if(lista.Obtener(p) < min)
					min = lista.Obtener(p);
				p = p.Siguiente();
			}
			existe = comprobarCamino(min, max);
		}
	}
	return existe;
}

bool TABBCom::comprobarCamino(const TComplejo &inicio, const TComplejo &fin) const{
	bool encontrado;
	// buscamos inicio
	TNodoABB *ptl;

	ptl = nodo;
	encontrado = false;
	while(ptl != NULL && !encontrado){
		if(inicio == ptl->item)
			encontrado = true;
		else
			if(inicio < ptl->item)
				ptl = ptl->iz.nodo; ///***
			else
				ptl = ptl->de.nodo; //***
	}
	if(encontrado){
		encontrado = false;
		while(ptl != NULL && !encontrado){
			if(fin == ptl->item)
				encontrado = true;
			else
				if(fin < ptl->item)
					ptl = ptl->iz.nodo; //***
				else
					ptl = ptl->de.nodo; //*** 
		}
	}
	// buscamos fin desde inicio
	return encontrado;	
}
*/

