// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// prueba: prueba +2 0 DD
#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {2, 1, 3, 4};

	for(int i = 0; i < 4; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
			cout << "Complejo borrado" << (TComplejo) (1) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
