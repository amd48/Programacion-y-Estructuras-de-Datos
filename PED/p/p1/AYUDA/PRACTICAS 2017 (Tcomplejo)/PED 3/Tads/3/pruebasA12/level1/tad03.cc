// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad03.cc
// --------------------------------

#include "tcomplejo.h"
#include "tavlcom.h"

using namespace std;

int main()
{
  TComplejo c1(1,1), c2(2, 2), c3(3, 3);
  TAVLCom a;
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);

  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;

  return 0;
}
