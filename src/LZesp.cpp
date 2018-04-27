#include "LZesp.hh"
#include <iostream>


std::ostream& operator <<(std::ostream& Strim, LZespolona Skl1)
{
  Strim << '(' << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos;
	return Strim;
}

std::istream& operator >>(std::istream  &Strim,LZespolona &Skl1)
{
  char znak;

  Strim >> znak;
  if(Strim.fail())
    return Strim;
  if(znak != '(')
  {
    Strim.setstate(std::ios::failbit);
    return Strim;
  }
  Strim >> Skl1.re;
  if(Strim.fail())
    return Strim;
  
  Strim >> Skl1.im;
  if(Strim.fail())
    return Strim;

  Strim >> znak;
  if(Strim.fail())
    return Strim;
  if(znak != 'i')
  {
    Strim.setstate(std::ios::failbit);
    return Strim;
  }

  Strim >> znak;  
  if(Strim.fail())
    return Strim;
  if(znak != ')')
  {
    Strim.setstate(std::ios::failbit);
    return Strim;
  }
  
  return Strim;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2.re - Skl1.im*Skl2.im;
  Wynik.im = Skl1.re*Skl2.im + Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  double  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  int  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re*Skl2;
  Wynik.im = Skl1.im*Skl2;
  return Wynik;
}


LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  pomocnicza_LZ = Skl1*Sprzezenie(Skl2);
  double pomocnicza_double = Modul_kwadrat(Skl2);
  LZespolona  Wynik = pomocnicza_LZ/pomocnicza_double;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  double Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

void Wyswietl(LZespolona Skl1)
{
  std::cout << '(' << Skl1.re << std::showpos << Skl1.im << "i)" << std::noshowpos;
}

LZespolona Sprzezenie(LZespolona Skl1)
{
  LZespolona pomocnicza;
  pomocnicza.re = Skl1.re;
  pomocnicza.im = -Skl1.im;
  return pomocnicza;
}

double Modul_kwadrat(LZespolona Skl1)
{
  double pomocnicza;
  pomocnicza = Skl1.re*Skl1.re + Skl1.im*Skl1.im;
  return pomocnicza;  
}
