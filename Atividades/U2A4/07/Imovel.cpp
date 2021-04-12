#include <string>
#include "Imovel.h"

Imovel::Imovel(string endereco, float preco) :  endereco(endereco), preco(preco) {}
void Imovel::setEndereco(string endereco){
    this->endereco = endereco;
} 
string Imovel::getEndereco(){
    return this->endereco;
}
void Imovel::setPreco(float preco){
    this->preco = preco>0.0 ? preco : 0.0;
}
float Imovel::getPreco(){
    return this->preco;
}