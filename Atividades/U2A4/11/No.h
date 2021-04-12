#ifndef NO_H
#define NO_H
#include "..\09\Funcionario.h"
#include "..\10\Cliente.h"

class NoF{
public:
    NoF() : prox(nullptr), ant(nullptr) {}
    NoF(Funcionario &funcionario) : funcionario(funcionario), prox(nullptr), ant(nullptr) {}
    NoF *prox, *ant;
    Funcionario funcionario;
};

class NoC{
public:
    NoC() : prox(nullptr), ant(nullptr) {}
    NoC(Cliente &cliente) : cliente(cliente), prox(nullptr), ant(nullptr) {}
    NoC *prox, *ant;
    Cliente cliente;
};

#endif