#include <iostream>                                     //Entrada e saída c++
using std::cin, std::cout, std::endl;
#include <iomanip>                                          //Manipulação de entrada e saída 
using std::setprecision, std::setw, std::fixed;
#include <string>                                       //Tipo string c++
using std::string;                                  
#include <vector>                                       //STL -> Lista duplamente encadeada
using std::vector;
#include <stdexcept>                                    //Biblioteca para exception
using std::exception;
#include <exception>                                    //Biblioteca para runtime_error
using std::runtime_error;
#include <Windows.h>                                    //Biblioteca de controle do windows
#include <ctime>                                        //Biblioteca time estilo c para pegar a dara do sistema
using std::time_t, std::tm;
#include ".\Banco\Banco.h"                              //Objeto Banco
#include "Correntista.h"                                //Controle do usuario/correntista
#include "Gerente.h"                                    //Controle do admin/gerente
#define sleep1 3000                                     //Tempo de espera 3 segundos
#define sleep2 10                                       //Tempo de espera 0.01 segundos
#define sleep3 10000                                    //Tempo de espera 10 segundos

int entrada(){
    int op0;
    cin >> op0;
    op0--;
    while(true){
        switch(op0){
            case 0:
            case 1:
                return op0;
            case -1:
                return 2;
            default:{
                cout << "Opção Invalida! Digite novamente: ";
                cin >> op0;
            }
        }
    }
}

int login(){
    const string senha="senha", login="login"; // Login de acesso do gerente
    cout << "Digite o login e a senha: "
         << "Digite senha como 0 e login como 0 para voltar" << endl;
    string s,l;
    while(true){
        cout << "login: ";
        cin >> l;
        cout << "senha: ";
        cin >> s;
        if(l==login && s==senha){
            system ("CLS");
            return 0;
        } else if(l=="0" && s=="0"){
            system ("CLS");
            return 1;
        } else {
            cout << "Login ou Senha invalidos!" << endl;
        }
    }
}

string dataAtual(){
    time_t t = std::time(0);
    tm *now = std::localtime(&t);
    return to_string((now->tm_mday)) + "/" + to_string((now->tm_mon + 1)) + "/" + to_string((now->tm_year + 1900));
}

string replace(string word, string target, string replacement){
    //Retirada de:
    //https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
    int len, loop=0;
    string nword="", let;
    len=word.length();
    len--;
    while(loop<=len){
        let=word.substr(loop, 1);
        if(let==target){
            nword=nword+replacement;
        }else{
            nword=nword+let;
        }
        loop++;
    }
    return nword;
}

