// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad02.cc
// --------------------------------

#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 100;
int main(void)
{
  TAVLCom a;
  int i;
  TComplejo complejos[kComplejos];

  for(i = kComplejos-1; i >= 0 ; i--)
  {
  	complejos[i].Re(i);
	complejos[i].Im(i);
  }
 
  for(i = 0; i < kComplejos; i++)
	  a.Insertar(complejos[i]);

  cout << a.Inorden() << endl << a.Preorden() << endl;
  
  return 0;
}
