#include <iostream>
using std::cout, std::endl;

#include "Quadrado.h"
#include "Circulo.h"
#include "Triangulo.h"

int main() {
    FormaBidimensional *formas[] = {new Quadrado(5.1), new Circulo(2.56), new Triangulo(8.0,3.15)};

    for (int i = 0 ; i < 3 ; i++)
    {
        formas[i]->desenhar();
        cout << "Area: " << formas[i]->calcularArea() << " || ";
        cout << "Perimetro: " << formas[i]->calcularPerimetro() << "\n" << endl;
        delete formas[i];
    }

    return 0;
}