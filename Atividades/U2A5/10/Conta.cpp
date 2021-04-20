#include <ctime>
#include "Conta.h"

Conta::~Conta(){
    while(this->init){
        No *temp = this->init;
        this->init = this->init->prox;
        delete(temp);
    }
}

void Conta::addTrans(No &no){
    /*Data da transação*/
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    string date;
    date = std::to_string((now->tm_mday)) + "/" + std::to_string((now->tm_mon + 1)) + "/" + std::to_string((now->tm_year + 1900));

    no.data = date;
    /**/
    if(!this->init){
        this->init = &no;
    } else {
        No *temp = this->init;
        while(temp->prox){
            temp = temp->prox;
        }
        temp->prox = &no;
    }

    return;
}

void Conta::deposito(float valor){
    this->saldo += valor > 0 ? valor : 0;

    No *no = new(No);
    no->valor = valor;
    no->desc = "Deposito";
    this->addTrans(*no);
    return;
}

float Conta::retirada(float valor){
    float ret = valor>this->saldo ? this->saldo : valor;
    this->saldo -= ret;
    
    No *no = new(No);
    no->valor = ret*-1;
    no->desc = "Retirada";
    this->addTrans(*no);
    
    return ret;
}
