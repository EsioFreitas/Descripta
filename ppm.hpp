#ifndef PPM_HPP
#define PPM_HPP

class Ppm : public Imagem{

private:
  int red;
  int green;
  int blue;

public:
  void setRed(int red);
  int getRed();
  void setGreen(int red);
  int getGreen();
  void setBlue(int red);
  int getBlue();

};

#endif
