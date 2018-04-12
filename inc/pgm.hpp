#ifndef PGM_HPP
#define PGM_HPP

class Pgm : public Imagem{

private:
  int pixel;

public:
  Pgm();
  ~Pgm();

  void setPixel(int pixel);
  int getPixel();
};

#endif
