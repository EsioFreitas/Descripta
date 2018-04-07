#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "menu.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  Imagem *imagem = new Imagem();
  Menu *menu = new Menu();

  menu->apresentarMenu();
  menu->getOpcao();

  if(menu->opcao == 1){

  }else if (menu->opcao == 2){
    
  }

  return 0;
}
