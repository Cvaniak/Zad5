
#include "Robot.hh"
#include "Scieszka.hh"
#include "lacze_do_gnuplota.hh"

#include <iostream>
#include <string>
#include <math.h>
#include <unistd.h>


void Robot::Inicjalizuj()
{
  Sciesz.InicjalizujKsztalt(_PolozenieObiektu);

  InicjalizujKsztalt();
  
}

void Robot::InicjalizujKsztalt()
{
  promien = 20*sqrt(2);
  _TabWierz_wzorzec.push_back({ 0 ,  45});
  _TabWierz_wzorzec.push_back({ 0 ,  0 });
  _TabWierz_wzorzec.push_back({ 0 ,  20});
  _TabWierz_wzorzec.push_back({ 20,  20});
  _TabWierz_wzorzec.push_back({ 20, -20});
  _TabWierz_wzorzec.push_back({-20, -20});
  _TabWierz_wzorzec.push_back({-20,  20});
  _TabWierz_wzorzec.push_back({  0,  20});
  _TabWierz = _TabWierz_wzorzec;
  
  /* _TabWierz[1][0] =  30;  _TabWierz[1][1]=   0;
  _TabWierz[2][0] =   0;  _TabWierz[2][1]= -30;
  _TabWierz[3][0] = -30;  _TabWierz[3][1]= -30;
  _TabWierz[4][0] = -30;  _TabWierz[4][1]=  30;
  _TabWierz[5][0] =   0;  _TabWierz[5][1]=  30;
  _TabWierz[6][0] =  30;  _TabWierz[6][1]=   0;*/
}

/*!
 *  Zmiania współrzędne położenia punktu, względem którego tworzony
 *  jest obrys obiektu.
 *  \param[in] x - współrzędna x-owa nowego położenia.
 *  \param[in] y - współrzędna y-owa nowego położenia.
 */
void Robot::ZmienPolozenie(double x, double y)
{
  _PolozenieObiektu[0] = x;
  _PolozenieObiektu[1] = y;
  Sciesz.dodaj(_PolozenieObiektu);
}

void Robot::ZmienPolozenie(Wektor2D W)
{
  _PolozenieObiektu = W;
  Sciesz.dodaj(_PolozenieObiektu);
}

void Robot::Obrot()
{
  _TabWierz = _TabWierz_wzorzec;
  for (Wektor2D& W_lok : _TabWierz)
    {
      W_lok.Obrot(kat);
    }
  
} 


void Robot::Obrot(double a)
{
  _TabWierz = _TabWierz_wzorzec;
  kat = kat+a;
  for (Wektor2D& W_lok : _TabWierz)
    {
      W_lok.Obrot(kat);
      //std::cout << a << " " << W_lok[0] << "  " << W_lok[1] << std::endl;
    }
  
} 


void Robot::Obrot(Wektor2D W)
{
  double a = (*this).KatObrotu(W);
  //    std::cout << a << " "  << std::endl;
  (*this).Obrot(a);

} 


double Robot::KatObrotu(Wektor2D W)
{
  Wektor2D Zero(1, 0);
  Wektor2D pom(0, 0);
  double a = 0;
  pom = W-_PolozenieObiektu;
  a = Zero.Kat(pom);
  ///std::cout << "kat " << a << std::endl;
 
  return a;
}

Wektor2D Robot::KrokRuchu()
{

  Wektor2D W(0,1);
  W.Obrot(kat);
  return W;
}


Wektor2D Robot::KrokRuchu(double danyKat)
{

  Wektor2D W(0,1);
  W.Obrot(danyKat);
  return W;
}


void Robot::Move()
{
  ZmienPolozenie(_PolozenieObiektu);
}

void Robot::Move(double a)
{
  ZmienPolozenie(KrokRuchu()*a);
}

void Robot::Move(Wektor2D W)
{
  //std::cout << W << std::endl;
  (*this).Obrot(W);
  (*this).ZmienPolozenie(W);
  Update();
}
void Robot::Move(Wektor2D W, PzG::LaczeDoGNUPlota L)
{
  Move(W);
  Update(L);
  L.Rysuj();
}

void Robot::Update()
{
  (*this).ZapiszDoPliku((*this).name.c_str());
  (*this).Sciesz.ZapiszDoPliku((*this).Sciesz.name.c_str());
}

