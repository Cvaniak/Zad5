#ifndef SCIESZKA_HH
#define SCIESZKA_HH

#include <iostream>
#include <vector>
#include "Wektor2D.hh"
#include "ObiektGraficzny.hh"
#include <string>
#include <typeinfo>
#include <time.h>



  /*!
   * \brief Klasa dziedziczaca po ObiektGraficzny
   *
   * Rysuje scieszke mieszy kolejnymi punktami robota
   */
class Scieszka: public ObiektGraficzny
{
public:
  /*!
   * \brief Indywidulana nazwa dla Scieszki
   */
  std::string name;
  
  /*!
   * \brief Konstruktor Scieszki - nic nie robi
   */
  Scieszka(){

  }

  /*!
   * \brief Tworzy Scieszke - zapisuje do pliku i ustawia poczatkowy punkt
   */
  int InicjalizujKsztalt(Wektor2D&);
  /*!
   * \brief Pusta metoda
   */
  void InicjalizujKsztalt();
  /*!
   * \brief Tworzy nazwe Scieszki - scieszka + numer
   */
  void Inicjalizuj(int x);
  /*!
   * \brief dodaje punkt do Scieszki
   */
  int dodaj(Wektor2D&);
  /*!
   * \brief Zwraca nazwe scieszki
   */
  std::string tell();
};

#endif
