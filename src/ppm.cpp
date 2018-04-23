#include "imagem.hpp"
#include"ppm.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

//Construtor e destrutor
Ppm::Ppm(){

}
Ppm::~Ppm(){

}

void Ppm::setKeyword(string keyword){
  this->keyword = keyword;
}
string Ppm::getKeyword(){
  return this->keyword;
}

//Outros métodos
//Copiando os dados da imagem para as variáveis
void Ppm::pegarDadosCriptografia(){
  int localSMS;
  int tamanhoSMS;
  string keyword;
	string descarte;

	ifstream imagem(nomeArquivo.c_str());

  //Descartar linhas iniciais
	getline(imagem, descarte);
	getline(imagem, descarte);
	descarte.erase(0, 1);

	istringstream iss(descarte);
	iss >> localSMS >> tamanhoSMS >> keyword;

  setLocalSMS(localSMS);
  setTamanhoSMS(tamanhoSMS);
  setKeyword(keyword);

	imagem.close();
  }

//Salvando a imagem em uma matriz para poder pegar a mensagem
void Ppm::transformarImagemEmMatriz(){

  ifstream imagem(this->nomeArquivo.c_str());

  matriz3D = new unsigned char **[getTamanhoLinha()];
	for (int i = 0; i < getTamanhoLinha(); i++){
		matriz3D[i] = new unsigned char *[getTamanhoColuna()];
		for (int j = 0; j < getTamanhoColuna(); j++){
			matriz3D[i][j] = new unsigned char[3];
		}
	}

  string descarte;

    for (int i = 0; i < 4; i++)
		  getline(imagem, descarte);

  for (int i = 0; i < getTamanhoLinha(); i++){
		for (int j = 0; j < getTamanhoColuna(); j++){
			char letra;
			imagem.get(letra);
      matriz3D[i][j][0] = (char)letra;
      imagem.get(letra);
      matriz3D[i][j][1] = (char)letra;
      imagem.get(letra);
      matriz3D[i][j][2] = (char)letra;
		}
	}
	imagem.close();
}


//Jogando o conteúdo da imagem é uma variável
void Ppm::pegarMensagem(){
  int contador = 0;
  string mensagem;
  int regra = getLocalSMS() + getTamanhoSMS()*3;
  int soma = 0;
  int temporario = 0;

	for (int i = 0; i < getTamanhoLinha(); i++){
		for (int j = 0; j < getTamanhoColuna(); j++){
			for (int k = 0; k < 3; k++){
				if (contador >= getLocalSMS() && contador < regra){
					soma +=  ((int) matriz3D[i][j][k] % 10);
					temporario++;
				}
				if (contador >= getLocalSMS() && contador < regra && temporario == 3){
					mensagem += (char) soma + 'a' - 1;
					soma = 0;
					temporario = 0;
				}

				contador++;
			}
		}
	}

  setMensagem(mensagem);
  std::cout << getMensagem() << '\n';
}
