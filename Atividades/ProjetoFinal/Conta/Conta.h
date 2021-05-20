#ifndef CONTA_H
#define CONTA_H
#include <ctime>                                //Hora local da transação
#include <string>                               //String c++
using std::string;
#include <list>                                 //STL -> Lista duplamente encadeada
using std::list;
#include ".\No.h"                               //No -> Objeto para guardar as informações na lista
#include ".\ExceptionOver.h"                    //Objeto abstrato -> Gasto de Limite/Saldo superior ao diponível
#include "..\Pessoa\Pessoa.h"                   //Classe abstrada Pessoa

class Conta{
    friend ofstream& operator<<(ofstream &data, Conta *c){
        //data << c->pessoa << endl;
        data << c->numConta << c->saldo << c->Trans.size();
        for(auto &item:c->Trans){
            data << item.desc << item.valor << item.data;}
        data << endl;
        return data;
    }
    friend ifstream& operator>>(ifstream &data, Conta *c){
        int size;
        data >> c->numConta >> c->saldo >> size;
        for(int i=0; i<size; i++){
            No no;
            data >> no.desc >> no.valor >> no.data;
            c->addTrans(no);
        }
        return data;
    }
public:
    Conta() {}
    Conta(string numero, Pessoa *pessoa, float saldo, int tipo) : numConta(numero), pessoa(pessoa), saldo(saldo), tipoPessoa(tipo){}
    ~Conta(){ this->Trans.clear(); }

    friend Conta &operator<<(Conta &c, float valor){
        c.saldo += valor > 0 ? valor : 0;

        No no;
        no.valor = valor;
        no.desc = "Deposito";
        c.addTrans(no);
        return c;
    }

    friend float operator>>(Conta &c, float valor){
        if (valor>c.saldo){
            throw ExceptionOver();
        }
        c.saldo -= valor;

        No no;
        no.valor = valor*-1;
        no.desc = "Retirada";
        c.addTrans(no);

        return valor;
    }

    bool operator==(Conta &c){
        if((this->pessoa != c.pessoa) || (this->Trans != c.Trans) || (this->numConta != c.numConta) || (this->saldo != c.saldo)){
                return 0;
            }
        return 1;
    }

    virtual void transferencia(float valor, Conta *c){
        if (valor>this->saldo){
            throw ExceptionOver();
        }
        this->saldo -= valor;
        c->saldo += valor;

        No no;

        // Transação na conta do tranferente 
        no.valor = valor*-1;
        no.desc = "Tranferencia";
        this->addTrans(no);

        // Transação na conta do recebedor
        no.valor = valor;
        no.desc = "Tranferencia Recebida";
        c->addTrans(no);

        return;
    }

    virtual void extrato(void) = 0;

    inline string getNum(void) { return this->numConta; }
    inline float getSaldo(void) { return this->saldo; }
    inline Pessoa* getPessoa(void) { return this->pessoa; }
    inline int getTipoPessoa(void) { return this->tipoPessoa; }

    inline void setPessoa(Pessoa *p){ this->pessoa = p; }
    inline void setTipoPessoa(int tp) { this->tipoPessoa = tp; }

protected:
    Pessoa *pessoa;
    list <No> Trans;
    string numConta;
    float saldo;
    int tipoPessoa;
    void addTrans(No &no){
        /*Data da transação*/
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        string date;
        date = std::to_string((now->tm_mday)) + "/" + std::to_string((now->tm_mon + 1)) + "/" + std::to_string((now->tm_year + 1900));

        no.data = date;
        /**/

        this->Trans.push_back(no);

        return;
    }
};

#endif