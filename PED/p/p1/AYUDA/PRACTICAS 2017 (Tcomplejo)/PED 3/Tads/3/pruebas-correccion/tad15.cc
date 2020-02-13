#include <iostream>
#include "tavlcom.h"

using namespace std;

int
main(void)
{
  TAVLCom a;
  TComplejo *vectorc;
  
  vectorc=new TComplejo[2000];
  for (int i=0; i<2000; i++)
  {
     vectorc[i].Re((double)i+1);
     vectorc[i].Im((double)i+1);
     a.Insertar(vectorc[i]);
  }

  cout<<"Inorden="<<a.Inorden()<<endl;

}
