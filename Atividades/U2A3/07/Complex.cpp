#include <iostream>
#include <string>
#include "Complex.h"
using std::cout, std::endl, std::string;

Complex::Complex(string complex=""){
    string temp;
    bool in=false,im=false;
    for(auto &i:complex){
        if(i == '+'){
            this->inteiro = stoi((temp+'\0'));
            temp.clear();
            in=true;
        }
        if(i=='i'){
            this->imaginario = stoi((temp+'\0'));
            im=true;
        }
        temp += i;
    }
    if(temp!="" && !in && !im){this->inteiro = stoi((temp+'\0'));in=true;}
    if(!in) {this->inteiro = 0;}
    if(!im) {this->imaginario = 0;}
}

ostream& operator<<(ostream &out, const Complex &complex){
    out << complex.inteiro << "+" << complex.imaginario << "i";
    return out;
}

Complex operator+(Complex &A, Complex &B){
    Complex C;
    C.inteiro = A.inteiro + B.inteiro;
    C.imaginario = A.imaginario + B.imaginario;
    return C;
}

Complex operator-(Complex &A, Complex &B){
    Complex C;
    C.inteiro = A.inteiro - B.inteiro;
    C.imaginario = A.imaginario - B.imaginario;
    return C;
}

void Complex::setComplex(int Int, int Imag){
    this->inteiro = Int;
    this->imaginario = Imag;
}

Complex Complex::operator++(int){
    Complex temp = *this;
    this->inteiro++;
    return temp;
}

Complex& Complex::operator++(){
    this->inteiro++;
    return *this;
}

Complex& Complex::operator+=(Complex &complex){
    this->inteiro += complex.inteiro;
    this->imaginario += complex.imaginario;
    return *this;
}

Complex Complex::operator--(int){
    Complex temp = *this;
    this->inteiro--;
    return temp;
}

Complex& Complex::operator--(){
    this->inteiro--;
    return *this;
}

Complex& Complex::operator-=(Complex &complex){
    this->inteiro -= complex.inteiro;
    this->imaginario -= complex.imaginario;
    return *this;
}