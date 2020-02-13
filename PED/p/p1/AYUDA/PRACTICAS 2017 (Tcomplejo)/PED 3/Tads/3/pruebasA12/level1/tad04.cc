// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad04.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(1, 1), c2(2, 2), c3(3, 3);
  TAVLCom a;

  cout << "Altura de un arbol vacio: " << a.Altura() << endl;  
  if(a.Insertar(c2) && a.Insertar(c3) && a.Insertar(c1))
    cout << "Esta altura debe ser 2: " << a.Altura() << endl;
  else
    cout << "no devuelve bien si ha insertado o no" << endl;    
  return 0;
}
