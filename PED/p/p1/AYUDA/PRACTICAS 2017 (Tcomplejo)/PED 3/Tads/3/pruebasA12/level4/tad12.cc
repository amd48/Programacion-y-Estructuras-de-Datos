// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba +2 0 DD (mas grande)
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {3, 2, 6, 1, 5, 8, 4, 7};

	for(int i = 0; i < 8; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
			cout << "Complejo borrado" << (TComplejo) (1) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
