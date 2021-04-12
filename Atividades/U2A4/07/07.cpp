#include <iostream>
#include "ImovelNovo.h"
#include "ImovelVelho.h"
using std::cout, std::endl;

int main(){
    Imovel imovel;
    ImovelNovo INovo;
    ImovelVelho IVelho;

    cout << "/*-----> Referentes ao Imovel <-----*/" << endl;
    imovel.setEndereco("Rua Aleatoria, 9999, Cidade Aleatoria");
    imovel.setPreco(15000);
    cout << "Endereco: " << imovel.getEndereco() << " \tPreco: " << imovel.getPreco() << endl;

    cout << "\n/*-----> Referentes ao Imovel Novo <-----*/" << endl;
    INovo.setEndereco("Rua Aleatoria 2, 111111, Cidade Aleatoria");
    INovo.setPreco(15000);
    INovo.setAdicional(650);
    cout << "Endereco: " << INovo.getEndereco() << " \tPreco: " << INovo.getPreco() << endl;

    cout << "\n/*-----> Referentes ao Imovel Velho <-----*/" << endl;
    IVelho.setEndereco("Rua Aleatoria 3, 06849, Cidade Aleatoria");
    IVelho.setPreco(15000);
    IVelho.setDesconto(650);
    cout << "Endereco: " << IVelho.getEndereco() << " \tPreco: " << IVelho.getPreco() << endl;
    IVelho.setDesconto(16000);
    cout << "Endereco: " << IVelho.getEndereco() << " \tPreco: " << IVelho.getPreco() << endl;


    return 0;
}