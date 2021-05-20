#ifndef NO_H
#define NO_H
#include <string>                                       //Tipo string c++ 
using std::string;

class No{
public:
    No() : valor(0) {}
    No(string data, string desc, float valor) : data(data), desc(desc), valor(valor) {}
    No(No *n) : data(n->data), desc(n->desc), valor(n->valor) {}
    string data, desc;
    float valor;
    bool operator==(const No &no) const{
        if((this->data != no.data) || (this->desc != no.desc) || (this->valor != no.valor)){
            return 0;
        }
        return 1;
    }
};

#endif