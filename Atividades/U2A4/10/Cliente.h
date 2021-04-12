#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <string>
#include "..\08\PessoaFisica.h"
using std::string, std::ostream;

class Cliente : public PessoaFisica {
    friend ostream& operator<<(ostream&, Cliente&);
public:
    Cliente& setTelefone(string telefone) { this->telefone = telefone; return *this;}
    string getTelefone() { return this->telefone; }
    
    Cliente setEndereco(string endereco) { this->endereco = endereco; return *this;}
    string getEndereco() { return this->endereco; }

private:
    string telefone, endereco;
};

#endif