// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad07.cc
// --------------------------------

#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 6;
int main(void)
{
  double valores[kComplejos][2] = {{50, 50}, {30, 30}, {60, 60}, {10, 10}, {40, 40}, {20, 20}};
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
