#ifndef BANCO_H
#define BANCO_H

#include <iostream>                                             //Entrada e saída c++ 
using std::cout, std::endl;
#include <string>                                               //Tipo string c++ 
using std::string;
#include <fstream>                                              //Entrada e saída para arquivos
using std::ofstream, std::ifstream;
#include <stdexcept>                                            //Biblioteca para runtime_error
#include <exception>                                            //Biblioteca para exception
using std::runtime_error, std::exception;
#include <list>                                                 //STL -> Lista duplamente encadeada
#include <vector>                                               //STL -> Lista duplamente encadeada
using std::list, std::vector;
#include "..\Pessoa\Juridica.h"                                 //PessoaJuridica
#include "..\Pessoa\Fisica.h"                                   //PessoaFisica
#include "..\Conta\Corrente.h"                                  //ContaCorrenteComun
#include "..\Conta\Limite.h"                                    //ContaCorrenteLimite
#include "..\Conta\Poupanca.h"                                  //ContaPoupanca
#include ".\Controlador.h"                                      //Controlador do arquivo de dados
#include ".\Data.h"                                             //Estrutura para armazenamento de dados

class Banco : public PessoaJuridica{
public:
    Banco(string nome, string end, string email, string CNPJ, string is, string rs) : 
        PessoaJuridica(nome, end, email, CNPJ, is, rs, 1) {
            ifstream contas(".\\Banco\\data.dat", std::ios::in);
            this->datacontroler.getData(&this->dados, &this->CorrentistasF, &this->CorrentistasJ, contas);
            contas.close();
    }
    
    ~Banco(){
        ofstream contas(".\\Banco\\data.dat", std::ios::out);
        this->datacontroler.setData(this->dados, contas);
        contas.close();
    }

    void cadastrar(string, Pessoa *, float, int, int, float=0.0, string="0/0/0");
    void remover(string);
    void consultar(string);
    void atualizar(string, Conta*);
    void listar();
    Data<Conta*>* buscar(string);
    Pessoa* buscarPessoa(string, int);
    inline int getContContas() { return this->dados.size(); }

private:
    int tData = 0;
    list <Data<Conta*>> dados;
    list <PessoaFisica> CorrentistasF;
    list <PessoaJuridica> CorrentistasJ;
    Controlador datacontroler;
};

#endif