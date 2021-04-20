#include <iostream>
#include <string>
using std::cout, std::endl, std::cin, std::string;

#include "Array.h"

int main() {
    Array <int> a1(2), a2(2);
    Array <float> a3(2);
    Array <string> a4(2);

    cout << "Array int 1" << endl;
    cin >> a1;
    cout << "Array int 2" << endl;
    cin >> a2;
    cout << "Array float 3" << endl;
    cin >> a3;
    cout << "Array string 4" << endl;
    cin >> a4;

    cout << endl << a1 << a2 << a3 << a4;

    if(a1==a2){ cout << "Array 1 == Array 2" << endl;}

    return 0;
}