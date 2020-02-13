// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba -2 0 II
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {3, 2, 4, 1};

	for(int i = 0; i < 4; i++)
		a.Insertar(v[i]);

	if(a.Borrar(4))
			cout << "Complejo borrado" << (TComplejo) (4) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
