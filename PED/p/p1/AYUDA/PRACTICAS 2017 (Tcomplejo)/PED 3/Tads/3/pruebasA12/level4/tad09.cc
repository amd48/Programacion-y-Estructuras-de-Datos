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
	float v[] = {4, 1, 6, 2, 5};

	for(int i = 0; i < 5; i++)
		a.Insertar(v[i]);

	if(a.Borrar(3))
		cout << "que lastimica que borres cosas que no estan!!" <<  endl;
	
	float vb[] = {1, 6, 2, 5, 4};

	for(int i = 0; i < 5; i++)
	{
		if(a.Borrar(vb[i]))
			cout << "Complejo borrado" << (TComplejo) (vb[i]) << endl;
		cout << "niveles: " << a.Niveles() << endl;
		cout << "inorden: " << a.Inorden() << endl;
	}
	return 0;
}
