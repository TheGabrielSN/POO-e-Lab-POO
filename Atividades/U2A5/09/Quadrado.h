#ifndef QUADRADO_H
#define QUADRADO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Quadrado : public FormaBidimensional{
public:
    Quadrado(float lado) : FormaBidimensional(4), lado(lado){}

    virtual void desenhar() {
        cout << "-----" << endl;
        cout << "|   |" << endl;
        cout << "-----" << endl;
    }

    virtual float calcularArea() {return this->lado*this->lado;}
    virtual float calcularPerimetro() {return this->lado*4;}
private:
    float lado;
};

#endif