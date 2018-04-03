#include <iostream>
#include <string>
#include "funcao.hpp"
#include <fstream>

using namespace std;

Funcao::Funcao(){

}

void Funcao::lerImagem(){

  cin>>arquivo;
  foto.open(arquivo);

  if(foto.is_open()){
    while(getline(foto,linha)){
      cout<<linha<< endl;
    }
  } else{
    cout<< "Não foi possivel abrir o arquivo\n";
  }

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
