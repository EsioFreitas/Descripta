#ifndef PGM_HPP
#define PGM_HPP

#include "imagem.hpp"
#include <string>
#include <fstream>
#include <stdlib.h>

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
