#include "imagem.hpp"
#include"ppm.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

//Construtor e destrutor:
Ppm::Ppm(){

}
Ppm::~Ppm(){

}

//Métodos acessores:
void Ppm::setKeyword(string keyword){
  this->keyword = keyword;
}
string Ppm::getKeyword(){
  return this->keyword;
}
void Ppm::setAlfabetoCriptografado(string alfabetoCriptografado){
  this->alfabetoCriptografado = alfabetoCriptografado;
}
string Ppm::getAlfabetoCriptografado(){
  return this->alfabetoCriptografado;
}


//Outros métodos:
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
  string nomeArq = getNomeArquivo();

  ifstream imagem(nomeArq.c_str());

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
  cout<< "Sua mensagem: " << getMensagem()<< '\n';

}

//Criar um alfabeco com a keyword
void Ppm::criarAlfabeto(){
  string alfabetoCodificado;
	bool validador = true;
	unsigned int i, j;
  string chave = getKeyword();

	for (i = 0; i < chave.size(); i++){
		for (j = 0; j < alfabetoCodificado.size(); j++){
			if (chave[i] == alfabetoCodificado[i]){
				validador = false;
			}
		}

		if (validador){
			if (chave[i] >= 'a' && chave[i] <= 'z')
				alfabetoCodificado += chave[i] - 32;
			else
				alfabetoCodificado += chave[i];
		}
		validador = true;
	}
  for (i = 0; i < 26; i++){
		for (j = 0; j < alfabetoCodificado.size(); j++){
			if (alfabetoCodificado[j] == ('A' + (int)i)){
				validador = false;
			}
		}

		if (validador){
			alfabetoCodificado += ('A' + i);
		}
		validador = true;
	}
  setAlfabetoCriptografado(alfabetoCodificado);
}

//Descriptografar a mensagem
void Ppm::keywordChipher(){
    int regra1 = getAlfabetoCriptografado().size();
    int regra2 = getMensagem().size();

    map <char,int> enc;
    for(int i=0; i<regra1; i++)
    {
        enc[alfabetoCriptografado[i]]=i;
    }

    string mensagemDescriptografada;
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i=0; i<regra2; i++)
    {
        if (mensagem[i] >='a' && mensagem[i] <='z')
        {
            int pos = enc[mensagem[i]-32];
            mensagemDescriptografada += alfabeto[pos];
        }
        else if(mensagem[i] >='A' && mensagem[i] <='Z')
        {
            int pos = enc[mensagem[i]];
            mensagemDescriptografada += alfabeto[pos];
        }
        else if(mensagem[i] == '`'){
          mensagem[i] = ' ';
          mensagemDescriptografada += mensagem[i];
        }
        else
        {
            mensagemDescriptografada += mensagem[i];
        }

    }
    setMensagem(mensagemDescriptografada);
    cout <<"A sua mensagem descriptografada: " <<getMensagem() << '\n';


}
