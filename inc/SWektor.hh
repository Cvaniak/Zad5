#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>
#include "LZesp.hh"
#include <math.h>



template <typename STyp, int SWymiar>
class SWektor {
    STyp  swektor[SWymiar];
  public: 
  static int ilosc_wszystkich;
  static int ilosc_zyjacych;
  SWektor()
  {
    for(int i=0; i<SWymiar; i++)
      swektor[i] = 0;
    ilosc_wszystkich++;
    ilosc_zyjacych++;
  }
  SWektor(STyp Tablica[])
  {
    for(int i=0; i<SWymiar; i++)
      swektor[i] = Tablica[i];
    ilosc_wszystkich++;
    ilosc_zyjacych++;
  }
  SWektor(STyp x, STyp y)
  {
    swektor[0]=x;
    swektor[1]=y;
    ilosc_wszystkich++;
    ilosc_zyjacych++;
  }
  SWektor(STyp x, STyp y, STyp z)
  {
    swektor[0]=x;
    swektor[1]=y;
    swektor[2]=z;
    ilosc_wszystkich++;
    ilosc_zyjacych++;
    }
  ~SWektor()
  {
    //std::cout << "I DIE " ;
    ilosc_zyjacych--;
  }
  SWektor(const SWektor<double, 2> &W)
  {
    for(int i=0; i<SWymiar; i++)
      swektor[i] = W[i];
    //std::cout << "I DIE " ;
    ilosc_zyjacych++;
    ilosc_wszystkich++;
  }
  
  STyp  operator [] (unsigned int x) const
  {
    return swektor[x];
  }

  STyp &operator [] (unsigned int x)
  {
    return swektor[x];
  }


  SWektor<STyp,SWymiar> operator +  (const SWektor<STyp,SWymiar> &Swektor) const;
  SWektor<STyp,SWymiar> operator -  (const SWektor<STyp,SWymiar> &Swektor) const;
  SWektor<STyp,SWymiar> operator *  (double &Double)                       const;
  STyp                  operator *  (SWektor<STyp,SWymiar> &Swektor)       const;
  bool                  operator %  (SWektor<STyp,SWymiar> &Swektor)       const;
  bool                  operator == (SWektor<STyp,SWymiar> &Swektor)       const;
  bool                  operator != (SWektor<STyp,SWymiar> &Swektor)       const;
  SWektor<STyp,SWymiar> operator /  (double &Double)                       const;
  double                Kat         (SWektor<STyp,SWymiar> W);
  double                Dlugosc     ();
  void                  Obrot       (double a);
};




template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Swektor) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (int i = 0; i < SWymiar; i++)
    Wynik[i] = (*this)[i] + Swektor[i];
  
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Swektor) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (int i = 0; i < SWymiar; i++)
    Wynik[i] = (*this)[i] - Swektor[i];
  
  return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double &Double) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (int i = 0; i < SWymiar; i++)
    Wynik[i] = (*this)[i]*Double;
  
  return Wynik;
}


template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (SWektor<STyp,SWymiar> &Swektor) const
{
  STyp  Wynik = 0;

  for (int i = 0; i < SWymiar; i++)
    Wynik = Wynik + (*this)[i]*Swektor[i];
  
  return Wynik;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator % (SWektor<STyp,SWymiar> &Swektor) const
{
  STyp k = (*this)[0]/Swektor[0];
  
  for (int i = 1; i < SWymiar; i++)
    if ((k-0.001 < (*this)[i]/Swektor[i]) && (k+0.001 > (*this)[i]/Swektor[i])) return 0;
//k != (*this)[i]/Swektor[i] || 
  return 1;
}

template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator == (SWektor<STyp,SWymiar> &Swektor) const
{ 
  for (int i = 0; i < SWymiar; i++)
    if ((*this)[i] != Swektor[i]) return 0;
  //k != (*this)[i]/Swektor[i] || 
  return 1;
}


template <typename STyp, int SWymiar>
bool SWektor<STyp,SWymiar>::operator != (SWektor<STyp,SWymiar> &Swektor) const
{ 
  for (int i = 0; i < SWymiar; i++)
    if ((*this)[i] != Swektor[i]) return 1;
  //k != (*this)[i]/Swektor[i] || 
  return 0;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator / (double &Double) const
{
  SWektor<STyp,SWymiar>  Wynik;

  for (int i = 0; i < SWymiar; i++)
    Wynik[i] = (*this)[i]/Double;
  
  return Wynik;
}


template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &Strm, const SWektor<STyp,SWymiar>& W)
{
  for (int i = 0; i < SWymiar; i++)
    {
    Strm << " " << W[i];
  }  
  return Strm;
}


template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &Strm, SWektor<STyp,SWymiar>& W)
{
  for (int i = 0; i < SWymiar; i++)
    {
      Strm >> W[i];
    }  
  return Strm;
}

template <typename STyp, int SWymiar>
double SWektor<STyp,SWymiar>::Dlugosc()
{
  double wynik = 0;

  for(int i=0; i<SWymiar; i++)
    wynik = wynik + (*this)[i]*(*this)[i];
  
  //std::cout <<  wynik << " " << std::endl;  
  wynik = sqrt(wynik);

  return wynik;
}

template <typename STyp, int SWymiar>
double SWektor<STyp,SWymiar>::Kat(SWektor<STyp,SWymiar> W)
{
  double wynik  = 0;
  double wynik1 = 0;
  double wynik2 = 0;
  double wynik3 = 0;
  wynik1 = (*this)*W;
  wynik2 = (*this).Dlugosc()*W.Dlugosc();
  wynik3 = wynik1 / wynik2;
  //if (abs) 
  wynik = (acos(wynik3)-M_PI/2) * 180.0 / M_PI;
  std::cout << wynik << std::endl;
  //(*this).Dlugosc() << " " << W.Dlugosc() << " " << wynik1 << " " << wynik2 << " " <<
  
  if(W[1] < 0)
    {
      if(wynik < 0)
	wynik = -180 - wynik;
      else
	wynik = 180 - wynik;
    }
    return wynik;
}

template <typename STyp, int SWymiar>
void SWektor<STyp,SWymiar>::Obrot(double a)
{
  
  double x = (*this)[0];
  double y = (*this)[1];
  double b  = a * M_PI / 180.0;
      
  (*this)[0] = x*cos(b) - y*sin(b);
  (*this)[1] = (x*sin(b) + y*cos(b));
  
}

#endif
