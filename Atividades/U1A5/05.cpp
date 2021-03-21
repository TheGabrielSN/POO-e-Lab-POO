#include <iostream>
#include <string>
using std::cout, std::endl, std::string;

class Cupom{
public:

    Cupom(string Id, string Descricao, int Quantidade, float Preco){
        Quantidade < 0 ? quantidade = 0 : quantidade = Quantidade;
        Preco < 0 ? preco = 0 : preco = Preco;
        id = Id; descricao = Descricao;
    }

    // ID
    void setId(string Id){
        id = Id;
    }
    
    string getId(){
        return id;
    }

    // Descrição
    void setDescricao(string Descricao){
        descricao = Descricao;
    }
    
    string getDescricao(){
        return descricao;
    }

    // Quantidade
    void setQuantidade(int Quantidade){
        Quantidade < 0 ? quantidade = 0 : quantidade = Quantidade;
    }
    
    int getQuantidade(){
        return quantidade;
    }

    // Preço
    void setPreco(float Preco){
        Preco < 0 ? preco = 0 : preco = Preco;
    }
    
    float getPreco(){
        return preco;
    }

    // valor total do cupom
    float calculaCupom(){
        return preco*quantidade;
    }

private:
    string id, descricao;
    int quantidade;
    float preco;
};

int main() {
    Cupom cupom("C0", "Produtos", 5, 8.50f);

    cout << "Valor do cupom: " << cupom.calculaCupom() << endl;

    cupom.setQuantidade(0);
    cupom.setPreco(2);

    cupom.setId("Falso");
    cupom.setDescricao("Ja usado");

    cout << "Valor do cupom: " << cupom.calculaCupom() << ", Situacao: " << cupom.getDescricao() << endl;



    return 0;
}