#include <iostream>
#include <iomanip>
using std::cout, std::endl, std::fixed, std::setprecision;

int main(){
    double num(100.453627);
    cout << fixed;
    cout << setprecision(1) << "Precisao 1 = " << num << endl;
    cout << setprecision(2) << "Precisao 2 = " << num << endl;
    cout << setprecision(3) << "Precisao 3 = " << num << endl;
    cout << setprecision(4) << "Precisao 4 = " << num << endl;

    return 0;
}