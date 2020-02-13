#include <iostream>
#include "tlistacom.h"

using namespace std;

int main(){
	TListaCom lista;

	for(int i = 1; i <= 5; i++)
		lista.InsCabeza(TComplejo(i, i));

	cout << lista << endl;

	TListaPos pos;
	// recorremos la lista hacia delante.
	pos = lista.Primera();
	while(!pos.EsVacia()){
		cout << lista.Obtener(pos) << " >> ";
		pos = pos.Siguiente();
	}
	cout << endl;
	// recorremos la lista hacia atras.
	pos = lista.Ultima();
	while(!pos.EsVacia()){
		cout << lista.Obtener(pos) << " << ";
		pos = pos.Anterior();
	}
	cout << endl;

	TListaPos vacia;
	cout << lista.Borrar(vacia) << endl; // 0 false
	cout << lista << endl; // comprobamos lista sigue igual.


	TListaPos primera = lista.Primera();
	cout << lista.Borrar(primera);
	cout << "Despues de borrar primera: " << lista << endl;
	if(primera.EsVacia()) cout << "posicion vacia" << endl;

	TListaPos ultima = lista.Ultima();
	cout << lista.Borrar(ultima);
	cout << "Despues de borrar ultima: " << lista << endl;
	if(ultima.EsVacia()) cout << "posicion vacia" << endl;
	
	pos = lista.Primera();
	while(pos.EsVacia() == false && lista.Obtener(pos) != TComplejo(3, 3))
		pos = pos.Siguiente();

	lista.Borrar(pos);
	cout << "lista despues de borrar (3, 3): " << lista << endl;
	if(pos.EsVacia()) cout << "posicion vacia" << endl;
		

		
	return 0;
}


