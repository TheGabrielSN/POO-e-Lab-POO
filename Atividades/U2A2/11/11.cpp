#include <iostream>
using std::cout, std::endl;

#include "IntegerSet.h"

int main(){
    int lista[] = {0,2,4,6,8,10,12,14,16,18,20};
    IntegerSet arr1, arr2(lista, 11);
    arr1.insertElement(1).insertElement(2).insertElement(3).insertElement(4).insertElement(5).insertElement(6);
    cout << "arr1: ";
    arr1.print();
    cout << "arr2: ";
    arr2.print();
    cout << "arr3: ";

    IntegerSet arr3 = unionOfSets(arr1, arr2);
    arr3.print();
    cout << "arr4: ";
    IntegerSet arr4 = intersectionOfSets(arr1, arr2);
    arr4.print();

    /* Obs: Tentei fazer:
        IntegerSet arr3;
        arr3 = unionOfSets(arr1, arr2);
        arr3 = intersectionOfSets(arr1, arr2);
    Mas estava gerando uma modificação dos dados iniciais da lista (Os 4 primeiros apareciam
    como números diferes de 0/1, como 1194420240 e 534), a única maneira de corrigir foi na 
    maneira acima. Existe alguma explicação para isso?
    */

    return 0;
}