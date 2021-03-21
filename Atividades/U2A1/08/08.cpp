#include <iostream>
using std::cout, std::endl;

#include "Retangulo.h"

int main(){
    Retangulo r0;

    cout << "Area: " << r0.area() << "\t\tPerimetro: " << r0.perimetro() << "\t\t--> " << "Largura: " << r0.getLargura() << "\t\tAltura: " << r0.getAltura() << endl;
    r0.setAltura(5.15f);
    r0.setLargura(3.14f);
    cout << "Area: " << r0.area() << "\tPerimetro: " << r0.perimetro() << "\t--> " << "Largura: " << r0.getLargura() << "\tAltura: " << r0.getAltura() << endl;
    r0.setAltura(25);
    r0.setLargura(0);
    cout << "Area: " << r0.area() << "\t\tPerimetro: " << r0.perimetro() << "\t\t--> " << "Largura: " << r0.getLargura() << "\t\tAltura: " << r0.getAltura() << endl;

}