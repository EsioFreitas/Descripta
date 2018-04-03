#include <iostream>
#include "descricao.hpp"
#include "funcao.hpp"
#include <fstream>


using namespace std;

int main(int argc, char const *argv[]) {


  Descricao *descricao = new Descricao();
  Funcao *funcao = new Funcao();

  descricao->imprimirEntrada();
  descricao->imprimirOpcoes();

  funcao->getOpcao();
  funcao->escolherOpcao();





  return 0;
}
