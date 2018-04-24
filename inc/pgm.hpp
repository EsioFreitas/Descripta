#ifndef PGM_HPP
#define PGM_HPP

#include "imagem.hpp"

class Pgm : public Imagem {

private:
  char ***matriz;

public:
  Pgm();
  ~Pgm();
  void pegarDadosCriptografia();
  void pegarMensagem();
  void transformarImagemEmMatriz();
  void ceasarChipher();


};

#endif
