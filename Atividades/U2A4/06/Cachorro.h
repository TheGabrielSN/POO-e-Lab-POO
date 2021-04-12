#ifndef CACHORRO_H
#define CACHORRO_H
#include <string>
#include "Animal.h"
using std::string;

class Cachorro : public Animal{
public:
    Cachorro();
    Cachorro(string);
    string late();
};

#endif