#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "menu.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  Imagem *imagem = new Imagem();
  Menu *menu = new Menu();

  imagem->lerImagem();


  return 0;
}
