#ifndef IMOVELVELHO_H
#define IMOVELVELHO_H
#include <string>
#include "Imovel.h"
using std::string;

class ImovelVelho : public Imovel{
public:
    ImovelVelho(string="", float=0.0);

    float getPreco();
    void setDesconto(float);
    float getDesconto();

private:
    float desc;
};

#endif