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
  unsigned char ***matriz3D;

public:
  //Construtor e destrutor
  Imagem();
  virtual ~Imagem();

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
  ifstream imagem;
  void lerImagem();
  virtual void pegarDadosCriptografia()=0;
  virtual void pegarMensagem() = 0;
  virtual void transformarImagemEmMatriz()=0;
};
#endif
