#ifndef FUNCAO_HPP
#define FUNCAO_HPP

class Funcao {
private:
  char opcao;

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
