#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);

    if (a != b){
        if (a > b){
            cout << a << endl;
        } else {
            cout << b << endl;}
    }
    return 0;
}