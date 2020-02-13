// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level2/tad18.cc
// --------------------------------

#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 10;
int main(void)
{
  double valores[kComplejos][2] = {{3, 3}, {2, 2}, {8, 8}, {1, 1}, {5, 5}, {10, 10}, {4, 4}, {7, 7}, {9, 9}, {6, 6}};
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
