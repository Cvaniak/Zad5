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
#include <linux/input.h>

#include <ncurses.h>


using namespace std;

int Scena::Run()
{
  Wektor2D Z(100,-100);
  
  nowyRobot(IloscRobotow++, {0, 0  });
  nowyRobot(IloscRobotow++, {100, 0});
  nowaPrzeszkoda(IloscPrzeszkod++, {-200, 200}, {200, 100});
  Lacze.Rysuj();
  initscr();
  //noecho();
  endwin();
  Menu();
  cout << "sss" << endl;
  /* while(true)
    {
      initscr();
      noecho();
      c = getch();
      clear();
      printw("znaczek: %d", c);
      refresh();
      }*/
  while(true)
    {
      Update();
      usleep(szybkoscAnimacji);
      if(Status == 0)
	Menu();
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

void Scena::Update()
{
  Status = 0;
  for(Robot &R : Roboty)
    {
      Status += R.Animuj(Przeszkody, Roboty);
    }
  Lacze.Rysuj();  
}


void Scena::Menu()
{
  char Znak;
  
  cout << endl <<  "Ver 1 Obecna ilosc zyjacych wektorow to  "  << Wektor2D::ilosc_zyjacych << " z " << Wektor2D::ilosc_wszystkich << endl;
  cout << "Co chesz zrobic?" << endl;
  cout << "n - nowy robot" << endl;
  cout << "p - nowa przeszkoda " << endl;
  cout << "z - zmien polozenie przeszkody " << endl;
  cout << "f - zmien szybkosc animacji " << endl;
  cout << "c - zmien skoki " << endl;
  cout << "s - skaluj do rozmiaru " << endl;
  cout << "l - podaj obrot i ile naprzod " << endl;
  cout << "v - podaj kordynaty " << endl;
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
      cin >> szybkoscAnimacji;
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
      double i;
      double a, b;
      
      cout << "Podaj numer robota" << endl;
      cin >> i;
      
      cout << "kat: " << endl;
      cin >> a;
      cout << "ile naprzod: " << endl;
      cin >> b;

      Roboty[i].UstalPolozenie(a, b);
    }
    if (Znak == 'v')
    {
      double i;
      Wektor2D a;
      
      cout << "Podaj numer robota" << endl;
      cin >> i;
      cout << "kordynaty: " << endl;
      cin >> a;

      Roboty[i].UstalPolozenie(a);
    }
    if (Znak == 'z')
    {
      double i;
      Wektor2D b;
      
      cout << "Podaj numer przeszkody" << endl;
      cin >> i;
      Lacze.DodajNazwePliku(Przeszkody[i].name.c_str(),PzG::RR_Ciagly,5);
      Lacze.Rysuj();
      cout << "Nowe Polozenie:  " << endl;
      cin >> b;

      Przeszkody[i].ZmienPolozenie(b);
      cout << "Nowe Polozenie:  " << Przeszkody[i]._PolozenieObiektu << endl;
      
      OdnowListePlikow();
      Lacze.Rysuj();
    }
    if (Znak == 'o')
    {
      int c = 0;
      initscr();
      while(c != 49)
	{
	  noecho();
	  c = getch();
	  clear();
	  printw("znaczek: %d", c);
	  endwin();
	  Sterowanie(c);
	  Update();
	  usleep(szybkoscAnimacji);
	  usleep(10000);
	  initscr();
	  refresh();
	}
    }

    
}


void Scena::OdnowListePlikow()
{
  Lacze.UsunWszystkieNazwyPlikow();
  for(Robot &R : Roboty)
    { 
      Lacze.DodajNazwePliku(R.name.c_str(),PzG::RR_Ciagly,2);
      Lacze.DodajNazwePliku(R.Sciesz.name.c_str(),PzG::RR_Ciagly,2);
    }
  
  for(Przeszkoda &P : Przeszkody)
    {
      Lacze.DodajNazwePliku(P.name.c_str(),PzG::RR_Ciagly,2);
    }
  
  Lacze.Rysuj();  
}

void Scena::Sterowanie(int c)
{
  Robot &R = Roboty[0];
  if(c == 65)
    R.UstalPolozenie(0, R.krok_move);
  if(c == 66)
    R.UstalPolozenie(0, -R.krok_move);
  if(c == 97)
    R.UstalPolozenie(R.krok_move, 0);
  if(c == 100)
    R.UstalPolozenie(-R.krok_move, 0);
  if(c == 67)
    R.UstalPolozenie(R.krok_move, 0);
  if(c == 68)
    R.UstalPolozenie(-R.krok_move, 0);
    
    
}
