#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main() {
  Time t0(16,40), t1(11,50,59), t2(11,59,59), t3(23,59,59);

  cout << "t0" << endl;
  t0.printUniversal();
  t0.tick();
  t0.printUniversal();

  cout << "\nt1" << endl;
  t1.printUniversal();
  t1.tick();
  t1.printUniversal();

  cout << "\nt2" << endl;
  t2.printUniversal();
  t2.tick();
  t2.printUniversal();

  cout << "\nt3" << endl;
  t3.printUniversal();
  t3.tick();
  t3.printUniversal();

  return 0;
}
