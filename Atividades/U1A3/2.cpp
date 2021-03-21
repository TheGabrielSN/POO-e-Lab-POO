#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main(){
    string a;
    cin >> a;
    for (auto &i:a){
        cout << 'X';
    }
    cout << endl;

    return 0;
}