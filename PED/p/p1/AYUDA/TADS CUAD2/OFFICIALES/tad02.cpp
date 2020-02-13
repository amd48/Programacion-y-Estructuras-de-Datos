#include <iostream>
#include "tabbcalendario.h"
using namespace std;

int
main(void)
{
/************************************************/
/* CONSTRUCTOR COPIA Y ASIGNACION ARBOLES VACIOS		
/************************************************/
  TABBCalendario a,c;
  cout << "No hace nada" << endl;
  TABBCalendario b(a);

  c=b;
  
  cout << "No hace nada" << endl;
  return 0;
}
