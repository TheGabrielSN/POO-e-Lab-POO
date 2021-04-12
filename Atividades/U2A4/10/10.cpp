#include <iostream>
#include "Cliente.h"
using std::cout, std::endl;

int main(){
    Cliente cliente;
    cliente.setNome("Aleatorio");
    cliente.setCPF("999.999.999-99");
    cliente.setEndereco("Rua aleatoria 1, 999, Aleatoria");
    cliente.setTelefone("(99)9 9999-9999");
    
    cout << cliente << endl;

    return 0;
}