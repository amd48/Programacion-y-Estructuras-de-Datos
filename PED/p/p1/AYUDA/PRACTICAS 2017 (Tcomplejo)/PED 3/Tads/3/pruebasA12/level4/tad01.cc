// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// Prueba: los 4 recorridos vacios.

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"

using namespace std;

int main()
{
	TAVLCom a;
	cout << a.Niveles() << a.Preorden() << a.Inorden() << a.Postorden() << endl;
	return 0;
}
