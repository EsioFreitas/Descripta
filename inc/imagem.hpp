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
  void setAltura(int altura);
  int getAltura();
  void setLargura(int largura);
  int getLargura();
  void setTipo(string tipo);
  string getTipo();
  void setComentario(string comentario);
  string getComentario();
  void setLocalSMS(int localSMS);
  int getLocalSMS();
  int getTamanhoSMS();

  //Outros Métodos
  void lerImagem();
  ifstream imagem;
  void pegarDados();
  void pegarMensagem();
  virtual void pegarTerceiroDado() = 0;



};
#endif
