// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba DI + DI (solo un borrado -> dos rotaciones)
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {5, 2, 10, 1, 4, 7, 12, 3, 6, 9, 11, 8};

	for(int i = 0; i < 12; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
			cout << "Complejo borrado" << (TComplejo) (1) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
