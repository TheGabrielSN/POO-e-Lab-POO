#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include "..\08\PessoaFisica.h"
using std::ostream;

class Funcionario : public PessoaFisica{
    friend ostream& operator<<(ostream&, const Funcionario&);
public:
    float calculaSalarioBruto();

    Funcionario& setMatricula(int matricula) {this->matricula = matricula; return *this;}
    int getMatricula() { return this->matricula; }

    Funcionario& setCargaHoraria(int);
    int getCargaHoraria() { return this->ch; }

    Funcionario& setHorasTrabalhadas(int);
    int getHorasTrabalhadas() { return this->ht; }

    Funcionario& setSalario(float);
    float getSalario() { return this->salario; }
private:
    // ch - carga horaria; ht - horas trabalhadas
    int matricula, ch, ht;
    float salario;
};
#endif
