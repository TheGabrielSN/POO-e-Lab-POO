#ifndef JURIDICA_H
#define JURIDICA_H
#include <iostream>                                          //Entrada e saída c++
using std::ostream, std::endl,
      std::left, std::right;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::fixed, std::setw;
#include <fstream>                                          //Entrada e saída para arquivos
using std::ofstream, std::ifstream;
#include ".\Pessoa.h"                                       //Classe abstrada Pessoa

class PessoaJuridica : public Pessoa {
    friend ofstream& operator<<(ofstream &data, PessoaJuridica &p){
        data << p.nome << " " << p.endereco << " " << p.email << " " << p.tipoPessoa << " " << p.CNPJ << " " << p.is << " " << p.rs;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, PessoaJuridica &p){
        data >> p.nome >> p.endereco >> p.email >> p.tipoPessoa
             >> p.CNPJ >> p.is >> p.rs;
        return data;
    }
public:
    PessoaJuridica() : Pessoa() {}
    PessoaJuridica(string nome, string end, string email, string CNPJ, string is, string rs, int tipo) : 
                   Pessoa(nome, end, email, tipo), CNPJ(CNPJ), is(is), rs(rs){}
    PessoaJuridica(const PessoaJuridica &pj) : Pessoa(pj.nome, pj.endereco, pj.email, pj.tipoPessoa), CNPJ(pj.CNPJ), is(pj.is), rs(pj.rs){}
    
    ~PessoaJuridica() {}

    virtual vector<string>& getIdentificador(void) {      
        this->dados.push_back(this->nome);
        this->dados.push_back(this->endereco);
        this->dados.push_back(this->email);
        this->dados.push_back(this->CNPJ);
        this->dados.push_back(this->is);
        this->dados.push_back(this->rs);

        return this->dados;
    }

    virtual void imprimir(){
        cout << "Nome: " << this->replace(this->nome, "_", " ")
             << right << setw(29) << " | CNPJ: " << this->CNPJ << endl
             << "Inscricao Estadual: " << right << setw(16) << this->is 
             << right << setw(5) << " | Razao Social: " << this->rs << endl
             << "E-mail: " << right << setw(20) << this->email << " "
             << right << setw(5) << "| Endereco: " << this->replace(this->endereco, "_", " ") << endl << endl;
    }

private:
    // is -> inscrição estadual, rs -> razão social
    string CNPJ, is, rs;
    vector<string> dados;
};

#endif