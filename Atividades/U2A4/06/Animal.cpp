#include <string>
#include "Animal.h"
using std::string;

Animal::Animal() : nome(""), raca("") {}
Animal::Animal(string nome) : nome(nome), raca("") {}
string Animal::caminhar(){
    return "Caminhando...";
}