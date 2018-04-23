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

  string tipo="";
  string descarte= "";
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

//Jogando os dadados da imagem em variáveis
void Imagem::pegarDadosCriptografia(){
  int localSMS;
  int tamanhoSMS;
  int dadoCriptografia;
	string descarte;

	ifstream imagem(nomeArquivo.c_str());

	getline(imagem, descarte); // despreza a primeira linha do arquivo
	getline(imagem, descarte);

	descarte.erase(0, 1); // apaga a sinalização de comentário (#)
	istringstream iss(descarte);
	iss >> localSMS >> tamanhoSMS >> dadoCriptografia;

  setLocalSMS(localSMS);
  setTamanhoSMS(tamanhoSMS);
  setDadoCriptografia(dadoCriptografia);

  std::cout <<  getLocalSMS()<< '\n';
  std::cout <<  getTamanhoSMS()<< '\n';

  std::cout <<  getDadoCriptografia()<< '\n';



	imagem.close();
  }


void Imagem::transformarImagemEmMatriz(){

  ifstream imagem(this->nomeArquivo.c_str());

  matriz = new char **[getTamanhoLinha()];
	for (int i = 0; i < getTamanhoLinha(); i++){
		matriz[i] = new char *[getTamanhoColuna()];
		for (int j = 0; j < getTamanhoColuna(); j++){
			matriz[i][j] = new char[1];
		}
	}

  std::cout << matriz << '\n';
  std::cout << nomeArquivo << '\n';
  string aux = " ";

    for (int i = 0; i < 4; i++)
		  getline(imagem, aux);


  for (int i = 0; i < getTamanhoLinha(); i++){
		for (int j = 0; j < getTamanhoColuna(); j++){
			char letra;
			imagem.get(letra);
      matriz[i][j][0] = letra;
		}
	}
  std::cout << matriz << '\n';
	imagem.close();

}


//Jogando o conteúdo da imagem é uma variável
void Imagem::pegarMensagem(){


  int contador = 0;
  string mensagem = "";
  int regra = localSMS + tamanhoSMS;

  for (int i = 0; i < getTamanhoLinha(); i++){
    for (int j = 0; j < getTamanhoColuna(); j++){
      if (contador >= getLocalSMS() && contador < regra)
        mensagem += matriz[i][j][0];
        contador++;
      }
    }

    setMensagem(mensagem);
    std::cout << getMensagem() <<"eeee"<< '\n';
  }

//Método para ser sobrescrito nas classes Ppm e Pgm
void pegarTerceiroDado(){

  }
