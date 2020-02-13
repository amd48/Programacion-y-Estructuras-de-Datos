// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado hoja no decrece altura del subarbol 3

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {6, 3, 8, 2, 5, 9, 1, 4};

	for(int i = 0; i < 8; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
		cout << "Complejo borrado" << (TComplejo) (1) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	a.Insertar(1);
	cout << "Complejo insertado" << (TComplejo) (1) << endl;
	if(a.Borrar(4))
		cout << "Complejo borrado" << (TComplejo) (4) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
	return 0;
}
