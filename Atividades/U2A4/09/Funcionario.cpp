#include "Funcionario.h"

ostream& operator<<(ostream &cout, const Funcionario &funcionario){
    cout << "Nome: " << funcionario.nome <<
    " | Matricula: " << funcionario.matricula << 
    " | Salario: " << funcionario.salario << 
    " | Carga Horaria: " << funcionario.ch << 
    " | Horas Trabalhadas: " << funcionario.ht;
    return cout;
}

float Funcionario::calculaSalarioBruto(){
    float aux;
    return this->salario * (aux = static_cast<float>(this->ht), aux/this->ch);
}

Funcionario& Funcionario::setCargaHoraria(int ch){
    this->ch = ch>0 ? ch : 0;
    return *this;
}

Funcionario& Funcionario::setHorasTrabalhadas(int ht){
    this->ht = (ht>0 && ht<=this->ch) ? ht : 0;
    return *this;
}

Funcionario& Funcionario::setSalario(float salario){
    this->salario = salario>0 ? salario : 0;
    return *this;
}
