#include "imagem.hpp"
#include"ppm.hpp"
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

//Construtor e destrutor
Ppm::Ppm(){

}
Ppm::~Ppm(){

}

//Outros métodos
void Ppm::pegarDados(){
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
  std::cout << tamanhoSMS << '\n';
  this->tamanhoReal = tamanhoSMS*3;
  std::cout << tamanhoReal << '\n';

 
  //Salvando a ultima posição do i para poder pegar a 3° SMS
  this->posicaoComentario = i;
}
