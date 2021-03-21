#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

#include "HugeInteger.h"

int main(){
    HugeInteger x, y;
    string n("1010101010101010101010101010101010101010");
    x.input(n);
    x.output();
    n = "0101010101010101010101010101010101010101";
    y.input(n);
    y.output();
    x.add(y);
    x.output();
    cout << (x.isEqualTo(y)==true ? "True" : "False") << endl;
    cout << (x.isNotEqualTo(y)==true ? "True" : "False") << endl;
    cout << (x.isGreaterThan(y)==true ? "True" : "False") << endl;
    cout << (x.isGreaterThanOrIqual(y)==true ? "True" : "False") << endl;
    cout << (x.isLessThan(y)==true ? "True" : "False") << endl;
    cout << (x.isLessThanOrIqual(y)==true ? "True" : "False") << endl;

    return 0;
}