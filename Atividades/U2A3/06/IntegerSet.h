#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <iostream>
using std::ostream, std::istream;

class IntegerSet{
    friend IntegerSet operator|(const IntegerSet &A, const IntegerSet &B);
    friend IntegerSet operator&(const IntegerSet &A, const IntegerSet &B);
    friend ostream& operator<<(ostream &, const IntegerSet &);
    friend IntegerSet unionOfSets(const IntegerSet &A, const IntegerSet &B);
    friend IntegerSet intersectionOfSets(const IntegerSet &A, const IntegerSet &B);
public:
    IntegerSet();
    IntegerSet(int[], int);

    ~IntegerSet();

    IntegerSet& insertElement(int);
    IntegerSet& deleteElement(int);
    IntegerSet& print();

    IntegerSet &operator<<(int number){
        if(number>-1 && number<100){ this->arr[number] = 1; }
        return *this;
    }
    int operator>>(int number){
        if(number>-1 && number<100){ this->arr[number] = 0; }
        return number;
    }

private:
    int *arr;
};

#endif