#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

#include "HugeInteger.h"

int main(){
    HugeInteger x, y;
    string n("1010101010101010101010101010101010101010");
    x = n;
    cout << "X = " << x << endl;
    n = "0101010101010101010101010101010101010101";
    y = n;
    cout << "Y = " << y << endl;
    x += y;
    cout << "X+Y = " << x << endl;
    cout << "X==Y = " << (x==y ? "True" : "False") << endl;
    cout << "X!=Y = " << (x!=y ? "True" : "False") << endl;
    cout << "X>Y = " << (x > y ? "True" : "False") << endl;
    cout << "X<Y = " << (x < y ? "True" : "False") << endl;
    cout << "X>=Y = " << (x >= y ? "True" : "False") << endl;
    cout << "X<=Y = " << (x <= y ? "True" : "False") << endl;

    return 0;
}