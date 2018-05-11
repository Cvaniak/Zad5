/*!
 * \file
 * \brief Zawiera wywołanie funkcji main
 *
 * Główny moduł programu wraz z wywołaniem funkcji main.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Przeszkoda.hh"
#include "Robot.hh"
#include "Scena.hh"
#include "SWektor.hh"

using namespace std;

template<>
int Wektor2D::ilosc_zyjacych=0;
template<>
int Wektor2D::ilosc_wszystkich=0;


int main()
{
  /*
  PzG::LaczeDoGNUPlota Lacze;
  Robot R(0, {0, 0});
  Przeszkoda P(0, {-100, -100}, {-200, -200});
  Przeszkoda P1(1, {100, 100}, {200, 200});
  Lacze.DodajNazwePliku(R.name.c_str(),PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku(P.name.c_str(),PzG::RR_Ciagly,2);
  Lacze.DodajNazwePliku(P1.name.c_str(),PzG::RR_Ciagly,2);
  if (!R.ZapiszDoPliku(R.name.c_str())) return 1;
  if (!P.ZapiszDoPliku(P.name.c_str())) return 1;
  if (!P.ZapiszDoPliku(P1.name.c_str())) return 1;
  Lacze.Rysuj();*/
  Scena S;
  S.Run();
}
