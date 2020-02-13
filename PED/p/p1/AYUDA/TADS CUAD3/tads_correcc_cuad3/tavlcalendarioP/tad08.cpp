/************************************************************
** RAIZ, <<
*************************************************************/
#include <iostream>
#include "tavlcalendario.h"

using namespace std;

int
main()
{
  TAVLCalendario arb1;

  TCalendario c1(1,1,2011,(char *)"uno");
  TCalendario c2(2,2,2011,(char *)"dos");
  TCalendario c3(3,3,2011,(char *)"tres");
  TCalendario c4(4,4,2011,(char *)"cuatro");
  TCalendario c5(5,5,2011,(char *)"cinco");
  TCalendario c6(6,6,2011,(char *)"seis");

  arb1.Insertar(c5);
  arb1.Insertar(c2);
  arb1.Insertar(c1);
  arb1.Insertar(c3);
  arb1.Insertar(c6);

  cout << arb1.Raiz()<<endl;

  cout<<arb1<<endl;

  return 0;
}
