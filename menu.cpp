#include <iostream>
#include "menu.hpp"
#include <stdlib.h>

using namespace std;

int Menu::apresentarMenu(){

    cout<<"Bem ao programa para descriptografar uma mensagem em uma imagem!\n";
    cout<<"Que tipo de arquivo você quer descriptografar?\n";
    cout<<"1) Imagem .ppm\n";
    cout<<"2) Imagem .pgm\n";

    int opcao;

    for(1;1;1){
      cin>>opcao;
      system("cls");
      system("clear");

      switch(opcao){
        case 1:
          cout<<"nada";
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
    return opcao;
}
