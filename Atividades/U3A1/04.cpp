#include <iostream>
#include <iomanip>
using std::cin, std::cout, std::endl, std::fixed, std::setprecision;

int main(){
    int temp;
    while(true){
        cout << "Digite a temperatura (em fahrenheit)"
             << endl 
             << "Digite -1 para sair"
             << endl;
        cin >> temp;
        if (temp ==-1) { break; }
        else if (temp > 212){ cout << "Valor Invalido!"; }
        else {
            cout << fixed;
            cout << setprecision(3) << "Temperatura em celsius: " 
                 << endl;
            cout.width(2);
            cout << ((5.0 / 9.0) * (temp - 32)) 
                 << endl;
            cout << "--------------------"
                 << endl;
        }
    }

    return 0;
}