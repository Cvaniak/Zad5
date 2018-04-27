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
  Scena S;
  S.Run();
}
