#include <iostream>
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
using std::cout, std::endl;

int main(){
    Pessoa p1;
    PessoaFisica pf1;
    PessoaJuridica pj1;
    cout << "/*-----> Informacoes relacionadas a pessoa <-----*/" << endl;
    p1.setNome("Aleatorio 1");
    cout << p1 << endl;
    cout << "\n/*-----> Informacoes relacionadas a pessoa fisica <-----*/" << endl;
    pf1.setNome("Aleatorio 2");
    pf1.setCPF("999.999.999-99");
    cout << pf1 << " - " << pf1.getCPF() << endl;
    cout << "\n/*-----> Informacoes relacionadas a pessoa juridica<-----*/" << endl;
    pj1.setNomeFantasia("Aleatorio 3");
    pj1.setCNPJ("000.000.000-00");
    pj1.setRazaoSocial("Random");
    cout << pj1 << " - " << pj1.getCNPJ() << " - " << pj1.getRazaoSocial() << endl;
    return 0;
}