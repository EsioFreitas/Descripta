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
int Imagem::getLocalSMS(){
  return this->localSMS;
}
int Imagem::getTamanhoSMS(){
  return this->tamanhoSMS;
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
  int i=0;
  int j=0;

  this->tipo = conteudos[0];
  this->comentario = conteudos[1];

  for(i; strlen(comentario.c_str()) && !isspace(comentario[i]); i++)
  comentario[0] = ' ';

  this->localSMS = atoi(comentario.c_str());
  std::cout << localSMS << '\n';

  for(i++; strlen(comentario.c_str()) && !isspace(comentario[i]); i++){
    comentario[j] = comentario[i];
    comentario[j+1] = '\0';
    j++;
  }

  this->tamanhoSMS = atoi(comentario.c_str());
  std::cout << tamanhoSMS << '\n';

}

void Imagem::pegarMensagem(){

int i = localSMS;
int regra = localSMS + tamanhoSMS;

   for (i; i<regra;i++){

     this->mensagem += conteudos[4][i];
   }
   std::cout << this->mensagem << '\n';

}


void Imagem::cifra(){

  //tem que pegar a chave!!!  && ver exeções
  int tamanhoTexto = strlen(this->mensagem.c_str());
  char texto[tamanhoTexto];

  for(int i=0; i<tamanhoTexto;i++){
    texto[i] = mensagem[i];
    texto[i+1] = '\0';
  }

  std::cout << tamanhoTexto << '\n';
  std::cout << texto << '\n';

  int i=0;
  int contador = 0;
  char letra;

  for(letra = 'a'; letra <= 'z'; letra++){
    while (i<=tamanhoTexto) {
      if(texto[i] == letra){
        texto[i] = letra-8;
        i++;
        contador++;
        letra='a';
      }
      else if (texto[i] == ' '|| texto[i] == '-'||texto[i] =='.'){
        i++;
        contador++;
        letra='a';
      }
      else if(texto[i] == toupper(letra)){
        texto[i] = toupper(letra-8);
        i++;
        contador++;
        letra='a';
      }
      else if( texto[i]<=96){
        int temporario;
        //std::cout << texto[i] << '\n';
        temporario = 96 - texto[i];
        texto[i] = 122;
        texto[i] -=temporario;
      //  std::cout << texto[i] << '\n';

      }
     else
        letra++;
        if(contador == tamanhoTexto)
          break;

    }
  }
  std::cout << texto << '\n';

}
