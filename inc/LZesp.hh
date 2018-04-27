#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>


struct  LZespolona
{
  double   re;    
  double   im;

  LZespolona& operator=(const double& Skl2)
  {
  this->re = Skl2;
  this->im = 0;
  
  return *this;
  }
  
  LZespolona& operator=(const LZespolona& Skl2)
  {
  this->re = Skl2.re;
  this->im = Skl2.im;
  
  return *this;
  }
};


std::ostream& operator <<(std::ostream& Strim, LZespolona Skl1);

std::istream& operator >>(std::istream& Strim, LZespolona &Skl1);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  double  Skl2);

LZespolona  operator * (LZespolona  Skl1,  int  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  double  Skl2);

void Wyswietl(LZespolona Skl1); //to samo co << 

LZespolona Sprzezenie(LZespolona);

double Modul_kwadrat(LZespolona);


#endif
