#include <iostream>
#include "descricao.hpp"
#include "funcao.hpp"


using namespace std;

int main(int argc, char const *argv[]) {

  Descricao *descricao = new Descricao();

  descricao->imprimirEntrada();
  descricao->imprimirOpcoes();


  return 0;
}
