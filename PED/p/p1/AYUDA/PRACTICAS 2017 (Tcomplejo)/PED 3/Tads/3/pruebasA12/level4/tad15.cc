// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba ID + II (solo un borrado -> dos rotaciones)
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;
	float v[] = {8, 5, 11, 2, 7, 9, 12, 1, 4, 6, 10, 3};

	for(int i = 0; i < 12; i++)
		a.Insertar(v[i]);

	if(a.Borrar(12))
			cout << "Complejo borrado" << (TComplejo) (12) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
