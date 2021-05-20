#include "Correntista.h"

void Correntista::depositar(float valor){
    Data<Conta*> *d;
    try{
        d = this->banco.buscar(this->num);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    *d->conta << valor;
}
float Correntista::retirar(float valor){
    Data<Conta*> *d;
    try{
        d = this->banco.buscar(this->num);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    try{
        return *d->conta >> valor;
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    return 0;
}
bool Correntista::tranferir(float valor, string num){
    Data<Conta*> *d, *dt;
    try{
        d = this->banco.buscar(this->num);
        dt = this->banco.buscar(num);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    try{
        d->conta->transferencia(valor, dt->conta);
        return true;
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    return false;
}
void Correntista::saldo(){
    Data<Conta*> *d;
    try{
        d = this->banco.buscar(this->num);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    cout << fixed;
    cout << "Saldo: " << setprecision(2) << d->conta->getSaldo() << endl; 
}
void Correntista::extrato(){
    Data<Conta*> *d;
    try{
        d = this->banco.buscar(this->num);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    d->conta->extrato();
}