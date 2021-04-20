#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FormaBidimensional.h"

#include <iostream>
using std::cout, std::endl;

class Triangulo : public FormaBidimensional{
public:
    Triangulo(float base, float altura) : FormaBidimensional(3), base(base), altura(altura) {}

    virtual void desenhar() {
        cout << "  .   " << endl;
        cout << " / \\ " << endl;
        cout << "/   \\" << endl;
        cout << "~~~~~ " << endl;
    }

    virtual float calcularArea() {return (this->base*this->altura)/2;}
    virtual float calcularPerimetro() {return this->base*3;} //Considerando um triangulo equilatero
private:
    float base, altura;
};

#endif