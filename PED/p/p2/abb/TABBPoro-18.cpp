#include <iostream>
#include "tabbporo.h"
using namespace std;

int
main(void)
{

  TABBPoro a, b, c, d;



  TPoro p1(0,0,0,NULL);
  TPoro p2(1,2,0,(char *) "rojo");

 /*/ if(a.Insertar(p1))//luego cambia p1 por p2, asi tienes dos tads
    cout << "INSERTADO PORO VACIO" << endl;

  if(a.Insertar(p2))//luego cambia p2 por p1, asi tienes dos tads
    cout << "MAL INSERTADO" << endl;
  else
    cout << "NO SE INSERTA, OK" << endl;  */

  //////////////////////////////////////////

  TPoro p3(1,2,24,(char *) "rojo");
  TPoro p4(1,2,8,(char *) "rojo");
  TPoro p5(1,2,12,(char *) "rojo");
  TPoro p6(1,2,26,(char *) "rojo");
  TPoro p7(1,2,28,(char *) "rojo");

  TPoro p8(1,2,24,(char *) "rojo");
  TPoro p9(1,2,22,(char *) "rojo");
  TPoro p10(1,2,27,(char *) "rojo");
  TPoro p11(1,2,4,(char *) "rojo");
  TPoro p12(1,2,3,(char *) "rojo");
  TPoro p13(1,2,2,(char *) "rojo");
  TPoro p14(1,2,1,(char *) "rojo");


  a.Insertar(p3);
  a.Insertar(p4);
  a.Insertar(p5);
  a.Insertar(p6);
  a.Insertar(p7);

  c.Insertar(p8);
  a = a+c;
  cout << "paso de la suma en el tad " << endl;
  cout << " a despues de sumar "<<a <<endl;// << a << endl;

  /*c.Insertar(p8);
  c.Insertar(p9);
  c.Insertar(p10);
  c.Insertar(p11);
  c.Insertar(p12);

  cout << "a " << a << endl;
  cout << "c " << c << endl;*/

  return 1;
}
