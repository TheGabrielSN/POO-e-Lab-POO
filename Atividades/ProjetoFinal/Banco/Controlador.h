#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <fstream>                                              //Entrada e saída para arquivos
using std::ofstream, std::ifstream;
#include <iostream>                                             //Entrada e saída c++ 
using std::ostream, std::endl;
#include <list>                                                 //STL -> Lista duplamente encadeada
using std::list;
#include ".\Data.h"                                             //Tipo Abstrato de Dados - Data
#include ".\Exception.h"                                        //Objeto abstrato -> Erro de execução
#include "..\Conta\Conta.h"                                     //Classe abstrada Conta
#include "..\Conta\Corrente.h"                                  //Conta Corrente Comum
#include "..\Conta\Limite.h"                                    //Conta Corrente Com Limite
#include "..\Conta\Poupanca.h"                                  //Conta Poupança
#include "..\Pessoa\Fisica.h"                                   //Pessoa Fisica
#include "..\Pessoa\Juridica.h"                                 //Pessoa Juridica

class Controlador{
public:
    Controlador() {}
    void getData(list <Data<Conta*>> *, list <PessoaFisica> *, list<PessoaJuridica>*, ifstream &);
    void setData(list <Data<Conta*>> &, ofstream &);
};
#endif