#include <iostream>
using std::cout, std::endl;

int main(){
    for(int i=33; i<=126; i++){
        cout.width(3);
        cout << i << " | ";
        cout.put(i);
        cout << endl;
    }

    return 0;
}