int main(){
    system ("CLS");
    //Controle do códificação dos caracteres do pront de comando (CMD)
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    //Objeto de controle geral - Banco
    Banco banco("Banco dos Bancos", "Rua do Banco", "bancodosbancos@banco.com.br", "999.999.999/9999-99", "9999999999", "9999999999");
    
    while(true){
        int op0;
        cout << "Bem-vindo ao Banco dos Bancos" << endl
             << "Escolha as opções abaixo: " << endl
             << "1 - Gerente" << endl
             << "2 - Correntista" << endl
             << "0 - Sair" << endl
             << "Digite a sua opção: ";
        
        op0 = entrada();
        if(op0==2){ break; }

        system ("CLS");

        if(op0==0){
            if (login()==0){
                Gerente gerente(banco);
                while(true){
                    system ("CLS");
                    cout << "Selecione a função desejada: " << endl
                         << "1 - Abrir conta" << endl
                         << "2 - Consultar conta" << endl
                         << "3 - Atualizar conta" << endl
                         << "4 - Fechar conta" << endl
                         << "0 - Sair" << endl;
                    int op1;
                    cout << "Digite sua opção: ";
                    cin >> op1;
                    if(op1==0){break;}
                    else if(op1==1){
                        vector<string> info;
                        string temp;
                        float limite;
                        int tp, tc;
                        cout << "Preencha com os dados abaixo: " << endl;
                        cout << "0 - Voltar " << endl;
                        while(true){
                            cout << "1 - Pessoa Fisica ou 2 - Pessoa Juridica: ";
                            cin >> tp;
                            if(tp == 0) {break;} else {tp--;}
                            if(tp==0){
                                cout << "Informações Pessoais:" << endl;
                                cout << "Nome: ";
                                while(std::getline(cin, temp)){ if(temp!=""){break;}}
                                info.push_back(replace(temp, " ", "_"));
                                cout << "Endereço: ";
                                while(std::getline(cin, temp)){ if(temp!=""){break;}}
                                info.push_back(replace(temp, " ", "_"));
                                cout << "Email: ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "CPF: ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "Data de Nascimento (dd/mm/aaaa): ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "Estado Civil: ";
                                cin >> temp;
                                info.push_back(temp);
                                break;
                            } else if(tp==1){
                                cout << "Informações Pessoais:" << endl;
                                cout << "Nome: ";
                                while(std::getline(cin, temp)){ if(temp!=""){break;}}
                                info.push_back(replace(temp, " ", "_"));
                                cout << "Endereço: ";
                                while(std::getline(cin, temp)){ if(temp!=""){break;}}
                                info.push_back(replace(temp, " ", "_"));
                                cout << "Email: ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "CNPJ: ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "Inscrição Estadual: ";
                                cin >> temp;
                                info.push_back(temp);
                                cout << "Razão Social: ";
                                cin >> temp;
                                info.push_back(temp);
                                break;
                            } else {
                                cout << "Opção Invalida" << endl;
                            }
                        }
                        system ("CLS");
                        cout << "Informações de Conta: " << endl;
                        cout << "0 - Voltar" << endl;
                        cout << "1 - Conta Corrente Comum" << endl;
                        cout << "2 - Conta Corrente Com Limite" << endl;
                        cout << "3 - Conta Poupança" << endl;
                        while(true){
                            cin >> tc;
                            if(tc==0){ info.clear(); break; }
                            else if(tc==1){
                                gerente.abrir(info, tp+1, tc-1);
                                break;
                            }
                            else if(tc==2){
                                cout << "Informe o valor do limite da conta: ";
                                cin >> limite;
                                gerente.abrir(info, tp+1, tc-1, limite);
                                break;
                            }
                            else if(tc==3){
                                gerente.abrir(info, tp+1, tc-1, 0.0, dataAtual());
                                break;
                            }
                            else{
                                cout << "Opção Invalida!" << endl;
                            }
                        }
                        cout << "Conta criada com sucesso." << endl;
                        Sleep(sleep3);
                    } else if(op1== 2){
                        string num;
                        system ("CLS");
                        cout <<  "Digite 0 para voltar." << endl;
                        cout << "Informe o número da conta: ";
                        cin >> num;
                        if(num=="0"){ break; }
                        try{
                            banco.buscar(num);
                        } catch(runtime_error &e){
                            cout << e.what() << endl;
                        }
                        gerente.consultar(num);
                        Sleep(sleep3);
                    
                    } else if(op1== 3){
                        int opA;
                        string conta, info;
                        system ("CLS");
                        cout << "Digite o número da conta: ";
                        cin >> conta;
                        gerente.consultar(conta);
                        cout << "Escolha a informação a ser alterada: " << endl;
                        cout << "1 - Endereço" << endl;
                        cout << "2 - Email" << endl;
                        cout << "3 - Estado Civil" << endl;
                        cout << "4 - Limite da Conta" << endl;
                        cout << "0 - Voltar" << endl;
                        while(true){
                            cin >> opA;
                            if(opA == 0){break;}
                            else if(opA == 1){
                                cout << "Digite o novo endereço: ";
                                cin >> info;
                                info.replace(info.begin(), info.end(), " ", "_");
                                break;
                            }
                            else if(opA == 2){
                                cout << "Digite o novo e-mail: ";
                                cin >> info;
                                break;
                            }
                            else if(opA == 3){
                                cout << "Digite o novo estado civil: ";
                                cin >> info;
                                break;
                            }
                            else if(opA == 4){
                                cout << "Digite o novo limie da conta: ";
                                cin >> info;
                                break;
                            }
                            else{
                                cout << "Opção invalida!";
                                Sleep(sleep2);
                            }
                        }
                        gerente.atualizar(conta, info, opA);
                        Sleep(sleep1);
                    } else if(op1==4){
                        string conta;
                        cout << "Digite 0 para voltar." << endl;
                        cout << "Digite o número da conta: ";
                        cin >> conta;
                        try{
                            banco.buscar(conta);
                        } catch(runtime_error &e){
                            cout << e.what() << endl;
                        }
                        gerente.fechar(conta);
                        cout << "Conta fechada com sucesso" << endl;
                        Sleep(sleep1);
                    } else {
                        cout << "Opção invalida" << endl;
                        Sleep(sleep2);
                    } //else
                } //while
            } //if
        } //if

        if(op0==1){
            string num;
            cout << "Informe o número da conta: ";
            cin >> num;
            try{
                banco.buscar(num);
            } catch(runtime_error &e){
                cout << e.what() << endl;
            }
            Correntista correntista(num, banco);
            while(true){
                system ("CLS");
                int opC;
                cout << "Digite a opção desejada: " << endl
                    << "1 - Depositar" << endl
                    << "2 - Retirar" << endl
                    << "3 - Transferir" << endl
                    << "4 - Ver Saldo" << endl
                    << "5 - Extrato" << endl
                    << "0 - Voltar" << endl;
                cin >> opC;
                if(opC==0){ break; }
                system ("CLS");
                float valor;
                if(opC==1){
                    cout << "Digite 0 para voltar." << endl;
                    cout << "Digite o valor a ser depositado: ";
                    cin >> valor;
                    if(valor == 0) { break; }
                    correntista.depositar(valor);
                    cout << "Depositado com sucesso!" << endl;
                    Sleep(sleep1);
                }
                else if(opC==2){
                        cout << "Digite 0 para voltar." << endl;
                        cout << "Digite o valor a ser retirado: ";
                        cin >> valor;
                        if(valor == 0){ break; }
                        try{
                            cout << fixed;
                            cout << "Valor retirado: " << setprecision(2) << (correntista.retirar(valor)) << ", com sucesos!" << endl; 
                        } catch(exception &e){
                            cout << "Valor indisponível." << endl;
                        }
                    Sleep(sleep1);
                    }
                else if(opC==3){
                    string num;
                    cout << "Digite 0 para voltar." << endl;
                    cout << "Digite o número da conta a qual deseja transferir: ";
                    cin >> num;
                    cout << "Digite o valor a ser transferido: ";
                    cin >> valor;
                    try{
                        correntista.tranferir(valor, num);
                        cout << "Transferido com sucesso." << endl;
                    } catch(exception &e){
                        cout << "Não foi possível concluir a transferencia!" << endl;
                    }
                    Sleep(sleep1);
                }
                else if(opC==4){
                    correntista.saldo();
                    Sleep(sleep1);
                }
                else if(opC==5){
                    correntista.extrato();
                    Sleep(sleep1);
                } else {
                    cout << "Opção não disponível." << endl;
                    Sleep(sleep2);
                }//else
            } //while
        } //if
    } //while


    system ("CLS");
    cout << "Obrigado por utilizar o Banco dos Bancos!" << endl;
    cout << "Desenvolvido por:" << endl;
    cout << "\t\tGabriel da Silva Nascimento" << endl;
    cout << "\t\tBacharelado em Engenharia de Computação." << endl;
    cout << "\t\tProgramação Orientada a Objetos." << endl;

    return 0;
}