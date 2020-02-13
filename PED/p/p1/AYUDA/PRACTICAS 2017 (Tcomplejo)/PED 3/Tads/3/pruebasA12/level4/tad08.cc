// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------


#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	float v[] = {2, 1, 3};

	for(int i = 0; i < 3; i++)
		a.Insertar(v[i]);

	if(a.Borrar(1))
		cout << "Complejo borrado" << (TComplejo) (1) <<  endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;

	if(a.Borrar(2))
		cout << "Complejo borrado" << (TComplejo) (2) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;

	if(a.Borrar(3))
		cout << "Complejo borrado" << (TComplejo) (3) << endl;
	cout << "niveles: " << a.Niveles() << endl;
	cout << "inorden: " << a.Inorden() << endl;
	
		

	return 0;
}
