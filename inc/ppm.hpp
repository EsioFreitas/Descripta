#ifndef PPM_HPP
#define PPM_HPP

#include "imagem.hpp"

using namespace std;

class Ppm : public Imagem {

private:
  string keyword;
  string alfabetoCriptografado;
  unsigned char ***matriz3D;
public:
  Ppm();
  ~Ppm();

//Médodos acessores:
  void setKeyword(string keyword);
  string getKeyword();
  void setAlfabetoCriptografado(string alfabetoCriptografado);
  string getAlfabetoCriptografado();

//Outros métodos
  void pegarDadosCriptografia();
  void pegarMensagem();
  void transformarImagemEmMatriz();
  void keywordChipher();
  void criarAlfabeto();

};

#endif
