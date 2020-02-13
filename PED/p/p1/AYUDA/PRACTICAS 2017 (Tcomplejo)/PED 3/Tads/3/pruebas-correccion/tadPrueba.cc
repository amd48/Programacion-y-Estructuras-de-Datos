#include <iostream>
#include "ta234com.h"

using namespace std;

int main(void)
{
  TA234Com a;
  TComplejo c4(4,4),c8(8,8),c9(9,9),c10(10,10),c12(12,12),c14(14,14),c15(15,15);
    
  a.Insertar(c8);
  a.Insertar(c12);
  a.Insertar(c4);
  a.Insertar(c9);
  a.Insertar(c14);
  a.Insertar(c10);
  //a.Insertar(c15);

  cout<<"niveles="<<a.Niveles()<<endl;

  if(a.Mas3que2())
  	cout<<"si"<<endl;
  else
  	cout<<"no"<<endl;
 }
