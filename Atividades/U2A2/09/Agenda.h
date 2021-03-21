#ifndef AGENDA_H
#define AGENDA_H
#include <string>
#include "../08/Pessoa.h"
using std::string;

class Agenda{
public:
    void armazenaPessoa(string, int, float);
    void armazenaPessoa(const Pessoa &);

    void removePessoa(string);

    int buscaPessoa(string) const; // informa em que posição da agenda está a pessoa
    void imprimePovo() const; // imprime todos os dados de todas as pessoas da agenda
    void imprimePessoa(int) const; // imprime os dados da pessoa que está na posição 'i' da agenda
private:
    Pessoa pessoas[10];
};

#endif