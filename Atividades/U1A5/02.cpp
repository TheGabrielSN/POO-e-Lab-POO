#include <iostream>
using std::cout, std::endl;

class ContaBanco{
public:

    ContaBanco(double SaldoI){
        SaldoI < 0 ? saldo = 0 : saldo = SaldoI;
    }

    bool creditar(double valor){
        if(valor > 0){saldo += valor; return true;}
        else{return false;}
    }

    bool debitar(double valor){
        if(valor > saldo){
            cout << "Valor acima do permitido!" << endl;
            return false;
        } else if(valor>0){
            saldo -= valor;
            return true;
        }
        return false;
    }

    double getSaldo(){
        return saldo;
    }

private:
    double saldo;
};

int main() {
    ContaBanco contaA(5000.0), contaB(-100);
    contaA.creditar(6000);
    contaA.debitar(7050.15);
    contaA.debitar(10250.90);
    cout << "Saldo atual: " << contaA.getSaldo() << endl;
    
    contaB.creditar(500.50);
    contaB.debitar(450.45);
    cout << "Saldo atual: " << contaB.getSaldo() << endl;
    return 0;
}