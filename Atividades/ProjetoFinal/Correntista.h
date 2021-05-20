#ifndef CORRENTISTA_H
#define CORRENTISTA_H

#include <iostream>                                     //Entrada e saída c++ 
using std::cout, std::endl;
#include <string>                                       //Tipo string c++ 
using std::string;
#include <vector>                                       //STL -> vetor sequencial 
using std::vector;
#include <exception>                                    //Biblioteca para exception
#include <stdexcept>                                    //Biblioteca para runtime_error
using std::runtime_error, std::exception;
#include ".\Pessoa\Fisica.h"                            //Pessoa Fisica
#include ".\Pessoa\Juridica.h"                          //Pessoa Juridica
#include ".\Conta\Corrente.h"                           //Conta Corrente Comum
#include ".\Conta\Limite.h"                             //Conta Corrente Com Limite
#include ".\Conta\Poupanca.h"                           //Conta Poupança
#include ".\Banco\Banco.h"                              //Banco
#include ".\Banco\Data.h"                               //Tipo Abstrato de Dados - Data

class Correntista{
public:
    Correntista(string num, Banco &banco) : num(num), banco(banco) {}
    ~Correntista() {}
    void depositar(float valor);
    float retirar(float valor);
    bool tranferir(float valor, string num);
    void saldo();
    void extrato();
private:
    string num;
    Banco &banco;
};

#endif