#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a;
  TComplejo c1(1,1);
  TComplejo c2(2,2);
  TComplejo c3(3,3);

  a.Insertar(c1);
  cout<<"Nodos="<<a.Nodos()<<endl;
  cout<<"NodosHoja="<<a.NodosHoja()<<endl;
  cout << "Altura=" << a.Altura() << endl;
  
  a.Insertar(c2);
  cout<<"Nodos="<<a.Nodos()<<endl;
  cout<<"NodosHoja="<<a.NodosHoja()<<endl;
  cout << "Altura=" << a.Altura() << endl;

  a.Insertar(c3);
  cout<<"Nodos="<<a.Nodos()<<endl;
  cout<<"NodosHoja="<<a.NodosHoja()<<endl;
  cout << "Altura=" << a.Altura() << endl;
}
