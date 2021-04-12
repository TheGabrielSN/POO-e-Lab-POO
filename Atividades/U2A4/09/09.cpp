#include <iostream>
#include "Funcionario.h"
using std::cout, std::endl;

int main(){
    Funcionario funcionario;
    funcionario.setNome("Aleatorio");
    funcionario.setCPF("999.999.999-99");
    funcionario.setMatricula(999);
    funcionario.setCargaHoraria(47);
    funcionario.setHorasTrabalhadas(45);
    funcionario.setSalario(15650.00);
    
    cout << funcionario << " | CPF: " << funcionario.getCPF() << endl;

    return 0;
}