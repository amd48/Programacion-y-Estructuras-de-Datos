// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad04.cc
// --------------------------------

#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 10;
int main(void)
{
  double valores[kComplejos][2] = {{70, 70}, {30, 30}, {90, 90}, {20, 20}, {50, 50}, {80, 80}
  					, {10, 10}, {40, 40}, {60, 60}, {35, 35}};
  int i;
  TComplejo complejos[kComplejos];
  TAVLCom a;

  for(i = 0; i < kComplejos; i++)
  {
  	complejos[i].Re(valores[i][kRe]);
	complejos[i].Im(valores[i][kIm]);
  }
    
  for(i = 0; i < kComplejos; i++)
  {
	  a.Insertar(complejos[i]);
  }  
  cout << a.Inorden() << endl << a.Preorden() << endl;

cout << "altura: " << a.Altura() << endl;
cout << "nodos hoja: " << a.NodosHoja() << endl;
cout << "nodos: " << a.Nodos() << endl;
  
  return 0;
}
