#include <iostream>
#include "descricao.hpp"
#include "funcao.hpp"


using namespace std;

int main(int argc, char const *argv[]) {

  Descricao *descricao = new Descricao();
  Funcao *funcao = new Funcao();

  descricao->imprimirEntrada();
  descricao->imprimirOpcoes();

  char opcao;
  cin>>opcao;

  switch (opcao) {
    case 'a':
      funcao->lerImagem();
      break;

    case 'b':
      funcao->renomearImagem();
      break;

    case 'c':
      funcao->ppmParaPgm();
      break;

    default:
      cout << "\nescolha não existe! Tente novamente!\nByee!\n";
      break;

  return 0;
}
}
