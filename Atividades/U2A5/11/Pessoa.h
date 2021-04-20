#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using std::string;

class Pessoa{
public:
    Pessoa(string nome, string end, string email) : nome(nome), endereco(end), email(email) {}
    virtual void imprimir(void) = 0;
    virtual string getIdentificador(void) = 0;
    string getNome(void) {return this->nome;}
protected:
    string nome, endereco, email;
};

#endif