// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba -2 0 II (mas grande)
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {6, 3, 7, 1, 5, 8, 2, 4};

	for(int i = 0; i < 8; i++)
		a.Insertar(v[i]);

	if(a.Borrar(7))
			cout << "Complejo borrado" << (TComplejo) (7) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
