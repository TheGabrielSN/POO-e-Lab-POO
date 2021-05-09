#include <iostream>
using std::cout, std::endl;

#include "error1.h"
#include "error2.h"
#include "error3.h"

int main(){

    try {
        throw Error1();
        throw Error2();
        throw Error3();
    }
    catch (runtime_error &e)
    {
        cout << "Erros runtime_error:" << endl;
        cout << e.what() << endl;
    }
    try {
        throw Error2();
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    try {
        throw Error3();
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}