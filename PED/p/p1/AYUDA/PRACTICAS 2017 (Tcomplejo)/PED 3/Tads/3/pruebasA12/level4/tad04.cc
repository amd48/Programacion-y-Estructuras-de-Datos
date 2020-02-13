// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: borrado de un hoja, arbol resultado vacio

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {1};

	for(int i = 0; i < 1; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
		cout << "Complejo borrado" << (TComplejo) (1) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	return 0;
}
