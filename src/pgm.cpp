#include <string>
#include <bits/stdc++.h>
#include "pgm.hpp"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

//Construtor e destrutor
Pgm::Pgm(){
}
Pgm::~Pgm(){

}

//Outros métodos



//Copiando os dados da imagem para as variáveis
void Pgm::pegarDadosCriptografia(){
  int localSMS;
  int tamanhoSMS;
  int dadoCriptografia;
	string descarte;

	ifstream imagem(nomeArquivo.c_str());

  //Descartar linhas iniciais
	getline(imagem, descarte);
	getline(imagem, descarte);
	descarte.erase(0, 1);

	istringstream iss(descarte);
	iss >> localSMS >> tamanhoSMS >> dadoCriptografia;

  setLocalSMS(localSMS);
  setTamanhoSMS(tamanhoSMS);
  setDadoCriptografia(dadoCriptografia);

	imagem.close();
  }

//Salvando a imagem em uma matriz para poder pegar a mensagem
void Pgm::transformarImagemEmMatriz(){

  ifstream imagem(this->nomeArquivo.c_str());

  matriz = new char **[getTamanhoLinha()];
	for (int i = 0; i < getTamanhoLinha(); i++){
		matriz[i] = new char *[getTamanhoColuna()];
		for (int j = 0; j < getTamanhoColuna(); j++){
			matriz[i][j] = new char[1];
		}
	}

  string descarte;

    for (int i = 0; i < 4; i++)
		  getline(imagem, descarte);

  for (int i = 0; i < getTamanhoLinha(); i++){
		for (int j = 0; j < getTamanhoColuna(); j++){
			char letra;
			imagem.get(letra);
      matriz[i][j][0] = letra;
		}
	}
	imagem.close();
}


//Jogando o conteúdo da imagem é uma variável
void Pgm::pegarMensagem(){
  int contador = 0;
  string mensagem;
  int regra = getLocalSMS() + getTamanhoSMS();

  for (int i = 0; i < getTamanhoLinha(); i++){
    for (int j = 0; j < getTamanhoColuna(); j++){
      if (contador >= getLocalSMS() && contador < regra)
        mensagem += matriz[i][j][0];
        contador++;
      }
    }
    setMensagem(mensagem);
  }

//A cifra de Cesar
void Pgm::ceasarChipher(){

  //Jogando os dados em variáveis locai
  int deslocamento = getDadoCriptografia();
  int tamanhoTexto = strlen(this->mensagem.c_str());
  char texto[tamanhoTexto];

  for(int i=0; i<tamanhoTexto;i++){
    texto[i] = mensagem[i];
    texto[i+1] = '\0';
  }
  std::cout<< "Sua mensagem: " << texto<< '\n';

  int i=0;
  int contador = 0;
  char letra;

  //A cifra
  for(letra = 'a'; letra <= 'z'; letra++){
    while (i<=tamanhoTexto) {
      if(texto[i] == letra){
        texto[i] = letra-deslocamento;

        if(texto[i] <=96){
          int temporario;
          temporario = 96 - texto[i];
          texto[i] = 'z';
          texto[i] -=temporario;
        }
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
        texto[i] = toupper(letra-deslocamento);
        i++;
        contador++;
        letra='a';
      }
     else
        letra++;
        if(contador == tamanhoTexto)
          break;
    }
  }

    cout<<"A sua mensagem descriptografada: "; std::cout << texto << '\n';
}
