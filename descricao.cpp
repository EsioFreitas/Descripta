#include <iostream>
#include "descricao.hpp"
#include <string>

using namespace std;

Descricao::Descricao(){

}
Descricao::~Descricao(){

}
void Descricao::imprimirEntrada(){
  cout<<"Bem-vindo ao programa para editar imagens .ppm ou .gpm\n\n";
}
void Descricao::imprimirOpcoes(){
  cout<<"Escolha uma opição:\n\n";
  cout<<"A) Ler uma imagem\n";
  cout<<"B) Renomenar e salvar uma nova imagem\n";
  cout<<"C) Transformar uma imagem .ppm para .pgm\n";
  std::cout << "Opção: ";
}
