#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using std::string;

class Pessoa{
public:
    Pessoa(string="", int=1, float=1.0f);
    
    Pessoa& setIdade(int);
    Pessoa& setAltura(float);

    inline const string& getNome() const { return this->nome; }
    inline const int& getIdade() const { return this->idade; }
    inline const float& getAltura() const { return this->altura; }

private:
    string nome;
    int idade;
    float altura;
};

#endif