#ifndef GERENTE_H
#define GERENTE_H

#include <iostream>                                     //Entrada e saída c++ 
using std::cout, std::endl;
#include <string>                                       //Tipo string c++
using std::string, std::to_string;
#include <vector>                                       //STL -> vetor sequencial 
using std::vector;
#include <stdexcept>                                    //Biblioteca para exception
using std::exception;
#include <exception>                                    //Biblioteca para runtime_error
using std::runtime_error;
#include ".\Conta\ExceptionOver.h"
#include ".\Pessoa\Fisica.h"                            //Pessoa Fisica
#include ".\Pessoa\Juridica.h"                          //Pessoa Juridica
#include ".\Conta\Corrente.h"                           //Conta Corrente Comum
#include ".\Conta\Limite.h"                             //Conta Corrente Com Limite
#include ".\Conta\Poupanca.h"                           //Conta Poupança
#include ".\Banco\Banco.h"                              //Banco
#include ".\Banco\Data.h"                               //Tipo Abstrato de Dados - Data

class Gerente{
public:
    Gerente(Banco &banco) : banco(banco), numConta(banco.getContContas()) {}
    ~Gerente() {}
    void abrir(vector<string>&, int, int, float=0.0, string="0/0/0");
    void fechar(string);
    void consultar(string);
    void atualizar(string, string, int);

private:
    Banco &banco;
    unsigned int numConta = 0;
    void gerarNumConta();
};
#endif