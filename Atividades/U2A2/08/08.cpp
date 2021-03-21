#include <iostream>
#include <string>
#include "Pessoa.h"
using std::cout, std::endl, std::string;

int main(){
    Pessoa p1("Pessoa Qualquer 1"), p2("Pessoa Qualquer 2", 39, 1.85f);
    Pessoa p3;
    p1.setAltura(1.65).setIdade(24);
    cout << "Nome: " << p1.getNome() << " | Idade: " << p1.getIdade() << " | Altura: " << p1.getAltura() << endl; 
    cout << "Nome: " << p2.getNome() << " | Idade: " << p2.getIdade() << " | Altura: " << p2.getAltura() << endl; 
}