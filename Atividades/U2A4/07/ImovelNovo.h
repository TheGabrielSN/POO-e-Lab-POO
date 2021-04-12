#ifndef IMOVELNOVO_H
#define IMOVELNOVO_H
#include <string>
#include "Imovel.h"
using std::string;

class ImovelNovo : public Imovel{
public:
    ImovelNovo(string="", float=0.0);

    float getPreco();
    void setAdicional(float);
    float getAdicional();

private:
    float add;
};

#endif