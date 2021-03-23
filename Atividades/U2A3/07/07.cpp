#include <iostream>
#include "Complex.h"
using std::cout, std::endl;

int main(){
    Complex c1("10+5i"), c2("15i"), c3("25");
    cout << c1 << " " << c2 << " " << c3 << endl;

    cout << "/-> + <-/" << endl;
    Complex c4 = c1+c3;
    cout << c1 << " + " << c3 << " = " << c4 << endl;

    cout << "/-> += <-/" << endl;
    cout << c2 << " += " << c4 << " = " << (c2+=c4, c2) << endl;

    cout << "/-> - <-/" << endl;
    c3 = c2 - c1;
    cout << c1 << " - " << c2 << " = " << c3 << endl;

    cout << "/-> -= <-/" << endl;
    cout << c1 << " -= " << c1 << " = " << (c1-=c1, c1) << endl;

    cout << "/-> ++ <-/" << endl;
    cout << c1 << " ++" << " = " << c1++ << endl;
    cout << "++ " << c1 << " = " << ++c1 << endl;

    cout << "/-> -- <-/" << endl;
    cout << c4 << " --" << " = " << c4-- << endl;
    cout << "-- " << c4 << " = " << --c4 << endl;
    return 0;
}