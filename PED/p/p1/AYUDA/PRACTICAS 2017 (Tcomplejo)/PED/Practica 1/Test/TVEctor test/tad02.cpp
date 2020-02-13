#include <iostream>

using namespace std;

#include "tvectorcom.h"

int
main(void)
{
cout << "a: ";
  TVectorCom a(2);
  TVectorCom b(a);
  TVectorCom c(b);

   << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;

  return 0;
}


