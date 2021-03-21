#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

//definição da Classe Carro
class Carro{

public:

    Carro(string nome, int vano){
        marca = nome;
    }

    void setAno(int vano){
        ano = vano;
    }

    int getAno(){
        return ano;
    }

    void setMarca(string nome){
        marca = nome;
    }

    string getMarca(){
        return marca;
    }

    void displayMessage(){
        cout << "Olah, eu sou um carro da marca " << getMarca() << "e meu ano eh: " << ano << endl;
    }

private:
    string marca;
    int ano;
};

int main() {
    //Carro meuCarro; //erro, não existe mais o construtor-padrão

    Carro meuCarro("Renault",2012);

    meuCarro.displayMessage();
    meuCarro.setAno(2010);
    cout << "Ano: " << meuCarro.getAno() << endl;

    return 0;
}