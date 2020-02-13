// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level3/tad07.cc
// --------------------------------

// prueba DD - 2 niveles (6 nodos).
#include <iostream>
#include "tavlcom.h"
#define kRe 0
#define kIm 1
using namespace std;

const int kComplejos = 6;
int main(void)
{
  double valores[kComplejos][2] = {{30, 30}, {30, 30}, {15, 10}, {10, 15}, {0, 0}, {0, 0}};
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
	if(a.Insertar(complejos[i]))
		cout << "insertado " << complejos[i] << endl;
	else
		cout << "no insertado " << complejos[i] << endl;
  }  
  cout << a.Inorden() << endl << a.Preorden() << endl;

	if(a.Buscar(complejos[4]))
		cout << "no debemos insertar el complejo " << complejos[4] << endl;

	TComplejo trampa(10, 15);
	if(a.Buscar(trampa))
		cout << "error. tiene el mismo modulo pero no es el mismo complejo" << endl;
	else
		cout << "no caiste en la trampa.. xupi.. ya has terminado mis putos correctores " << endl;
  
  return 0;
}
