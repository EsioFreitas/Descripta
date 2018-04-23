#include "imagem.hpp"
#include "ppm.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "pgm.hpp"
#include <bits/stdc++.h>


using namespace std;

char opcao =1;

int main(int argc, char const *argv[]) {



  while(opcao != 0){
    system("clear || cls");
    cout<<"Bem vindo ao programa que descriptografar uma mensagem em uma imagem!\n";
    cout<<"Que tipo de arquivo você quer descriptografar?\n";
    cout<<"1) Descriptografar uma imagem .ppm\n";
    cout<<"2) Descriptografar uma imagem .pgm\n";
    cout<<"0) Sair do programa\n";

    std::cout << "Sua opção: "; cin>>opcao;

    if(opcao == '1'){
      system("clear || cls");
      Ppm *ppm = new Ppm();
      ppm->lerImagem();
      //ppm->pegarDados();

      break;
    } else if(opcao == '2'){
      system("clear || cls");
      Pgm *pgm = new Pgm();
      pgm->lerImagem();
      pgm->pegarDadosCriptografia();
      pgm->transformarImagemEmMatriz();
      pgm->pegarMensagem();
      //pgm->pegarMensagem();
      pgm->cifraDeCesar();


      std::cout << "Muito obrigado!" << '\n';
      delete pgm;

      break;
    } else if (opcao == '0'){
      system("clear || cls");
      std::cout << "\n\nMuito obrigado pela preferência." << '\n';

      break;
    } else
    system("clear || cls");
    cout << "\nVERIIFIQUE A OPÇÃO ESCOLHIDA!\n" << '\n';
  }



  return 0;
}
