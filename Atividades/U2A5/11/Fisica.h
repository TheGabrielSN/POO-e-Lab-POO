#ifndef FISICA_H
#define FISICA_H
#include "Pessoa.h"

class PessoaFisica : public Pessoa {
public:
    PessoaFisica(string nome, string end, string email, string CPF, string nasc, string ec) : 
                 Pessoa(nome, end, email), CPF(CPF), dataNasc(nasc), ec(ec) {}
    virtual void imprimir(void);
    virtual string getIdentificador(void) {return this->CPF;}
    
private:
    // ec -> estado civil
    string CPF, dataNasc, ec;
};

#endif