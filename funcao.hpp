#ifndef FUNCAO_HPP
#define FUNCAO_HPP

#include <string>
#include <fstream>

using namespace std;

class Funcao {
private:
  char opcao;
  string linha;
  string arquivo;
  ifstream foto;

public:
  Funcao();
  ~Funcao();
  void lerImagem();
  void renomearImagem();
  void ppmParaPgm();
  void escolherOpcao();
  void setOpcao(char opcao);
  char getOpcao();

};

#endif
