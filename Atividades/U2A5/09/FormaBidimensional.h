#ifndef FORMABI_H
#define FORMABI_H 

//classe abstrata

class FormaBidimensional{
public:
    FormaBidimensional(int numLados) : numLados(numLados) { }

    virtual void desenhar() = 0;
    virtual float calcularArea() = 0;
    virtual float calcularPerimetro() = 0;

private:
    int numLados;
};

#endif