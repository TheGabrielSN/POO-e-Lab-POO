#ifndef ERROR1_H
#define ERROR1_H

#include <stdexcept>
using std::runtime_error;

class Error1 : public runtime_error{
public:
    Error1() : runtime_error("Erro Aleatorio 1.") {}
};

#endif