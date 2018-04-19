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
int Imagem::getLocalSMS(){
  return this->localSMS;
}
int Imagem::getTamanhoSMS(){
  return this->tamanhoSMS;
}


//Outros métodos
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

    imagem.clear();

  }
  else{
    cout<<"Não foi possível encontrar o arquivo.\nMuito obrigado!";
    imagem.clear();
    }

}
void Imagem::pegarDados(){
  int i=0;
  int j=0;

  this->tipo = conteudos[0];
  this->comentario = conteudos[1];

  //Pegando os dados do comentario e separando em variáveis
  for(i; strlen(comentario.c_str()) && !isspace(comentario[i]); i++)
  comentario[0] = ' ';

  this->localSMS = atoi(comentario.c_str());

  for(i++; strlen(comentario.c_str()) && !isspace(comentario[i]); i++){
    comentario[j] = comentario[i];
    comentario[j+1] = '\0';
    j++;

  }
  this->tamanhoSMS = atoi(comentario.c_str());

  //Salvando a ultima posição do i para poder pegar a 3° SMS
  this->posicaoComentario = i;
}
void Imagem::pegarMensagem(){
  int i = localSMS;
  int regra = localSMS + tamanhoSMS;
   for (i; i<regra;i++){

     this->mensagem += conteudos[4][i];
   }
   std::cout << "A sua mensagem: "; std::cout << this->mensagem << '\n';

}
