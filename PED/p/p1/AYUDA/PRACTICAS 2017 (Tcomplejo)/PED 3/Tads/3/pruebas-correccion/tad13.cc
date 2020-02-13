#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a;
  TComplejo c3(3,3),c5(5,5),c9(9,9),c12(12,12),c10(10,10);
  TListaCom l1,l2,l3,l4;
  
  if (a.EsVacio())
    cout<<"es vacio"<<endl; 
    
  a.Insertar(c10);
  a.Insertar(c12);
  a.Insertar(c9);

  l1=a.Inorden();
  l2=a.Postorden();
  l3=a.Niveles();

  if (!a.EsVacio())
  {
    cout<<"inorden="<<l1<<endl;
    cout<<"postorden="<<l2<<endl;
    cout<<"niveles="<<l3<<endl;
  }
  
  a.~TAVLCom();

  if (a.EsVacio())
    cout<<"inorden="<<a.Inorden()<<endl;

  
}
