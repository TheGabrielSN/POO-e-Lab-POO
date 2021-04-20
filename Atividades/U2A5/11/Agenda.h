#ifndef AGENDA_H
#define AGENDA_H
#include "Fisica.h"
#include "Juridica.h"
#include "No.h"

class Agenda {
public:
    Agenda() : init(nullptr) {}
    ~Agenda();
    void adicionar(bool, string, string, string, string, string, string);
    void remover(string);
    Pessoa* pesquisar(string);
    void mostrarTodos(void);
private:
    No *init = nullptr;
};

#endif