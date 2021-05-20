#ifndef EXEPTIONOVER_H
#define EXEPTIONOVER_H
#include <stdexcept>                                       //Classe abstrada Pessoa
using std::runtime_error;
class ExceptionOver : public runtime_error{
public:
    ExceptionOver(const char *e = "SaldoInsuficiente") : runtime_error(e) {} 
};

#endif