#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo{
public:
    Retangulo(float = 1.0f, float = 1.0f);

    void setAltura(float);
    void setLargura(float);

    float getAltura();
    float getLargura();

    float perimetro();
    float area();

private:
    float largura, altura;
};

#endif