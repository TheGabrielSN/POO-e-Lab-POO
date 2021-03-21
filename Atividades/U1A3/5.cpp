#include <iostream>

using std::cout, std::cin, std::endl;

int main(){
    float km, L, tgasol;
    while (true){
        cin >> km;
        if(km == -1) break;
        cin >> L;
        tgasol += L;
        cout << "Consumo: " << (km/L) << "Km/L" << "\nTotal de gasolina: " << tgasol << "L" << endl;
    }

    return 0;
}