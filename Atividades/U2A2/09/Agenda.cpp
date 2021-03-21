#include <iostream>
#include <string>
#include "Agenda.h"
#include "../08/Pessoa.h"
using std::cout, std::endl, std::string;

void Agenda::armazenaPessoa(string nome, int idade, float altura){
    Pessoa p1(nome, idade, altura);
    this->armazenaPessoa(p1);
}

void Agenda::armazenaPessoa(const Pessoa &p){
    static int pos = 0;
    this->pessoas[pos] = p;
    pos ++;
}

void Agenda::removePessoa(string nome){
    bool ok = false;
    int pos;
    for(int i=0; i<10; i++){
        if(!ok){
            if(this->pessoas[i].getNome() == nome) { ok=true; pos = i;}
        } else {
            this->pessoas[pos] = this->pessoas[i];
            pos++;
        }
    }
}

int Agenda::buscaPessoa(string nome) const {
    int pos = 0;
    for(auto &i:this->pessoas){
        if(i.getNome() == nome){ break; }
        pos++;
    }
    return ++pos;
}

void Agenda::imprimePessoa(int i) const {
    cout << "Nome: " << this->pessoas[--i].getNome() << " | Idade: " << this->pessoas[i].getIdade() << " | Altura: " << this->pessoas[i].getAltura() << endl;
}

void Agenda::imprimePovo() const {
    for(auto &i:this->pessoas){
        if(i.getNome() != string(""))
            cout << "Nome: " << i.getNome() << " | Idade: " << i.getIdade() << " | Altura: " << i.getAltura() << endl;
    }
}