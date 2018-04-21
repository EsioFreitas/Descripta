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

//Método sobrescrito para pegar o 3° dado do comentário
void Pgm::pegarTerceiroDado(){

  int i = posicaoComentario;
  int k = 0;

  i++;
  comentario[k] = comentario[i];
  comentario[k+1] = '\0';
  this->dadoCriptografia = atoi(comentario.c_str());
}

//A cifra de Cesar
void Pgm::cifraDeCesar(){

  //Jogando os dados em variáveis locai
  int deslocamento = this->dadoCriptografia;
  int tamanhoTexto = strlen(this->mensagem.c_str());
  char texto[tamanhoTexto];

  for(int i=0; i<tamanhoTexto;i++){
    texto[i] = mensagem[i];
    texto[i+1] = '\0';
  }

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
