#ifndef LIMITE_H
#define LIMITE_H
#include "Conta.h"

class ContaCorrenteLimite : public Conta {
public:
    ContaCorrenteLimite(string numero, string nome, float saldo, float limite) : Conta(numero, nome, saldo), limite(limite) {}
    virtual void extrato(void);
    virtual float retirada(float);
private:
    float limite;
};

#endif