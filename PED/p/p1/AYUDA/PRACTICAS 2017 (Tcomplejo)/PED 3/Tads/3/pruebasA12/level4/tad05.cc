// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado solo hijo izquierdo

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {3, 2, 6, 1, 5, 7, 4};

	for(int i = 0; i < 7; i++)
		a.Insertar(v[i]);

	if(a.Borrar(5))
		cout << "Complejo borrado" << (TComplejo) (5) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	return 0;
}
