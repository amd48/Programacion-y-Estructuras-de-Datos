// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad07.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(10, 10), c2(20, 20), c3(30, 30), c4(40, 40), c5(50, 50);
  TAVLCom a;

  cout << "NodosHoja (0): " << a.NodosHoja() << endl;
  a.Insertar(c4);
  cout << "NodosHoja (1): " << a.NodosHoja() << endl;
  a.Insertar(c5);   
  cout << "NodosHoja (1): " << a.NodosHoja() <<  endl;    
  a.Insertar(c2);
  cout << "NodosHoja (2): " << a.NodosHoja() << endl;
  a.Insertar(c1);
  cout << "NodosHoja (2): " << a.NodosHoja() << endl;
  a.Insertar(c3);
  cout << "NodosHoja (3): " << a.NodosHoja() << endl;

  return 0;
}
