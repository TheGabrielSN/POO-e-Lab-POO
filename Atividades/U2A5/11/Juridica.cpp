#include <iostream>
#include "Juridica.h"
using std::cout, std::endl;

void PessoaJuridica::imprimir(){
    cout << "Nome: " << this->nome <<
            " | CNPJ: " << this->CNPJ << endl <<
            "Inscricao Estadual: " << this->is << 
            " | Razao Social: " << this->rs << endl <<
            "E-mail: " << this->email << 
            "| Endereco: " << this->endereco << endl;
}