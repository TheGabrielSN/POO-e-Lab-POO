#include <iostream>
#include "Agenda.h"
using std::cout, std::endl;

Agenda::~Agenda(){
    No *temp;
    while(init){
        temp = init;
        init = init->prox;
        delete temp;
    }
}

//P/ Pessoa Física         0         nome,      end,       email,     CPF,       nasc,     ec
//P/ Pessoa Juridica       1         nome,      end,       email,     CNPJ,       is,      rs
void Agenda::adicionar(bool tipo, string p1, string p2, string p3, string p4, string p5, string p6){
    Pessoa *pessoa = nullptr;
    if(!tipo){
        pessoa = new PessoaFisica(p1, p2, p3, p4, p5, p6);
    } else {
        pessoa = new PessoaJuridica(p1, p2, p3, p4, p5, p6);
    }
    No *no = new No;
    no->pessoa = pessoa;

    if(!this->init){
        this->init = no;
    } else {
        No *temp = this->init;
        while(temp->prox){
            temp = temp->prox;
        }
        temp->prox = no;
    }
}

void Agenda::remover(string param){
    No *temp = this->init, *ant = nullptr;
    while(temp){
        if(temp->pessoa->getNome() == param || temp->pessoa->getIdentificador() == param){
            break;
        }
        ant = temp;
        temp = temp->prox;
    }
    if(!temp){
        cout << "Pessoa Nao Encontrada." << endl;
        return;
    }
    cout << "Removendo: " << endl;
    temp->pessoa->imprimir();
    if(!ant){
        this->init = this->init->prox;
    } else {
        ant->prox = temp->prox;
    }
    delete temp;
    cout << "Removido!" << endl;
}

Pessoa* Agenda::pesquisar(string param){
    No *temp = this->init;
    while(temp){
        if(temp->pessoa->getNome() == param || temp->pessoa->getIdentificador() == param){
            break;
        }
        temp = temp->prox;
    }
    if(!temp){
        cout << "Pessoa Nao Encontrada." << endl;
        return nullptr;
    }
    return temp->pessoa;
}

void Agenda::mostrarTodos(void){
    No *temp = this->init;
    while(temp){
        temp->pessoa->imprimir();
        cout << "----------" << endl;
        temp = temp->prox;
    }
}