#ifndef DATA_h
#define DATA_h
#include "..\Conta\Conta.h"                                       //Classe abstrada Conta

template<class T>
class Data{
public:
    Data() : index(-1) {}
    Data(T conta, int index, bool status, int tipo) : conta(conta), index(index), status(status), tipoConta(tipo){}
    //Data(Data<T> &d) : conta(d.conta), index(d.index), status(d.status) {}
    Data(const Data<T> &d) : conta(d.conta), index(d.index), status(d.status), tipoConta(d.tipoConta) {}
    bool operator==(const Data<T> &d){
        if((this->conta != d.conta) || (this->status != d.status) || (this->index != d.status)){
            return 0;
        }
        return 1;
    }
    inline T getConta(){ return this->conta; }
    inline int getIndex(){ return this->index; }
    inline bool getStatus(){ return this->status; }
    T conta;
    int index;
    bool status;
    int tipoConta;
};
#endif