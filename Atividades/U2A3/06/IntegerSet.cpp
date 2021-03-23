#include <iostream>
using std::cout, std::endl;

#include "IntegerSet.h"

IntegerSet::IntegerSet(){
    this->arr = new int[100];
    for(int i=0; i<100; i++){ this->arr[i] = 0; }    
}

IntegerSet::IntegerSet(int arr[], int tam){
    this->arr = new int[100];
    for(int i=0; i<100; i++){ this->arr[i] = 0; }
    for(int i=0; i<tam; i++){
        if(arr[i]>-1 && arr[i]<100){
            this->arr[arr[i]] = 1;
        } else {
            cout << "Number out the range!" << endl;
        }
    }
}

IntegerSet::~IntegerSet(){
    delete this->arr;
}

IntegerSet& IntegerSet::insertElement(int n){
    if(n>-1 && n<100){
        if(this->arr[n] == 1){ cout << "Number already added " << endl; }
        else {this->arr[n] = 1;}
    } else {
        cout << "Number out the range!" << endl;
    }
    return *this;
}

IntegerSet& IntegerSet::deleteElement(int n){
    if(n>-1 && n<100){
        this->arr[n] = 0;
    } else {
        cout << "Number out the range!" << endl;
    }
    return *this;
}

IntegerSet& IntegerSet::print(){
    for(int i=0; i<100; i++){
        if(this->arr[i] == 1){ cout << i << " "; }
    }
    cout << endl;
    return *this;
}

IntegerSet operator|(const IntegerSet &A, const IntegerSet &B){
    IntegerSet C;
    for(int i=0; i<100; i++){
        if(A.arr[i]==1 || B.arr[i]==1){ C.arr[i] = 1;}
        else {C.arr[i] = 0;}
    }
    return C;
}

IntegerSet operator&(const IntegerSet &A, const IntegerSet &B){
    IntegerSet C;
    for(int i=0; i<100; i++){
        if(A.arr[i]==1 && B.arr[i]==1){ C.arr[i] = 1; }
        else {C.arr[i] = 0;}
    }
    return C;
}

ostream& operator<<(ostream &out, const IntegerSet &IS){
    for(int i=0; i<100; i++){
        if(IS.arr[i] == 1){ out << i << " "; }
    }
    cout << endl;
    return out;
}

IntegerSet unionOfSets(const IntegerSet &A, const IntegerSet &B){
    IntegerSet C;
    for(int i=0; i<100; i++){
        if(A.arr[i]==1 || B.arr[i]==1){ C.arr[i] = 1;}
        else {C.arr[i] = 0;}
    }
    return C;
}

IntegerSet intersectionOfSets(const IntegerSet &A, const IntegerSet &B){
    IntegerSet C;
    for(int i=0; i<100; i++){
        if(A.arr[i]==1 && B.arr[i]==1){ C.arr[i] = 1; }
        else {C.arr[i] = 0;}
    }

    return C;
}