void Robot::Update( PzG::LaczeDoGNUPlota L)
{
  Update();
  L.Rysuj();
}

bool Robot::Animuj()
{
  
  std::cout << std::endl << katDocelowy << std::endl <<  polozenieDocelowe << std::endl ;
  if( kat >= 360)
    kat -= 360;
  if( kat <= 0 )
    kat += 360;
  if(kat != katDocelowy)
    {
      if((abs(katDocelowy - kat) < krok_kat) || (abs(katDocelowy - kat) > 360 - krok_kat))
	{
	  kat = katDocelowy;
	}
      else
	{
	  int znak = 1;
	  if((katDocelowy - kat)<0)
	    znak = -znak;
	  if(abs(katDocelowy - kat)>180)
	    znak = -znak;
	  kat = kat + znak*krok_kat;
	}
      Obrot();
      Update();
      return 1;
    }
  else if((_PolozenieObiektu[0] != polozenieDocelowe[0])||
	(_PolozenieObiektu[1] != polozenieDocelowe[1]))
    {
      std::cout << "a" << std::endl;
      if((abs(polozenieDocelowe[0]- _PolozenieObiektu[0])>abs(KrokRuchu()[0]))||
	 (abs(polozenieDocelowe[1]- _PolozenieObiektu[1])>abs(KrokRuchu()[1])))
	{
	  std::cout << "c" << std::endl;
	  _PolozenieObiektu = _PolozenieObiektu + KrokRuchu();
	}
      else
	{
	  
	  std::cout << "b" << std::endl;
	  _PolozenieObiektu = polozenieDocelowe;
	}
      Move();
      Update();
      return 1;
    }
  else
    return 0;
}
/*
void Robot::Animuj(double nowyKat, double nowePolozenie, PzG::LaczeDoGNUPlota L)
{
  double katDocelowy = nowyKat + kat;
  
  while(kat != katDocelowy)
    {
      if(abs(katDocelowy - kat - krok_kat) > abs(katDocelowy - kat ))
	kat = katDocelowy;
      else
	kat = kat + krok_kat;
      Obrot();
      Update(L);
      usleep(speed);
    }

  Wektor2D polozenieDocelowe;
  polozenieDocelowe = _PolozenieObiektu + KrokRuchu()*nowePolozenie; 
  
  while((_PolozenieObiektu[0] != polozenieDocelowe[0])||
	(_PolozenieObiektu[1] != polozenieDocelowe[1]))
    {
      if((abs(polozenieDocelowe[0]- _PolozenieObiektu[0])>abs(KrokRuchu()[0]))||
	 (abs(polozenieDocelowe[1]- _PolozenieObiektu[1])>abs(KrokRuchu()[1])))
	{
	  _PolozenieObiektu = _PolozenieObiektu + KrokRuchu();
	}
      else
	{
	  _PolozenieObiektu = polozenieDocelowe;
	}
      Move();
      Update(L);
      usleep(speed);
    }
  
}
*/
void Robot::Skaluj(double s)
{
  
  for (Wektor2D& W_lok : _TabWierz_wzorzec)
    W_lok = (W_lok/rozmiar)*s;
  promien = promien/rozmiar*s;
  rozmiar = s;
  Obrot();
  
}


void Robot::UstalPolozenie(double zmianaKata, double zmianaPolozenia)
{
  //std::cout << std::endl << fmod(zmianaKata, 360.0) << std::endl;
  zmianaKata = fmod(zmianaKata, 360.0);
  if(abs(zmianaKata)>180)
    zmianaKata =  -(copysign(360, zmianaKata) - zmianaKata);
  katDocelowy = fmod((kat + zmianaKata), 360.0);
  if(katDocelowy < 0)
    katDocelowy = 360.0 + katDocelowy;
  std::cout << std::endl << katDocelowy << std::endl;
  
  polozenieDocelowe = _PolozenieObiektu + KrokRuchu(katDocelowy)*zmianaPolozenia;
  
}

void Robot::UstalPolozenie(Wektor2D punktKoncowy)
{
  
  katDocelowy = KatObrotu(punktKoncowy);
  if(katDocelowy < 0)
    katDocelowy = 360.0 + katDocelowy;
  polozenieDocelowe = punktKoncowy;
}
    

