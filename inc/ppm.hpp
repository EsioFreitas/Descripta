#ifndef PPM_HPP
#define PPM_HPP

#include "imagem.hpp"
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Ppm : public Imagem {

private:
  int tamanhoReal;
public:
  Ppm();
  ~Ppm();
  void pegarTerceiroDado();

};

#endif
