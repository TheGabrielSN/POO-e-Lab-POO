#include <iostream>
#include "Corrente.h"
#include "Limite.h"
#include "Poupanca.h"
using std::cout, std::endl;

int main(){
    Conta *arr[] = {new ContaCorrenteComun("0123456789", "Aleatorio 1", 15938.00),
                  new ContaCorrenteLimite("987654321", "Aleatorio 2", 5578.20, 17000),
                  new ContaPoupanca("147258369", "Aleatorio 3", 12078.20, "15/04/2021")
                  };
    
    arr[0]->deposito(5000);
    cout << "Retirada: " << arr[0]->retirada(25000) << endl;
    
    arr[1]->deposito(1000);
    cout << "Retirada: " << arr[1]->retirada(20000) << endl;
    
    arr[2]->deposito(100);
    cout << "Retirada: " << arr[2]->retirada(5000) << endl;
    
    cout << endl;

    for(auto &i : arr){
        i->extrato();
        cout << endl;
    }

    return 0;
}