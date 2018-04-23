#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <string>
#include <fstream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <sstream>



using namespace std;

class Imagem{

protected:

  string nomeArquivo;
  string tipo;
  string comentario;
  vector<string> conteudos;
  int localSMS;
  int tamanhoSMS;
  int dadoCriptografia;
  string mensagem;
  int posicaoComentario;
  int tamanhoColuna;
  int tamanhoLinha;
  char ***matriz;

public:
  //Construtor e destrutor
  Imagem();
  ~Imagem();

  //Métodos acessores
    void setNomeArquivo(string nomeArquivo);
    string getNomeArquivo();
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

 void setTamanhoColuna(int tamanhoColuna);
 int getTamanhoColuna();
 void setTamanhoLinha(int tamanhoLinha);
 int getTamanhoLinha();



  //Outros Métodos
  void lerImagem();
  ifstream imagem;
  void pegarDadosCriptografia();
  void pegarMensagem();
  void transformarImagemEmMatriz();

  //virtual void pegarTerceiroDado()=0;
};
#endif
