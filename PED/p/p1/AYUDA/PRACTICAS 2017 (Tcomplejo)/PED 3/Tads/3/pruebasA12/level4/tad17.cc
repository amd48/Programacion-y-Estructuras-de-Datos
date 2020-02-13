// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba borrado de un nodo con dos hijos,
// el mayor izquierda es un nodo hoja.
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {2, 1, 3};

	for(int i = 0; i < 3; i++)
		a.Insertar(v[i]);

	if(a.Borrar(2))
			cout << "Complejo borrado" << (TComplejo) (2) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
