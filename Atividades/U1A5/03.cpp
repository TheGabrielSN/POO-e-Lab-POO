#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

//definição da Classe Carro
class Empregado{

public:

    Empregado(string Nome, string Sobrenome,double Salario){
        Salario < 0 ? salario = 0 : salario = Salario;
        nome = Nome; sobrenome = Sobrenome;
    }

    void setNome(string Nome){
        nome = Nome;
    }

    string getNome(){
        return nome;
    }

    void setSobrenome(string Sobrenome){
        sobrenome = Sobrenome;
    }

    string getSobrenome(){
        return sobrenome;
    }

    void setSalario(double Salario){
        Salario < 0 ? salario = 0 : salario = Salario;
    }

    double getSalario(){
        return salario;
    }

private:
    string nome, sobrenome;
    double salario;
};

int main() {
    Empregado empregadoA("Aa", "Aaa", -252), empregadoB("Bb", "Bbb", 2000);

    empregadoA.setNome("Antonio");
    empregadoA.setSobrenome("Alves");
    empregadoA.setSalario(1500);

    cout << "Nome: " << empregadoA.getNome() << ", Sobrenome: " << empregadoA.getSobrenome() << ", Salario: " << empregadoA.getSalario() << endl;

    empregadoB.setSalario(200);
    
    cout << "Nome: " << empregadoB.getNome() << ", Sobrenome: " << empregadoB.getSobrenome() << ", Salario: " << empregadoB.getSalario() << endl;

    //Adição de 10%
    empregadoA.setSalario(empregadoA.getSalario()+(empregadoA.getSalario()/10));
    cout << "\nNome: " << empregadoA.getNome() << ", Sobrenome: " << empregadoA.getSobrenome() << ", Salario: " << empregadoA.getSalario() << endl;
    empregadoB.setSalario(empregadoB.getSalario()+(empregadoB.getSalario()/10));
    cout << "Nome: " << empregadoB.getNome() << ", Sobrenome: " << empregadoB.getSobrenome() << ", Salario: " << empregadoB.getSalario() << endl;


    return 0;
}