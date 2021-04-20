#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

template <class T>
bool comparar(T t1, T t2){
    return t1==t2;
}

int main(){
    cout << comparar(1,1) << endl;
    cout << comparar(1,2) << endl;
    cout << comparar(0.0,0.0) << endl;
    cout << comparar(0.1,0.0) << endl;
    cout << comparar<double>(0.1,0.0) << endl;
    cout << comparar<double>(0.1,0.0) << endl;
    cout << comparar<string>("aqui","aqui") << endl;
    cout << comparar<string>("aqui","ali") << endl;

    return 0;
}