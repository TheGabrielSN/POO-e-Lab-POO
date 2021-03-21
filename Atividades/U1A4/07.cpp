#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;

void minuscula(string &txt){
    string aux;
    for(auto &i:txt){
        aux += tolower(i);
    }
    txt = aux;
    return;
}

int main(){
    string txt = "ARQUIVO DE TESTE";
    minuscula(txt);
    cout << txt << endl;
    return 0;
}