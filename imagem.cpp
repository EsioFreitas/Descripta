#include <string>
#include "imagem.hpp"

using namespace std;

Imagem::Imagem(string tipo, int altura, int largura){
  this->tipo = tipo;
  this->altura = altura;
  this->largura = largura;
}
Imagem::~Imagem(){

}
void Imagem::setAltura(int altura){
  this->altura = altura;
}
int Imagem::getAltura(){
  return this->altura;
}
void Imagem::setLargura(int largura){
  this->largura = largura;
}
int Imagem::getLargura(){
return this->altura;
}
void Imagem::setTipo(string tipo){
  this->tipo = tipo;
}
string Imagem::getTipo(){
  return this->tipo;
}
void Imagem::setComentario(string comentario){
  this->comentario = comentario;
}
string Imagem::getComentario(){
  return this->comentario;
}
