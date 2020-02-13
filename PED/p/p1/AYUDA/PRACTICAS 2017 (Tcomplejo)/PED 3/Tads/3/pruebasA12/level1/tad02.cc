// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad02.cc
// --------------------------------

#include <iostream>
#include "tavlcom.h"

using namespace std;

int main(void)
{
  TAVLCom a;
  TComplejo c(1, 1);

  a.Insertar(c);

  cout << "Altura: " << a.Altura() << endl;

  return 0;
}
