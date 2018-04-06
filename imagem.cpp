#include <string>
#include "imagem.hpp"
#include <fstream>


using namespace std;

//Construtores e destrutores
Imagem::Imagem(){

}
Imagem::~Imagem(){

}

//Métodos acessores
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

//Outros métodos
void Imagem::lerImagem(){
  char nomeArquivo[100];
  cin>>nomeArquivo;
  ifstream imagem;
  imagem.open(nomeArquivo);

  if(!imagem.is_open()){
    cout<<"Não foi possível encontrar o arquivo.\n";
    imagem.clear();
  }
}
