#include <iostream>
using std::cout, std::endl;

#include "IntegerSet.h"

int main(){
    int lista[] = {0,2,4,6,8,10,12,14,16,18,20};
    IntegerSet arr1, arr2(lista, 11);
    arr1.insertElement(1).insertElement(2).insertElement(3).insertElement(4).insertElement(5).insertElement(6);
    arr1 << 10 << 11 << 12 << 13 << 14 << 15;
    cout << "arr1: " << arr1;
    cout << "arr2: " << arr2;

    IntegerSet arr3 = arr1 | arr2;
    cout << "arr3: " << arr3;
    IntegerSet arr4 = arr1 & arr2;
    cout << "arr4: " << arr4;

    return 0;
}