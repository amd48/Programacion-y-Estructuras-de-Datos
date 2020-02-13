// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado solo hijo derecho

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {3, 2, 6, 1, 4, 7, 5};

	for(int i = 0; i < 7; i++)
		a.Insertar(v[i]);

	if(a.Borrar(4))
		cout << "Complejo borrado" << (TComplejo) (4) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	return 0;
}
