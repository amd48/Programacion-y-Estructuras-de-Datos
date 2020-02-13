// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad01.cc
// --------------------------------

// prueba DD basico (3 nodos).
#include <iostream>
#include "tavlcom.h"

using namespace std;

int main(void)
{
  TComplejo c1(1, 1), c2(2, 2), c3(3, 3);
  TAVLCom a;
  
  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  
  cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
