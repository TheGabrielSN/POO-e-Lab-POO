#ifndef FISICA_H
#define FISICA_H
#include <iostream>                                          //Entrada e saída c++
using std::cout, std::endl,
      std::ostream,  std::left, std::right;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::fixed, std::setw;
#include <fstream>                                          //Entrada e saída para arquivos
using std::ofstream, std::ifstream;
#include ".\Pessoa.h"                                       //Classe abstrada Pessoa

class PessoaFisica : public Pessoa {
    friend ofstream& operator<<(ofstream &data, PessoaFisica &p){
        data << p.nome << " " << p.endereco << " " << p.email << " " << p.tipoPessoa << " " << p.CPF << " " << p.dataNasc << " " << p.ec;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, PessoaFisica &p){
        data >> p.nome >> p.endereco >> p.email >> p.tipoPessoa
             >> p.CPF >> p.dataNasc >> p.ec;
        return data;
    }
public:
    PessoaFisica() : Pessoa() {}
    PessoaFisica(string nome, string end, string email, string CPF, string nasc, string ec, int tipo) : 
                 Pessoa(nome, end, email, tipo), CPF(CPF), dataNasc(nasc), ec(ec) {}
    PessoaFisica(const PessoaFisica &pf) : Pessoa(pf.nome, pf.endereco, pf.email, pf.tipoPessoa), CPF(pf.CPF), dataNasc(pf.dataNasc), ec(pf.ec) {}

    ~PessoaFisica() {}

    vector<string>& getIdentificador(void) {       
        this->dados.push_back(this->nome);
        this->dados.push_back(this->endereco);
        this->dados.push_back(this->email);
        this->dados.push_back(this->CPF);
        this->dados.push_back(this->dataNasc);
        this->dados.push_back(this->ec);

        return this->dados;
    }
    
    void imprimir(){
        cout << fixed;
        cout << "Nome: " << this->replace(this->nome, "_", " ")
             << right << setw(31) << "  | CPF: " << this->CPF << endl
             << "Nascimento: " << right << setw(17) << this->dataNasc 
             << right << setw(5) << "  | Estado Cívil: " << this->ec << endl
             << "E-mail: " << right << setw(21) << this->email << " "
             << right << setw(5) << " | Endereco: " << this->replace(this->endereco, "_", " ") << endl << endl;
    }

    inline void setEC(string ec){ this->ec = ec; }

private:
    // ec -> estado civil
    string CPF, dataNasc, ec;
    vector<string> dados;
};


#endif