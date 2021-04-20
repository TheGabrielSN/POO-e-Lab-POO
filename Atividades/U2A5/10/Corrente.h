#ifndef CORRENTE_H
#define CORRENTE_H
#include "Conta.h"

class ContaCorrenteComun : public Conta {
public:
    ContaCorrenteComun(string numero, string nome, float saldo) : Conta(numero, nome, saldo) {}
    virtual void extrato(void);
};

#endif