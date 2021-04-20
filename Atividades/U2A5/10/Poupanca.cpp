#include "Poupanca.h"
#include <iostream>
using std::cout, std::endl;

void ContaPoupanca::extrato(){
    cout << "Conta: " << this->numConta <<
            "\tNome: " << this->nome << 
            "\tAniversario: " << this->data << endl;
    No *temp = this->init;
    while(temp){
        cout << "Descricao: " << temp->desc <<
                " | Data: " << temp->data <<
                " | Valor: " << temp->valor << endl;
        temp = temp->prox;
    }
    cout << "Saldo: " << this->saldo << endl;
}