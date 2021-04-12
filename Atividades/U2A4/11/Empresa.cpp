#include <iostream>
#include "Empresa.h"
using std::cout, std::endl;

Empresa::~Empresa(){
    while(this->iniC){
        NoC *temp = this->iniC;
        this->iniC = temp->prox;
        delete temp;
    }
    while(this->iniF){
        NoF *temp = this->iniF;
        this->iniF = temp->prox;
        delete temp;
    }
}

Empresa& Empresa::addClientes(Cliente cliente){
    NoC *no = new(NoC);
    no->cliente = cliente;
    if(!this->iniC){
        this->iniC = no;
    } else {
        NoC *tmp = new(NoC);
        tmp = iniC;
        while(tmp->prox){
            tmp = tmp->prox;
        }
        no->ant = tmp;
        tmp->prox = no;
    }
    return *this;
}

Empresa& Empresa::addFuncionarios(Funcionario funcionario){
    NoF *no = new(NoF);
    no->funcionario = funcionario;
    if(!this->iniF){
        this->iniF = no;
    } else {
        NoF *tmp = new(NoF);
        tmp = iniF;
        while(tmp->prox){
            tmp = tmp->prox;
        }
        no->ant = tmp;
        tmp->prox = no;
    }
    return *this;
}

void Empresa::printClientes(){
    NoC *tmp = new(NoC);
    tmp = this->iniC;
    while(tmp){
        cout << "Nome: " << tmp->cliente.getNome() <<
                " | Endereco: " << tmp->cliente.getEndereco() <<
                " | Telefone: " << tmp->cliente.getTelefone() <<
                " | CPF: " << tmp->cliente.getCPF() <<
        endl;
        tmp = tmp->prox;
    }
}

void Empresa::printFuncionarios(){
    NoF *tmp = new(NoF);
    tmp = this->iniF;
    while(tmp){
        cout << "Nome: " << tmp->funcionario.getNome() <<
                " | Matricula: " << tmp->funcionario.getMatricula() << 
                " | CPF: " << tmp->funcionario.getCPF() << 
                " | Salario: " << tmp->funcionario.getSalario() << 
                " | Carga Horaria: " << tmp->funcionario.getCargaHoraria() << 
                " | Horas Trabalhadas: " << tmp->funcionario.getHorasTrabalhadas() <<
        endl;
        tmp = tmp->prox;
    }
}

float Empresa::calcularFolhaDePagamento(){
    float fp = 0;
    NoF *tmp = new(NoF);
    tmp = this->iniF;
    while(tmp){
        fp += tmp->funcionario.calculaSalarioBruto();
        tmp = tmp->prox;
    }
    return fp;
}