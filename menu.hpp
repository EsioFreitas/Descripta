#ifndef MENU_HPP
#define MEUNU_HPP

class Menu{
private:
  int opcao;
public:
  Menu();
  ~Menu();
  void setOpcao(int opcao);
  int getOpcao();
  void apresentarMenu();
};
#endif
