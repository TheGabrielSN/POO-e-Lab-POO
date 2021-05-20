#ifndef LIMITE_H
#define LIMITE_H
#include <iostream>                                         //Entrada e saída c++ 
using std::cout, std::endl;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::setprecision, std::setw, std::fixed;
#include ".\Conta.h"                                       //Classe abstrada Conta

class ContaCorrenteLimite : public Conta {
    friend ofstream& operator<<(ofstream &data, ContaCorrenteLimite &c){
        data << c.numConta << " " << c.saldo << " " << c.getLimite() << " " << c.Trans.size() << " ";
        if(c.Trans.size()!=0){
            for(auto &item:c.Trans){
                data << item.desc << " " << item.valor << " " << item.data << " ";}
        }
        data << endl;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, ContaCorrenteLimite &c){
        int size;
        data >> c.numConta >> c.saldo >> c.limite >> size;
        for(int i=0; i<size; i++){
            No no;
            data >> no.desc >> no.valor >> no.data;
            c.addTrans(no);
        }
        return data;
    }
public:
    ContaCorrenteLimite() : Conta(){}
    ContaCorrenteLimite(string numero, Pessoa *pessoa, float saldo, int tipo, float limite) : Conta(numero, pessoa, saldo, tipo), limite(limite) {}
    ContaCorrenteLimite(ContaCorrenteLimite &CL) : Conta(CL.numConta, CL.pessoa, CL.saldo, CL.tipoPessoa), limite(CL.limite){this->Trans = CL.Trans;}

    ~ContaCorrenteLimite() {}

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
        cout << "Limite: " << setprecision(2) << this->limite << endl;

        return;
    }

    friend float operator>>(ContaCorrenteLimite &c, float valor){
        bool over = false;
        float ret = valor>c.saldo ? c.saldo + (valor-c.saldo > c.limite ? (over=true, c.limite) : valor-c.saldo) : valor;
        if(over){
            throw ExceptionOver("ExcedeLimite");
        }
        c.saldo -= valor>c.saldo ? (c.limite-=(valor-c.saldo > c.limite ? c.limite : valor-c.saldo), c.saldo) : ret;
        
        No no;
        no.valor = ret*-1;
        no.desc = "Retirada";
        c.addTrans(no);
        
        return ret;
    }

    inline float getLimite(void) { return this->limite; }
    inline void setLimite(float limite) { this->limite = limite; }

private:
    float limite;
};

#endif