#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main(){
    string txt;

    cout << "Digite o texto de entrada: ";
    cin >> txt;

    cout.width(txt.length()*2);
    cout << txt << endl;

    return 0; 
}