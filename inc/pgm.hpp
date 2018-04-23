#ifndef PGM_HPP
#define PGM_HPP

#include "imagem.hpp"
#include <string>
#include <fstream>
#include <stdlib.h>

class Pgm : public Imagem {

public:
  Pgm();
  ~Pgm();
  void cifraDeCesar();

};

#endif
