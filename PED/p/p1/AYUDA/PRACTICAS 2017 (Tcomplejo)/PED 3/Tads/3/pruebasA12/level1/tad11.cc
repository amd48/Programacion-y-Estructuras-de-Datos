// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad11.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(10, 10), c2(20, 20), c3(30, 30), c4(40, 40), c5(50, 50), cx(12, 12);
  TAVLCom a;


  a.Insertar(c4);
  a.Insertar(c5);   
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  
  TAVLCom b = a;
  
  cout << "a.Inorden(): " << a.Inorden() << endl << "a.Preorden(): " << a.Preorden() << endl;
  cout << "b.Inorden(): " << b.Inorden() << endl << "b.Preorden(): " << b.Preorden() << endl;

  if(a == b)
  	cout << "a y b son iguales" << endl;
  else
  	cout << "no rula el = o el ==" << endl;
	
  TAVLCom c, d;
  d = c;
  cout << "c.Inorden(): " << c.Inorden() << endl << "c.Preorden(): " << c.Preorden() << endl;
  cout << "d.Inorden(): " << d.Inorden() << endl << "d.Preorden(): " << d.Preorden() << endl;
  
  if(c == d)
  	cout << "c y d son iguales" << endl;
  else
  	cout << "no rula el = o el == con dos vacios" << endl;
	
	
  
  return 0;
}
