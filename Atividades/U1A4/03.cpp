#include <iostream>

using std::cout,std::endl;

int sequencia(){
    static int n = 0;
    return n++;
}

int main(){
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    cout << sequencia() << endl;
    return 0;
}