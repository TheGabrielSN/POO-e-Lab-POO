#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include <string>
#include "Pessoa.h"
using std::string;

class PessoaJuridica : public Pessoa{
public:
    PessoaJuridica& setCNPJ(string CNPJ) { this->CNPJ = CNPJ; return *this;}
    string getCNPJ() { return this->CNPJ;}

    PessoaJuridica& setRazaoSocial(string RS) {this->RS = RS; return *this;}
    string getRazaoSocial() { return this->RS; }

    PessoaJuridica& setNomeFantasia(string NF) {this->nome = NF; return *this;}
    string getNomeFantasia() {return this->nome;}
private:
    /*RS - Razão Social; NF - Nome Fantasia*/
    string CNPJ, RS;
};

#endif