#include <iostream>

/*01*/
/*
int i = 42;
int main(){
   int i = 100;
   int j = i;
}
*/

/*3*/
/*
int main()
{
   int i, &ri = i;
   i = 5; ri = 10;
   std::cout << i << " " << ri << std::endl;
   return 0;
}*/
int main(){
  //int i = -1;
  //const int i2 = i, &r = i;
  //int *const p2 = &i2;
  //int *p1 = &i2;
  //const int *const p3 = &i2;
  //const int &const r2;

  int i;
  double d;
  i = d = 3.5;
  std::cout << d << " " << i << std::endl;
  return 0;
}