#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    int max, min, temp;
    for(int i = 0; i<6; i++){(i==5?(cout << "Min: " << min << "\nMax: " << max << endl,0):((cin >> temp), (i==0?min=temp:min=min,temp) > max?max=temp:(temp<min?min=temp:min=min)));}
    return 0;
}