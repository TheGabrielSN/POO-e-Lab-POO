#include <iostream>
using std::cin, std::cout, std::endl, std::left, std::right, std::defaultfloat;

#include <string>
using std::string;

#include <fstream>
using std::fstream;

#include <iomanip>
using std::fixed, std::setw, std::setprecision;;

struct{
    int nRegistro;
    char nome[20];
    int quantidade;
    double preço;
    bool status;
} typedef data;

data dados[]={
        {0,"Lixadeira", 7, 57.98,true},
        {1,"Martelo", 76, 11.99,true},
        {2,"Serra_tico-tico", 21, 11.00,true},
        {3,"Cortador_de_grama", 3, 79.50,true},
        {4,"Serra_eletrica", 18, 99.99,true},
        {5,"Chave_de fenda", 106, 6.99,true},
        {6,"Marreta", 11, 21.50,true},
        {7,"Chave_inglesa", 34, 7.50,true},
};

int tData;

bool salvar_dados(data d[], int n, fstream &f){
    f.seekp(0);  
    for (int i = 0 ; i < n ; i++)
        f.write(reinterpret_cast<char *>(&d[i]),sizeof(d[i]));
    f.flush();

    tData = n-1;

    return true;
}


int atualizar_num_registro(fstream &f){
    data *d = new data;
    int reg = 0;

    f.clear();
    f.seekg(0);
    while (true){
        f.read(reinterpret_cast<char *> (&(*d)),sizeof(data));
        if (f.eof()){break;}
        reg++;
    }

    return reg;
}

void listar(fstream &f){  
    data *d = new data;

    cout << " N do registro " << "  Nome da ferramenta  " << " Quantidade " << " Preco (R$) " << endl;
    cout << fixed;
    f.clear();
    f.seekg(0);
    while (true){
        f.read(reinterpret_cast<char *> (&(*d)),sizeof(data));
        if (f.eof()) {break;}

        if (!d->status) {continue;}
        cout.width(10);
        cout << setw(8) << d->nRegistro << ' ' 
             << setw(26) << d->nome << ' ' 
             << setw(10) << d->quantidade << ' ' 
             << setw(10) << setprecision(2) << d->preço
             << endl;
    }
    cout << defaultfloat;
}

bool adicionar(fstream &f, data &d){
    data *ant = new data;
    bool controler = false;
    f.clear();
    f.seekg(0);
    while (true){
        f.read(reinterpret_cast<char *> (&(*ant)),sizeof(data));
        if (f.eof()) {
            f.clear();
            f.seekg((tData-1) * sizeof(data));
            break;
        }
        if (!ant->status) {
            controler = true;
            f.clear();
            f.seekg((ant->nRegistro) * sizeof(data));
            break;
        }
    }

    d.nRegistro = !controler ? (tData) : ant->nRegistro;
    d.status = true;

    f.seekg(!controler ? ((tData) * sizeof(data)): ((ant->nRegistro) * sizeof(data)));
    
    f.write(reinterpret_cast<char *> (&d),sizeof(data));

    f.flush();
    
    if(!controler){ tData++; }

    return true;
}

bool atualizar(fstream &f, data &d){
    f.clear();
    f.seekp(d.nRegistro * sizeof(data));
    
    f.write(reinterpret_cast<char *> (&d),sizeof(data));

    f.flush();
    return true;
}

bool remover(fstream &f, int registro){
    data *d = new data;

    f.clear();
    f.seekg(registro * sizeof(data));

    f.read(reinterpret_cast<char *> (&(*d)),sizeof(data));
    
    d->status = false;

    f.seekp(registro * sizeof(data));
    
    f.write(reinterpret_cast<char *> (&(*d)),sizeof(data));

    f.flush();
    return true;
}

bool validar(int reg){
    return (reg > -1 && reg < tData);
}

int main() {
    fstream fileIO("hardware.dat", std::ios::out | std::ios::in);

    /* if (!fileIO){
        fileIO.open("hardware.dat", std::ios::out);
    }
    salvar_dados(dados, 8, fileIO); */

    if (!fileIO){ return 1; }

    tData = atualizar_num_registro(fileIO);

    /* fileIO.close(); */
    while (1){
        cout << "-------------------------------------" << endl;
        cout << "Lojinha da esquina." << endl;
        cout << "Opcoes:" << endl;
        cout << "0 - Listar as ferramentas" << endl;
        cout << "1 - Cadastrar nova ferramenta" << endl;
        cout << "2 - Alterar dados da ferramenta" << endl;
        cout << "3 - Remover ferramenta" << endl;
        cout << endl << "-1 - Sair" << endl;
        int op;
        cin >> op;
        
        switch (op){
            case 0:{
                listar(fileIO);
                break;
            }
            case 1:{
                if(tData < 101){
                    data d;
                    cout << "Nome: ";
                    cin >> d.nome;
                    cout << endl << "Quantidade: ";
                    cin >> d.quantidade;
                    cout << endl << "Preco: ";
                    cin >> d.preço;
                    cout << endl;
                    adicionar(fileIO, d);
                    break;
                } else {
                    cout << "Limite de registro cadastrado atingido." << endl;
                }
            }
            case 2:{
                int reg;
                cout << "Número de registro da ferramenta: ";
                cin >> reg;
                if (validar(reg)){
                    data d;
                    d.nRegistro = reg;
                    d.status = true;
                    cout << "Nome: ";
                    cin >> d.nome;
                    cout << endl << "Quantidade: ";
                    cin >> d.quantidade;
                    cout << endl << "Preco: ";
                    cin >> d.preço;
                    cout << endl;
                    atualizar(fileIO, d);
                }
                break;
            }
            case 3:{
                int reg;
                cout << "Número de registro da ferramenta: ";
                cin >> reg;
                if (validar(reg)){
                    remover(fileIO, reg);
                }
                break;
            }
            case -1:{
                fileIO.close();
                exit(0);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}