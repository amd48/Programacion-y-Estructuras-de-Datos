#include <iostream>
#include "tabbporo.h"
#include "tlistaporo.h"
#include <vector>

using namespace std;

int
main(void)
{
/**********************************************/
/***************** ALTURA, NODOS, NODOSHOJA   */
/**********************************************/
  
  TABBPoro a, b;
  TListaPoro l, l2;
  TPoro p;
  TPoro p100(1,2,100,(char *) "rojo");
  TPoro p50(1,2,50,(char *) "rojo");
  TPoro p20(1,2,20,(char *) "rojo");
  TPoro p110(1,2,110,(char *) "rojo");

  l.Insertar(p100);
  l.Insertar(p50);
  l.Insertar(p110);
  l.Insertar(p20);

  a.Insertar(p100);
  a.Insertar(p50);
  a.Insertar(p110);
  a.Insertar(p20);

  

  
  TVectorPoro* re = new TVectorPoro[l.Longitud()];
  re = a.examen2(l);

  /*s = a.examen(l2);
  cout << s << endl;

  cout << "arbol vacio , lista con elementos: " <<endl;
  s = b.examen(l);

  for(int i = 0; i < l.Longitud();i++)
  {
    cout << s[i];
  }
  cout << endl;

  cout << "Arbol y lista no vacios: " <<endl;
  s = a.examen(l);
  
  for(int i = 0; i < l.Longitud();i++)
  {
    cout << s[i];
  } 
  cout << endl;*/
  
  return 1; 

}