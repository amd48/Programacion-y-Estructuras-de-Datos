// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba 2 -1 DI (mas grande)
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {6, 3, 9, 2, 5, 8, 12, 1, 4, 7, 10, 13, 11};

	for(int i = 0; i < 13; i++)
		a.Insertar(v[i]);

	if(a.Borrar(8))
			cout << "Complejo borrado" << (TComplejo) (8) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
