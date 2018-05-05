#include "Scena.hh"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SWektor.hh"
#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include "Przeszkoda.hh"
#include <string>
#include <cstring>
#include <time.h>
#include <unistd.h>


using namespace std;

int Scena::Run()
{
  Wektor2D Z(100,-100);
  
  nowyRobot(IloscRobotow++, {0, 0});
  Lacze.Rysuj();
  Menu();
  cout << "sss" << endl;
  while(true)
    {
      for(Robot &R : Roboty)
	{
	  R.Animuj();
	  cout << R.kat << endl;
    	  
	}
      Lacze.Rysuj();
      usleep(65000);
      cout << "www" << endl;
    }
  return 0;
}

int Scena::nowyRobot(int x, Wektor2D W)
{
  Robot R(x, W);
  Lacze.DodajNazwePliku(R.name.c_str(),PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku(R.Sciesz.name.c_str(),PzG::RR_Ciagly,2);
  if (!R.ZapiszDoPliku(R.name.c_str())) return 1;
  if (!R.Sciesz.ZapiszDoPliku(R.Sciesz.name.c_str())) return 1;
  Roboty.push_back(R);
  
  return 0;
}

int Scena::nowaPrzeszkoda(int x, Wektor2D LG, Wektor2D PD)
{
  Przeszkoda P(x, LG, PD);
  Lacze.DodajNazwePliku(P.name.c_str(),PzG::RR_Ciagly,2);
  if (!P.ZapiszDoPliku(P.name.c_str())) return 1;
  Przeszkody.push_back(P);
  
  return 0;
}

void Update()
{
  
}


void Scena::Menu()
{
  char Znak;
  
  cout << endl <<  "Ver 1 Obecna ilosc zyjacych wektorow to  "  << Wektor2D::ilosc_zyjacych << " z " << Wektor2D::ilosc_wszystkich << endl;
  cout << "Co chesz zrobic?" << endl;
  cout << "n - nowy robot" << endl;
  cout << "z - przesun do" << endl;
  cout << "o - obrot o" << endl;
  cout << "n - nowy robot" << endl;
  cout << "m - do przodu wzgledem katu" << endl;
  cout << "a - animacja o obrot i ruch do przodu" << endl;
  cout << "s - skaluj do rozmiaru " << endl;
  cout << "c - zmien skoki " << endl;
  cout << "f - zmien szybkosc animacji " << endl;
  cout << "p - nowa przeszkoda " << endl;
  cout << "l - anim " << endl;
  //cin >> noskipws >> Znak;
  cin >> Znak;
  if (Znak == 'n')
    {
      Wektor2D W;
      cout << "Podaj Wspolrzedne" << endl;
      cin >> W;
      nowyRobot(IloscRobotow++, W);
      Lacze.Rysuj();
    }
  if (Znak == 'z')
    {
      int k;
      cout << "Podaj numer robota" << endl;
      cin >> k;
      cout << "Podaj x i y" << endl;
      cin >> NowePolozenie;
      Roboty[k].Move(NowePolozenie);
      Roboty[k].Update(Lacze);
      Lacze.Rysuj();
    }
  if (Znak == 'o')
    {
      double k, r;
      cout << "Podaj numer robota" << endl;
      cin >> k;
      cout << "Podaj kat" << endl;
      cin >> r;
      Roboty[k].Obrot(r);
      Roboty[k].Update(Lacze);
    }
  if (Znak == 'm')
    {
      double k, m;
      cout << "Podaj numer robota" << endl;
      cin >> k;
      cout << "Podaj odleglosc" << endl;
      cin >> m;
      Roboty[k].Move(m);
      Roboty[k].Update(Lacze);
    }
  /*
  if (Znak == 'a')
    {
      double j, k, m;
      cout << "Podaj numer robota" << endl;
      cin >> j;
      cout << "Podaj kat" << endl;
      cin >> k;
      cout << "Podaj odleglosc" << endl;
      cin >> m;
      Roboty[j].Animuj(k, m, Lacze);
    }*/
  
  if (Znak == 's')
    {
      double j, s;
      cout << "Podaj numer robota" << endl;
      cin >> j;
      cout << "Podaj nowy rozmiar X.Y" << endl;
      cin >> s;
      Roboty[j].Skaluj(s);
      Roboty[j].Update(Lacze);
    }
  if (Znak == 'f')
    {
      double j, f;
      cout << "Podaj numer robota" << endl;
      cin >> j;
      cout << "Podaj czas miedzy skokami w mikro sekundach" << endl;
      cin >> f;
      Roboty[j].speed = f;
    }
  if (Znak == 'c')
    {
      double j, a, b;
      cout << "Podaj numer robota" << endl;
      cin >> j;
      cout << "Podaj skok katu" << endl;
      cin >> a;
      cout << "Podaj skok ruchu" << endl;
      cin >> b;
      Roboty[j].krok_kat = a;
      Roboty[j].krok_move = b;
      }
  // cin >> NowePolozenie;
  
  if (Znak == 'p')
    {
      Wektor2D LG, PD;
      
      cout << "LG: " << endl;
      cin >> LG;
      cout << "PD: " << endl;
      cin >> PD;
 
      nowaPrzeszkoda(IloscPrzeszkod++, LG, PD);
      Lacze.Rysuj();      
    }
  
    if (Znak == 'l')
    {
      double i = 0;
      double a;
      Wektor2D b;
      
      cout << "LG: " << endl;
      cin >> a;
      cout << "PD: " << endl;
      cin >> b;

      Roboty[i].katDocelowy = a;
      
      Roboty[i].polozenieDocelowe = b;
      
    }
}
