#include "Gerente.h"

void Gerente::abrir(vector<string> &info, int tp, int tc, float limite, string data){
    this->gerarNumConta();
    if(tp==1){
        PessoaFisica p(info[0], info[1], info[2], info[3], info[4], info[5], tp);
        this->banco.cadastrar(std::to_string(this->numConta), &p, 0.0, tp, tc, limite, data);
    } else {
        PessoaJuridica p(info[0], info[1], info[2], info[3], info[4], info[5], tp);
        this->banco.cadastrar(std::to_string(this->numConta), &p, 0.0, tp, tc, limite, data);
    }
    cout << "Numero da conta: " << this->numConta << endl;
    this->numConta++;
    return;
}

void Gerente::fechar(string num){
    this->banco.remover(num);
    return;
}

void Gerente::consultar(string numConta){
    try{
        this->banco.consultar(numConta);
    } catch(runtime_error &e){
        cout << e.what() << endl;
    }
    return;
}

void Gerente::atualizar(string numConta, string info, int tipo){
   Data<Conta*> *d;
   try{
       d = this->banco.buscar(numConta);
   } catch(runtime_error &e){
       cout << "Conta não encontrada." << endl;
   }
   // Endereço
   if(tipo==1){
       d->conta->getPessoa()->setEndereco(info);
   }
   //Email
   if(tipo==2){
       d->conta->getPessoa()->setEmail(info);
   }
   //Estado Civil
   if(tipo==3){
       dynamic_cast<PessoaFisica*>(d->conta->getPessoa())->setEC(info);
   }
   //Limite
   if(tipo==4){
       if(d->tipoConta!=1){
          cout << "A conta informada não é do tipo ContaCorrenteLimite." << endl;
       } else {
            dynamic_cast<ContaCorrenteLimite*>(d->conta)->setLimite(std::stof(info));
       }
   }
    return ;
}

void Gerente::gerarNumConta(){
    static int i = 1;
    int num = (this->numConta*3.14+1.75)/7*17;
    num = num > 10000 ? i++ : num;
    this->numConta = static_cast<int>(num*3.14+1.75)*4545;
}