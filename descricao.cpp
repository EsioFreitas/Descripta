#include <iostream>
#include "descricao.hpp"

using namespace std;

Descricao::Descricao(){

}
Descricao::~Descricao(){

}
Descricao::imprimirEntrada(){
  cout<<"Bem-vindo ao programa para editar imagens .ppm ou .gpm\n"
}
Descricao::imprimirOpcoes(){
  cout<<"Escolha uma opição:\n"
  cout<<"A) Ler uma imagem\n"
  cout<<"B) Renomer uma imagem\n"
  cout<<"C) Mudar a cor da imagem\n"
}
