#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include <string>
#include "Pessoa.h"
using std::string;

class PessoaFisica : public Pessoa{
public:
    PessoaFisica setCPF(string CPF) { this->CPF = CPF; return *this;}
    string getCPF() { return this->CPF;}
private:
    string CPF;
};

#endif