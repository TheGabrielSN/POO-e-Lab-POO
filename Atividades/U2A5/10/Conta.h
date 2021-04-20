#ifndef CONTA_H
#define CONTA_H
#include <ctime>
#include <string>
#include "No.h"
using std::string;

class Conta{
public:
    Conta(string numero, string nome, float saldo) : numConta(numero), nome(nome), saldo(saldo) {}
    ~Conta();
    void deposito(float);
    virtual float retirada(float);
    virtual void extrato(void) = 0;
protected:
    void addTrans(No&);
    No *init = nullptr;
    string numConta, nome;
    float saldo;
};

#endif