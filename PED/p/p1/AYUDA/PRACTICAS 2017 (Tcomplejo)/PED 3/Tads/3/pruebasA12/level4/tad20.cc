// ------------------------
// Autor: Jose Manuel Baldo
// www.auladoce.com
// ------------------------

// siempre borra un nodo intermedio

#include <iostream>
#include "tavlcom.h"
#include "tcomplejo.h"
 
using namespace std; 

int main()
{
	TAVLCom a;

        a.Insertar(5);
	a.Insertar(2);
	a.Insertar(8);
	a.Insertar(1);
	a.Insertar(4);
	a.Insertar(6);
	a.Insertar(9);
	a.Insertar(3);
	a.Insertar(7);
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;

	a.Borrar(5);
	cout << "Resultado Borrar 5" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(4);
	cout << "Resultado Borrar 4" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(3);
	cout << "Resultado Borrar 3" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(6);
	cout << "Resultado Borrar 6" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(2);
	cout << "Resultado Borrar 2" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(8);
	cout << "Resultado Borrar 8" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(7);
	cout << "Resultado Borrar 7" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(1);
	cout << "Resultado Borrar 1" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;
	
	a.Borrar(9);
	cout << "Resultado Borrar 9" << endl;
	cout << a.Niveles() << endl;
	cout << a.Inorden() << endl;

			
		
	return 0;
}
