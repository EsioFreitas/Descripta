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

  string linha;


  cin>>this->nomeArquivo;
  imagem.open(nomeArquivo, ifstream::binary);

  if(imagem.is_open()){
    while (getline(imagem,linha)){
      conteudos.push_back(linha);
    }

    //cout << conteudos[4][13000] << endl;
    //imprimido a sms
    //for(int i = 13000; i < 13050; i++){
    //  cout << conteudos[4][i];
  //  }

    // for(int i = 4; i < conteudos.size(); i++){
    //   cout << conteudos[i] << endl;
    // }
    imagem.clear();
  }
  else{
    cout<<"Não foi possível encontrar o arquivo.\n";
    imagem.clear();
    }

}

void Imagem::pegarDados(){
  this->tipo = conteudos[0];
  this->comentario = conteudos[1];

  for(int i = 1; strlen(comentario.c_str()) && !isspace(comentario[i]); i++)
  comentario[0] = ' ';

  tamanhoSMS = atoi(comentario.c_str());
  std::cout << tamanhoSMS << '\n';




}
