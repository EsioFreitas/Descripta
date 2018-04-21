#include <string>
#include <bits/stdc++.h>
#include "imagem.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>


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


//Outros métodos

//Ler a imagem
void Imagem::lerImagem(){

  string linha;
  //Pegando o arquivo pelo path
  std::cout << "Nome do arquivo: ";cin>>this->nomeArquivo;
  imagem.open(nomeArquivo, ifstream::binary);

  //Jovando o arquivo em um vector
  if(imagem.is_open()){
    while (getline(imagem,linha)){
      conteudos.push_back(linha);
    }
    //Apagando imagem
    imagem.clear();

  }
  else{
    cout<<"Não foi possível encontrar o arquivo.\nMuito obrigado!";
    imagem.clear();
    }

  }

//Jogando os dadados da imagem em variáveis
void Imagem::pegarDados(){
  int i=0;
  int j=0;

  //Salvando os conteúdos nas variáveis
  this->tipo = conteudos[0];
  this->comentario = conteudos[1];

  //Pegando os dados do comentario e separando em suas respectivas variáveis
  for(i; strlen(comentario.c_str()) && !isspace(comentario[i]); i++)
  comentario[0] = ' ';
  this->localSMS = atoi(comentario.c_str());

  for(i++; strlen(comentario.c_str()) && !isspace(comentario[i]); i++){
    comentario[j] = comentario[i];
    comentario[j+1] = '\0';
    j++;
  }
  this->tamanhoSMS = atoi(comentario.c_str());

  //Salvando a ultima posição do i para poder pegar o 3° dado
  this->posicaoComentario = i;
  }

//Jogando o conteúdo da imagem é uma variável
void Imagem::pegarMensagem(){
    int i = localSMS;
    int regra = localSMS + tamanhoSMS;
    for (i; i<regra;i++){

     this->mensagem += conteudos[4][i];
    }
    std::cout << "A sua mensagem: " << this->mensagem << '\n';
  }

  void pegarTerceiroDado(){

  }
