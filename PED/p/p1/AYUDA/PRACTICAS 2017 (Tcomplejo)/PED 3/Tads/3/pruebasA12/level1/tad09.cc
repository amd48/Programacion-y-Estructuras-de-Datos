// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad09.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(10, 10), c2(20, 20), c3(30, 30), c4(40, 40), c5(50, 50), cx(12, 12);
  TAVLCom a;

  if(a.Buscar(c1))
    cout << "Pues a a ser que no!!" << endl;
  else
    cout << "Pudiendo estar y no." << endl;

  a.Insertar(c4);
  a.Insertar(c5);   
  a.Insertar(c2);
  a.Insertar(c1);
  a.Insertar(c3);
  
  if(a.Buscar(c4))
    cout << "esta si" << endl;
  if(!a.Buscar(cx))
    cout << "esta no" << endl;
  if(a.Buscar(c1))
    cout << "esta me gusta me la como yo" << endl;

  return 0;
}
