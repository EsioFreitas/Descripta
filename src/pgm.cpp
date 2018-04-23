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


//A cifra de Cesar

void Pgm::cifraDeCesar(){

  //Jogando os dados em variáveis locai
  int deslocamento = getDadoCriptografia();
  int tamanhoTexto = strlen(this->mensagem.c_str());
  char texto[tamanhoTexto];

  std::cout << deslocamento << '\n';
  std::cout << tamanhoTexto << '\n';

  for(int i=0; i<tamanhoTexto;i++){
    texto[i] = mensagem[i];
    texto[i+1] = '\0';
  }
  std::cout << texto << '\n';

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


/*void Pgm::cifraDeCesar(){
  string mensagemDecodificada = "";

	for (int i= 0; i < (int) getMensagem().length(); i++){
		char letraResultante = mensagem[i], letraPadrao = 'a';

		if (isupper(mensagem[i]))
			letraPadrao = 'A';
		// há interesse apenas em aplicar a cifra em letras
		if (isalpha(mensagem[i]))
			// pega-se o resto da divisão por 26 devido a ciclicidade dos valores possíveis
			letraResultante = ((mensagem[i] - dadoCriptografia - letraPadrao + 26) % 26) + letraPadrao;

		mensagemDecodificada += letraResultante;
	}

	string texto= mensagemDecodificada;

  std::cout << texto << '\n';

}*/
