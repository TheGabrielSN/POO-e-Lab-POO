#include "Limite.h"
#include <iostream>
using std::cout, std::endl;

void ContaCorrenteLimite::extrato(){
    cout << "Conta: " << this->numConta <<
            "\tNome: " << this->nome << endl;
    No *temp = this->init;
    while(temp){
        cout << "Descricao: " << temp->desc <<
                " | Data: " << temp->data <<
                " | Valor: " << temp->valor << endl;
        temp = temp->prox;
    }
    cout << "Saldo: " << this->saldo << endl;
    cout << "Limite: " << this->limite << endl;
}

float ContaCorrenteLimite::retirada(float valor){
    float ret = valor>this->saldo ? this->saldo + (valor-this->saldo > this->limite ? this->limite : valor-this->saldo) : valor;
    this->saldo -= valor>this->saldo ? (limite-=(valor-this->saldo > this->limite ? this->limite : valor-this->saldo), this->saldo) : ret;
    
    No *no = new(No);
    no->valor = ret*-1;
    no->desc = "Retirada";
    this->addTrans(*no);
    
    return ret;
}
