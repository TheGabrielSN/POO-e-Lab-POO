#include <iostream>
using std::cout, std::endl;

#include "Agenda.h"


int main () {
	char linha[] = "---------------------------------------------\n";
	Agenda A;

	A.armazenaPessoa("Abel", 22, 1.78);
	A.armazenaPessoa(Pessoa("Tiago", 20, 1.80));
	A.imprimePovo();
	cout << linha;

	int posicao = A.buscaPessoa("Tiago");
	if (posicao > 0)
    	A.imprimePessoa(posicao);
	cout << linha;

	A.removePessoa("Tiago");
	A.imprimePovo();
	cout << linha;
	
 	return 0;
}