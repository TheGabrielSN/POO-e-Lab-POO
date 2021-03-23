#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <string>
#include <iostream>
using std::ostream, std::istream, std::string;

class HugeInteger{
    friend ostream& operator<<(ostream&, const HugeInteger&);
    friend HugeInteger operator+(HugeInteger&, HugeInteger&);
public:
    HugeInteger& operator=(string&);
    HugeInteger& operator+=(const HugeInteger&);
    bool operator==(const HugeInteger &numer){ return this->x == numer.x; }
    bool operator!=(const HugeInteger &numer){ return this->x != numer.x; }
    bool operator>=(const HugeInteger &numer){ return this->x >= numer.x; }
    bool operator<=(const HugeInteger &numer){ return this->x <= numer.x; }
    bool operator>(const HugeInteger &numer){ return this->x > numer.x; }
    bool operator<(const HugeInteger &numer){ return this->x < numer.x; }
private:
    std::string x;
};

#endif