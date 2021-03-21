#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet{
    friend IntegerSet unionOfSets(const IntegerSet &A, const IntegerSet &B);
    friend IntegerSet intersectionOfSets(const IntegerSet &A, const IntegerSet &B);
public:
    IntegerSet();
    IntegerSet(int[], int);

    ~IntegerSet();

    IntegerSet& insertElement(int);
    IntegerSet& deleteElement(int);
    IntegerSet& print();

private:
    int *arr;
};

#endif