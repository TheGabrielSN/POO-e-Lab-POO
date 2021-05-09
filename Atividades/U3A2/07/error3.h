#ifndef ERROR3_H
#define ERROR3_H

#include <stdexcept>
using std::runtime_error;

class Error3 : public runtime_error{
public:
    Error3() : runtime_error("Erro Aleatorio 3.") {}
    void mostrar_error(){
        throw this;
    }
};

#endif