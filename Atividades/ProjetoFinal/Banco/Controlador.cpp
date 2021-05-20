#include ".\Controlador.h"

void Controlador::getData(list <Data<Conta*>> *lConta, list <PessoaFisica> *vPessoaF, list<PessoaJuridica> *vPessoaJ, ifstream &contas){
    int tc, tp;
    while(contas >> tc >> tp){
      
        //Controler Pessoa
        if(tp==1){
          PessoaFisica pessoa;
          contas >> pessoa;
          vPessoaF->push_back(pessoa);
        } else {
          PessoaJuridica pessoa;
          contas >> pessoa;
          vPessoaJ->push_back(pessoa);
        }

        //Controler Conta
        Data<Conta*> *d = new Data<Conta*>;

        if(tc==0){
          ContaCorrenteComun *conta = new ContaCorrenteComun;
          contas >> d->index >> d->status, contas >> *conta;
          conta->setTipoPessoa(tp);
          conta->setPessoa(tp == 1 ? 
          dynamic_cast<Pessoa*>(&vPessoaF->back()) : dynamic_cast<Pessoa*>(&vPessoaJ->back()));
          Conta *c = conta;
          d->conta = c;
        }
        if(tc==1){
          ContaCorrenteLimite *conta = new ContaCorrenteLimite;
          contas >> d->index >> d->status, contas >> *conta;
          conta->setTipoPessoa(tp);
          conta->setPessoa(tp == 1 ? 
          dynamic_cast<Pessoa*>(&vPessoaF->back()) : dynamic_cast<Pessoa*>(&vPessoaJ->back()));
          Conta *c = conta;
          d->conta = c;
        }
        if(tc==2){
          ContaPoupanca *conta = new ContaPoupanca;
          contas >> d->index >> d->status, contas >> *conta;
          conta->setTipoPessoa(tp);
          conta->setPessoa(tp == 1 ? 
          dynamic_cast<Pessoa*>(&vPessoaF->back()) : dynamic_cast<Pessoa*>(&vPessoaJ->back()));
          Conta *c = conta;
          d->conta = c;
        }

        d->tipoConta = tc;


        lConta->push_back(*d);
    }

    return;
}

void Controlador::setData(list <Data<Conta*>> &c, ofstream &contas){
    for(auto &item:c){
        contas  << item.tipoConta << " " << item.conta->getTipoPessoa() << endl; //Tipo de conta e tipo de pessoa

        //Pessoa
        if(item.conta->getTipoPessoa() == 1){
          PessoaFisica *pessoa = dynamic_cast<PessoaFisica*>(item.conta->getPessoa());
          contas << *pessoa << endl;
        }
        if(item.conta->getTipoPessoa() == 2){
          PessoaJuridica *pessoa = dynamic_cast<PessoaJuridica*>(item.conta->getPessoa());
          contas << *pessoa << endl;
        }
        
        // Conta
        contas << item.index << " " << item.status << " ";
        if(item.tipoConta == 0){
          ContaCorrenteComun *conta = dynamic_cast<ContaCorrenteComun *>(item.conta);
          contas << *conta;
        }
        if(item.tipoConta == 1){
          ContaCorrenteLimite *conta = dynamic_cast<ContaCorrenteLimite *>(item.conta);
          contas << *conta;
        }
        if(item.tipoConta == 2){
          ContaPoupanca *conta = dynamic_cast<ContaPoupanca *>(item.conta);
          contas << *conta;
        }
    }

    return;
}