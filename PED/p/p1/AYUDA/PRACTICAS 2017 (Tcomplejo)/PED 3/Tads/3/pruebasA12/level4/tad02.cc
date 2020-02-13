// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: niveles del avl, todos los posibles nodos.

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {6, 3, 9, 1, 5, 8, 10, 2, 4, 7};

	for(int i = 0; i < 10; i++)
		a.Insertar(v[i]);

	cout << a.Niveles() << endl;
	return 0;
}
