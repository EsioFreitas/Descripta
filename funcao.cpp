#include <iostream>
#include "funcao.hpp"
#include <string>

using namespace std;

Funcao::Funcao(){

}

void Funcao::lerImagem(){


}
void Funcao::renomearImagem(){

}
void Funcao::ppmParaPgm(){

}

void Funcao::escolherOpcao(){

  switch (opcao) {
    case 'a':
      lerImagem();
      break;

    case 'b':
      renomearImagem();
      cout<<"oooi";
      break;

    case 'c':
      ppmParaPgm();
      break;

    default:
      cout << "\nEssa escolha não existe! Tente novamente!\nByee!\n";
      break;
    }
}
void Funcao::setOpcao(char opcao){
  this->opcao=opcao;
}

char Funcao::getOpcao(){
  cin>>opcao;
  return this->opcao;
}
