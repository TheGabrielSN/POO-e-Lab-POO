#include "Cliente.h"
ostream& operator<<(ostream &cout, Cliente &cliente){
    cout << "Nome: " << cliente.nome <<
    " | Endereco: " << cliente.endereco <<
    " | Telefone: " << cliente.telefone <<
    " | CPF: " << cliente.getCPF();

    return cout;
}