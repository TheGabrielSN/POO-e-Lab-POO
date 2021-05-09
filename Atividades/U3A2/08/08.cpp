#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

#include "Pilha.h"

int main() {
    Pilha<int> pi;
    int popEli;
    try{
        pi.push(10);
        pi.pop(popEli);
        pi.pop(popEli);
        cout << popEli << endl;
    } catch (range_error &e){
        cout << e.what() << endl;
    }    

    Pilha<double> pd;
    double popEld;
    try{
        pd.push(10.0);
        pd.pop(popEld);
        cout << popEld << endl;
    } catch (range_error &e){
        cout << e.what() << endl;
    }

    Pilha<string> ps(1);
    string popEls;
    try{
        ps.push("str1");
        ps.pop(popEls);
        ps.push("str1");
        ps.push("str1");
        cout << popEls << endl;
    } catch (range_error &e){
        cout << e.what() << endl;
    }

    Pilha< Pilha<int> > ppi(1);
    Pilha<int> popElp;
    try{
        ppi.push(pi);
        ppi.push(pi);
        ppi.push(pi);
        ppi.pop(pi);
        ppi.pop(pi);
        ppi.pop(pi);
        ppi.pop(pi);
        ppi.pop(pi);
        ppi.pop(pi);
    } catch (range_error &e){
        cout << e.what() << endl;
    }

    return 0;
}