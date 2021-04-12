#include <iostream>
#include "Pessoa.h"

ostream& operator<<(ostream &cout, const Pessoa &pessoa){
    cout << pessoa.nome;
    return cout;
}

Pessoa& Pessoa::setNome(string nome){
    this->nome = nome;
    return *this;
}

string Pessoa::getNome(){
    return this->nome;
}
