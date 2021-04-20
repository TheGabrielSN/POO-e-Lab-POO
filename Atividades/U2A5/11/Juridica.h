#ifndef JURIDICA_H
#define JURIDICA_H
#include "Pessoa.h"

class PessoaJuridica : public Pessoa {
public:
    PessoaJuridica(string nome, string end, string email, string CNPJ, string is, string rs) : 
                   Pessoa(nome, end, email), CNPJ(CNPJ), is(is), rs(rs){}
    virtual void imprimir(void);
    virtual string getIdentificador(void) {return this->CNPJ;}

private:
    // is -> inscrição estadual, rs -> razão social
    string CNPJ, is, rs;
};

#endif