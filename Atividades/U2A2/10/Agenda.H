#ifndef AGENDA_H
#define AGENDA_H
#include <string>
#include "../08/Pessoa.h"
using std::string;

class Agenda{
public:
    Agenda(int);
    ~Agenda();
    void armazenaPessoa(string, int, float);
    void armazenaPessoa(const Pessoa &);

    void removePessoa(string);

    int buscaPessoa(string) const;
    void imprimePovo() const;
    void imprimePessoa(int i) const;
private:
    Pessoa *pessoas;
    int qtdePessoas;
};

#endif