#ifndef POUPANCA_H
#define POUPANCA_H
#include <iostream>                                         //Entrada e saída c++ 
using std::cout, std::endl;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::setprecision, std::setw, std::fixed;
#include ".\Conta.h"                                       //Classe abstrada Conta

class ContaPoupanca : public Conta {
    friend ofstream& operator<<(ofstream &dados, ContaPoupanca &c){
        dados << c.numConta << " " << c.saldo << " " << c.data << " " << c.Trans.size() << " ";
        if(c.Trans.size() != 0){
          for(auto &item:c.Trans){
              dados << item.desc << " " << item.valor << " " << item.data << " " ;}
        }
        dados << endl;
        return dados;
    }
    friend ifstream& operator>>(ifstream &dados, ContaPoupanca &c){
        int size;
        dados >> c.numConta >> c.saldo >> c.data >> size;
        if(size!=0){
          for(int i=0; i<size; i++){
              No no;
              dados >> no.desc >> no.valor >> no.data;
              c.addTrans(no);
          }
        }
        return dados;
    }
public:
    ContaPoupanca() : Conta(){}
    ContaPoupanca(string numero, Pessoa *pessoa, float saldo, string data, int tipo) : Conta(numero, pessoa, saldo, tipo), data(data) {}
    ContaPoupanca(const ContaPoupanca &CP) : Conta(CP.numConta, CP.pessoa, CP.saldo, CP.tipoPessoa), data(CP.data) {this->Trans = CP.Trans;}

    ~ContaPoupanca(){}

    virtual void extrato(void){
        this->pessoa->imprimir();
        cout << fixed;
        cout << endl << "Número da conta: " << this->numConta
             << setw(20) << " | Aniversario: " << this->data << endl;
        for(auto &item : this->Trans){
            cout << "Descricao: " << item.desc
                 << setw(20) << " | Data: " << item.data
                 << setw(20) << " | Valor: " << setprecision(2) << item.valor << endl;
        }
        return;
    }
private:
    string data;
};

#endif