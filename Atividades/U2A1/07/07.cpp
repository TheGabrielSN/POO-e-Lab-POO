#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t0(10), t1(11,50), t2(11,59,59), t3;

  cout << "t0" << endl;
  t0.printUniversal();

  cout << "\nt1" << endl;
  t1.printUniversal();

  cout << "\nt2" << endl;
  t2.printUniversal();

  cout << "\nt3" << endl;
  t3.printUniversal();

  return 0;
}
