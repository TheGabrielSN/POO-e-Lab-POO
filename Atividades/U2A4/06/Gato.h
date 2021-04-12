#ifndef GATO_H
#define GATO_H
#include <string>
#include "Animal.h"
using std::string;

class Gato : public Animal{
public:
    Gato();
    Gato(string);
    string mia();
};

#endif