// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad05.cc
// --------------------------------

// prueba DD - 2 niveles (6 nodos).
#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 8;
int main(void)
{
  double valores[kComplejos][2] = {{10, 10}, {20, 20}, {30, 30}, {40, 40}, {50, 50}, {60, 60}, {70, 70}, {80, 80}};
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
  
  return 0;
}
