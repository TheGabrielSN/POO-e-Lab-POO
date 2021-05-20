#ifndef CORRENTE_H
#define CORRENTE_H
#include <iostream>                                         //Entrada e saída c++ 
using std::cout, std::endl;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::setprecision, std::setw, std::fixed;
#include ".\Conta.h"                                       //Classe abstrada Conta

class ContaCorrenteComun : public Conta {
    friend ofstream& operator<<(ofstream &data, ContaCorrenteComun &c){
        data << c.numConta << " " << c.saldo << " " << c.Trans.size() << " ";
        if(c.Trans.size() != 0){
          for(auto &item:c.Trans){
              data << item.desc << " " << item.valor << " " << item.data << " " ;}
        }
        data << endl;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, ContaCorrenteComun &c){
        int size;
        data >> c.numConta >> c.saldo >> size;
        for(int i=0; i<size; i++){
            No no;
            data >> no.desc >> no.valor >> no.data;
            c.addTrans(no);
        }
        return data;
    }
public:
    ContaCorrenteComun() : Conta(){}
    ContaCorrenteComun(string numero, Pessoa *pessoa, float saldo, int tipo) : Conta(numero, pessoa, saldo, tipo) {}
    ContaCorrenteComun(ContaCorrenteComun &CC) : Conta(CC.numConta, CC.pessoa, CC.saldo, CC.tipoPessoa){this->Trans = CC.Trans;}

    ~ContaCorrenteComun(){}

    virtual void extrato(void){
        this->pessoa->imprimir();
        cout << fixed;
        cout << endl << "Número da conta: " << this->numConta << endl;
        for(auto &item : this->Trans){
            cout << "Descricao: " << item.desc
                 << setw(20) << " | Data: " << item.data
                 << setw(20) << " | Valor: " << setprecision(2) << item.valor << endl;
        }
        cout << "Saldo: " << setprecision(2) << this->saldo << endl;

        return;
    }
};

#endif