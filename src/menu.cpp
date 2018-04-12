#include <iostream>
#include "menu.hpp"
#include <stdlib.h>

using namespace std;

Menu::Menu(){

}
Menu::~Menu(){

}

void Menu::setOpcao(int opcao){
  this->opcao=opcao;
}
int Menu::getOpcao(){
  std::cout << this->opcao << '\n';
  return this->opcao;
}

void Menu::apresentarMenu(){

    cout<<"Bem ao programa para descriptografar uma mensagem em uma imagem!\n";
    cout<<"Que tipo de arquivo você quer descriptografar?\n";
    cout<<"1) Imagem .ppm\n";
    cout<<"2) Imagem .pgm\n";

    for(1;1;1){
      cin>>this->opcao;
      system("cls");
      system("clear");

      switch(opcao){
        case 1:
          break;
        case 2:
          break;
        default:
        cout<<"Não existe essa opção! Tente novamente!\n";
        cout<<"Que tipo de arquivo você quer descriptografar?\n";
        cout<<"1) Imagem .ppm\n";
        cout<<"2) Imagem .pgm\n";
        break;

      }
    }
}
