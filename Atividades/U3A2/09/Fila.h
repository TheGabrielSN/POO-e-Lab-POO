#ifndef FILA_H
#define FILA_H
#include <iostream>
using std::cout, std::endl, std::ostream, std::istream;
#include <stdexcept>
using std::range_error;

template <class T>
class Fila{
    friend ostream &operator<<( ostream &out, const Fila<T> &a){
        for (int i = 0 ; i < a.pos ; i++){
            out << a.filla[i] << " ";
        }
        out << endl;
        return out;
    }

    friend istream &operator>>( istream &inp, Fila<T> &a){
        for (int i = 0 ; i < a.tam ; i++){
            inp >> a.filla[i];
            a.pos++;
        }
        return inp;
    }
public:
    Fila(int tam = 10){
        this->tam = (tam > 0 ? tam : 10);
        filla = new T[this->tam];
        this->pos = 0;
    }

    void enqueue(T elemento){
        if (this->pos < this->tam){
            this->filla[this->pos++] = elemento;
        } else{
            throw range_error("Erro de Inserção. Fila Cheia!");
        }
    }

    T dequeue(){
        T dado;
        if (this->pos) {
            dado = this->filla[0];
            for (int i = 0 ; i < this->pos -1 ; i++){
                this->filla[i] = this->filla[i+1];
            }
            this->pos--;
        }
        else {
            throw range_error("Erro de Remoção. Fila Vazia!");
        }
        return dado;
    }

    int tamanho(){
        return this->pos;
    }

    int getFront(){
        return this->filla[0];
    }

private:
    T *filla;
    int pos, tam;
};

#endif