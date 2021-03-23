#include <iostream>
using std::cout, std::endl;
using std::cin;

#include "Array.h"

int main() {
    Array a1(7);
    Array a2;

    cin >> a1; 

    cout << a1;

    if (a1 == a2)
        cout << "a1 e a2 são iguais";

    Array a3(a1);

    a3[5] = 100;

    cout << "a3[5] == " << a3[5] << endl;

    a2 = a3;

    cout << "a2[5] == " << a3[5] << endl;

    Array a4 = a1 + a2;
    cout << "a1 + a2 = "<< a4;

    a3+=a1;
    cout << "a3 += a1 -> " << a3;

    return 0;
}