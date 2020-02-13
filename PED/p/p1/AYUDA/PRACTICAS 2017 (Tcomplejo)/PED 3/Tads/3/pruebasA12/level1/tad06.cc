// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad06.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(10, 10), c2(20, 20), c3(30, 30), c4(40, 40), c5(50, 50);
  TAVLCom a;

  cout << "Nodos (0): " << a.Nodos() << endl;
  a.Insertar(c4);
  cout << "Nodos (1): " << a.Nodos() << endl;
  a.Insertar(c5);   
  cout << "Nodos (2): " << a.Nodos() <<  endl;    
  a.Insertar(c2);
  cout << "Nodos (3): " << a.Nodos() << endl;
  a.Insertar(c1);
  cout << "Nodos (4): " << a.Nodos() << endl;
  a.Insertar(c3);
  cout << "Nodos (5): " << a.Nodos() << endl;

  return 0;
}
