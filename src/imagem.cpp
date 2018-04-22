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
  char nomeArquivo[100];

  //Pegando o arquivo pelo path
  cout << "Nome do arquivo: "; cin>>nomeArquivo;
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
  int contador1 = 0;
  int contador2 = 0;
  int primeiraPosicao = 0;
  int segundaPosicao = 1;

  //Salvando os conteúdos nas variáveis
  setTipo(conteudos[primeiraPosicao]);
  setComentario(conteudos[segundaPosicao]);

  //Pegando os dados do comentario e separando em suas respectivas variáveis
  for(contador1; strlen(comentario.c_str()) && !isspace(comentario[contador1]); contador1++)
  comentario[primeiraPosicao] = ' ';
  setLocalSMS(atoi(comentario.c_str()));

  for(contador1++; strlen(comentario.c_str()) && !isspace(comentario[contador1]); contador1++){
    comentario[contador2] = comentario[contador1];
    comentario[contador2+segundaPosicao] = '\0';
    contador2++;
  }
  setTamanhoSMS(atoi(comentario.c_str()));

  //Salvando a ultima posição do i para poder pegar o 3° dado
  setPosicaoComentario(contador1);
  }

//Jogando o conteúdo da imagem é uma variável
void Imagem::pegarMensagem(){

    int contador = localSMS;
    int regra = localSMS + tamanhoSMS;
    int linhaDoConteudo =4;

    for (contador; contador<regra; contador++){

     this->mensagem += conteudos[linhaDoConteudo][contador];
    }
    cout << "A sua mensagem: " << getMensagem() << '\n';
  }

//Método para ser sobrescrito nas classes Ppm e Pgm
void pegarTerceiroDado(){

  }
