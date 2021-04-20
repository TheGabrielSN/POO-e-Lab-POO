#ifndef CIRCULO_H
#define CIRCULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Circulo : public FormaBidimensional{
public:
    Circulo(float raio) : FormaBidimensional(99999), raio(raio) {}

    virtual void desenhar() {
        cout << "  _ " << endl;
        cout << "/   \\" << endl;
        cout << "\\   /" << endl;
        cout << "  ~ " << endl;
    }

    virtual float calcularArea() {return this->pi * (this->raio*this->raio);}
    virtual float calcularPerimetro() {return 2*this->pi*this->raio;}
private:
    float pi = 3.14;
    float raio;
};

#endif