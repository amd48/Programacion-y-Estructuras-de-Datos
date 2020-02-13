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

	for(int i = 1; i <= 20; i++)
		a.Insertar(i);

	for(int i = 20; i >= 1; i--)
	{
		cout << "Complejo borrado" << (TComplejo) (i) << endl;
		cout << "niveles: " << a.Niveles() << endl;
		cout << "inorden: " << a.Inorden() << endl;
	}
	
	return 0;
}
