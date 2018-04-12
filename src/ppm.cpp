#include"ppm.hpp"
#include <fstream>

#include "imagem.hpp"

using namespace std;

void Ppm::setRed(int red){
  this->red = red;
}
int Ppm::getRed(){
  return this->red;
}
void Ppm::setGreen(int red){
  this->green = green;
}
int Ppm::getGreen(){
  return this->green;
}
void Ppm::setBlue(int red){
  this->blue = blue;
}
int Ppm::getBlue(){
  return blue;
}
