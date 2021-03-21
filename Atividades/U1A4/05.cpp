#include <iostream>

using std::cin, std::cout, std::endl;

void swap(int &a, int &b){
    int aux = b;
    b = a;
    a = aux;
}

int main(){
    int a, b;
    cout << "Digite os valores de entrada: " << endl;
    cin >> a;
    cin >> b;
    cout << "A: " << a << " B: " << b << endl;
    swap(a,b);
    cout << "A: " << a << " B: " << b << endl;
    return 0;
}