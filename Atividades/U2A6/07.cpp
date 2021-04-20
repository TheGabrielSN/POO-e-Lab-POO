#include <iostream>
#include <string>
using std::cout, std::endl, std::cin, std::string;

#include "Fila.h"

int main() {
    Fila <int> a1(2), a2(2);
    Fila <float> a3(2);
    Fila <string> a4(2);

    cout << "Fila int 1" << endl;
    cin >> a1;
    cout << "Fila int 2" << endl;
    cin >> a2;
    cout << "Fila float 3" << endl;
    cin >> a3;
    cout << "Fila string 4" << endl;
    cin >> a4;

    cout << endl << a1 << a2 << a3 << a4;

    cout << a1.dequeue() << endl;
    cout << a4.dequeue() << endl;
    cout << a4.dequeue() << endl;

    cout << endl << a1 << a2 << a3 << a4;
    
    return 0;
}