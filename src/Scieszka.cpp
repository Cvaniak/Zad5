#include "Scieszka.hh"
#include <iostream>
#include <string>
#include <cstring>

int Scieszka::InicjalizujKsztalt(Wektor2D& W)
{
  _TabWierz.push_back(W);
  if (!this->ZapiszDoPliku(name.c_str())) return 1;
  return 0;
}

void Scieszka::InicjalizujKsztalt()
{
  //_TabWierz.push_back(W);
}

void Scieszka::Inicjalizuj(int x)
{
  std::string a = "figury/";
  std::string b = "scieszka";
  std::string c = std::to_string(x);
  std::string d = ".dat";
  name = a + b + c + d;
  
}

int Scieszka::dodaj(Wektor2D& W)
{
  int Size = _TabWierz.size();
  if(Size > 2)
    {
      Wektor2D b = _TabWierz[Size - 1];
      Wektor2D a = _TabWierz[Size - 2];

      if(a%b == a%W)
	_TabWierz.pop_back();
      
    }
  _TabWierz.push_back(W);
  
  if (!this->ZapiszDoPliku(name.c_str())) return 1;
  return 0;
}

std::string Scieszka::tell()
{
  return name;
}
