// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado de un hoja. sin rotaciones.

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {1, 2, 4, 3};

	for(int i = 0; i < 4; i++)
		a.Insertar(v[i]);

	if(a.Borrar(3))
		cout << "Complejo borrado" << (TComplejo) (3) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	return 0;
}
