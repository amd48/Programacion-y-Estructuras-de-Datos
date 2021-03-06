// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba 2 borrados de un nodo con dos hijos,
// el ultimo borrado provoca un DD. 2 1 basico.
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {3, 2, 4, 1, 5};

	for(int i = 0; i < 5; i++)
		a.Insertar(v[i]);

	if(a.Borrar(3))
			cout << "Complejo borrado" << (TComplejo) (3) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	if(a.Borrar(2))
			cout << "Complejo borrado" << (TComplejo) (2) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
