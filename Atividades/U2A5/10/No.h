#ifndef NO_H
#define NO_H
#include <string>
using std::string;

class No{
public:
    No() : prox(nullptr) {}
    No *prox;
    string data, desc;
    float valor;
};

#endif