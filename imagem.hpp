#ifndef IMAGEM_HPP
#define IMAGEM_HPP

#include <string>
#include <fstream>

using namespace std;

class Imagem{
protected:
  int altura;
  int largura;
  string tipo;
  string comentario;

public:
  ifstream imagem;
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

  //Outros métodos
  void lerImagem();
  bool saberTipo();
};
#endif
