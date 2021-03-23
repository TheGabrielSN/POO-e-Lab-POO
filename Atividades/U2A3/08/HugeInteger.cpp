#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

#include "HugeInteger.h"

ostream& operator<<(ostream &out, const HugeInteger &hungerinteger){
    out << hungerinteger.x;
    return out;
}
HugeInteger operator+(HugeInteger &A, HugeInteger &B){
    HugeInteger C(A);
    C+=B;
    return C;
}

HugeInteger& HugeInteger::operator=(string &numer){
    bool num (true);
    for (auto &i : numer) {
        if (!isdigit(i))
        num = false;
    }
    if (num && numer.length() <= 40) { this->x = numer;} 
    else { cout << "Valor invalido!" << endl; }
    return *this;
}

HugeInteger& HugeInteger::operator+=(const HugeInteger &numer){
    string aux = string(this->x.rbegin(),this->x.rend());
    string aux2 = string(numer.x.rbegin(),numer.x.rend());
    string n1, n2;
    int rest = 0, sum;
    for(int i = 0; i<(aux2.length()>=aux.length()?aux.length():aux2.length()); i++){
        n1 = aux[i]+'\0';
        n2 = aux2[i]+'\0';
        sum = stoi(n1) + stoi(n2) + rest;
        rest = sum>9 ? 1 : 0;
        sum -= sum>9 ? 10 : 0;
        if(aux2.length() >= aux.length()){ aux2[i] = sum+'0'; }
        else {aux[i] = sum+'0';}
    }
    aux = (aux2.length()>=aux.length() ? aux2 : aux);
    this->x = string(aux.rbegin(),aux.rend());
    return *this;
}