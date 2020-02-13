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

const int kComplejos = 20;
int main(void)
{
	TAVLCom a;
	int i, j;
	TComplejo complejos[kComplejos];

	i = 0;
	j = kComplejos-1;

	while(i < j)
	{
		complejos[i].Re(i);
		complejos[i].Im(i);
		complejos[j].Re(j);
		complejos[j].Im(j);
		a.Insertar(complejos[i]);
		a.Insertar(complejos[j]);
		i++;
		j--;
	}
	
	cout << a.Inorden() << endl << a.Preorden() << endl;
 
  return 0;
}
