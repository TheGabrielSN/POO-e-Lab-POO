#include <iostream>
#include "Gato.h"
#include "Cachorro.h"

int main(){
    Animal aleatorio("Rato Ratoso");
    Gato cat("Gato 1");
    Cachorro dog("Cachorro 1");
    
    std::cout << "Gato, mie!: " << cat.mia() << "\nGato, caminhe!: " << cat.caminhar() << std::endl;
    std::cout << "Cachorro, late!: " << dog.late() << "\nCachorro, caminhe!: " << dog.caminhar() << std::endl;

    return 0;
}