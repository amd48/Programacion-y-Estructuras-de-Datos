#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{
/*************/
/******* Prueba Examen */
/*************/
  
TListaPoro tp;
TABBPoro ab;

/* Para el TPoro con ints
TPoro a(1,2,68,"verde");
TPoro b(5,2,71,"azul");
TPoro c(0,2,82,"rojo");
TPoro d(5,2,92,"lila");
TPoro e(5,2,98,"amarillo");

TPoro f(1,2,40,"verde");
TPoro g(5,2,55,"azul");
TPoro h(0,2,11,"rojo");
TPoro i(5,2,35,"lila");
TPoro j(5,2,56,"amarillo");

TPoro k(1,2,60,"verde");
TPoro l(5,2,64,"azul");
TPoro m(0,2,83,"rojo");
TPoro n(5,2,70,"lila");
TPoro o(5,2,80,"amarillo");
TPoro z(5,2,84,"amarillo");


tp.Insertar(a);
tp.Insertar(b);
tp.Insertar(c);
tp.Insertar(d);
tp.Insertar(e);

// izquierdo
ab.Insertar(a);
ab.Insertar(j);
ab.Insertar(i);
ab.Insertar(k);
ab.Insertar(l);
ab.Insertar(h);
ab.Insertar(g);
ab.Insertar(f);

// derecho
ab.Insertar(z);
ab.Insertar(o);
ab.Insertar(e);
ab.Insertar(d);
ab.Insertar(n);
ab.Insertar(c);
ab.Insertar(m);

int* v = ab.examen(tp);
	if(v == NULL){
		cout << "Es NULL :)" << endl;
	}
	else{
			cout << "[ ";
	for(int i = 0 ; i<tp.Longitud();i++){
	  cout << v[i] << " ";
	}
	cout << "]" << endl;
	}
*/


// Para el vector de vectores

TPoro a(1,2,20,"verde");
TPoro b(5,2,10,"azul");
TPoro c(0,2,25,"rojo");
TPoro d(5,2,9,"lila");
TPoro e(5,2,11,"amarillo");
TPoro f(1,2,24,"verde");
TPoro g(5,2,26,"azul");
TPoro x(5,2,1,"azul");


tp.Insertar(a);
tp.Insertar(b);
tp.Insertar(c);
tp.Insertar(d);
tp.Insertar(e);
tp.Insertar(f);
tp.Insertar(g);


ab.Insertar(a);
ab.Insertar(b);
ab.Insertar(c);
ab.Insertar(d);
ab.Insertar(e);
ab.Insertar(f);
ab.Insertar(g);


//ab.examen2(tp);

return 1;


}