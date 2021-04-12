#ifndef IMOVEL_H
#define IMOVEL_H
#include <string>
using std::string;

class Imovel{
public:
    Imovel(string="", float=0.0);
    
    void setEndereco(string);
    string getEndereco();
    void setPreco(float);
    float getPreco();

private:
    string endereco;
    float preco;
};

#endif