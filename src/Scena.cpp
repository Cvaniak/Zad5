#include "Scena.hh"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "SWektor.hh"
#include "Wektor2D.hh"
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Robot.hh"
#include <string>
#include <cstring>
#include <time.h>
#include <unistd.h>


using namespace std;

int Scena::Run()
{
  Wektor2D Z(100,-100);
  
  nowyRobot(IloscRobotow++);
  Lacze.Rysuj();
  while(true)
    {
      Menu();      
    }
  return 0;
}

int Scena::nowyRobot(int x)
{
  Robot R(x);
  Lacze.DodajNazwePliku(R.name.c_str(),PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku(R.Sciesz.name.c_str(),PzG::RR_Ciagly,2);
  if (!R.ZapiszDoPliku(R.name.c_str())) return 1;
  if (!R.Sciesz.ZapiszDoPliku(R.Sciesz.name.c_str())) return 1;
  Roboty.push_back(R);
  
  return 0;
}

void Update()
{
  
}


void Scena::Menu()
{
  char Znak;
  
  cout << endl <<  "Obecna ilosc zyjacych wektorow to  "  << Wektor2D::ilosc_zyjacych << " z " << Wektor2D::ilosc_wszystkich << endl;
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
  //cin >> noskipws >> Znak;
  cin >> Znak;
  if (Znak == 'n')
    {
      nowyRobot(IloscRobotow++);
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
    }
  
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
  
}
