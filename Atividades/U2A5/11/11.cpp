#include <iostream>
#include "Agenda.h"
using std::cout, std::endl;

int main(){
    Agenda agenda;
    //P/ P Física    0         nome,      end,               email,                 CPF,          nasc,        ec
    //P/ P Juridica  1         nome,      end,               email,                 CNPJ,          is,         rs
    agenda.adicionar(0, "AleatorioF 1", "Rua aleatoria 1", "aleatorio@alet.com", "99999999999", "99/99/9999", "S");
    agenda.adicionar(0, "AleatorioF 2", "Rua aleatoria 2", "oirotaela@alet.com", "99999999998", "99/99/9999", "C");
    agenda.adicionar(0, "AleatorioF 3", "Rua aleatoria 3", "random@alet.com", "99999999997", "99/99/9999", "V");
    agenda.adicionar(0, "AleatorioF 4", "Rua aleatoria 4", "aleatorio2@alet.com", "99999999996", "99/99/9999", "C");
    agenda.adicionar(0, "AleatorioF 5", "Rua aleatoria 5", "ards@alet.com", "99999999995", "99/99/9999", "S");

    agenda.adicionar(1, "AleatorioJ 1", "Rua aleatoria 1", "aleatorio@empresarial.com", "99999999994", "99999999", "Random1");
    agenda.adicionar(1, "AleatorioJ 2", "Rua aleatoria 2", "oirotaela@empresarial.com", "99999999993", "99999999", "Random2");
    agenda.adicionar(1, "AleatorioJ 3", "Rua aleatoria 3", "random@empresarial.com", "99999999992", "99999999", "Random3");
    agenda.adicionar(1, "AleatorioJ 4", "Rua aleatoria 4", "aleatorio2@empresarial.com", "99999999991", "99999999", "Random4");
    agenda.adicionar(1, "AleatorioJ 5", "Rua aleatoria 5", "ards@empresarial.com", "99999999990", "99999999", "Random5");
    
    cout << "Mostrar todos: " << endl << endl;
    
    agenda.mostrarTodos();

    cout << "------------------------------" << endl << endl;
    cout << "Remocoes: " << endl << endl;
    agenda.remover("AleatorioF 1");
    agenda.remover("99999999997");
    agenda.remover("99999999995");
    agenda.remover("AleatorioJ 5");
    agenda.remover("AleatorioJ 3");
    agenda.remover("99999999994");
    cout << "------------------------------" << endl << endl;
    

    cout << "Mostrar todos: " << endl << endl;
    agenda.mostrarTodos();
    cout << "------------------------------" << endl << endl;

    cout << "Imprimir Selecionado: " << endl << endl;
    Pessoa *pessoa = agenda.pesquisar("AleatorioF 2");
    pessoa->imprimir();

    return 0;
}