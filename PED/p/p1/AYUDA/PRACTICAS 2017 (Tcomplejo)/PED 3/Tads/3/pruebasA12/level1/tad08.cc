// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad08.cc
// --------------------------------

#include <iostream>
#include "tcomplejo.h"
#include "tavlcom.h"
using namespace std;

int main()
{
  TComplejo c1(10, 10), c2(20, 20), c3(30, 30), c4(40, 40), c5(50, 50);
  TAVLCom a;

  a.Insertar(c4);
  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;
  cout << "Postorden: " << a.Postorden() << endl;
  a.Insertar(c5);   
  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;
  cout << "Postorden: " << a.Postorden() << endl;
  a.Insertar(c2);
  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;
  cout << "Postorden: " << a.Postorden() << endl;
  a.Insertar(c1);
  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;
  cout << "Postorden: " << a.Postorden() << endl;
  a.Insertar(c3);
  cout << "Inorden: " << a.Inorden() << endl;
  cout << "Preorden: " << a.Preorden() << endl;
  cout << "Postorden: " << a.Postorden() << endl;

  return 0;
}
