#include <iostream>
using std::cout, std::endl;

#include "Retangulo.h"

Retangulo::Retangulo(float altura, float largura){
    setAltura((altura>0.0 && altura<20.0)? altura : 1.0f);
    setLargura((largura>0.0 && largura<20.0)? largura : 1.0f);
}

void Retangulo::setAltura(float a){
    altura = (a>0.0 && a<20.0)? a : 1.0f;
}

void Retangulo::setLargura(float l){
    largura = (l>0.0 && l<20.0)? l : 1.0f;
}

float Retangulo::getAltura(){
    return altura;
}

float Retangulo::getLargura(){
    return largura;
}

float Retangulo::perimetro(){
    return (getAltura()*2)+(getLargura()*2);
}

float Retangulo::area(){
    return getAltura()*getLargura();
}
