#include <iostream>
#include "Fisica.h"
using std::cout, std::endl;

void PessoaFisica::imprimir(){
    cout << "Nome: " << this->nome <<
            " | CPF: " << this->CPF << endl <<
            "Nascimento: " << this->dataNasc << 
            " | Estado Cívil: " << this->ec << endl <<
            "E-mail: " << this->email << 
            "| Endereco: " << this->endereco << endl;
}