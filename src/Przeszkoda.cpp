#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include <iostream>
#include <string>
#include <math.h>
#include <unistd.h>


void Przeszkoda::Inicjalizuj(Wektor2D LG, Wektor2D PD)
{
  szerokosc = PD[0] - LG[0];
  wysokosc  = LG[1] - PD[1];
  _PolozenieObiektu = {LG[0]+szerokosc/2,PD[1]+wysokosc/2};
  InicjalizujKsztalt(LG, PD);
}

void Przeszkoda::InicjalizujKsztalt(Wektor2D LG, Wektor2D PD)
{
  _TabWierz_wzorzec.push_back({ -szerokosc/2, -wysokosc/2});
  _TabWierz_wzorzec.push_back({  szerokosc/2, -wysokosc/2});
  _TabWierz_wzorzec.push_back({  szerokosc/2,  wysokosc/2});
  _TabWierz_wzorzec.push_back({ -szerokosc/2,  wysokosc/2});
  _TabWierz_wzorzec.push_back({ -szerokosc/2, -wysokosc/2});
  _TabWierz = _TabWierz_wzorzec;
  /*_TabWierz_wzorzec.push_back(  LG          );
  _TabWierz_wzorzec.push_back({PD[0], LG[1]});
  _TabWierz_wzorzec.push_back(  PD          );
  _TabWierz_wzorzec.push_back({LG[0], PD[1]});
  _TabWierz_wzorzec.push_back(  LG          );
  _TabWierz = _TabWierz_wzorzec;
  
  _TabWierz[1][0] =  30;  _TabWierz[1][1]=   0;
  _TabWierz[2][0] =   0;  _TabWierz[2][1]= -30;
  _TabWierz[3][0] = -30;  _TabWierz[3][1]= -30;
  _TabWierz[4][0] = -30;  _TabWierz[4][1]=  30;
  _TabWierz[5][0] =   0;  _TabWierz[5][1]=  30;
  _TabWierz[6][0] =  30;  _TabWierz[6][1]=   0;*/
}
