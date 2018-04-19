#ifndef PPM_HPP
#define PPM_HPP

#include "imagem.hpp"
#include <string>
#include <fstream>
#include <stdlib.h>

class Ppm : public Imagem {

private:
  int red;
  int green;
  int blue;

public:
  Ppm();
  ~Ppm();

  void setRed(int red);
  int getRed();
  void setGreen(int red);
  int getGreen();
  void setBlue(int red);
  int getBlue();

};

#endif
