#include <string>
#include "Pessoa.h"
using std::string;

Pessoa::Pessoa(string nome, int idade, float altura){
    this->nome = nome;
    this->idade = idade;
    this->altura = altura;
}

Pessoa& Pessoa::setAltura(float altura){
    this->altura = altura;
    return *this;
}

Pessoa& Pessoa::setIdade(int idade){
    this->idade = idade;
    return *this;
}
