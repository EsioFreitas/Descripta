#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  Imagem *imagem = new Imagem();
  imagem->saberTipo();
  imagem->lerImagem();


  return 0;
}
