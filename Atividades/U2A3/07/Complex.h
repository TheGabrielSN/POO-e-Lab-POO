#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
using std::ostream, std::istream, std::string;

class Complex{
    friend ostream& operator<<(ostream&, const Complex&);
    friend Complex operator+(Complex&, Complex&);
    friend Complex operator-(Complex&, Complex&);
public:
    Complex(string);

    Complex& operator+=(Complex&);
    Complex& operator-=(Complex&);
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);

    void setComplex(int,int);

private:
    int inteiro, imaginario;
};
#endif