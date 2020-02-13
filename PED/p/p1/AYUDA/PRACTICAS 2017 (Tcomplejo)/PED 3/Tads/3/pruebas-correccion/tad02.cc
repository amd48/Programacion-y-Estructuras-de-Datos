#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a,b,c;
  
  TComplejo c1(1,1),c2(2,2),c3(3,3);
  
  if (a==b)
    cout<<"Iguales"<<endl;
  else
    cout<<"Distintos"<<endl;
  
  cout<<"a="<<a.Inorden()<<" b="<<b.Niveles()<<" c="<<c.Postorden()<<endl;
}
