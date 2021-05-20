#ifndef PESSOA_H
#define PESSOA_H
#include <iostream>                                     //Entrada e saída c++ 
using std::ostream, std::cout, std::endl;
#include <fstream>                                     //Entrada e saída para arquivos 
using std::ofstream, std::ifstream;
#include <string>                                     //Tipo string c++ 
using std::string;
#include <vector>                                     //STL -> vetor sequencial 
using std::vector;

class Pessoa{
    friend ofstream& operator<<(ofstream &data, Pessoa *p){
        data << p->nome << "" << p->endereco << "" << p->email << "" << p->tipoPessoa;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, Pessoa *p){
        data >> p->nome >> p->endereco >> p->email >> p->tipoPessoa;
        return data;
    }
public:
    Pessoa() {}
    Pessoa(string nome, string end, string email, int tipo) : nome(nome), endereco(end), email(email), tipoPessoa(tipo) {}
    ~Pessoa() {}
    virtual vector<string>& getIdentificador(void) = 0;
    virtual void imprimir(void) = 0;
    bool operator==(Pessoa *p){ return this->getIdentificador() == p->getIdentificador();}
    inline int getTipoPessoa(void) { return this->tipoPessoa; }
    inline void setEmail(string email) { this->email = email; }
    inline void setEndereco(string end) { this->endereco = end; }
protected:
    string nome, endereco, email;
    int tipoPessoa;
    string replace(string word, string target, string replacement){
        int len, loop=0;
        string nword="", let;
        len=word.length();
        len--;
        while(loop<=len){
            let=word.substr(loop, 1);
            if(let==target){
                nword=nword+replacement;
            }else{
                nword=nword+let;
            }
            loop++;
        }
        return nword;
    }
};

#endif