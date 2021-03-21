#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

#include "HugeInteger.h"


void HugeInteger::input(string &numer){
    bool num (true);
    for (auto &i : numer) {
        if (!isdigit(i))
        num = false;
    }
    if (num && numer.length() <= 40) { this->x = numer;} 
    else { cout << "Valor invalido!" << endl; }
}

void HugeInteger::output(){
    cout << this->x << endl;
}

void HugeInteger::add(const HugeInteger &numer){
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
}
    
bool HugeInteger::isEqualTo(const HugeInteger &numer){
    return this->x == numer.x;
}

bool HugeInteger::isNotEqualTo(const HugeInteger &numer){
    return this->x != numer.x;
}

bool HugeInteger::isGreaterThan(const HugeInteger &numer){
    return this->x > numer.x;
}

bool HugeInteger::isLessThan(const HugeInteger &numer){
    return this->x < numer.x;
}

bool HugeInteger::isGreaterThanOrIqual(const HugeInteger &numer){
    return this->x >= numer.x;
}

bool HugeInteger::isLessThanOrIqual(const HugeInteger &numer){
    return this->x <= numer.x;
}