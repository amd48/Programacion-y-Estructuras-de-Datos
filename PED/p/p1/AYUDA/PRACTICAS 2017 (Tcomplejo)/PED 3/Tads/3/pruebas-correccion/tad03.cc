#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a,b(a),c(a);
  TComplejo c1(1,1),c2(2,2),c3(3,3);
  TListaCom l1,l2,l3;
  
  if (a==b)
    cout<<"Iguales"<<endl;
  else
    cout<<"Distintos"<<endl;
  l1=a.Inorden();
  l2=b.Inorden();
  l3=c.Niveles();
  cout<<"a="<<l1<<" b="<<l2<<" c="<<l3<<endl;
}
