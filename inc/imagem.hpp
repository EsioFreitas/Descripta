#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <string>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>



using namespace std;

class Imagem{
protected:
  string tipo;
  string comentario;
  char nomeArquivo[100];
  vector<string> conteudos;
  int localSMS;
  int tamanhoSMS;
  int dadoCriptografia;
  string mensagem;
  int posicaoComentario;

public:
  //Construtor e destrutor
  Imagem();
  ~Imagem();

  //Métodos acessores
    void setPosicaoComentario(int posicaoComentario);
    int getPosicaoComentario();
    void setDadoCriptografia(int dadoCriptografia);
    int getDadoCriptografia();
    void setTipo(string tipo);
    string getTipo();
    void setComentario(string comentario);
    string getComentario();
    void setLocalSMS(int localSMS);
    int getLocalSMS();
    void setTamanhoSMS(int tamanhoSMS);
    int getTamanhoSMS();
    void setMensagem(string mensagem);
    string getMensagem();


  //Outros Métodos
  void lerImagem();
  ifstream imagem;
  void pegarDados();
  void pegarMensagem();
};
#endif
