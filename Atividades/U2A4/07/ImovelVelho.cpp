#include "ImovelVelho.h"

ImovelVelho::ImovelVelho(string endereco, float preco) : Imovel(endereco, preco) {}
float ImovelVelho::getPreco() {
    return this->desc > Imovel::getPreco() ? 0.0 : Imovel::getPreco() - this->desc;
}
void ImovelVelho::setDesconto(float desc){
    this->desc = desc>0.0 ? desc : 0.0;
}
float ImovelVelho::getDesconto(){
    return this->desc;
}