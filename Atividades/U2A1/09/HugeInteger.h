#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <string>

class HugeInteger{
public:
    /* HugeInteger(string); */
    void input(std::string &);
    void output();
    void add(const HugeInteger &);
    
    bool isEqualTo(const HugeInteger &);
    bool isNotEqualTo(const HugeInteger &);
    bool isGreaterThan(const HugeInteger &);
    bool isLessThan(const HugeInteger &);
    bool isGreaterThanOrIqual(const HugeInteger &);
    bool isLessThanOrIqual(const HugeInteger &);
private:
    std::string x;
};

#endif