#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::endl;

int main(){
    string a;
    getline(cin, a);

    for (auto &i:a){
        if (!(isalnum(i)) && i!=' ') continue;
        else {
            cout << i;
        }
    }
    cout << endl;

    return 0;
}