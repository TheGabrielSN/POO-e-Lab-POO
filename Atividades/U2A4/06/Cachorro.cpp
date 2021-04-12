#include <string>
#include "Cachorro.h"
using std::string;

Cachorro::Cachorro() : Animal(){}
Cachorro::Cachorro(string nome) : Animal(nome){}

string Cachorro::late(){
    return "Auau, te amo mestre!";
}