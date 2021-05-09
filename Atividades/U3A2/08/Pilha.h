#ifndef PILHA_H
#define PILHA_H

#include <stdexcept>
using std::range_error;

template < class T >
class Pilha {
public:
    Pilha( int = 10 );
    ~Pilha();
    
    void push(const T &);
    void pop(T &);

    bool isEmpty() const { return pos == 0; }
private:
    T *pPtr;
    int pos, tam;
};

template < class T >
Pilha<T>::Pilha( int tam ){
    this->tam = ( (tam > 0) ? tam : 10 );
    pos = 0;

    pPtr = new T[this->tam];
}

template < class T >
Pilha<T>::~Pilha(){
    delete [] pPtr;
}

template < class T >
void Pilha<T>::push(const T &el){
    if (this->pos == this->tam){
        throw range_error("Erro de Inserção. Pilha Cheia!");
    }
    pPtr[pos++] = el;
}

template < class T>
void Pilha<T>::pop(T &el){
    if (this->pos==0){
        throw range_error("Erro de Remoção. Pilha Vazia!");
    }
    el = pPtr[--pos];
}

#endif