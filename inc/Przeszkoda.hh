#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include <iostream>
#include <vector>
#include "Wektor2D.hh"
#include "ObiektGraficzny.hh"
#include "lacze_do_gnuplota.hh"
#include <typeinfo> 
#include <string>



  /*!
   * \brief Klasa Robota
   *
   * Klasa dziedziczy po robocie, sterowany przez Scene
   */
class Przeszkoda : public ObiektGraficzny
{
protected:
  /*!
   * \brief numer indeksu wykorzystywany do tworzenia nazwy
   */
  int numer;
public:
  /*!
   * \brief Zmienna przechowujaca nazwe Robota
   *
   * Nazwa robota to robot + numer
   */
  std::string name;
  /*!
   * \brief Zmienna informujaca o wielkosci robota
   */
  double rozmiar = 1;
  /*!
   * \brief Zmienna informujaca o wielkosci robota
   */
  double szerokosc = 0;
  /*!
   * \brief Zmienna informujaca o wielkosci robota
   */
  double wysokosc = 0;
  //Robot(){}
  /*!
   * \brief Konstruktor robota
   *
   * Nadaje mu nazwe, inicjalizuje scieszke, Inicjalizuje krztalt
   */
  Przeszkoda(int i, Wektor2D LG, Wektor PD)
  {
    std::string   a = "figury/";
    std::string   b = "przeszkoda";
    std::string   c = std::to_string(i);
    std::string   d = ".dat";
    name = a + b + c + d;

    
    
    Inicjalizuj(LG, PD);
  }
  /*!
   * \brief Metoda incjacji krztaltu Robota
   */
  void InicjalizujKsztalt();
  /*!
   * \brief Metoda wywolujoca Inicjalizacje krztaltu robota i scieszki
   */
  void Inicjalizuj();
};

#endif
