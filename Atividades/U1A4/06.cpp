#include <iostream>
#include <string>

using std::cin, std::cout, std::endl, std::string;

bool maiscula(string txt){
    for(auto &i:txt){
        if(isupper(i)==1){
            return true;
        }
    }
    return false;
}

int main(){
    cout << maiscula("arquivo") << endl;
    cout << maiscula("arquivo De") << endl;
    return 0;
}