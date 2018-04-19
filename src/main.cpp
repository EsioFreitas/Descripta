#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "menu.hpp"

using namespace std;

char opcao =1;

int main(int argc, char const *argv[]) {

  Imagem *imagem = new Imagem();


  while(opcao != 0){
    cout<<"Bem vindo ao programa que descriptografar uma mensagem em uma imagem!\n";
    cout<<"Que tipo de arquivo você quer descriptografar?\n";
    cout<<"1) Descriptografar uma imagem .ppm\n";
    cout<<"2) Descriptografar uma imagem .pgm\n";
    cout<<"0) Sair do programa\n";

    std::cout << "Sua opção: "; cin>>opcao;

    if(opcao == '1'){
      system("clear || cls");

      std::cout << "1" << '\n';

      break;
    }
    else if(opcao == '2'){
      system("clear || cls");

      std::cout << "2" << '\n';
    }
    else if (opcao == '0'){
      system("clear || cls");
      std::cout << "Muito obrigado!" << '\n';

      break;
    }
    else
    system("clear || cls");
      std::cout << "\nVERIIFIQUE A OPÇÃO ESCOLHIDA!\n" << '\n';
  }


  std::cout << opcao<<"eeee" << '\n';

  /*if(menu->opcao == 1){

  }else if (menu->opcao == 2){

  }
  imagem->lerImagem();
  // imagem->imprimeDadosImagem();
  //  menu->apresentarMenu();
  imagem->pegarDados();
  imagem->pegarMensagem();

  imagem->pegarCaracteristicaDescriptogaria();

  imagem->cifra();*/


  return 0;
}
