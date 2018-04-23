#include <string>
#include <bits/stdc++.h>
#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <sstream>


using namespace std;

//Construtores e destrutores
Imagem::Imagem(){

}
Imagem::~Imagem(){

}

//Métodos acessores
void Imagem::setPosicaoComentario(int posicaoComentario){
  this->posicaoComentario = posicaoComentario;
}
int Imagem::getPosicaoComentario(){
  return this->posicaoComentario;
}
void Imagem::setDadoCriptografia(int dadoCriptografia){
  this->dadoCriptografia = dadoCriptografia;
}
int Imagem::getDadoCriptografia(){
  return this->dadoCriptografia;
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
void Imagem::setLocalSMS(int localSMS){
  this->localSMS = localSMS;
}
int Imagem::getLocalSMS(){
  return this->localSMS;
}
void Imagem::setTamanhoSMS(int tamanhoSMS){
  this->tamanhoSMS = tamanhoSMS;
}
int Imagem::getTamanhoSMS(){
  return this->tamanhoSMS;
}
void Imagem::setMensagem(string mensagem){
  this->mensagem = mensagem;
}
string Imagem::getMensagem(){
  return this->mensagem;
}
void Imagem::setNomeArquivo(string nomeArquivo){
  this->nomeArquivo = nomeArquivo;
}
string Imagem::getNomeArquivo(){
  return this->nomeArquivo.c_str();
}
void Imagem::setTamanhoColuna(int tamanhoColuna){
  this->tamanhoColuna = tamanhoColuna;
}
int Imagem::getTamanhoColuna(){
  return this->tamanhoColuna;
}
void Imagem::setTamanhoLinha(int tamanhoLinha){
  this->tamanhoLinha = tamanhoLinha;
}
int Imagem::getTamanhoLinha(){
  return this->tamanhoLinha;
}





//Outros métodos

//Ler a imagem
void Imagem::lerImagem(){

  string linha;
  string abrirArquivo;
  string tipo;
  string descarte;
	int tamanhoColuna;
  int tamanhoLinha;

  //Pegando o arquivo pelo path
  cout << "Nome do arquivo: "; cin>> abrirArquivo;

  imagem.open(abrirArquivo.c_str());


  //Validando o arquivo e pegando os dados da imagem
  if(imagem.is_open()){

    getline(imagem,tipo);
    getline(imagem, descarte);

    imagem>>tamanhoColuna>>tamanhoLinha;

    //Pegando os dados
    setTamanhoLinha(tamanhoLinha);
    setTamanhoColuna(tamanhoColuna);
    setTipo(tipo);
    setNomeArquivo(abrirArquivo);
    imagem.close();

  } else {
    cout<<"Não foi possível encontrar o arquivo.\nMuito obrigado!";
    imagem.clear();
  }
}
