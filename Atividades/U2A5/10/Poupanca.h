#ifndef POUPANCA_H
#define POUPANCA_H
#include "Conta.h"

class ContaPoupanca : public Conta {
public:
    ContaPoupanca(string numero, string nome, float saldo, string data) : Conta(numero, nome, saldo), data(data) {}
    virtual void extrato(void);
private:
    string data;
};

#endif