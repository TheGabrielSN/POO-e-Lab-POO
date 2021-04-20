#ifndef NO_H
#define NO_H
#include <string>
#include "Pessoa.h"
using std::string;

class No{
public:
    No() : prox(nullptr){}
    No *prox;
    Pessoa *pessoa;
};

#endif