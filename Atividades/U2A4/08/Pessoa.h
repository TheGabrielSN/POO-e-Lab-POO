#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>
using std::string, std::ostream;

class Pessoa{
    friend ostream& operator<<(ostream&, const Pessoa&);
public:
    Pessoa& setNome(string);
    string getNome();
protected:
    string nome;
};

#endif