#include "ImovelNovo.h"

ImovelNovo::ImovelNovo(string endereco, float preco) : Imovel(endereco, preco) {}
float ImovelNovo::getPreco() {
    return this->add + Imovel::getPreco();
}
void ImovelNovo::setAdicional(float add){
    this->add = add>0.0 ? add : 0.0;
}
float ImovelNovo::getAdicional(){
    return this->add;
}